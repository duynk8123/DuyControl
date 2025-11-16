#include "ui.h"
#include "ui_state.h"
#include "ui_main_menu.h"
#include "ui_rasp_select.h"
#include "ui_rasp_tools.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void* ui_thread_func(void* arg)
{
    SystemContext* ctx = arg;
    /*ctx->running = 1*/
    while(ctx->running)
    {
        system("clear");

        switch(ctx->ui_state)
        {
            case UI_STATE_MAIN_MENU:
                ui_main_menu_draw();
                break;

            case UI_STATE_SELECT_RASP:
                ui_rasp_select_draw();
                break;

            case UI_STATE_RASP_TOOLS:
                ui_rasp_tools_draw(ctx);
                break;

            case UI_STATE_I2C:
                ui_i2c_menu_draw();
                break;

            case UI_STATE_SPI:
                printf("=== SPI MENU ===\nAdd your code\nPress b to back.\n");
                break;

            case UI_STATE_UART:
                printf("=== UART MENU ===\nAdd your code\nPress b to back.\n");
                break;
        }

        char c = getchar();

        switch(ctx->ui_state)
        {
            case UI_STATE_MAIN_MENU:
                ui_main_menu_handle(ctx, c);
                break;

            case UI_STATE_SELECT_RASP:
                ui_rasp_select_handle(ctx, c);
                break;

            case UI_STATE_RASP_TOOLS:
                ui_rasp_tools_handle(ctx, c);
                break;

            case UI_STATE_I2C:
                ui_i2c_menu_handle(ctx, c);
                break;

            case UI_STATE_SPI:
                if (c == 'b') ctx->ui_state = UI_STATE_RASP_TOOLS;
                break;

            case UI_STATE_UART:
                if (c == 'b') ctx->ui_state = UI_STATE_RASP_TOOLS;
                break;
        }

        usleep(150000);
    }

    return NULL;
}
