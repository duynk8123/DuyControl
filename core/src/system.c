#include "system.h"
#include "ui.h"
#include <string.h>

void system_init(SystemContext* ctx)
{
    memset(ctx, 0, sizeof(SystemContext));

    /*enable function : "ui_thread_func" run */
    ctx->running = 1;

    ctx->selected_raspberry = -1;

    state_init(&ctx->state);
    queue_init(&ctx->tx_queue);

    // UART not be able - set = -1
    ctx->uart_fd = -1;
}

void system_start(SystemContext* ctx)
{
    // just one thread for UI
    pthread_create(&ctx->ui_thread, NULL, ui_thread_func, ctx);
}

void system_stop(SystemContext* ctx)
{
    ctx->running = 0;
}
