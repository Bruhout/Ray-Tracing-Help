#ifndef MATERIAL_HPP
#define MATERIAL_HPP
#include "ray.hpp"
#include "vec3d.hpp"
// #include "hitRecord.hpp"
#include "color.hpp"

/*
hit Record calls include on material, material calls include on hit record.
due to this neither is defined and we get an error.
we can remedy this by not including hit record in material
instead hit record is shortly declared in material.
since this is just a header file, there is no need for the actual implementation of the class
that is handled by the linked during compilation
*/

// HitRecord is passed as pointer when intent is to write info, for example in case of HitCheck.
// HitRecord is passed as value when intent is to read information.

class HitRecord;

class Material
{
public:
    Color matColor;

    virtual ~Material() = default;

    virtual Ray RayInteract(Ray shotRay , HitRecord hitRec) = 0;
};

class Metal : public Material
{
public:
    Ray RayInteract(Ray shotRay , HitRecord hitRec) override;
};

class Diffuse : public Material
{
public:
    Ray RayInteract(Ray shotRay , HitRecord hitRec) override;
};

#endif // MATERIAL_HPP