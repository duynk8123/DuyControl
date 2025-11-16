#ifndef SYSTEM_H
#define SYSTEM_H

#include <pthread.h>
#include <stdint.h>
#include "state.h"
#include "queue.h"

typedef struct {
    pthread_t ui_thread;
    pthread_t rx_thread;
    pthread_t tx_thread;
    pthread_t logic_thread;

    int uart_fd;                // Chưa dùng, để sau tích hợp
    uint8_t running;

    // UI state
    int selected_raspberry;     

    // Shared state
    DControlState state;

    // TX queue
    CommandQueue tx_queue;

    // UI state machine
    int ui_state;

}SystemContext;

void system_init(SystemContext* ctx);
void system_start(SystemContext* ctx);
void system_stop(SystemContext* ctx);

#endif
