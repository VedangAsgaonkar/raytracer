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

#define PI 3.14159265

int main(){

    //camera
    vec3 lookfrom(-2,1,0.5);
    vec3 lookat(0,0,-1);
    vec3 roll(0,1,0);
    float vertical_theta = PI/4;
    float horizontal_theta = atan(2);
    int vertical_pixel = 500;
    int horizontal_pixel = 1000;
    camera c(lookfrom,lookat,roll,vertical_theta, horizontal_theta, vertical_pixel, horizontal_pixel);

    //world
    hitable* list[6];
    list[0] = new sphere(vec3(0,0,-1), 0.5, new dielectric(1.5) );
    list[1] = new sphere(vec3(0,-100.5,-1),100, new metal(vec3(0.7,0.8,0.9),0.05));
    list[2] = new sphere(vec3(1,0,-2),0.5,new metal(vec3(0.8,0.6,0.2),0.1));
    list[3] = new sphere(vec3(-1,0,-1),0.5, new metal(vec3(0.8,0.6,0.2),0.1) );
    list[4] = new sphere(vec3(1,0,-8),0.45, new lambertian(vec3(0.3,0.3,0.8)));
    list[5] = new sphere(vec3(0.5,0,0.5), 0.25, new lambertian(vec3(0.8,0.3,0.3)));
    hitable *world = new hitable_list(list,6);

    //render
    c.render(world,"images/fifthImage.ppm");
}