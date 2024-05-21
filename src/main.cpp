#include <iostream>
#include <memory>

#include "../header/camera.hpp"
#include "../header/color.hpp"
#include "../header/hitRecord.hpp"
#include "../header/hittable_arr.hpp"
#include "../header/hittable.hpp"
#include "../header/interval.hpp"
#include "../header/material.hpp"
#include "../header/ray.hpp"
#include "../header/sphere.hpp"
#include "../header/vec3d.hpp"

#define PIXEL_HEIGHT 100
#define PIXEL_WIDTH 100
#define SAMPLES_PER_PIXEL 1

int main(void)
{
    HittableArray sceneObjects = HittableArray();

    Diffuse diffuseMat;
    diffuseMat.matColor = Color(255 , 100 , 100); 

    Sphere sphereObj = Sphere(Vec3D(0,0,0) , 1.5f , &diffuseMat);
    Sphere sphereBase = Sphere(Vec3D(0.0f , 0.0f , -11.5f) , 10.0f , &diffuseMat);

    sceneObjects.objArray.push_back(&sphereObj);
    sceneObjects.objArray.push_back(&sphereBase);

    Camera cam = Camera(PIXEL_WIDTH , PIXEL_HEIGHT);

    std::cout << "P3\n";
    std::cout << PIXEL_WIDTH << ' ' << PIXEL_HEIGHT << '\n';
    std::cout << 255 << '\n'; 

    for (int i = 0 ; i<PIXEL_HEIGHT ; i++)
    {
        for (int j=0 ; j<PIXEL_WIDTH ; j++)
        {
            std::clog << "here" << PIXEL_WIDTH*i + j << "\n";
            Color pixelColor = Color(0 , 0 , 0);
            for (int s=0 ; s<SAMPLES_PER_PIXEL ; s++)
            {
                Ray shotRay = cam.ShootSampleRay(j , i);
                std::clog << "shot ray" << PIXEL_WIDTH*i + j << "\n";
                Color sampleColor = sceneObjects.BounceThrough(shotRay , 1 , Interval(0.01f , 1000) , Color(0 , 200 , 0));
                pixelColor = pixelColor + sampleColor;
            }

            (pixelColor / SAMPLES_PER_PIXEL).WriteColor();
        }
    }
}

    // Triangle triGround = Triangle(
    //     Vec3D(0 , -6 , -3),
    //     Vec3D(2 , -1 , -3),
    //     Vec3D(-2 , -1 , -3)
    // );
// #include "triangle.hpp"
                // else if (triGround.HitCheck(shotRay , Interval()))
                // {
                //     rTotal += 25;
                //     gTotal += 200;
                //     bTotal += 50;
                // }