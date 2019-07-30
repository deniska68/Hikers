#include <vector>

using namespace std;

class Hiker
{
public:
    Hiker(float _speed) : speed(_speed)
    {}

    float Speed()
    {
        return speed;
    }

private:
    float speed;
};

class Hikers
{
public:
    Hikers(float *_hikersSpeeds, int count);

    float CrossBridgeTime(float _bridgeLength);

    float CrossBridgeWithFriendsTime(float _bridgeLength, float *_additionalHikers, int count);

private:
    vector<Hiker> hikersSpeeds;

    float maxSpeed;
    int fastestHikerIndex;
};