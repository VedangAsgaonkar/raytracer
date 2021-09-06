#include<iostream>
#include<fstream>
#include<cmath>
#include<bits/stdc++.h>
#include"hitable_list.h"
#include"sphere.h"
#include"camera.h"
#include"lambertian.h"
#include"metal.h"
#include"dielectric.h"
using namespace std;

int max_depth = 20;

vec3 color(const ray& r, hitable* world, int depth){
    hit_record rec;
    if(world->hit(r,0.001,MAXFLOAT,rec)){
        ray scattered;
        vec3 attenuation;
        if(depth >= max_depth || !rec.mat_ptr->scatter(r,rec,attenuation,scattered)){
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

int main(){

    //output
    fstream out_file;
    out_file.open("images/firstimage.ppm",ios::out);

    //frame
    int nx = 200;
    int ny = 100;
    int ns = 100;
    vec3 origin(0,0,0);
    vec3 horizontal(4,0,0);
    vec3 vertical(0,2,0);
    vec3 lower_left_corner(-2,-1,-1);

    //camera
    camera c(origin,horizontal,vertical,lower_left_corner);

    //world
    hitable* list[5];
    list[0] = new sphere(vec3(0,0,-1), 0.5, new dielectric(1.5) );
    list[1] = new sphere(vec3(0,-100.5,-1),100, new lambertian(vec3(0.8,0.8,0.0)));
    list[2] = new sphere(vec3(1,0,-1),0.5,new metal(vec3(0.8,0.6,0.2),0.1));
    list[3] = new sphere(vec3(-1,0,-1),0.5, new lambertian(vec3(0.8,0.3,0.3)) );
    list[4] = new sphere(vec3(1,0,-8),0.45, new lambertian(vec3(0.3,0.3,0.8)));
    hitable *world = new hitable_list(list,5);

    out_file << "P3\n" << nx << " " << ny << "\n225\n";
    for(int j=ny-1 ; j>=0 ; j--){
        for (int i = 0; i <nx; i++)
        {   
            vec3 col(0,0,0);
            for (int k = 0; k<ns ; k++)
            {
                float u = float(i+drand48())/float(nx);
                float v = float(j+drand48())/float(ny);
                ray r = c.get_ray(u,v);
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

    out_file.close();
}