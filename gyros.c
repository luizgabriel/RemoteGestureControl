#include "gyros.h"

void Gyros_Init()
{
    Gyros_LastAccel.x = 0;
    Gyros_LastAccel.y = 0;
    Gyros_LastAccel.z = 0;
    
    Gyros_Vel.x = 0;
    Gyros_Vel.y = 0;
    Gyros_Vel.z = 0;
    
    Gyros_Angle.phi = 0;
    Gyros_Angle.theta = 0;
}

void Gyros_Update(float dt)
{
    vec3f a;
    Accel_Get(&a);
    
    a.x *= G_CONV; //Converts to m/s^2
    a.y *= G_CONV; //Converts to m/s^2
    a.z *= G_CONV; //Converts to m/s^2
    
    Gyros_Angle.theta = atan(a.x / a.y);
    Gyros_Angle.phi = acos(a.z / (sqrt(pow(a.x, 2.0) + pow(a.y, 2.0) + pow(a.z, 2.0))));
    
    Gyros_Vel.x += (a.x + Gyros_LastAccel.x) * dt / 2.0;
    Gyros_Vel.y += (a.y + Gyros_LastAccel.y) * dt / 2.0;
    Gyros_Vel.z += (a.z + Gyros_LastAccel.z) * dt / 2.0;
            
    Gyros_LastAccel.x = a.x;
    Gyros_LastAccel.y = a.y;
    Gyros_LastAccel.z = a.z;
}
