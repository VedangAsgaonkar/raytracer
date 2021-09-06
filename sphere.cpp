#include"sphere.h"
#include<cmath>
#include<iostream>
using namespace std;

sphere::sphere(){

}
sphere::sphere(vec3 cen, float r, material* mat_ptr){
    center = cen;
    radius = r;
    this->mat_ptr = mat_ptr;
}
bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const{
    float a = r.direction().squared_length();
    float b = 2*( dot(r.direction(),r.origin()) - dot(r.direction(),center) );
    float c = r.origin().squared_length() + center.squared_length() - radius*radius - 2*( dot(center,r.origin()) );
    if(b*b-4*a*c <=0){
        return false;
    }
    else{
        float t1 = (-b - sqrt(b*b-4*a*c))/(2*a) ;
        float t2 = (-b + sqrt(b*b-4*a*c))/(2*a) ;
        if(t2<t_min || t1>t_max){
            return false;
        }
        else{
            if(t1>=t_min){
                rec.t = t1;
                rec.p = r.point_at_parameter(rec.t);
                rec.normal = (rec.p-center)/radius;
                rec.mat_ptr = mat_ptr;
                return true;
            }
            else{
                rec.t = t2;
                rec.p = r.point_at_parameter(rec.t);
                rec.normal = (rec.p-center)/radius;
                rec.mat_ptr = mat_ptr;
                return true;
            }
        }
    }
}