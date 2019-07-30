#include <vector>
#include "objects.h"

using namespace std;

class HikersBase
{
public:
    HikersBase(float *_hikersSpeeds, int count);

    virtual float CrossBridgeTime(float _bridgeLength);

    virtual ~HikersBase() {}

protected:
    void GetMaxSpeedWithIndex(/*float *_pMaxSpeed, float *_pFastestHikerIndex*/);

    vector<Hiker> hikersSpeeds;

    float maxSpeed;
    int fastestHikerIndex;
};

class HikersWithFriends : public HikersBase
{
public:
    HikersWithFriends(float *_hikersSpeeds, int hikersNumber, float *_friendsSpeeds, int friendsNumber);

    float CrossBridgeTime(float _bridgeLength);
};