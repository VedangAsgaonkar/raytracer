#include"lambertian.h"

lambertian::lambertian(const vec3& a){
    albedo = a;
}

bool lambertian::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const{
    vec3 p;
    do
    {
        p = vec3(drand48(),drand48(),drand48())*2.0 - vec3(1,1,1);
    } while (p.squared_length()>=1.0);
    vec3 target = rec.p + rec.normal + p;
    scattered = ray(rec.p, target-rec.p);
    attenuation = albedo;
    return true;
}
