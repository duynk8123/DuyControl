#include "system.h"
#include "ui.h"
#include "ui_state.h"   

#include <pthread.h>

SystemContext g_ctx;

int main()
{
    /*init system*/
    system_init(&g_ctx);

    g_ctx.ui_state = UI_STATE_MAIN_MENU;   

    system_start(&g_ctx);
    
    pthread_join(g_ctx.ui_thread, NULL);

    return 0;
}
