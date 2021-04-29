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
#include "../../module/stepper.h"
#include "../../module/probe.h"
#include "../../feature/bedlevel/bedlevel.h"
#include "../../feature/powerloss.h"

#include "../../module/printcounter.h"

#include "../../feature/bedlevel/ubl/ubl.h"



////

////
//constructores de menu
void crear_marco_superior(PGM_P utf8_str_P, int altura = 0, int largo = 9);
void menu_main();
void menu_ajustes();
void removeSpacesInPlace(char* str);
void menu_logros();
void crear_cartel_si_no();
void init_boto(int medida_boton_, int espaciado_, int cantidad_, int altura_, int columna_bit_ = 3);
void crear_boton(const u8g_pgm_uint8_t* img_mapa_bit, const u8g_pgm_uint8_t* img_mapa_bit_2, PGM_P utf8_str_P, screenFunc_t screen, const uint16_t encoder = 0);
void opciones_no_disponible(screenFunc_t screen, const uint16_t encoder = 0);
int centrar_texto(int numero, int grande_de_letra = 6);
void crear_texto_centrado(PGM_P utf8_str_P, int altura = 0);
void menu_tmc();

//SALIDA
void calcular_pid();

//cartel de vercion
///////////////////

void menu_vercion(){
    u8g.drawBitmapP(23, 0, 10, 12, logo_kuttercraft);

    crear_marco_superior(Language_es::MSG_SERIE, 35);
    crear_texto_centrado(MarlinUI::numero_de_serie, 45);
    crear_marco_superior(Language_es::MSG_INDUSTRIA, 55);

    lcd_moveto(12, 22);   // posicion del texto
    lcd_put_u8str_P(PSTR(Language_es::MSG_VER_VERSION)); // el texto

    lcd_moveto(18, 32);   // posicion del texto
    lcd_put_u8str_P(PSTR(Language_es::MSG_VER_MODELO)); // el texto

    lcd_moveto(66, 22);   // posicion del texto
    lcd_put_u8str_P(PSTR(SHORT_BUILD_VERSION));

    lcd_moveto(66, 32);   // posicion del texto
    lcd_put_u8str_P(PSTR(MODELO_DE_MAQUINA));

    if(ui.use_click()){
      MarlinUI::goto_screen(menu_ajustes, MarlinUI::endcoder_ulti_aux);
    }
}


////////////////////////
//menu de estadisticas//
////////////////////////
void estadisticas_impreciones(){
    printStatistics stats = print_job_timer.getStats();
    MarlinUI::contenedor_str[0] = '\0';

    crear_marco_superior(Language_es::MSG_INFO_STATS_MENU);
    crear_marco_superior(Language_es::MSG_IMPRESIONES,55);

    //textos
    lcd_moveto(40, 22);   // posicion del texto
    lcd_put_u8str_P(PSTR(Language_es::MSG_TOTAL));

    lcd_moveto(10, 35);   // posicion del texto
    lcd_put_u8str_P(PSTR(Language_es::MSG_TERMINADAS));

    lcd_moveto(4, 48);   // posicion del texto
    lcd_put_u8str_P(PSTR(Language_es::MSG_INCOMPLETAS));

    //kilometros
    ////////////
    strcpy(MarlinUI::contenedor_str, i16tostr3left(stats.totalPrints) ); //guarda el valor en el contenedor
    removeSpacesInPlace(MarlinUI::contenedor_str); //elimina los espacios en blanco generado por la tranformacion
    lcd_moveto(76, 22);
    lcd_put_u8str(MarlinUI::contenedor_str);

    //metro
    ///////
    strcpy(MarlinUI::contenedor_str, i16tostr3left(stats.finishedPrints) ); //guarda el valor en el contenedor
    removeSpacesInPlace(MarlinUI::contenedor_str); //elimina los espacios en blanco generado por la tranformacion
    lcd_moveto(76, 35);
    lcd_put_u8str(MarlinUI::contenedor_str);

    //centimetro
    ////////////
    strcpy(MarlinUI::contenedor_str, i16tostr3left(stats.totalPrints - stats.finishedPrints) ); //guarda el valor en el contenedor
    removeSpacesInPlace(MarlinUI::contenedor_str); //elimina los espacios en blanco generado por la tranformacion
    lcd_moveto(76, 48);
    lcd_put_u8str(MarlinUI::contenedor_str);

    if(ui.use_click()){
      MarlinUI::goto_screen(menu_ajustes, MarlinUI::endcoder_ulti_aux);
    }

}

