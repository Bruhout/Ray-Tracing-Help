#ifndef HITTABLE_ARR_HPP
#define HITTABLE_ARR_HPP

#include <iostream>
#include <memory>
#include <vector>
#include "hittable.hpp"
#include "interval.hpp"
#include "hitRecord.hpp"

// Very important : The coloring of the ray and the reflection of the ray is handled completely separately
// Material class handles how the ray is reflected with RayInteract() function
// Color class handles how the ray is colored with the attentuation() function

class HittableArray
{
public:
    std::vector<Hittable*> objArray;

    HittableArray();

    // Check if the hitObjPtr is NULL and faceMaterialPtr is NULL.
    // tHit is -100000.0f for no hit
    // Just return info about the ray hit if any takes place
    bool HitCheckArray(Ray shotRay , Interval tInterval , HitRecord* hitRec);

    // take in one ray, calculate intersection and spawn another from that point till maxDepth
    Color BounceThrough(Ray shotRay , int maxDepth , Interval tInterval , Color initialColor);
};

#endif // HITTABLE_ARR_HPP










//     float BounceThroughDirect(Ray shotRay , int maxDepth , Interval tInterval , float absorptionRatio)
//     {
//         float colorScaleFactor = 1.0f;
//         Ray currentRay = shotRay;
//         for(int i=0 ; i<maxDepth ; i++)
//         {
//             HitRecord recentHit = HitCheckArray(currentRay , tInterval);
//             if (recentHit.hitObjPtr != NULL && tInterval.Contains(recentHit.tHit))
//             {
//                 Ray reflectedRay = currentRay.GetDirectReflecton(recentHit.hitPoint , recentHit.surfaceNormal);
//                 colorScaleFactor *= absorptionRatio;
//                 currentRay = reflectedRay;
//             }
//             else
//             {
//                 break;
//             }
//         } 

//         return colorScaleFactor;
//     }

//     float BounceThroughLambert(Ray shotRay , int maxDepth , Interval tInterval , float absorptionRatio)
//    {
//         Ray currentRay = shotRay;
//         float colorScalingFactor = 1.0f;
//         for(int i=0 ; i<maxDepth ; i++)
//         {
//             HitRecord recentHit = HitCheckArray(currentRay , tInterval);
//             if (recentHit.hitObjPtr != NULL && tInterval.Contains(recentHit.tHit))
//             {
//                 Ray reflectedRay = Ray::GetRandomReflection(recentHit.hitPoint , recentHit.surfaceNormal);
//                 float cosine = reflectedRay.B.DotProduct(recentHit.surfaceNormal);

//                 colorScalingFactor *= (absorptionRatio * cosine);
//                 currentRay = reflectedRay;
//             }
//             else
//             {
//                 break;
//             }
//         } 

//         return colorScalingFactor;
//     }