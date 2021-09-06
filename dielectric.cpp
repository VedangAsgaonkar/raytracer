#include"dielectric.h"
#include<cmath>
#include<iostream>

dielectric::dielectric(float ri){
    ref_index = ri;
}

float schlick(float cosine, float ref_index){
    //finding reflectivity as a function of angle of incidence
    float r0 = (1-ref_index)/(1+ref_index);
    r0 = r0*r0;
    return r0 + (1-r0)*pow(1-cosine,5);
}

bool dielectric::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const{
    vec3 outward_normal;
    vec3 reflected = r_in.direction() - rec.normal*(2*dot(rec.normal,r_in.direction()));
    float ni_over_nt;
    attenuation = vec3(0.9,1,0.9);
    if(dot(r_in.direction(),rec.normal)>0){
        outward_normal = rec.normal*(-1);
        ni_over_nt = ref_index;
    }
    else{
        outward_normal = rec.normal;
        ni_over_nt = 1/ref_index;
    }

    vec3 uv = unit_vector(r_in.direction());
    float dt = dot(uv,outward_normal);
    float disc = 1- ni_over_nt*ni_over_nt*(1-dt*dt);
    if(disc > 0){
        vec3 refracted = (uv-outward_normal*dt)*ni_over_nt - outward_normal*sqrt(disc);
        float cosine = -ref_index*dot(r_in.direction(),outward_normal)/r_in.direction().length();
        float reflected_prob = schlick(cosine,ref_index);
        if(drand48()<schlick(cosine, ref_index)){
            // std::cout << schlick(cosine, ref_index)<< std::endl;
            scattered = ray(rec.p, reflected);
        }
        else{
            // std::cout << "refracted" << std::endl;
            scattered = ray(rec.p,refracted);
        }
    }
    else{
        scattered = ray(rec.p, reflected);
    }
    return true;
}

