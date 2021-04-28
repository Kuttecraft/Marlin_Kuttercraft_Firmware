/**************************************************/
/*╔╗╔═╦╗ ╔╦════╦════╦═══╦═══╦═══╦═══╦═══╦═══╦════╗*/
/*║║║╔╣║ ║║╔╗╔╗║╔╗╔╗║╔══╣╔═╗║╔═╗║╔═╗║╔═╗║╔══╣╔╗╔╗║*/
/*║╚╝╝║║ ║╠╝║║╚╩╝║║╚╣╚══╣╚═╝║║ ╚╣╚═╝║║ ║║╚══╬╝║║╚╝*/
/*║╔╗║║║ ║║ ║║   ║║ ║╔══╣╔╗╔╣║ ╔╣╔╗╔╣╚═╝║╔══╝ ║║  */
/*║║║╚╣╚═╝║ ║║   ║║ ║╚══╣║║╚╣╚═╝║║║╚╣╔═╗║║    ║║  */
/*╚╝╚═╩═══╝ ╚╝   ╚╝ ╚═══╩╝╚═╩═══╩╝╚═╩╝ ╚╩╝    ╚╝  */
/*             ╔═╗                                */
/*             ║╔╝                                */
/*            ╔╝╚╦╦═╦╗╔╦╗╔╗╔╦══╦═╦══╗             */
/*            ╚╗╔╬╣╔╣╚╝║╚╝╚╝║╔╗║╔╣║═╣             */
/*             ║║║║║║║║╠╗╔╗╔╣╔╗║║║║═╣             */
/*             ╚╝╚╩╝╚╩╩╝╚╝╚╝╚╝╚╩╝╚══╝             */
/**************************************************/

#include "../../inc/MarlinConfigPre.h"

#if HAS_LCD_MENU
#if ENABLED(MENU_KUTTERCRAFT)

#include "menu_item.h"
void menu_main();

bool estado_del_led = false;

bool estado_actual_led(){
    return estado_del_led;
}

void prender_apagar_led(){
    const bool esta_imprimiendo = printingIsActive();

    if(estado_del_led){
        estado_del_led = false;
        WRITE(P2_04, LOW);
    }else{
        WRITE(P2_04, HIGH);
        estado_del_led = true;
    }
    if(!esta_imprimiendo){
        MarlinUI::goto_screen(menu_main, 5);
    }else{
        MarlinUI::goto_screen(menu_main, 8);
    }
}

#endif // MENU_KUTTERCRAFT
#endif // HAS_LCD_MENU