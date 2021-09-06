#include"camera.h"
#include<fstream>
#include<cmath>
#include<iostream>
#include"material.h"
#include"hitable.h"
using namespace std;

camera::camera(const vec3 &lookfrom, const vec3 &lookat, const vec3 &roll, float vertical_theta, float horizontal_theta, float vertical_pixel, float horizontal_pixel){
    this->lookfrom = lookfrom;
    this->lookat = lookat;
    this->roll = roll;
    this->vertical_theta = vertical_theta;
    this->horizontal_theta = horizontal_theta;
    this->vertical_pixel = vertical_pixel;
    this->horizontal_pixel = horizontal_pixel;
}
void camera::render(hitable *world, std::string outfile){
    std::fstream out_file;
    out_file.open(outfile,std::ios::out);
    int ns = 100;
    out_file << "P3\n" << horizontal_pixel << " " << vertical_pixel << "\n225\n";
    float distance = (lookat-lookfrom).length();
    // cout << "distance " << distance << "vertical tan theta " << tan(vertical_theta) << endl;
    float half_height = distance*tan(vertical_theta);
    float half_width = distance*tan(horizontal_theta);
    vec3 height_dir = unit_vector(roll);
    vec3 width_dir = unit_vector(cross(lookat-lookfrom,height_dir));
    // std::cout << width_dir << std::endl;
    for(int j=vertical_pixel-1 ; j>=0 ; j-- ){
        for(int i=0 ; i<horizontal_pixel ; i++ ){
            vec3 col(0,0,0);
            for(int k=0 ; k<ns ; k++){
                float u = float(i+drand48())/float(horizontal_pixel);
                float v = float(j+drand48())/float(vertical_pixel);                
                ray r(lookfrom, lookat-lookfrom + height_dir*half_height*(2*v-1) + width_dir*half_width*(2*u-1) ) ;
                col += color(r,world,0);
            }
            col /=float(ns) ;
            col = vec3(sqrt(col.e[0]),sqrt(col.e[1]),sqrt(col.e[2]));
            int ir = int(255.99*col.e[0]);
            int ig = int(255.99*col.e[1]);
            int ib = int(255.99*col.e[2]);
            out_file << ir << " " << ig << " " << ib << "\n";
        }
    }
}

vec3 camera::color(const ray& r, hitable* world, int depth){
    hit_record rec;
    if(world->hit(r,0.001,MAXFLOAT,rec)){
        ray scattered;
        vec3 attenuation;
        if(depth>=MAX_DEPTH || !rec.mat_ptr->scatter(r,rec,attenuation,scattered)){
            return vec3(0,0,0);
        }
        else{
            return attenuation*color(scattered,world,depth+1);          
        }
    }
    else{
        vec3 dir = r.direction()/r.direction().length();
        float t = 0.5*(dir.y()+1);
        return vec3(1,1,1)*(1-t)+vec3(0.5,0.7,1.0)*t;
    }
}

