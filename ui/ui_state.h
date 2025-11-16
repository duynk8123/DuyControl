#ifndef UI_STATE_H
#define UI_STATE_H
#include "../core/system.h"
typedef enum {
    UI_STATE_MAIN_MENU,
    UI_STATE_SELECT_RASP,
    UI_STATE_RASP_TOOLS,
    UI_STATE_I2C,
    UI_STATE_SPI,
    UI_STATE_UART
} UIState;

void ui_i2c_menu_draw();
void ui_i2c_menu_handle(SystemContext* ctx, char key);

#endif
