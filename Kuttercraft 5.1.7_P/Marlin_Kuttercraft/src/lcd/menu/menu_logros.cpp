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
#include "../../module/motion.h"
#include "../../module/planner.h"
#include "../../MarlinCore.h"

#include "menu.h"
#include "../dogm/ultralcd_DOGM.h"
#include "../mapa_bit/bitmap_kuttercraft.h"
#include "../../module/settings.h"


//constructores de menu
void init_boto(int medida_boton_, int espaciado_, int cantidad_, int altura_, int columna_bit_ = 3);
void crear_marco_superior(PGM_P utf8_str_P, int altura = 0, int largo = 9);
void crear_logro(PGM_P utf8_str_P_1, PGM_P utf8_str_P_2, PGM_P utf8_str_P_3);
void crear_descuento(PGM_P utf8_str_P_1, PGM_P utf8_str_P_2, PGM_P utf8_str_P_3);
void set_numero_de_descuento(int numero_de_descuento);
int valor_total_id();

//SALIDA
void menu_ajustes();
void menu_logros();

void no_hay_logros(){
    crear_marco_superior(Language_es::MSG_NO_LOGROS, 43, 11);
    crear_marco_superior(Language_es::MSG_TU_PUEDES, 53, 11);
    u8g.drawBitmapP(58, 14, 2, 15, no_logros_ico);

    if(ui.use_click()){
      MarlinUI::goto_screen(menu_ajustes, 3);
    }
}



void menu_logros(){

    START_MENU();
    BACK_ITEM(MSG_VOLVER);
    SUBMENU(MSG_LOGRO_KM, no_hay_logros);
    SUBMENU(MSG_LOGRO_PZ, no_hay_logros);
    END_MENU();
}

#endif
#endif