void estadisticas_horas(){
    printStatistics stats = print_job_timer.getStats();
    MarlinUI::contenedor_str[0] = '\0';

    crear_marco_superior(Language_es::MSG_INFO_STATS_MENU);
    crear_marco_superior(Language_es::MSG_TIEMPO_DE_IMPRESION,55);

    //textos
    lcd_moveto(46, 22);   // posicion del texto
    lcd_put_u8str_P(PSTR(Language_es::MSG_TIEMPO_DIAS));

    lcd_moveto(40, 35);   // posicion del texto
    lcd_put_u8str_P(PSTR(Language_es::MSG_TIEMPO_HORAS));

    lcd_moveto(28, 48);   // posicion del texto
    lcd_put_u8str_P(PSTR(Language_es::MSG_TIEMPO_MINUTOS));

    //Años
    //////
    strcpy(MarlinUI::contenedor_str, i16tostr3left(duration_t(stats.printTime).day()% 24) ); //guarda el valor en el contenedor
    removeSpacesInPlace(MarlinUI::contenedor_str); //elimina los espacios en blanco generado por la tranformacion
    lcd_moveto(76, 22);
    lcd_put_u8str(MarlinUI::contenedor_str);

    //dias
    //////
    strcpy(MarlinUI::contenedor_str, i16tostr3left(duration_t(stats.printTime).hour() % 60) ); //guarda el valor en el contenedor
    removeSpacesInPlace(MarlinUI::contenedor_str); //elimina los espacios en blanco generado por la tranformacion
    lcd_moveto(76, 35);
    lcd_put_u8str(MarlinUI::contenedor_str);

    //horas
    ///////
    strcpy(MarlinUI::contenedor_str, i16tostr3left(duration_t(stats.printTime).minute() % 60) ); //guarda el valor en el contenedor
    removeSpacesInPlace(MarlinUI::contenedor_str); //elimina los espacios en blanco generado por la tranformacion
    lcd_moveto(76, 48);
    lcd_put_u8str(MarlinUI::contenedor_str);

    if(ui.use_click()){
      MarlinUI::goto_screen(estadisticas_impreciones);
    }

}
void estadisticas(){
    printStatistics stats = print_job_timer.getStats(); //obtiene las estadisticas
    MarlinUI::contenedor_str[0] = '\0';                 //variable para guardar texto temporal mente

    crear_marco_superior(Language_es::MSG_INFO_STATS_MENU);
    crear_marco_superior(Language_es::MSG_FILAMENTO_USADO,55);

    //Texto centrales
    lcd_moveto(10, 22);   // posicion del texto
    lcd_put_u8str_P(PSTR(Language_es::MSG_KILOMETRO));

    lcd_moveto(34, 35);   // posicion del texto
    lcd_put_u8str_P(PSTR(Language_es::MSG_METRO));

    lcd_moveto(4, 48);   // posicion del texto
    lcd_put_u8str_P(PSTR(Language_es::MSG_CENTIMETRO));


    //kilometros
    ////////////
    strcpy(MarlinUI::contenedor_str,ltostr7(long(stats.filamentUsed / 1000 / 1000))); //guarda el valor en el contenedor
    removeSpacesInPlace(MarlinUI::contenedor_str); //elimina los espacios en blanco generado por la tranformacion
    lcd_moveto(76, 22);
    lcd_put_u8str(MarlinUI::contenedor_str);

    //metro
    ///////
    strcpy(MarlinUI::contenedor_str,ltostr7(long(stats.filamentUsed / 1000))); //guarda el valor en el contenedor
    removeSpacesInPlace(MarlinUI::contenedor_str); //elimina los espacios en blanco generado por la tranformacion
    lcd_moveto(76, 35);
    lcd_put_u8str(MarlinUI::contenedor_str);

    //centimetro
    ////////////
    strcpy(MarlinUI::contenedor_str,ltostr7(long(stats.filamentUsed / 10) % 100)); //guarda el valor en el contenedor
    removeSpacesInPlace(MarlinUI::contenedor_str); //elimina los espacios en blanco generado por la tranformacion
    lcd_moveto(76, 48);
    lcd_put_u8str(MarlinUI::contenedor_str);

    if(ui.use_click()){
      MarlinUI::goto_screen(estadisticas_horas);
    }

}
//carteles de si o no
//////////////////////
void error_no_hay_mapa(){
  crear_marco_superior("Error No hay Mapa",0,11);

  u8g.drawBitmapP(58, 14, 2, 15, no_logros_ico);

  crear_texto_centrado("Es Necesario Hacer",32);
  crear_texto_centrado("Un Mapa De Cama Para",42);
  crear_texto_centrado("Activar Autolevel",52);

  if(ui.use_click()){
    MarlinUI::goto_screen(menu_ajustes, MarlinUI::endcoder_ulti_aux);
  }
}
void cambiar_estado_autolevel(){
    //guarda el mapa en el primer lugar
    settings.store_mesh(0);
    ubl.storage_slot = 0;

    bool aux_bool = planner.leveling_active;

    if(planner.leveling_active){
      set_bed_leveling_enabled(false);
    }else{
      set_bed_leveling_enabled(true);
    }

    (void)settings.save();
    (void)settings.load();

    if(aux_bool == planner.leveling_active){
      unified_bed_leveling::z_values[0][0] = 0.025;
      set_bed_leveling_enabled(true);
      MarlinUI::goto_screen(menu_ajustes, MarlinUI::endcoder_ulti_aux);
    }else{
      MarlinUI::goto_screen(menu_ajustes, MarlinUI::endcoder_ulti_aux);
    }
}

