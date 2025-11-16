#include "ui_main_menu.h"
#include "ui_state.h"
#include <stdio.h>

void ui_main_menu_draw()
{
    printf("====== DCONTROL MAIN MENU ======\n");
    printf("1. Raspberry Pi Options\n");
    printf("2. Exit\n");
    printf("> ");
}

void ui_main_menu_handle(SystemContext* ctx, char key)
{
    if (key == '1')
        ctx->ui_state = UI_STATE_SELECT_RASP;

    if (key == '2')
        ctx->running = 0;
}
