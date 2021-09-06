#ifndef _CAMERA_H_
#define _CAMERA_H_

#include"ray.h"
#include"hitable_list.h"
#include<string>

#define MAX_DEPTH 20

class camera{
    public:
    camera(const vec3 &lookfrom, const vec3 &lookat, const vec3 &roll, float vertical_theta, float horizontal_theta, float vertical_pixel, float horizontal_pixel);
    void render(hitable *world, std::string outfile);
    private:
    vec3 lookfrom;
    vec3 lookat;
    vec3 roll;
    float vertical_theta;
    float horizontal_theta;
    int vertical_pixel;
    int horizontal_pixel;
    vec3 color(const ray& r, hitable* world, int depth);
};

#endif