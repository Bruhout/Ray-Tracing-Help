#include "../header/vec3d.hpp"
#include "../header/ray.hpp"
#include "../header/material.hpp"
#include "../header/sphere.hpp"
#include "../header/interval.hpp"
#include "../header/hitRecord.hpp"


Sphere::Sphere()
    : center{0 , 0 , 0},
      radius(1.0f),
      matSurface(NULL)
{}

Sphere::Sphere(Vec3D Center , float Radius , Material* MatSurface)
    : center(Center),
      radius(Radius),
      matSurface(MatSurface)
{}

bool Sphere::HitCheck(Ray shotRay , Interval tInterval , HitRecord* hitRec)
{
    float b = 2 * shotRay.B.DotProduct(shotRay.A - center);
    float a = shotRay.B.MagnitudeSq();
    float c = (shotRay.A.MagnitudeSq() + center.MagnitudeSq() - (shotRay.A.DotProduct(center) * 2) - (radius * radius));

    if ((b*b - 4*a*c) > 0)
    {
        float tValue = (-b - pow(b*b - 4*a*c , 0.5)) / 2 * a;

        hitRec->tHit = tValue;
        hitRec->hitPoint = shotRay.PointFromT(tValue);
        hitRec->surfaceNormal = GetNormal(shotRay.PointFromT(tValue));
        hitRec->hitObjPtr = this;
        hitRec->faceMaterialPtr = matSurface;

        return true;
    }
        
    else
    {
        hitRec->tHit = -100000.0f;
        hitRec->hitPoint = Vec3D();
        hitRec->surfaceNormal = Vec3D();
        hitRec->hitObjPtr = NULL;
        hitRec->faceMaterialPtr = NULL;

        return false;
    }
}

Vec3D Sphere::GetNormal(Vec3D hitPoint) 
{
    Vec3D normalVec = (center - hitPoint) / (center - hitPoint).Magnitude();
    return normalVec;
}

void Sphere::PrintSphere()
{
    std::clog << "Center:";
    center.PrintVec();
    std::clog << "Radius" << radius << "\n";
}

