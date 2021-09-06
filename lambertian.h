#ifndef _LAMBERTIAN_H_
#define _LAMBERTIAN_H_

#include"material.h"

class lambertian : public material{
    public:
    lambertian(const vec3 &a);
    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;
    vec3 albedo;
};

#endif