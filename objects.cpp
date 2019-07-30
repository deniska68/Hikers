#include "objects.h"
#include <vector>

using namespace std;

Hikers::Hikers(float *_hikersSpeeds, int count):
    maxSpeed(0), 
    fastestHikerIndex(0)
{
    hikersSpeeds.assign(_hikersSpeeds, _hikersSpeeds + count);

    int i(0);
    for each (Hiker hiker in hikersSpeeds)
    {
        if (maxSpeed < hiker.Speed())
        {
            fastestHikerIndex = i;
            maxSpeed = hiker.Speed();
        }
        i++;
    }
}

float Hikers::CrossBridgeTime(float _bridgeLength)
{
    if(_bridgeLength <= 0)
        return 0;

    float crossBridgeTime = 0;

    for (int i = 0; i < fastestHikerIndex; i++)
    {
        crossBridgeTime += _bridgeLength / hikersSpeeds[i].Speed();
    }

    for (int i = fastestHikerIndex + 1; i < hikersSpeeds.size(); i++)
    {
        crossBridgeTime += _bridgeLength / hikersSpeeds[i].Speed();        
    }

    return (hikersSpeeds.size() - 2)*_bridgeLength / maxSpeed + crossBridgeTime;
}

float Hikers::CrossBridgeWithFriendsTime(float _bridgeLength, float *_additionalHikers, int count)
{
    hikersSpeeds.insert(hikersSpeeds.end(), _additionalHikers, _additionalHikers + count);

    float maxSpeedCopy(maxSpeed);
    float fastestHikerIndexCopy(fastestHikerIndex);

    int i(0);
    for each (Hiker hiker in hikersSpeeds)
    {
        if (maxSpeed < hiker.Speed())
        {
            fastestHikerIndex = i;
            maxSpeed = hiker.Speed();
        }
        i++;
    }

    float time = CrossBridgeTime(_bridgeLength);

    maxSpeed = maxSpeedCopy;
    fastestHikerIndex = fastestHikerIndexCopy;

    hikersSpeeds.erase(hikersSpeeds.end() - count, hikersSpeeds.end());

    return time;
}