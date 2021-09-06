#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "hitable.h"
#include "material.h"

class sphere : public hitable{
    public:
    sphere();
    sphere(vec3 cen, float r, material* mat_ptr); 
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;
    vec3 center;
    float radius;
    material* mat_ptr;
};

#endif