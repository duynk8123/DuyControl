#ifndef QUEUE_H
#define QUEUE_H

#include <pthread.h>
#include <stdint.h>

typedef struct {
    uint8_t cmd;
    uint8_t id;
    uint8_t data[4];
    uint8_t len;
} TxCommand;

typedef struct {
    TxCommand buffer[32];
    int head, tail;

    pthread_mutex_t lock;
    pthread_cond_t cond;
} CommandQueue;

void queue_init(CommandQueue* q);
void queue_push(CommandQueue* q, TxCommand* cmd);
TxCommand queue_pop(CommandQueue* q);

#endif
