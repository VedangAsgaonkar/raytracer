#include "hitable_list.h"
#include"sphere.h"
#include<cmath>
using namespace std;

hitable_list::hitable_list(){
    list = nullptr;
    list_size =0;
}
hitable_list::hitable_list(hitable **l, int n){
    list = l;
    list_size = n;
}
bool hitable_list::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
    hit_record temp_rec;
    bool hit_yet = false;
    double closest_t = t_max;
    for(int i=0 ; i<list_size ; i++){
        if(list[i]->hit(r,t_min,t_max,temp_rec)){
            hit_yet = true;
            if(temp_rec.t < closest_t){
                rec = temp_rec;
                closest_t = temp_rec.t;
            } 
        }
    }
    return hit_yet;

}