void cambiar_estado_sensor(){MarlinUI::sensor_on_off = !MarlinUI::sensor_on_off; MarlinUI::goto_screen(menu_ajustes, MarlinUI::endcoder_ulti_aux);}
void cambiar_estado_eprom(){queue.inject_P(PSTR("M502\nM500")); MarlinUI::goto_screen(menu_ajustes, MarlinUI::endcoder_ulti_aux);}

void cartel_auto_calibracion(){
  START_MENU();
  NEXT_ITEM_(2);
  END_MENU();

  crear_marco_superior(Language_es::MSG_BUTTON_ADVERTENCIA);
  init_boto(23, 5, 2, 29);

  crear_boton(boton_detener_a,     boton_detener_b,     Language_es::MSG_BUTTON_CANCEL,   menu_ajustes, MarlinUI::endcoder_ulti_aux);
  crear_boton(boton_reanudar_a,    boton_reanudar_b,    Language_es::MSG_BUTTON_ACEPTAR,  cambiar_estado_autolevel);
  
  if(!planner.leveling_active){
    lcd_moveto(centrar_texto(strlen(Language_es::MSG_CARTEL_AUTOLEVEL_03)), 18);
    lcd_put_u8str_P(Language_es::MSG_CARTEL_AUTOLEVEL_03);
    lcd_moveto(centrar_texto(strlen(Language_es::MSG_CARTEL_AUTOLEVEL_04)), 27);
    lcd_put_u8str_P(Language_es::MSG_CARTEL_AUTOLEVEL_04);
  }else{
    lcd_moveto(centrar_texto(strlen(Language_es::MSG_CARTEL_AUTOLEVEL_01)), 18);
    lcd_put_u8str_P(Language_es::MSG_CARTEL_AUTOLEVEL_01);
    lcd_moveto(centrar_texto(strlen(Language_es::MSG_CARTEL_AUTOLEVEL_02)), 27);
    lcd_put_u8str_P(Language_es::MSG_CARTEL_AUTOLEVEL_03);
  }

  

}
//Cartel para el sensor de filamento
void cartel_sensor_filamento(){
  START_MENU();
  NEXT_ITEM_(2);
  END_MENU();

  crear_marco_superior(Language_es::MSG_BUTTON_ADVERTENCIA);
  init_boto(23, 5, 2, 29);

  crear_boton(boton_detener_a,     boton_detener_b,     Language_es::MSG_BUTTON_CANCEL,   menu_ajustes, 8);
  crear_boton(boton_reanudar_a,    boton_reanudar_b,    Language_es::MSG_BUTTON_ACEPTAR,  cambiar_estado_sensor);
  
  if(MarlinUI::sensor_on_off){
    lcd_moveto(centrar_texto(strlen(Language_es::MSG_CARTEL_SENSOR_01)), 18);
    lcd_put_u8str_P(Language_es::MSG_CARTEL_SENSOR_01);
    lcd_moveto(centrar_texto(strlen(Language_es::MSG_CARTEL_SENSOR_02)), 27);
    lcd_put_u8str_P(Language_es::MSG_CARTEL_SENSOR_02);
  }else{
    lcd_moveto(centrar_texto(strlen(Language_es::MSG_CARTEL_SENSOR_03)), 18);
    lcd_put_u8str_P(Language_es::MSG_CARTEL_SENSOR_03);
    lcd_moveto(centrar_texto(strlen(Language_es::MSG_CARTEL_SENSOR_04)), 27);
    lcd_put_u8str_P(Language_es::MSG_CARTEL_SENSOR_04);
  }

}

