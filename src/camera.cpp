#include "../header/camera.hpp"
#include "../header/vec3d.hpp"
#include "../header/ray.hpp"
#include "../header/interval.hpp"

Camera::Camera()
    : camPos{0 , 6 , 0},
      frameOrigin{1 , 4 , 1},
      xVec{-2 , 0 , 0},
      yVec{0 , 0 , -2},
      xRes(256),
      yRes(256)
{}

Camera::Camera(Vec3D CamPos , Vec3D FrameOrigin , Vec3D XVec , Vec3D YVec , int XRes , int YRes)
    : camPos(CamPos),
      frameOrigin(FrameOrigin),
      xVec(XVec),
      yVec(YVec),
      xRes(XRes),
      yRes(YRes)
{}

Camera::Camera(int XRes , int YRes)
    : camPos{0 , 6 , 0},
      frameOrigin{1.0f * ((float)XRes/(float)YRes), 4 , 1.0f},
      xVec{-2 * ((float)XRes/(float)YRes) , 0 , 0},
      yVec{0 , 0 , -2},
      xRes(XRes),
      yRes(YRes)
{}

Ray Camera::ShootRay(int xCoord , int yCoord)
{
    Vec3D xVecDx = xVec / xRes;
    Vec3D yVecDy = yVec / yRes;

    Vec3D rayDirection = (frameOrigin + (xVecDx * xCoord) + (yVecDy * yCoord)) - camPos;
    // (camPos + rayDirection).PrintVec();
    rayDirection = rayDirection / rayDirection.Magnitude();
    Ray shotRay = Ray(camPos , rayDirection);
    return shotRay;
}


Ray Camera::ShootSampleRay(int xCoord , int yCoord)
{
    Vec3D xVecDx = xVec / xRes;
    Vec3D yVecDy = yVec / yRes;

    float xOffset = Interval(0.0f , 1.0f).RandNum();
    float yOffset = Interval(0.0f , 1.0f).RandNum();

    Vec3D rayDirection = (frameOrigin + (xVecDx * (xCoord + xOffset)) + (yVecDy * (yCoord + yOffset))) - camPos;
    // (camPos + rayDirection).PrintVec();
    rayDirection = rayDirection / rayDirection.Magnitude();
    Ray shotRay = Ray(camPos , rayDirection);
    return shotRay;
}