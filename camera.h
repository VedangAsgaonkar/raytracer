#ifndef _CAMERA_H_
#define _CAMERA_H_

#include"ray.h"

class camera{
    public:
    camera(vec3 origin, vec3 horizontal, vec3 vertical, vec3 lower_left_corner);
    ray get_ray(float u, float v);

    private:
    vec3 origin;
    vec3 horizontal;
    vec3 vertical;
    vec3 lower_left_corner;
};

#endif