void cartel_eprom(){
  START_MENU();
  NEXT_ITEM_(2);
  END_MENU();

  crear_marco_superior(Language_es::MSG_BUTTON_ADVERTENCIA);
  init_boto(23, 5, 2, 29);

  crear_boton(boton_detener_a,     boton_detener_b,     Language_es::MSG_BUTTON_CANCEL,   menu_ajustes, MarlinUI::endcoder_ulti_aux);
  crear_boton(boton_reanudar_a,    boton_reanudar_b,    Language_es::MSG_CARTEL_EPROM_01,  cambiar_estado_eprom);
  
  lcd_moveto(centrar_texto(strlen(Language_es::MSG_CARTEL_EPROM_02)), 18);
  lcd_put_u8str_P(Language_es::MSG_CARTEL_EPROM_02);
  lcd_moveto(centrar_texto(strlen(Language_es::MSG_CARTEL_EPROM_03)), 27);
  lcd_put_u8str_P(Language_es::MSG_CARTEL_EPROM_03);

}
 
//Redireccion
void auto_calibracion_on_off(){//tiene un cartel de advertencia
  MarlinUI::goto_screen(cartel_auto_calibracion);
}


void _cambiar_modo_tmc(){
  //serialprintPGM(st.get_stealthChop_status() ? PSTR("stealthChop") : PSTR("spreadCycle"));
}

void _informacion_capas_coord(){
  MarlinUI::informacion_capas_coord = !MarlinUI::informacion_capas_coord;

  (void)settings.save();
  (void)settings.load();

  MarlinUI::goto_screen(menu_ajustes, MarlinUI::endcoder_ulti_aux);
}
///////////////
//inicio s
//sensor inductivo o final de carrera
void _inductivo_endstop(){
  MarlinUI::inductivo_final_carrera = !MarlinUI::inductivo_final_carrera;

  (void)settings.save();
  (void)settings.load();

  MarlinUI::goto_screen(menu_ajustes, MarlinUI::endcoder_ulti_aux);
}

void _error_sensor_inductivo(){
  crear_marco_superior(Language_es::MSG_BUTTON_ADVERTENCIA);

  lcd_moveto(centrar_texto(strlen(Language_es::MSG_ERROR_SENSOR_IND_2)), 25);
  lcd_put_u8str_P(Language_es::MSG_ERROR_SENSOR_IND_2);
  lcd_moveto(centrar_texto(strlen(Language_es::MSG_ERROR_SENSOR_IND_0)), 34);
  lcd_put_u8str_P(Language_es::MSG_ERROR_SENSOR_IND_0);
  lcd_moveto(centrar_texto(strlen(Language_es::MSG_ERROR_SENSOR_IND_1)), 43);
  lcd_put_u8str_P(Language_es::MSG_ERROR_SENSOR_IND_1);

  crear_marco_superior(Language_es::MSG_CLICK_PARA_SALIR, 54, 10);

  if(ui.use_click()){
    MarlinUI::goto_screen(menu_ajustes, MarlinUI::endcoder_ulti_aux);
  }
}

