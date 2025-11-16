#include "queue.h"
#include <string.h>

void queue_init(CommandQueue* q)
{
    q->head = 0;
    q->tail = 0;

    pthread_mutex_init(&q->lock, NULL);
    pthread_cond_init(&q->cond, NULL);
}

void queue_push(CommandQueue* q, TxCommand* cmd)
{
    pthread_mutex_lock(&q->lock);

    q->buffer[q->tail] = *cmd;
    q->tail = (q->tail + 1) % 32;

    pthread_cond_signal(&q->cond);
    pthread_mutex_unlock(&q->lock);
}

TxCommand queue_pop(CommandQueue* q)
{
    pthread_mutex_lock(&q->lock);

    while (q->head == q->tail)
        pthread_cond_wait(&q->cond, &q->lock);

    TxCommand out = q->buffer[q->head];
    q->head = (q->head + 1) % 32;

    pthread_mutex_unlock(&q->lock);

    return out;
}
