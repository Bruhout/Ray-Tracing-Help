#include "../header/hittable_arr.hpp"
#include "../header/hittable.hpp"
#include "../header/vec3d.hpp"
#include "../header/hitRecord.hpp"
#include "../header/ray.hpp"
#include "../header/interval.hpp"
#include "../header/color.hpp"

HittableArray::HittableArray()
    : objArray{}
{}

// Check if the hitObjPtr is NULL and faceMaterialPtr is NULL.
// tHit is -100000.0f for no hit
// Just return info about the ray hit if any takes place
bool HittableArray::HitCheckArray(Ray shotRay , Interval tInterval , HitRecord* hitRec)
{
    std::vector<float> tValues;

    for (auto obj : objArray)
    {
        if (obj->HitCheck(shotRay , tInterval , hitRec))
        {
            tValues.push_back(hitRec->tHit);
        }
    }

    float minT = 100000.0f;
    int minTIndex = -1;
    int counter = 0;
    for (float T : tValues)
    {
        // tValues should only contain +ve t
        if (T < minT /*&& T > 0.01f*/)
        {
            minT = T;
            minTIndex = counter;
        }
        counter++;
    }

    if (minTIndex == -1)
    {
        *hitRec = HitRecord();
        return false;
    }

    else
    {
        hitRec->tHit = minT;
        hitRec->hitPoint = shotRay.PointFromT(minT);
        hitRec->surfaceNormal = objArray[minTIndex]->GetNormal(shotRay.PointFromT(minT));
        hitRec->hitObjPtr = objArray[minTIndex];
        hitRec->faceMaterialPtr = objArray[counter]->matSurface;
        return true;
    }
}

// take in one ray, calculate intersection and spawn another from that point till maxDepth
Color HittableArray::BounceThrough(Ray shotRay , int maxDepth , Interval tInterval , Color initialColor)
{
    Color currentColor = initialColor;
    Ray currentRay = shotRay;
    HitRecord currentRayHitRecord = HitRecord();
    for(int i=0 ; i<maxDepth ; i++)
    {
        if (HitCheckArray(currentRay , tInterval , &currentRayHitRecord))
        {
            // currentColor.Attenuate(currentRayHitRecord.faceMaterialPtr->matColor);
            currentColor = Color(255 , 0 , 0);
            currentRay = currentRayHitRecord.faceMaterialPtr->RayInteract(currentRay , currentRayHitRecord);
        }
        else
        {
            break;
        }
    }

    return currentColor;
}