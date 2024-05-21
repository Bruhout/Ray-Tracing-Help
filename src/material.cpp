#include "../header/material.hpp"
#include "../header/hitRecord.hpp"
#include "../header/ray.hpp"
#include "../header/vec3d.hpp"

// Ensure hitrecord is included after material to get the correct hit record class

Ray Metal::RayInteract(Ray shotRay , HitRecord hitRec)
{
    return shotRay.GetDirectReflecton(hitRec.hitPoint , hitRec.surfaceNormal);
}

Ray Diffuse::RayInteract(Ray shotRay , HitRecord hitRec)
{
    return Ray::GetRandomReflection(hitRec.hitPoint , hitRec.surfaceNormal);
}