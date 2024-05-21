#include "../header/ray.hpp"
#include "../header/vec3d.hpp"

Ray::Ray(Vec3D a , Vec3D b) : A(a) , B(b) {}

void Ray::PrintRay()
{
    std::cout << "A:";
    A.PrintVec();

    std::cout << "B";
    B.PrintVec();
}

Vec3D Ray::PointFromT(float t)
{
    return A + B*t;
}

Ray Ray::GetRandomReflection(Vec3D incidentPoint , Vec3D surfaceNormal)
{
    Vec3D reflectedVecDir = Vec3D::GetRandDir();
    if (surfaceNormal.DotProduct(reflectedVecDir) < 0.0f)
    {
        return Ray(incidentPoint , reflectedVecDir * -1);
    }
    else
    {
        return Ray(incidentPoint , reflectedVecDir);
    }
}

Ray Ray::GetDirectReflecton(Vec3D incidentPoint , Vec3D surfaceNormal)
{
    Vec3D reflectedVecDir = B.GetDirectReflection(surfaceNormal);
    return Ray(incidentPoint , reflectedVecDir * -1);
}