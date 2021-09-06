#include"camera.h"

camera::camera(vec3 origin, vec3 horizontal, vec3 vertical, vec3 lower_left_corner){
    this->origin = origin;
    this->horizontal = horizontal;
    this->vertical = vertical;
    this->lower_left_corner = lower_left_corner;
}

ray camera::get_ray(float u, float v){
    return ray(origin,lower_left_corner+horizontal*u+vertical*v-origin);
}
