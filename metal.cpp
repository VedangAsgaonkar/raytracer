#include"metal.h"

metal::metal(const vec3& a, float f){
    albedo = a;
    fuzz = f >1 ? 1 : f;
}

bool metal::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const{
    vec3 dir = r_in.direction() - rec.normal*(2*dot(rec.normal,r_in.direction()));
    vec3 p;
    do
    {
        p = vec3(drand48(),drand48(),drand48())*2.0 - vec3(1,1,1);
    } while (p.squared_length()>=1.0);
    scattered = ray(rec.p,dir+p*fuzz);
    attenuation = albedo;
    return (dot(scattered.direction(),rec.normal) > 0);    
}
