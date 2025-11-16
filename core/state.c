#include "state.h"
#include <string.h>

void state_init(DControlState* s)
{
    memset(s, 0, sizeof(DControlState));
    pthread_mutex_init(&s->lock, NULL);
}

void state_update_sensor(DControlState* s, float t, float h)
{
    pthread_mutex_lock(&s->lock);
    s->temperature = t;
    s->humidity = h;
    pthread_mutex_unlock(&s->lock);
}

void state_update_motion(DControlState* s, float ax, float ay, float az)
{
    pthread_mutex_lock(&s->lock);
    s->ax = ax;
    s->ay = ay;
    s->az = az;
    pthread_mutex_unlock(&s->lock);
}
