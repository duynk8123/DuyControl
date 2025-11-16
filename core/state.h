#ifndef STATE_H
#define STATE_H

#include <pthread.h>
#include <stdint.h>

typedef struct {
    float temperature;
    float humidity;

    float ax, ay, az;

    pthread_mutex_t lock;
} DControlState;

void state_init(DControlState* s);
void state_update_sensor(DControlState* s, float t, float h);
void state_update_motion(DControlState* s, float ax, float ay, float az);

#endif