void cartel_inductivo_endstop(){
  START_MENU();
  NEXT_ITEM_(2);
  END_MENU();

  crear_marco_superior(Language_es::MSG_BUTTON_ADVERTENCIA);
  init_boto(23, 5, 2, 29);

  crear_boton(boton_detener_a,     boton_detener_b,     Language_es::MSG_BUTTON_CANCEL,   menu_ajustes, MarlinUI::endcoder_ulti_aux);
  crear_boton(boton_reanudar_a,    boton_reanudar_b,    Language_es::MSG_BUTTON_ACEPTAR,  _inductivo_endstop);
  
  if(MarlinUI::inductivo_final_carrera){
    lcd_moveto(centrar_texto(strlen(Language_es::MSG_CARTEL_ENDSTOP_01)), 18);
    lcd_put_u8str_P(Language_es::MSG_CARTEL_ENDSTOP_01);
    lcd_moveto(centrar_texto(strlen(Language_es::MSG_CARTEL_ENDSTOP_02)), 27);
    lcd_put_u8str_P(Language_es::MSG_CARTEL_ENDSTOP_02);

  }else{
    lcd_moveto(centrar_texto(strlen(Language_es::MSG_CARTEL_ENDSTOP_03)), 18);
    lcd_put_u8str_P(Language_es::MSG_CARTEL_ENDSTOP_03);
    lcd_moveto(centrar_texto(strlen(Language_es::MSG_CARTEL_ENDSTOP_04)), 27);
    lcd_put_u8str_P(Language_es::MSG_CARTEL_ENDSTOP_04);
  }

}

void cartel_guardar_tmc(){
  crear_marco_superior(Language_es::MSG_BUTTON_ADVERTENCIA);

  lcd_moveto(centrar_texto(strlen(Language_es::MSG_GUARDAR_CONFI_0)), 27);
  lcd_put_u8str_P(Language_es::MSG_GUARDAR_CONFI_0);
  lcd_moveto(centrar_texto(strlen(Language_es::MSG_GUARDAR_CONFI_1)), 36);
  lcd_put_u8str_P(Language_es::MSG_GUARDAR_CONFI_1);

  crear_marco_superior(Language_es::MSG_CLICK_PARA_SALIR, 54, 10);

  if(ui.use_click()){
    MarlinUI::goto_screen(menu_ajustes, 13);
  }

}
void ir_cartel_error_sensor(){MarlinUI::goto_screen(_error_sensor_inductivo);}
void ir_cartel_inductivo_endstop(){MarlinUI::goto_screen(cartel_inductivo_endstop);}
//final s
/////////////
void _guardado_on_off(){
  MarlinUI::guardado_on_off = !MarlinUI::guardado_on_off;
  MarlinUI::goto_screen(menu_ajustes, MarlinUI::endcoder_ulti_aux);
}

void _sensor_on_off(){//tiene un cartel de advertencia
  MarlinUI::goto_screen(cartel_sensor_filamento);
}

void _cambiar_paso_varilla(){
  if(MarlinUI::paso_de_varrilla){
    planner.settings.axis_steps_per_mm[Z_AXIS] = 800;
    planner.set_max_feedrate(Z_AXIS, 20);
    planner.set_max_acceleration(Z_AXIS, 200);
  }else{
    planner.settings.axis_steps_per_mm[Z_AXIS] = 400;
    planner.set_max_feedrate(Z_AXIS, 10);
    planner.set_max_acceleration(Z_AXIS, 100);
  }

  MarlinUI::paso_de_varrilla =! MarlinUI::paso_de_varrilla;

  (void)settings.save();
  (void)settings.load();

  MarlinUI::goto_screen(menu_ajustes, MarlinUI::endcoder_ulti_aux);
}

