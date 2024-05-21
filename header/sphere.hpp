#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "vec3d.hpp"
#include "ray.hpp"
#include "hittable.hpp"
#include "hitRecord.hpp"
#include "material.hpp"

class Sphere : public Hittable 
{
public:
    // Member variables
    Vec3D center;
    float radius;
    Material* matSurface;

    // Constructors
    Sphere();
    Sphere(Vec3D Center, float Radius, Material* MatSurface);

    // Functions declared but not defined (prototypes)
    bool HitCheck(Ray shotRay, Interval tInterval, HitRecord* hitRec) override;
    Vec3D GetNormal(Vec3D hitPoint) override;
    void PrintSphere();
};

#endif // SPHERE_HPP
