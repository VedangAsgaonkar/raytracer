#ifndef _RAY_H_
#define _RAY_H_

#include"vec3.h"

class ray{
public:
    ray();
    ray(const vec3 &v1, const vec3 &v2);
    vec3 origin() const;
    vec3 direction() const;
    vec3 point_at_parameter(float t) const;

    vec3 A;
    vec3 B;
};

#endif