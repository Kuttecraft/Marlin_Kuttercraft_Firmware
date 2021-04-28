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
#include "../../module/temperature.h"
#include "../../MarlinCore.h"

#include "menu.h"
#include "../dogm/ultralcd_DOGM.h"
#include "../mapa_bit/bitmap_kuttercraft.h"
#include "../../module/settings.h"

//constructores de menu
void init_boto(int medida_boton_, int espaciado_, int cantidad_, int altura_, int columna_bit_ = 3);
void crear_boton(const u8g_pgm_uint8_t* img_mapa_bit, const u8g_pgm_uint8_t* img_mapa_bit_2, PGM_P utf8_str_P, screenFunc_t screen, const uint16_t encoder = 0);
void crear_marco_superior(PGM_P utf8_str_P, int altura = 0, int largo = 9);
void crear_espera();

int centrar_texto(int numero);
int cantidad_de_digitos(int numero);
int rango_encoder(uint32_t valor_maximo, uint32_t valor_minimo = 0);

//salidas de menus
void menu_main();
void ajuste_de_filamento();
void cargar_y_retirar_filamento();

int contador_repeticiones = 0;


//funciones
////////////////////////////////////////
float obtener_valor_actual_e(){
    //encargado de mostrar la posicion actual real del eje z
    get_cartesian_from_steppers();
    xyze_pos_t npos = cartes;
    const xyze_pos_t lpos = npos.asLogical();

    return lpos.e;
}

void cargar_filamento_visual(){
    //NO se vuelve al status y se sigue actualizando
    MarlinUI::defer_return_to_status = true;
    MarlinUI::lcdDrawUpdate = LCDVIEW_CALL_REDRAW_NEXT;

    contador_repeticiones++;

    //crea la barra de espera
    crear_espera();

    crear_marco_superior(Language_es::MSG_CARGANDO_FILAMENTO,0,11);
    crear_marco_superior(Language_es::MSG_POR_FAVOR_ESPERE, 54, 11);
    
    //Obtiene el valor actual del e
    xyze_pos_t npos = cartes;
    npos.e = planner.get_axis_position_mm(E_AXIS);

    if(npos.e >= 100){
        MarlinUI::goto_screen(cargar_y_retirar_filamento, 1);
    }
}

void cargar_filamento(){
    queue.inject_P(PSTR("G1 F200\nG92 E0\nG1 E100 F200"));

    MarlinUI::goto_screen(cargar_filamento_visual);
}

void retirar_filamento_visual(){
    //NO se vuelve al status y se sigue actualizando
    MarlinUI::defer_return_to_status = true;
    MarlinUI::lcdDrawUpdate = LCDVIEW_CALL_REDRAW_NEXT;

    contador_repeticiones++;

    //crea la barra de espera
    crear_espera();
    crear_marco_superior(Language_es::MSG_POR_FAVOR_ESPERE, 54, 11);

    //Obtiene el valor actual del e
    xyze_pos_t npos = cartes;
    npos.e = planner.get_axis_position_mm(E_AXIS);

    if(npos.e >= 1){
        crear_marco_superior(Language_es::MSG_CARGANDO_FILAMENTO,0,11);
    }else{
        crear_marco_superior(Language_es::MSG_RETIRANDO_FILAMENTO,0,11);
    }

    if(npos.e <= -100){
        MarlinUI::goto_screen(cargar_y_retirar_filamento, 2);
    }
}

void retirar_filamento(){
    queue.inject_P(PSTR("G1 F200\nG92 E0 Z0\nG1 Z0 E30 F200\nG92 Z0 E0\nG1 E-100 F200"));
    MarlinUI::goto_screen(retirar_filamento_visual);
}

void cargar_y_retirar_filamento(){
    contador_repeticiones = 0; //reset
    crear_marco_superior(Language_es::MSG_PREDETERMINADO);

    START_MENU();
    NEXT_ITEM_(3);
    END_MENU();

    init_boto(30, 5, 3, 17, 4);

    crear_boton(volver_boton_a,  volver_boton_b,    Language_es::MSG_VOLVER,           menu_main,2);
    crear_boton(cargar_boton_a,  cargar_boton_b,    Language_es::MSG_FILAMENTLOAD,     cargar_filamento);
    crear_boton(retirar_boton_a, retirar_boton_b,   Language_es::MSG_FILAMENTUNLOAD,   retirar_filamento);
}

