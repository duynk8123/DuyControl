#include "ui_state.h"
#include <stdio.h>

void ui_i2c_menu_draw()
{
    printf("======= I2C TOOLS =======\n");
    printf("1. Scan Bus\n");
    printf("2. Read Register\n");
    printf("3. Write Register\n");
    printf("b. Back\n");
    printf("> ");
}

void ui_i2c_menu_handle(SystemContext* ctx, char key)
{
    if (key == '1')
        {
            printf("I2CService_Scan is called\n");
            //I2CService_Scan();
        }
    if (key == '2')
        {
            printf("I2CService_ReadInteractive is called\n");
            //I2CService_ReadInteractive();
        }

    if (key == '3')
        {
            printf("I2CService_WriteInteractive is called\n");
            //I2CService_WriteInteractive();
        }
    if (key == 'b')
        ctx->ui_state = UI_STATE_RASP_TOOLS;
}