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

/**
 *
 * Firmware Modificado Por Kuttercraft
 * Copyright (c) 2021 Kuttercraft [https://www.kuttercraft.com]
 *
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

//
// Main Menu
//

#include "../../inc/MarlinConfigPre.h"

#if HAS_LCD_MENU

#include "menu_item.h"
#include "../../module/temperature.h"
#include "../../gcode/queue.h"
#include "../../module/printcounter.h"
#include "../../module/stepper.h"
#include "../../sd/cardreader.h"
#include "../ultralcd.h"
#include "../dogm/fontdata/fontdata_ISO10646_1.h"
#include "../dogm/ultralcd_DOGM.h"

#if HAS_GAMES && DISABLED(LCD_INFO_MENU)
  #include "game/game.h"
#endif

#if EITHER(SDSUPPORT, HOST_PROMPT_SUPPORT) || defined(ACTION_ON_CANCEL)
  #define MACHINE_CAN_STOP 1
#endif
#if ANY(SDSUPPORT, HOST_PROMPT_SUPPORT, PARK_HEAD_ON_PAUSE) || defined(ACTION_ON_PAUSE)
  #define MACHINE_CAN_PAUSE 1
#endif

#if ENABLED(PRUSA_MMU2)
  #include "../../lcd/menu/menu_mmu2.h"
#endif

#if ENABLED(PASSWORD_FEATURE)
  #include "../../feature/password/password.h"
#endif

#if ENABLED(HOST_START_MENU_ITEM) && defined(ACTION_ON_START)
  #include "../../feature/host_actions.h"
#endif

#if ENABLED(MENU_KUTTERCRAFT)
  #include "../mapa_bit/bitmap_kuttercraft.h"
#endif

void menu_tune();
void menu_cancelobject();
void menu_motion();
void menu_temperature();
void menu_configuration();

//BOTONES
void init_boto(int medida_boton_, int espaciado_, int cantidad_, int altura_, int columna_bit_ = 3);
void crear_boton(const u8g_pgm_uint8_t* img_mapa_bit, const u8g_pgm_uint8_t* img_mapa_bit_2, PGM_P utf8_str_P, screenFunc_t screen, const uint16_t encoder = 0);
void opciones_no_disponible(screenFunc_t screen, const uint16_t encoder = 0);
void crear_espera();

//menu kuttercraft
void ajuste_de_filamento();
void temperatura_preset_manual();
void prender_apagar_led();
bool estado_actual_led();
void mover_o_home();
void kuttercraft_store();
void menu_ajustes();
void menu_calibracion_auto();
void menu_calibracion_printer();
void menu_modificar_flow();
void menu_modificar_velocidad();
void cancelar_imprecion();
void menu_pausa_reanudar();
void reiniciar_sistema();
void menu_calibracion_();
void menu_calibracion_endstop();

#if ENABLED(CUSTOM_USER_MENUS)
  void menu_user();
#endif

#if HAS_POWER_MONITOR
  void menu_power_monitor();
#endif

#if ENABLED(MIXING_EXTRUDER)
  void menu_mixer();
#endif

#if ENABLED(ADVANCED_PAUSE_FEATURE)
  void _menu_temp_filament_op(const PauseMode, const int8_t);
  void menu_change_filament();
#endif

#if ENABLED(LCD_INFO_MENU)
  void menu_info();
#endif

#if EITHER(LED_CONTROL_MENU, CASE_LIGHT_MENU)
  void menu_led();
#endif

#if HAS_CUTTER
  void menu_spindle_laser();
#endif

extern const char M21_STR[];

#if ENABLED(AUTO_BED_LEVELING_UBL) && DISABLED(MENU_KUTTERCRAFT)
  void _lcd_ubl_level_bed();
#endif

#if ENABLED(MENU_KUTTERCRAFT)

  void apagar_motores(){
    queue.inject_P(PSTR("M84\n M117 Motor Apagado"));
    MarlinUI::goto_screen(MarlinUI::status_screen);
  }

  void menu_main();

  void _menu_filamento(){
    queue.inject_P(PSTR("M600"));
    MarlinUI::goto_screen(MarlinUI::status_screen);
  }
  void redirigir_filamento(){
    MarlinUI::goto_screen(_menu_filamento);
  }

  //menu principal
  void menu_main() {
    const bool card_detected = card.isMounted();
    const bool card_open = card_detected && card.isFileOpen();
    const bool esta_imprimiendo = printingIsActive();
    MarlinUI::defer_return_to_status = false;

    //encoderLine indica la pocision del encoder
    //establese el rango del encoder de 0 / x-1
    START_MENU();
    NEXT_ITEM_(10);
    END_MENU();
    //FONT_MEN
    
    //tamaño del boton, espacio entre botones, cantidas de botones por fila, altura del boton
    init_boto(23, 2, 5, 2);
    
    crear_boton(boton_inicio_a,     boton_inicio_b,    Language_es::MSG_INICIO,           MarlinUI::status_screen);

    if (!esta_imprimiendo && !printingIsPaused()) {

      if (card_detected) {
        if (!card_open) {
          crear_boton(boton_sd_a,         boton_sd_b,        Language_es::MSG_MEDIA_MENU,       menu_media); //falta auto guardado y salida
        }
      }else {
          crear_boton(boton_recargar_a,     boton_recargar_b,  Language_es::MSG_MEDIA_MENU,       menu_media);
      }

      crear_boton(boton_filamento_a,  boton_filamento_b, Language_es::MSG_FILAMENT,         ajuste_de_filamento, 149);  

      crear_boton(boton_Temp_a,       boton_Temp_b,      Language_es::MSG_TEMPERATURE,      temperatura_preset_manual);
      
      if(planner.leveling_active){
      crear_boton(boton_hotend_a,     boton_hotend_b,    Language_es::MSG_CALIBRATE,        menu_calibracion_auto);
      }else{
        if(MarlinUI::inductivo_final_carrera){
          crear_boton(boton_hotend_a,     boton_hotend_b,    Language_es::MSG_CALIBRATE,        menu_calibracion_);
        }else{
          crear_boton(boton_hotend_a,     boton_hotend_b,    Language_es::MSG_CALIBRATE,        menu_calibracion_endstop);
        }
      }

      if(estado_actual_led()){
        crear_boton(boton_led_prendido_a, boton_led_prendido_b, Language_es::MSG_LED_APAGAR,  prender_apagar_led);
      }else{
        crear_boton(boton_led_a,          boton_led_b,          Language_es::MSG_LED_CONTROL, prender_apagar_led);
      }
      
      crear_boton(boton_mover_a,      boton_mover_b,     Language_es::MSG_MOVE_AXIS,        mover_o_home);

      crear_boton(boton_apagar_a,     boton_apagar_b,    Language_es::MSG_DISABLE_STEPPERS, apagar_motores);
      crear_boton(store_boton_a,      store_boton_b,     Language_es::MSG_STORE,            kuttercraft_store);
      crear_boton(boton_ajustes_a,    boton_ajustes_b,   Language_es::MSG_TUNE,             menu_ajustes);


    }else{
      //menu mientras imprimiendo

      crear_boton(boton_Temp_a,         boton_Temp_b,         Language_es::MSG_TEMPERATURE,      temperatura_preset_manual);
      
      crear_boton(boton_hotend_a,       boton_hotend_b,       Language_es::MSG_CALIBRATE,        menu_calibracion_printer);

      crear_boton(boton_ajustes_a,      boton_ajustes_b,      Language_es::MSG_FLOW_MENU,        menu_modificar_flow);

      crear_boton(boton_x_a,            boton_x_b,            Language_es::MSG_PRINT_CANCELAR,   cancelar_imprecion);

      if(printingIsPaused()){
        crear_boton(boton_reanudar_a,     boton_reanudar_b,        Language_es::MSG_PAUSE_PRINT,      menu_pausa_reanudar);
      }else{
        crear_boton(boton_pausa_a,        boton_pausa_b,           Language_es::MSG_PAUSE_PRINT,      menu_pausa_reanudar);
      }

      crear_boton(boton_filamento_a,    boton_filamento_b,    Language_es::MSG_FILAMENTCHANGE,   redirigir_filamento);//

      crear_boton(boton_velocidad_a,    boton_velocidad_b,    Language_es::MSG_VELOCITY_MENU,    menu_modificar_velocidad);
      //led
      if(estado_actual_led()){
        crear_boton(boton_led_prendido_a, boton_led_prendido_b, Language_es::MSG_LED_APAGAR,       prender_apagar_led);
      }else{
        crear_boton(boton_led_a,          boton_led_b,          Language_es::MSG_LED_CONTROL,      prender_apagar_led);
      }
      
      crear_boton(boton_volver_a,       boton_volver_b,       Language_es::MSG_RESET_PRINTER,    reiniciar_sistema);
      

    }
    
    // boton_tipo_a
    //u8g.drawBitmapP(centrar_botones(23, 2, 5, 0), 40, 3, 23, boton_sd_a);
    
  }

#else
  void menu_main() {
  //variables de lectura
  //busy = Esta imprimiendo //card_detected =Hay tarjeta conectada //card_open = esta leyendo
  const bool busy = printingIsActive()
    #if ENABLED(SDSUPPORT)
      , card_detected = card.isMounted()
      , card_open = card_detected && card.isFileOpen()
    #endif
  ;
  //Inicio de lista de menu
  START_MENU();
  //primer item volver 
  BACK_ITEM(MSG_INFO_SCREEN);

  //si esta imprimiendo aparece
  if (busy) {
    #if MACHINE_CAN_PAUSE
      //Pausa 
      ACTION_ITEM(MSG_PAUSE_PRINT, ui.pause_print);
    #endif
    #if MACHINE_CAN_STOP
      //STOP
      SUBMENU(MSG_STOP_PRINT, []{
        MenuItem_confirm::select_screen(
          GET_TEXT(MSG_BUTTON_STOP), GET_TEXT(MSG_BACK),
          ui.abort_print, ui.goto_previous_screen,
          GET_TEXT(MSG_STOP_PRINT), (const char *)nullptr, PSTR("?")
        );
      });
    #endif
    //menu_tune ajustar (Permite cambiar valores de temp, fan, velocidad, etc)
    SUBMENU(MSG_TUNE, menu_tune);

    #if ENABLED(CANCEL_OBJECTS) && DISABLED(SLIM_LCD_MENUS)
      SUBMENU(MSG_CANCEL_OBJECT, []{ editable.int8 = -1; ui.goto_screen(menu_cancelobject); });
    #endif
  }
  else {

    #if !HAS_ENCODER_WHEEL && ENABLED(SDSUPPORT)

      // *** IF THIS SECTION IS CHANGED, REPRODUCE BELOW ***

      //
      // Autostart empiza a imprimir un archivo indicado
      //
      #if ENABLED(MENU_ADDAUTOSTART)
        ACTION_ITEM(MSG_AUTOSTART, card.beginautostart);
      #endif

      //recargar sd y abrir sd
      if (card_detected) {
        if (!card_open) {
          SUBMENU(MSG_MEDIA_MENU, TERN(PASSWORD_ON_SD_PRINT_MENU, password.media_gatekeeper, menu_media));
          #if PIN_EXISTS(SD_DETECT)
            GCODES_ITEM(MSG_CHANGE_MEDIA, M21_STR);
          #else
            GCODES_ITEM(MSG_RELEASE_MEDIA, PSTR("M22"));
          #endif
        }
      }
      else {
        #if PIN_EXISTS(SD_DETECT)
          ACTION_ITEM(MSG_NO_MEDIA, nullptr);
        #else
          GCODES_ITEM(MSG_ATTACH_MEDIA, M21_STR);
        #endif
      }

    #endif // !HAS_ENCODER_WHEEL && SDSUPPORT

    //Reanudar impresión
    if (TERN0(MACHINE_CAN_PAUSE, printingIsPaused()))
      ACTION_ITEM(MSG_RESUME_PRINT, ui.resume_print);

    //activa funciones de host
    #if ENABLED(HOST_START_MENU_ITEM) && defined(ACTION_ON_START)
      ACTION_ITEM(MSG_HOST_START_PRINT, host_action_start);
    #endif
    //mover ejes 
    SUBMENU(MSG_ORLANDO, menu_motion);
  }
  //menu laser ¿?
  #if HAS_CUTTER
    SUBMENU(MSG_CUTTER(MENU), menu_spindle_laser);
  #endif
  //menu de temperaturas 
  #if HAS_TEMPERATURE
    SUBMENU(MSG_TEMPERATURE, menu_temperature);
  #endif
  //se nesecita un medidor de voltage y amperaje
  #if HAS_POWER_MONITOR
    SUBMENU(MSG_POWER_MONITOR, menu_power_monitor);
  #endif

  //extrusor mezclador
  #if ENABLED(MIXING_EXTRUDER)
    SUBMENU(MSG_MIXER, menu_mixer);
  #endif
  //menu del multi material de prusa
  #if ENABLED(MMU2_MENUS)
    if (!busy) SUBMENU(MSG_MMU2_MENU, menu_mmu2);
  #endif
  //configuraciones de todo velocidad, pasos por mm, todo, ect...
  SUBMENU(MSG_CONFIGURATION, menu_configuration);

  //menu Especial donde se le permite al usuario agregar item a gcodes 
  #if ENABLED(CUSTOM_USER_MENUS)
    #ifdef CUSTOM_USER_MENU_TITLE
      SUBMENU_P(PSTR(CUSTOM_USER_MENU_TITLE), menu_user);
    #else
      SUBMENU(MSG_USER_MENU, menu_user);
    #endif
  #endif

  //cambio de filamento
  #if ENABLED(ADVANCED_PAUSE_FEATURE)
    #if E_STEPPERS == 1 && DISABLED(FILAMENT_LOAD_UNLOAD_GCODES)
      if (thermalManager.targetHotEnoughToExtrude(active_extruder))
        GCODES_ITEM(MSG_FILAMENTCHANGE, PSTR("M600 B0"));
      else
        SUBMENU(MSG_FILAMENTCHANGE, []{ _menu_temp_filament_op(PAUSE_MODE_CHANGE_FILAMENT, 0); });
    #else
      SUBMENU(MSG_FILAMENTCHANGE, menu_change_filament);
    #endif
  #endif
  //informacion de impresora, vercion, placa, etc...
  #if ENABLED(LCD_INFO_MENU)
    SUBMENU(MSG_INFO_MENU, menu_info);
  #endif
  //control de luces led
  #if EITHER(LED_CONTROL_MENU, CASE_LIGHT_MENU)
    SUBMENU(MSG_LEDS, menu_led);
  #endif

  //
  // Switch power on/off
  //
  //sañal de apagodo o prendido de fuente
  #if ENABLED(PSU_CONTROL)
    if (powersupply_on)
      GCODES_ITEM(MSG_SWITCH_PS_OFF, PSTR("M81"));
    else
      GCODES_ITEM(MSG_SWITCH_PS_ON, PSTR("M80"));
  #endif
  //Mueve los valores de sddupport en caso de HAS_ENCODER_WHEEL XD
  //Se repiten todos los valores
  #if BOTH(HAS_ENCODER_WHEEL, SDSUPPORT)

    if (!busy) {

      // *** IF THIS SECTION IS CHANGED, REPRODUCE ABOVE ***

      //
      // Autostart
      //
      #if ENABLED(MENU_ADDAUTOSTART)
        ACTION_ITEM(MSG_AUTOSTART, card.beginautostart);
      #endif

      if (card_detected) {
        if (!card_open) {
          #if PIN_EXISTS(SD_DETECT)
            GCODES_ITEM(MSG_CHANGE_MEDIA, M21_STR);
          #else
            GCODES_ITEM(MSG_RELEASE_MEDIA, PSTR("M22"));
          #endif
          SUBMENU(MSG_MEDIA_MENU, TERN(PASSWORD_ON_SD_PRINT_MENU, password.media_gatekeeper, menu_media));
        }
      }
      else {
        #if PIN_EXISTS(SD_DETECT)
          ACTION_ITEM(MSG_NO_MEDIA, nullptr);
        #else
          GCODES_ITEM(MSG_ATTACH_MEDIA, M21_STR);
        #endif
      }
    }

  #endif // HAS_ENCODER_WHEEL && SDSUPPORT

  //Variables de impresion
  #if HAS_SERVICE_INTERVALS
    static auto _service_reset = [](const int index) {
      print_job_timer.resetServiceInterval(index);
      ui.completion_feedback();
      ui.reset_status();
      ui.return_to_status();
    };
    #if SERVICE_INTERVAL_1 > 0
      CONFIRM_ITEM_P(PSTR(SERVICE_NAME_1),
        MSG_BUTTON_RESET, MSG_BUTTON_CANCEL,
        []{ _service_reset(1); }, ui.goto_previous_screen,
        GET_TEXT(MSG_SERVICE_RESET), F(SERVICE_NAME_1), PSTR("?")
      );
    #endif
    #if SERVICE_INTERVAL_2 > 0
      CONFIRM_ITEM_P(PSTR(SERVICE_NAME_2),
        MSG_BUTTON_RESET, MSG_BUTTON_CANCEL,
        []{ _service_reset(2); }, ui.goto_previous_screen,
        GET_TEXT(MSG_SERVICE_RESET), F(SERVICE_NAME_2), PSTR("?")
      );
    #endif
    #if SERVICE_INTERVAL_3 > 0
      CONFIRM_ITEM_P(PSTR(SERVICE_NAME_3),
        MSG_BUTTON_RESET, MSG_BUTTON_CANCEL,
        []{ _service_reset(3); }, ui.goto_previous_screen,
        GET_TEXT(MSG_SERVICE_RESET), F(SERVICE_NAME_3), PSTR("?")
      );
    #endif
  #endif
  //juegos porque?... porque no!
  #if HAS_GAMES && DISABLED(LCD_INFO_MENU)
    #if ENABLED(GAMES_EASTER_EGG)
      SKIP_ITEM();
      SKIP_ITEM();
      SKIP_ITEM();
    #endif
    // Game sub-menu or the individual game
    {
      SUBMENU(
        #if HAS_GAME_MENU
          MSG_GAMES, menu_game
        #elif ENABLED(MARLIN_BRICKOUT)
          MSG_BRICKOUT, brickout.enter_game
        #elif ENABLED(MARLIN_INVADERS)
          MSG_INVADERS, invaders.enter_game
        #elif ENABLED(MARLIN_SNAKE)
          MSG_SNAKE, snake.enter_game
        #elif ENABLED(MARLIN_MAZE)
          MSG_MAZE, maze.enter_game
        #endif
      );
    }
  #endif

  END_MENU();
  }
#endif




#endif // HAS_LCD_MENU
