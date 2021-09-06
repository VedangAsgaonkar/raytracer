#ifndef _HITABLE_LIST_H 
#define _HITABLE_LIST_H

#include "hitable.h"

class hitable_list : public hitable{
    public:
    hitable_list();
    hitable_list(hitable **l, int n);
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const ;
    hitable **list;
    int list_size;
};

#endif