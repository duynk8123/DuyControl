#include "ui_rasp_select.h"
#include "ui_state.h"
#include <stdio.h>

void ui_rasp_select_draw()
{
    printf("====== SELECT RASPBERRY PI ======\n");
    printf("1. Raspberry Pi 1\n");
    printf("2. Raspberry Pi 2\n");
    printf("3. Raspberry Pi 3\n");
    printf("b. Back\n");
    printf("> ");
}

void ui_rasp_select_handle(SystemContext* ctx, char key)
{
    if (key == '1') 
        { 
            ctx->selected_raspberry = 1; 
            ctx->ui_state = UI_STATE_RASP_TOOLS; 
        }
    if (key == '2') 
        { 
            ctx->selected_raspberry = 2; 
            ctx->ui_state = UI_STATE_RASP_TOOLS; 
        }
    if (key == '3') 
        { 
            ctx->selected_raspberry = 3; 
            ctx->ui_state = UI_STATE_RASP_TOOLS; 
        }
    if (key == 'b') 
        { 
            ctx->ui_state = UI_STATE_MAIN_MENU; 
        }
}
