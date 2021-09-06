#ifndef _METAL_H
#define _METAL_H

#include"material.h"

class metal : public material{
    public:
    metal(const vec3& a, float f);
    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;
    vec3 albedo;
    float fuzz;
};

#endif