#include"ray.h"

ray::ray(){

}
ray::ray(const vec3 &v1, const vec3 &v2){
    A = v1;
    B = v2;
}
vec3 ray::origin() const{
    return A;
}
vec3 ray::direction() const{
    return B;
}
vec3 ray::point_at_parameter(float t) const{
    return A+B*t;
}