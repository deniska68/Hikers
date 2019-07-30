//#define METHOD1
#define METHOD2

#include <iostream>

#ifdef METHOD1
#include "objects.h"
#endif

#ifdef METHOD2
#include "objects_2.h"
#endif

int main()
{
    float bridges[] = { 100, 250, 150};

    float hikerSpeedsABCD[] = { 100, 50, 20, 10 }; // A, B, C ,D
    float friendsSpeedsE[] = { 2.5 }; // E
    float friendsSpeedsFG[] = { 25, 15 }; // F, G
    
#ifdef METHOD1

    Hikers hikers(hikerSpeedsABCD, 4);

    float totalTime(0.0);

    float t0 = hikers.CrossBridgeTime(bridges[0]);
    float t1 = hikers.CrossBridgeWithFriendsTime(bridges[1], friendsSpeedsE, 1);
    float t2 = hikers.CrossBridgeWithFriendsTime(bridges[2], friendsSpeedsFG, 2);

    totalTime = t0 + t1 + t2;
    cout << "Total time for all bridges " << totalTime << endl;
#endif

#ifdef METHOD2
    HikersBase **hikers = (HikersBase**) new HikersBase*[3];

    hikers[0] = new HikersBase(hikerSpeedsABCD, 4);
    hikers[1] = new HikersWithFriends(hikerSpeedsABCD, 4, friendsSpeedsE, 1);
    hikers[2] = new HikersWithFriends(hikerSpeedsABCD, 4, friendsSpeedsFG, 2);

    float totalTime(0.0);
    for (int i = 0; i < 3; i++)
    {
        float t = hikers[i]->CrossBridgeTime(bridges[i]);
        cout << "Bridge number " << i << " time = " << t << endl;
        totalTime += t;
        delete hikers[i];
    }

    delete hikers;

    cout << "Total time for all bridges " << totalTime << endl;
#endif

    return 0;
}