void _encode_der_izd(){
  if(MarlinUI::encode_der_izd){
    MarlinUI::encode_der_izd =! MarlinUI::encode_der_izd;
    MarlinUI::encoder_giro = 1;

  }else{
    MarlinUI::encode_der_izd =! MarlinUI::encode_der_izd;
    MarlinUI::encoder_giro = -1;
  }
  (void)settings.save();
  (void)settings.load();
  MarlinUI::goto_screen(menu_ajustes, MarlinUI::endcoder_ulti_aux);
}

void _k_melody_on_off(){
  MarlinUI::k_melody_on_off =! MarlinUI::k_melody_on_off;

  (void)settings.save();
  (void)settings.load();
  
  MarlinUI::sonar_kuttermelody();
  MarlinUI::goto_screen(menu_ajustes, MarlinUI::endcoder_ulti_aux);
}

void _cartel_eprom(){
  MarlinUI::goto_screen(cartel_eprom);
}

void cambiar_tipo_extrusor(){
  if(MarlinUI::tipo_de_extrusor){
    MarlinUI::tipo_de_extrusor = false;
    planner.settings.axis_steps_per_mm[E_AXIS_N(0)] = 95;

    SERIAL_ECHOLN("MK8 Activado");
    SERIAL_ECHOLN(planner.settings.axis_steps_per_mm[E_AXIS_N(0)]);
  }else{
    MarlinUI::tipo_de_extrusor = true;
    planner.settings.axis_steps_per_mm[E_AXIS_N(0)] = 415;

    SERIAL_ECHOLN("BMG Activado");
    SERIAL_ECHOLN(planner.settings.axis_steps_per_mm[E_AXIS_N(0)]);

  }

  (void)settings.save();
  (void)settings.load();

  MarlinUI::goto_screen(menu_ajustes, MarlinUI::endcoder_ulti_aux);
}


//////////////////////////
//funciones sin terminar//

void _cartel_idioma(){
  opciones_no_disponible(menu_ajustes, 4);
}
void _cartel_idioma_redireccion(){
  MarlinUI::goto_screen(_cartel_idioma);
}

void _cartel_capas(){
  opciones_no_disponible(menu_ajustes, 6);
}
void _cartel_capas_redireccion(){
  MarlinUI::goto_screen(_cartel_capas);
}

void _cartel_guardado(){
  if(recovery.enabled){
    recovery.enable(false);
  }else{
    recovery.enable(true);
  }

  (void)settings.save();
  (void)settings.load();

  MarlinUI::goto_screen(menu_ajustes, MarlinUI::endcoder_ulti_aux);
}

void _cartel_guardado_redireccion(){
  MarlinUI::goto_screen(_cartel_guardado);
}

void _cartel_filamento(){
  opciones_no_disponible(menu_ajustes, 9);
}
void _cartel_filamento_redireccion(){
  MarlinUI::goto_screen(_cartel_filamento);
}

void _cartel_encode(){
  opciones_no_disponible(menu_ajustes, 10);
}
void _cartel_encode_redireccion(){
  MarlinUI::goto_screen(_cartel_encode);
}

void _cartel_gcode(){
  opciones_no_disponible(menu_ajustes, 14);
}
void _cartel_gcode_redireccion(){
  MarlinUI::goto_screen(_cartel_gcode);
}

void _cartel_sistema(){
  opciones_no_disponible(menu_ajustes, 15);
}
void _cartel_sistema_redireccion(){
  MarlinUI::goto_screen(_cartel_sistema);
}
//funciones sin terminar//
//////////////////////////

////////////////////
//Entrar a sistema//

//Entrar a sistema//
////////////////////

