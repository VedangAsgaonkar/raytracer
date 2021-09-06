#ifndef _VEC3_H_
#define _VEC3_H_

#include<cstdlib>
#include<iostream>

class vec3{
public:
    vec3();
    vec3(float e0, float e1, float e2);

    float x() const;
    float y() const;
    float z() const;
    float r() const;
    float g() const;
    float b() const;
    vec3& operator += (const vec3 &v2);
    vec3& operator -= (const vec3 &v2);
    vec3& operator *= (const vec3 &v2);
    vec3& operator /= (const vec3 &v2);
    vec3& operator *= (const float t);
    vec3& operator /= (const float t);
    float length() const;
    float squared_length() const;
    void make_unit_vector();

    float e[3];    
};

inline std::istream& operator>>(std::istream &is, vec3 &t){
    is >> t.e[0] >> t.e[1] >> t.e[2];
    return is;
}
inline std::ostream& operator<<(std::ostream &os, vec3 &t){
    os << t.e[0] << " " << t.e[1] << " " << t.e[2];
    return os;
}

inline vec3 operator+(const vec3 &v1,const vec3 &v2){
    return vec3(v1.e[0]+v2.e[0],v1.e[1]+v2.e[1],v1.e[2]+v2.e[2]);
}
inline vec3 operator-(const vec3 &v1,const vec3 &v2){
    return vec3(v1.e[0]-v2.e[0],v1.e[1]-v2.e[1],v1.e[2]-v2.e[2]);  
}
inline vec3 operator*(const vec3 &v1,const vec3 &v2){
    return vec3(v1.e[0]*v2.e[0],v1.e[1]*v2.e[1],v1.e[2]*v2.e[2]);
}
inline vec3 operator/(const vec3 &v1,const vec3 &v2){
    return vec3(v1.e[0]/v2.e[0],v1.e[1]/v2.e[1],v1.e[2]/v2.e[2]);
}
inline vec3 operator*(const vec3 &v1,float t){
    return vec3(v1.e[0]*t,v1.e[1]*t,v1.e[2]*t);
}
inline vec3 operator/(const vec3 &v1,float t){
    return vec3(v1.e[0]/t,v1.e[1]/t,v1.e[2]/t);
}
inline float dot(const vec3 &v1, const vec3 &v2){
    return v1.e[0]*v2.e[0]+v1.e[1]*v2.e[1]+v1.e[2]*v2.e[2];
}
inline vec3 cross(const vec3 &v1,const vec3 &v2){
    return vec3(v1.e[1]*v2.e[2]-v1.e[2]*v2.e[1],v1.e[2]*v2.e[0]-v1.e[0]*v2.e[2],v1.e[0]*v2.e[1]-v1.e[1]*v2.e[0]);
}
inline vec3 unit_vector(vec3 v){
    return v/v.length();
}

#endif