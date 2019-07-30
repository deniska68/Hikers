#include "objects_2.h"

HikersBase::HikersBase(float *_hikersSpeeds, int count) :
    maxSpeed(0),
    fastestHikerIndex(0)
{
    hikersSpeeds.assign(_hikersSpeeds, _hikersSpeeds + count);
    GetMaxSpeedWithIndex();
}

float HikersBase::CrossBridgeTime(float _bridgeLength)
{
    if (_bridgeLength <= 0)
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

    return (hikersSpeeds.size() - 2.0)*_bridgeLength / maxSpeed + crossBridgeTime;
}

void HikersBase::GetMaxSpeedWithIndex()
{
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

HikersWithFriends::HikersWithFriends(float *_hikersSpeeds, int hikersNumber,
    float *_friendsSpeeds, int friendsNumber) :
    HikersBase(_hikersSpeeds, hikersNumber)
{
    hikersSpeeds.insert(hikersSpeeds.end(), _friendsSpeeds, _friendsSpeeds + friendsNumber);

    GetMaxSpeedWithIndex();
}

float HikersWithFriends::CrossBridgeTime(float _bridgeLength)
{
    return HikersBase::CrossBridgeTime(_bridgeLength);
}
