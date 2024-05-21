#ifndef HIT_RECORD_HPP
#define HIT_RECORD_HPP
#include "vec3d.hpp"
#include "hittable.hpp"
#include "material.hpp"


class HitRecord
{
public:
    float tHit;
    Vec3D hitPoint;
    Vec3D surfaceNormal;
    Hittable* hitObjPtr;
    Material* faceMaterialPtr;

    HitRecord();

    HitRecord(float THit , Vec3D HitPoint , Vec3D SurfaceNormal , Hittable* HitObjPtr , Material* FaceMaterialPtr);
};

#endif // HIT_RECORD_HPP