void ajuste_de_filamento_espera(){
    //NO se vuelve al status y se sigue actualizando
    MarlinUI::defer_return_to_status = true;
    MarlinUI::lcdDrawUpdate = LCDVIEW_CALL_REDRAW_NEXT;
    //crea la barra de espera
    crear_espera();

    crear_marco_superior(Language_es::MSG_POR_FAVOR_ESPERE,0,11);
    crear_marco_superior(Language_es::MSG_HEATING,55);

    //informacion de temperatura
    lcd_moveto(89, 29);
    lcd_put_u8str(i16tostr4signrj( int(thermalManager.degTargetHotend(0)) )); //temp objectivo
    lcd_moveto(89, 29);
    lcd_put_u8str_P(PSTR("/"));//separador
    lcd_moveto(64, 29);
    lcd_put_u8str(i16tostr4signrj(thermalManager.degHotend(0)));// temp actual

    if(int(thermalManager.degHotend(0)) >= int(thermalManager.degTargetHotend(0)) - 5 ){
        MarlinUI::goto_screen(cargar_y_retirar_filamento, 0);
    }
}

void preset_pla(){
    thermalManager.setTargetHotend(190, 0);
    MarlinUI::goto_screen(ajuste_de_filamento_espera);
}
void preset_abs(){
    thermalManager.setTargetHotend(230, 0);
    MarlinUI::goto_screen(ajuste_de_filamento_espera);
}
void preset_flex(){
    thermalManager.setTargetHotend(225, 0);
    MarlinUI::goto_screen(ajuste_de_filamento_espera);
}
void preset_nylon(){
    thermalManager.setTargetHotend(240, 0);
    MarlinUI::goto_screen(ajuste_de_filamento_espera);
}

void preset_temperaturas(){
    crear_marco_superior(Language_es::MSG_PREDETERMINADO);

    START_MENU();
    NEXT_ITEM_(5);
    END_MENU();

    init_boto(23, 2, 5, 21);

    crear_boton(boton_volver_a,  boton_volver_b, Language_es::MSG_VOLVER,           ajuste_de_filamento,149);
    crear_boton(boton_pla_a,     boton_pla_b,    Language_es::MSG_PRESET_PLA,       preset_pla);
    crear_boton(boton_abs_a,     boton_abs_b,    Language_es::MSG_PRESET_ABS,       preset_abs);
    crear_boton(boton_flex_a,    boton_flex_b,   Language_es::MSG_PRESET_FLEX,      preset_flex);
    crear_boton(boton_nylon_a,   boton_nylon_b,  Language_es::MSG_PRESET_NYLON,     preset_nylon);

}



//seleccione temperatura
void ajuste_de_filamento(){    
    //establece un rango de movimiento para el encoder
    int valor_mintero = rango_encoder(280, 148);

    crear_marco_superior(Language_es::MSG_SELECT);
    crear_marco_superior(Language_es::MSG_LA_TEMPERATURE, 8, 11);

    //texto temperatura:
    lcd_moveto(16, 45);
    lcd_put_u8str_P(PSTR(Language_es::MSG_TEMPERATURE));
    lcd_moveto(82, 45);
    lcd_put_u8str_P(PSTR(":"));

    //SALIDA
    if(valor_mintero == 148){
        lcd_moveto(88, 45);
        lcd_put_u8str_P(PSTR(Language_es::MSG_SALIR));

        if(ui.use_click()){
            MarlinUI::goto_screen(menu_main, 2);
        }
    //PRESET
    }else if (valor_mintero == 149){
        lcd_moveto(88, 45);
        lcd_put_u8str_P(PSTR(Language_es::MSG_PRESET));

        if(ui.use_click()){
            MarlinUI::goto_screen(preset_temperaturas);
        }
    //SELECCIONAR TEMPERATURA
    }else{
        lcd_moveto(64 + (cantidad_de_digitos(valor_mintero) * 6), 45);
        lcd_put_u8str(i16tostr4signrj(valor_mintero));

        if(ui.use_click()){
            thermalManager.setTargetHotend(valor_mintero, 0);
            MarlinUI::goto_screen(ajuste_de_filamento_espera);
        }
    }
    
}




#endif // MENU_KUTTERCRAFT
#endif // HAS_LCD_MENU