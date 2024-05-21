#ifndef HITTABLE_HPP
#define HITTABLE_HPP

#include <iostream>
#include "ray.hpp"
#include "interval.hpp"
#include "material.hpp"

class HitRecord;

class Hittable
{
public:
    Material* matSurface;

    virtual ~Hittable() = default;

    virtual bool HitCheck(Ray shotRay , Interval tInterval , HitRecord* hitRec) = 0;

    virtual Vec3D GetNormal(Vec3D hitPoint) = 0;
};

#endif // HITTABLE_HPP