#include "ui_rasp_tools.h"
#include "ui_state.h"
#include <stdio.h>

void ui_rasp_tools_draw(SystemContext* ctx)
{
    printf("=== RASPBERRY TOOLS (Selected: RPi %d) ===\n", ctx->selected_raspberry);
    printf("1. I2C Tools\n");
    printf("2. SPI Tools\n");
    printf("3. UART Tools\n");
    printf("b. Back\n");
    printf("> ");
}

void ui_rasp_tools_handle(SystemContext* ctx, char key)
{
    if (key == '1') ctx->ui_state = UI_STATE_I2C;
    if (key == '2') ctx->ui_state = UI_STATE_SPI;
    if (key == '3') ctx->ui_state = UI_STATE_UART;
    if (key == 'b') ctx->ui_state = UI_STATE_SELECT_RASP;
}