///////////////////
//Menu de ajustes//
///////////////////
void menu_ajustes(){
  MarlinUI::lcdDrawUpdate = LCDVIEW_CALL_REDRAW_NEXT;
  //ui.currentScreen = menu_main;
  MarlinUI::ultimo_valor_ventana = menu_main;
  MarlinUI::ultimo_valor_encoder = 9;
  //MarlinUI::inductivo_final_carrera = true; //solucion a una vercion sin esta opcion
  if(planner.leveling_active)MarlinUI::inductivo_final_carrera = true;
  if(!planner.leveling_active) MarlinUI::inductivo_final_carrera = false;
  
  START_MENU();
  BACK_ITEM(MSG_VOLVER);                                  //0
  SUBMENU(MSG_VERCION,                    menu_vercion);  //1
  SUBMENU(MSG_INFO_STATS_MENU,            estadisticas);  //2
  SUBMENU(MSG_LOGROS,                     menu_logros);   //3

  SUBMENU2(MSG_IDIOMA,                       _cartel_idioma_redireccion);  //4   |Sin variable

  if(planner.leveling_active){
    SUBMENU2(MSG_DELTA_AUTO_CALIBRATE_ON,    auto_calibracion_on_off);     //5   |Cartel
  }else{
    SUBMENU2(MSG_DELTA_AUTO_CALIBRATE_OFF,   auto_calibracion_on_off);     //5   |
  }
  
  
  if(MarlinUI::inductivo_final_carrera){
    SUBMENU2(MSG_SENSOR_INDUCTIVO,          ir_cartel_error_sensor);     //6   |Cartel
  }else{
    SUBMENU2(MSG_FINAL_DE_CARRERA,          ir_cartel_error_sensor);     //6   |no se puede porque esta prendido sensor
  }
  

  if(MarlinUI::informacion_capas_coord){
    SUBMENU2(MSG_INFORMACION_CAPAS,         _informacion_capas_coord);     //7   |
  }else{
    SUBMENU2(MSG_INFORMACION_COORD,         _informacion_capas_coord);     //7   |
  }
  //serialprintPGM(st.get_stealthChop_status() ? PSTR("stealthChop") : PSTR("spreadCycle")); MSG_TMC2130_CHOP
  
  

  if(MarlinUI::tipo_de_extrusor){
    SUBMENU2(MSG_TIPO_EXTRU_BMG,            cambiar_tipo_extrusor);     //8   
  }else{
    SUBMENU2(MSG_TIPO_EXTRU_MK8,            cambiar_tipo_extrusor);     //8
  }
  
  if(MarlinUI::encode_der_izd){
    SUBMENU2(MSG_ENCODER_ON,                _encode_der_izd);              //10   |
  }else{
    SUBMENU2(MSG_ENCODER_OFF,               _encode_der_izd);              //10   |
  }

  if(MarlinUI::paso_de_varrilla){
    SUBMENU2(MSG_VARILLA_8MM,               _cambiar_paso_varilla);              //10   |
  }else{
    SUBMENU2(MSG_VARILLA_4MM,               _cambiar_paso_varilla);              //10   |
  }

  if(recovery.enabled){
    SUBMENU2(MSG_GUARDADO_ON,               _cartel_guardado_redireccion);             //9   |
  }else{
    SUBMENU2(MSG_GUARDADO_OFF,              _cartel_guardado_redireccion);             //9   |
  }
  
  /*
  if(MarlinUI::sensor_on_off){
    SUBMENU2(MSG_RUNOUT_SENSOR_ON,          _cartel_filamento_redireccion);               //8   |sensor_on_off //_sensor_on_off
  }else{
    SUBMENU2(MSG_RUNOUT_SENSOR_OFF,         _cartel_filamento_redireccion);               //8   |sensor_on_off
  }
  */

  if(MarlinUI::k_melody_on_off){
    SUBMENU2(MSG_KUTTERMELODY_ON,           _k_melody_on_off);             //11  |
  }else{
    SUBMENU2(MSG_KUTTERMELODY_OFF,          _k_melody_on_off);             //11  |

  }

  SUBMENU(MSG_TMC2130_CONFI,                menu_tmc);

  SUBMENU(MSG_PID_AUTOTUNE,               calcular_pid);                   //11  |Te dirive a PID

  SUBMENU(MSG_CONFIG_FABRICA,             _cartel_eprom);                  //12  |Tiene cartel de advertencia Carte

  SUBMENU(MSG_ENVIAR_GCODE,               _cartel_gcode_redireccion);                      //13  |

  END_MENU();

}

#endif // MENU_KUTTERCRAFT
#endif // HAS_LCD_MENU