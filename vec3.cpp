#include"vec3.h"
#include<cmath>
#include<cstdlib>
#include<iostream>


vec3::vec3(){

}

vec3::vec3(float e0, float e1, float e2){
    this->e[0] = e0;
    this->e[1] = e1;
    this->e[2] = e2;
}

float vec3::x() const{
    return e[0];
}
float vec3::y() const{
    return e[1];
}
float vec3::z() const{
    return e[2];
}
float vec3::r() const{
    return e[0];
}
float vec3::g() const{
    return e[1];
}
float vec3::b() const{
    return e[2];
}

vec3& vec3::operator += (const vec3 &v2){
    e[0] += v2.e[0];
    e[1] += v2.e[1];
    e[2] += v2.e[2];
    return *this;
}
vec3& vec3::operator -= (const vec3 &v2){
    e[0] -= v2.e[0];
    e[1] -= v2.e[1];
    e[2] -= v2.e[2];
    return *this;
}
vec3& vec3::operator *= (const vec3 &v2){
    e[0] *= v2.e[0];
    e[1] *= v2.e[1];
    e[2] *= v2.e[2];
    return *this;
}
vec3& vec3::operator /= (const vec3 &v2){
    e[0] /= v2.e[0];
    e[1] /= v2.e[1];
    e[2] /= v2.e[2];
    return *this;
}
vec3& vec3::operator *= (const float t){
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}
vec3& vec3::operator /= (const float t){
    e[0] /= t;
    e[1] /= t;
    e[2] /= t;
    return *this;
}
float vec3::length() const{
    return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
}
float vec3::squared_length() const{
    return (e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
 
}
void vec3::make_unit_vector() {
    e[0]= e[0]/this->length();
    e[1]= e[1]/this->length();
    e[2]= e[2]/this->length();
}