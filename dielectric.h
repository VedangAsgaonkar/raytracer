#ifndef _DIELECTRIC_H_
#define _DIELECTRIC_H_

#include"material.h"

class dielectric : public material{
    public:
    dielectric(float ri);
    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;
    float ref_index;
};

#endif