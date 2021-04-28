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
#pragma once

/**
 * Spanish
 *
 * LCD Menu Messages
 * See also https://marlinfw.org/docs/development/lcd_language.html
 */

namespace Language_es {
  using namespace Language_en; // Inherit undefined strings from English

  constexpr uint8_t    CHARSIZE                            = 2;
  PROGMEM Language_Str LANGUAGE                            = _UxGT("Spanish");

  PROGMEM Language_Str WELCOME_MSG                         = MACHINE_NAME _UxGT(" Lista");
  PROGMEM Language_Str MSG_MARLIN                          = _UxGT("Marlin");
  PROGMEM Language_Str MSG_YES                             = _UxGT("SI");
  PROGMEM Language_Str MSG_NO                              = _UxGT("NO");
  PROGMEM Language_Str MSG_BACK                            = _UxGT("Atrás");
  PROGMEM Language_Str MSG_MEDIA_ABORTING                  = _UxGT("Cancelando...");
  PROGMEM Language_Str MSG_MEDIA_INSERTED                  = _UxGT("SD/USB insertado");
  PROGMEM Language_Str MSG_MEDIA_REMOVED                   = _UxGT("SD/USB retirado");
  PROGMEM Language_Str MSG_MEDIA_WAITING                   = _UxGT("Esperando al SD/USB");
  PROGMEM Language_Str MSG_MEDIA_READ_ERROR                = _UxGT("Error lectura SD/USB");
  PROGMEM Language_Str MSG_MEDIA_USB_REMOVED               = _UxGT("Disp. USB retirado");
  PROGMEM Language_Str MSG_MEDIA_USB_FAILED                = _UxGT("Inicio USB fallido");
  PROGMEM Language_Str MSG_LCD_ENDSTOPS                    = _UxGT("Endstops"); // Max length 8 characters
  PROGMEM Language_Str MSG_LCD_SOFT_ENDSTOPS               = _UxGT("Soft Endstops");
  PROGMEM Language_Str MSG_MAIN                            = _UxGT("Menú principal");
  PROGMEM Language_Str MSG_ADVANCED_SETTINGS               = _UxGT("Ajustes avanzados");
  PROGMEM Language_Str MSG_CONFIGURATION                   = _UxGT("Configuración");
  PROGMEM Language_Str MSG_AUTOSTART                       = _UxGT("Inicio automático");
  PROGMEM Language_Str MSG_DISABLE_STEPPERS                = _UxGT("Apagar motores");
  PROGMEM Language_Str MSG_DEBUG_MENU                      = _UxGT("Menú depuración");
  PROGMEM Language_Str MSG_PROGRESS_BAR_TEST               = _UxGT("Prob. barra progreso");


  PROGMEM Language_Str MSG_LEVEL_BED_WAITING               = _UxGT("Pulsar para comenzar");
  PROGMEM Language_Str MSG_LEVEL_BED_NEXT_POINT            = _UxGT("Siguiente punto");
  PROGMEM Language_Str MSG_LEVEL_BED_DONE                  = _UxGT("¡Nivelación lista!");
  PROGMEM Language_Str MSG_Z_FADE_HEIGHT                   = _UxGT("Compen. Altura");
  PROGMEM Language_Str MSG_SET_HOME_OFFSETS                = _UxGT("Ajustar desfases");
  PROGMEM Language_Str MSG_HOME_OFFSETS_APPLIED            = _UxGT("Desfase aplicada");
  PROGMEM Language_Str MSG_SET_ORIGIN                      = _UxGT("Establecer origen");
  #if PREHEAT_COUNT
    PROGMEM Language_Str MSG_PREHEAT_1                     = _UxGT("Precal. ") PREHEAT_1_LABEL;
    PROGMEM Language_Str MSG_PREHEAT_1_H                   = _UxGT("Precal. ") PREHEAT_1_LABEL " ~";
    PROGMEM Language_Str MSG_PREHEAT_1_END                 = _UxGT("Precal. ") PREHEAT_1_LABEL _UxGT(" Fusor");
    PROGMEM Language_Str MSG_PREHEAT_1_END_E               = _UxGT("Precal. ") PREHEAT_1_LABEL _UxGT(" Fusor ~");
    PROGMEM Language_Str MSG_PREHEAT_1_ALL                 = _UxGT("Precal. ") PREHEAT_1_LABEL _UxGT(" Todo");
    PROGMEM Language_Str MSG_PREHEAT_1_BEDONLY             = _UxGT("Precal. ") PREHEAT_1_LABEL _UxGT(" Cama");
    PROGMEM Language_Str MSG_PREHEAT_1_SETTINGS            = _UxGT("Precal. ") PREHEAT_1_LABEL _UxGT(" Ajuste");

    PROGMEM Language_Str MSG_PREHEAT_M                    = _UxGT("Precal. $");
    PROGMEM Language_Str MSG_PREHEAT_M_H                  = _UxGT("Precal. $ ~");
    PROGMEM Language_Str MSG_PREHEAT_M_END                = _UxGT("Precal. $ Fusor");
    PROGMEM Language_Str MSG_PREHEAT_M_END_E              = _UxGT("Precal. $ Fusor ~");
    PROGMEM Language_Str MSG_PREHEAT_M_ALL                = _UxGT("Precal. $ Todo");
    PROGMEM Language_Str MSG_PREHEAT_M_BEDONLY            = _UxGT("Precal. $ Cama");
    PROGMEM Language_Str MSG_PREHEAT_M_SETTINGS           = _UxGT("Precal. $ Ajuste");
  #endif
  PROGMEM Language_Str MSG_PREHEAT_CUSTOM                  = _UxGT("Precal. manual");
  
  PROGMEM Language_Str MSG_CUTTER_FREQUENCY                = _UxGT("Frecuencia");
  PROGMEM Language_Str MSG_LASER_MENU                      = _UxGT("Control Láser");
  PROGMEM Language_Str MSG_LASER_OFF                       = _UxGT("Apagar Láser");
  PROGMEM Language_Str MSG_LASER_ON                        = _UxGT("Encender Láser");
  PROGMEM Language_Str MSG_LASER_POWER                     = _UxGT("Potencia Láser");
  PROGMEM Language_Str MSG_SPINDLE_MENU                    = _UxGT("Control Mandrino");
  PROGMEM Language_Str MSG_SPINDLE_OFF                     = _UxGT("Apagar Mandrino");
  PROGMEM Language_Str MSG_SPINDLE_ON                      = _UxGT("Encender Mandrino");
  PROGMEM Language_Str MSG_SPINDLE_POWER                   = _UxGT("Potencia Mandrino");
  PROGMEM Language_Str MSG_SPINDLE_REVERSE                 = _UxGT("Invertir giro");
  PROGMEM Language_Str MSG_SWITCH_PS_ON                    = _UxGT("Encender Fuente");
  PROGMEM Language_Str MSG_SWITCH_PS_OFF                   = _UxGT("Apagar Fuente");
  PROGMEM Language_Str MSG_EXTRUDE                         = _UxGT("Extruir");
  PROGMEM Language_Str MSG_RETRACT                         = _UxGT("Retraer");
  PROGMEM Language_Str MSG_BED_LEVELING                    = _UxGT("Nivelando Cama");
  PROGMEM Language_Str MSG_LEVEL_BED                       = _UxGT("Nivelar Cama");
  PROGMEM Language_Str MSG_LEVEL_CORNERS                   = _UxGT("Nivelar Esquinas");
  PROGMEM Language_Str MSG_NEXT_CORNER                     = _UxGT("Siguente Esquina");
  PROGMEM Language_Str MSG_MESH_EDITOR                     = _UxGT("Editor Mallado");
  PROGMEM Language_Str MSG_EDIT_MESH                       = _UxGT("Editar Mallado");
  PROGMEM Language_Str MSG_EDITING_STOPPED                 = _UxGT("Ed. Mallado parada");
  PROGMEM Language_Str MSG_MESH_X                          = _UxGT("Índice X");
  PROGMEM Language_Str MSG_MESH_Y                          = _UxGT("Índice Y");
  PROGMEM Language_Str MSG_MESH_EDIT_Z                     = _UxGT("Valor Z");
  PROGMEM Language_Str MSG_USER_MENU                       = _UxGT("Com. Personalizados");
  PROGMEM Language_Str MSG_M48_TEST                        = _UxGT("M48 Probar Sonda");
  PROGMEM Language_Str MSG_M48_POINT                       = _UxGT("M48 Punto");
  PROGMEM Language_Str MSG_M48_DEVIATION                   = _UxGT("Desviación");
  PROGMEM Language_Str MSG_IDEX_MENU                       = _UxGT("Modo IDEX");
  PROGMEM Language_Str MSG_OFFSETS_MENU                    = _UxGT("Desfase Herramienta");
  PROGMEM Language_Str MSG_IDEX_MODE_AUTOPARK              = _UxGT("Auto-Aparcado");
  PROGMEM Language_Str MSG_IDEX_MODE_DUPLICATE             = _UxGT("Duplicar");
  PROGMEM Language_Str MSG_IDEX_MODE_MIRRORED_COPY         = _UxGT("Copia Reflejada");
  PROGMEM Language_Str MSG_IDEX_MODE_FULL_CTRL             = _UxGT("Control Total");
  PROGMEM Language_Str MSG_HOTEND_OFFSET_X                 = _UxGT("2ª Fusor X");
  PROGMEM Language_Str MSG_HOTEND_OFFSET_Y                 = _UxGT("2ª Fusor Y");
  PROGMEM Language_Str MSG_HOTEND_OFFSET_Z                 = _UxGT("2ª Fusor Z");
  PROGMEM Language_Str MSG_UBL_DOING_G29                   = _UxGT("Hacer G29");
  PROGMEM Language_Str MSG_UBL_TOOLS                       = _UxGT("Herramientas UBL");
  PROGMEM Language_Str MSG_UBL_LEVEL_BED                   = _UxGT("Nivelado UBL");
  PROGMEM Language_Str MSG_LCD_TILTING_MESH                = _UxGT("Punto de inclinación");
  PROGMEM Language_Str MSG_UBL_MANUAL_MESH                 = _UxGT("Crear Mallado man.");
  PROGMEM Language_Str MSG_UBL_BC_INSERT                   = _UxGT("Colocar cuña y Medir");
  PROGMEM Language_Str MSG_UBL_BC_INSERT2                  = _UxGT("Medir");
  PROGMEM Language_Str MSG_UBL_BC_REMOVE                   = _UxGT("Retirar y Medir Cama");
  PROGMEM Language_Str MSG_UBL_MOVING_TO_NEXT              = _UxGT("Mover al Siguente");
  PROGMEM Language_Str MSG_UBL_ACTIVATE_MESH               = _UxGT("Activar UBL");
  PROGMEM Language_Str MSG_UBL_DEACTIVATE_MESH             = _UxGT("Desactivar UBL");
  PROGMEM Language_Str MSG_UBL_SET_TEMP_BED                = _UxGT("Temp. Cama");
  PROGMEM Language_Str MSG_UBL_BED_TEMP_CUSTOM             = _UxGT("Temp. Cama perso.");
  PROGMEM Language_Str MSG_UBL_SET_TEMP_HOTEND             = _UxGT("Temp. Fusor");
  PROGMEM Language_Str MSG_UBL_HOTEND_TEMP_CUSTOM          = _UxGT("Temp. Fusor perso.");
  PROGMEM Language_Str MSG_UBL_MESH_EDIT                   = _UxGT("Editar Mallado");
  PROGMEM Language_Str MSG_UBL_EDIT_CUSTOM_MESH            = _UxGT("Edit. Mallado perso.");
  PROGMEM Language_Str MSG_UBL_FINE_TUNE_MESH              = _UxGT("Ajuste fino Mallado");
  PROGMEM Language_Str MSG_UBL_DONE_EDITING_MESH           = _UxGT("Term. edici. Mallado");
  PROGMEM Language_Str MSG_UBL_BUILD_CUSTOM_MESH           = _UxGT("Crear Mallado Pers.");
  PROGMEM Language_Str MSG_UBL_BUILD_MESH_MENU             = _UxGT("Crear Mallado");
  #if PREHEAT_COUNT
    PROGMEM Language_Str MSG_UBL_BUILD_MESH_M              = _UxGT("Crear Mallado ($)");
    PROGMEM Language_Str MSG_UBL_VALIDATE_MESH_M           = _UxGT("Valid. Mall. ($)");
  #endif
  PROGMEM Language_Str MSG_UBL_BUILD_COLD_MESH             = _UxGT("Crear Mallado Frío");
  PROGMEM Language_Str MSG_UBL_MESH_HEIGHT_ADJUST          = _UxGT("Ajustar alt. Mallado");
  PROGMEM Language_Str MSG_UBL_MESH_HEIGHT_AMOUNT          = _UxGT("Cantidad de altura");
  PROGMEM Language_Str MSG_UBL_VALIDATE_MESH_MENU          = _UxGT("Valid. Mallado");
  PROGMEM Language_Str MSG_UBL_VALIDATE_CUSTOM_MESH        = _UxGT("Valid. Mall. perso.");
  PROGMEM Language_Str MSG_G26_HEATING_BED                 = _UxGT("G26 Calentando Cama");
  PROGMEM Language_Str MSG_G26_HEATING_NOZZLE              = _UxGT("G26 Calent. Boquilla");
  PROGMEM Language_Str MSG_G26_MANUAL_PRIME                = _UxGT("Imprimado manual...");
  PROGMEM Language_Str MSG_G26_FIXED_LENGTH                = _UxGT("Impri. longit. fija");
  PROGMEM Language_Str MSG_G26_PRIME_DONE                  = _UxGT("Imprimación Lista");
  PROGMEM Language_Str MSG_G26_CANCELED                    = _UxGT("G26 Cancelado");
  PROGMEM Language_Str MSG_G26_LEAVING                     = _UxGT("Dejando G26");
  PROGMEM Language_Str MSG_UBL_CONTINUE_MESH               = _UxGT("Contin. Mallado cama");
  PROGMEM Language_Str MSG_UBL_MESH_LEVELING               = _UxGT("Nivelando Mallado");
  PROGMEM Language_Str MSG_UBL_3POINT_MESH_LEVELING        = _UxGT("Nivelando 3Puntos");
  PROGMEM Language_Str MSG_UBL_GRID_MESH_LEVELING          = _UxGT("Niv. Mall. cuadri");
  PROGMEM Language_Str MSG_UBL_MESH_LEVEL                  = _UxGT("Nivel de Mallado");
  PROGMEM Language_Str MSG_UBL_SIDE_POINTS                 = _UxGT("Puntos Laterales");
  PROGMEM Language_Str MSG_UBL_MAP_TYPE                    = _UxGT("Tipo de mapa ");
  PROGMEM Language_Str MSG_UBL_OUTPUT_MAP                  = _UxGT("Salida Mapa mallado");
  PROGMEM Language_Str MSG_UBL_OUTPUT_MAP_HOST             = _UxGT("Salida para el host");
  PROGMEM Language_Str MSG_UBL_OUTPUT_MAP_CSV              = _UxGT("Salida para CSV");
  PROGMEM Language_Str MSG_UBL_OUTPUT_MAP_BACKUP           = _UxGT("Cópia de seg. ext");
  PROGMEM Language_Str MSG_UBL_INFO_UBL                    = _UxGT("Salida Info. UBL");
  PROGMEM Language_Str MSG_UBL_FILLIN_AMOUNT               = _UxGT("Cantidad de relleno");
  PROGMEM Language_Str MSG_UBL_MANUAL_FILLIN               = _UxGT("Relleno manual");
  PROGMEM Language_Str MSG_UBL_SMART_FILLIN                = _UxGT("Relleno inteligente");
  PROGMEM Language_Str MSG_UBL_FILLIN_MESH                 = _UxGT("Mallado de relleno");
  PROGMEM Language_Str MSG_UBL_INVALIDATE_ALL              = _UxGT("Invalidar todo");
  PROGMEM Language_Str MSG_UBL_INVALIDATE_CLOSEST          = _UxGT("Invalidar proximos");
  PROGMEM Language_Str MSG_UBL_FINE_TUNE_ALL               = _UxGT("Ajustar Fino Todo");
  PROGMEM Language_Str MSG_UBL_FINE_TUNE_CLOSEST           = _UxGT("Ajustar Fino proxi.");
  PROGMEM Language_Str MSG_UBL_STORAGE_MESH_MENU           = _UxGT("Almacen de Mallado");
  PROGMEM Language_Str MSG_UBL_STORAGE_SLOT                = _UxGT("Huecos memoria");
  PROGMEM Language_Str MSG_UBL_LOAD_MESH                   = _UxGT("Cargar Mall. cama");
  PROGMEM Language_Str MSG_UBL_SAVE_MESH                   = _UxGT("Guardar Mall. cama");
  PROGMEM Language_Str MSG_MESH_LOADED                     = _UxGT("Malla %i Cargada");
  PROGMEM Language_Str MSG_MESH_SAVED                      = _UxGT("Malla %i Guardada");
  PROGMEM Language_Str MSG_UBL_NO_STORAGE                  = _UxGT("Sin guardar");
  PROGMEM Language_Str MSG_UBL_SAVE_ERROR                  = _UxGT("Error: Guardar UBL");
  PROGMEM Language_Str MSG_UBL_RESTORE_ERROR               = _UxGT("Error: Restaurar UBL");
  PROGMEM Language_Str MSG_UBL_Z_OFFSET                    = _UxGT("Desfase de Z: ");
  PROGMEM Language_Str MSG_UBL_Z_OFFSET_STOPPED            = _UxGT("Desfase de Z Parado");
  PROGMEM Language_Str MSG_UBL_STEP_BY_STEP_MENU           = _UxGT("UBL Paso a Paso");
  PROGMEM Language_Str MSG_UBL_1_BUILD_COLD_MESH           = _UxGT("1.Crear Mall. Frío");
  PROGMEM Language_Str MSG_UBL_2_SMART_FILLIN              = _UxGT("2.Relleno intelig.");
  PROGMEM Language_Str MSG_UBL_3_VALIDATE_MESH_MENU        = _UxGT("3.Valid. Mallado");
  PROGMEM Language_Str MSG_UBL_4_FINE_TUNE_ALL             = _UxGT("4.Ajustar Fino Todo");
  PROGMEM Language_Str MSG_UBL_5_VALIDATE_MESH_MENU        = _UxGT("5.Valid. Mallado");
  PROGMEM Language_Str MSG_UBL_6_FINE_TUNE_ALL             = _UxGT("6.Ajustar Fino Todo");
  PROGMEM Language_Str MSG_UBL_7_SAVE_MESH                 = _UxGT("7.Guardar Mall. cama");
  PROGMEM Language_Str MSG_LEDS                            = _UxGT("LEDS");
  PROGMEM Language_Str MSG_LED_PRESETS                     = _UxGT("Color predefinido");
  PROGMEM Language_Str MSG_SET_LEDS_RED                    = _UxGT("Rojo");
  PROGMEM Language_Str MSG_SET_LEDS_ORANGE                 = _UxGT("Naranja");
  PROGMEM Language_Str MSG_SET_LEDS_YELLOW                 = _UxGT("Amarillo");
  PROGMEM Language_Str MSG_SET_LEDS_GREEN                  = _UxGT("Verde");
  PROGMEM Language_Str MSG_SET_LEDS_BLUE                   = _UxGT("Azul");
  PROGMEM Language_Str MSG_SET_LEDS_INDIGO                 = _UxGT("Índigo");
  PROGMEM Language_Str MSG_SET_LEDS_VIOLET                 = _UxGT("Violeta");
  PROGMEM Language_Str MSG_SET_LEDS_WHITE                  = _UxGT("Blanco");
  PROGMEM Language_Str MSG_SET_LEDS_DEFAULT                = _UxGT("Por defecto");
  PROGMEM Language_Str MSG_CUSTOM_LEDS                     = _UxGT("Color personalizado");
  PROGMEM Language_Str MSG_INTENSITY_R                     = _UxGT("Intensidad Rojo");
  PROGMEM Language_Str MSG_INTENSITY_G                     = _UxGT("Intensidad Verde");
  PROGMEM Language_Str MSG_INTENSITY_B                     = _UxGT("Intensidad Azul");
  PROGMEM Language_Str MSG_INTENSITY_W                     = _UxGT("Intensidad Blanco");
  PROGMEM Language_Str MSG_LED_BRIGHTNESS                  = _UxGT("Brillo");

  PROGMEM Language_Str MSG_MOVING                          = _UxGT("Moviendo...");
  PROGMEM Language_Str MSG_FREE_XY                         = _UxGT("Libre XY");
  PROGMEM Language_Str MSG_MOVE_E                          = _UxGT("Extrusor");
  PROGMEM Language_Str MSG_MOVE_EN                         = _UxGT("Extrusor *");
  PROGMEM Language_Str MSG_HOTEND_TOO_COLD                 = _UxGT("Hotend muy frio");
  PROGMEM Language_Str MSG_SPEED                           = _UxGT("Velocidad");
  PROGMEM Language_Str MSG_BED_Z                           = _UxGT("Cama Z");
  
  PROGMEM Language_Str MSG_NOZZLE_N                        = _UxGT("Boquilla ~");
  PROGMEM Language_Str MSG_NOZZLE_PARKED                   = _UxGT("Boquilla Aparcada");
  PROGMEM Language_Str MSG_NOZZLE_STANDBY                  = _UxGT("Boquilla en Espera");
  
  PROGMEM Language_Str MSG_CHAMBER                         = _UxGT("Recinto");
  PROGMEM Language_Str MSG_FAN_SPEED_N                     = _UxGT("Ventilador ~");
  PROGMEM Language_Str MSG_STORED_FAN_N                    = _UxGT("Vent. almacenado ~");
  PROGMEM Language_Str MSG_EXTRA_FAN_SPEED                 = _UxGT("Vel. Ext. ventil.");
  PROGMEM Language_Str MSG_EXTRA_FAN_SPEED_N               = _UxGT("Vel. Ext. ventil. ~");
  PROGMEM Language_Str MSG_CONTROLLER_FAN                  = _UxGT("Controlador Vent.");
  PROGMEM Language_Str MSG_CONTROLLER_FAN_IDLE_SPEED       = _UxGT("Velocidad en reposo");
  PROGMEM Language_Str MSG_CONTROLLER_FAN_AUTO_ON          = _UxGT("Modo Auto");
  PROGMEM Language_Str MSG_CONTROLLER_FAN_SPEED            = _UxGT("Velocidad Activa");
  PROGMEM Language_Str MSG_CONTROLLER_FAN_DURATION         = _UxGT("Periodo de reposo");
  PROGMEM Language_Str MSG_FLOW                            = _UxGT("Flujo");
  PROGMEM Language_Str MSG_FLOW_N                          = _UxGT("Flujo ~");
  PROGMEM Language_Str MSG_CONTROL                         = _UxGT("Control");
  PROGMEM Language_Str MSG_MIN                             = " " LCD_STR_THERMOMETER _UxGT(" Min");
  PROGMEM Language_Str MSG_MAX                             = " " LCD_STR_THERMOMETER _UxGT(" Max");
  PROGMEM Language_Str MSG_FACTOR                          = " " LCD_STR_THERMOMETER _UxGT(" Factor");
  PROGMEM Language_Str MSG_AUTOTEMP                        = _UxGT("Temp. Autom.");
  PROGMEM Language_Str MSG_LCD_ON                          = _UxGT("Enc");
  PROGMEM Language_Str MSG_LCD_OFF                         = _UxGT("Apg");
  PROGMEM Language_Str MSG_PID_AUTOTUNE_E                  = _UxGT("PID Auto-ajuste *");
  PROGMEM Language_Str MSG_PID_P                           = _UxGT("PID-P");
  PROGMEM Language_Str MSG_PID_P_E                         = _UxGT("PID-P *");
  PROGMEM Language_Str MSG_PID_I                           = _UxGT("PID-I");
  PROGMEM Language_Str MSG_PID_I_E                         = _UxGT("PID-I *");
  PROGMEM Language_Str MSG_PID_D                           = _UxGT("PID-D");
  PROGMEM Language_Str MSG_PID_D_E                         = _UxGT("PID-D *");
  PROGMEM Language_Str MSG_PID_C                           = _UxGT("PID-C");
  PROGMEM Language_Str MSG_PID_C_E                         = _UxGT("PID-C *");
  PROGMEM Language_Str MSG_PID_F                           = _UxGT("PID-F");
  PROGMEM Language_Str MSG_PID_F_E                         = _UxGT("PID-F *");
  PROGMEM Language_Str MSG_ACC                             = _UxGT("Aceleración");
  PROGMEM Language_Str MSG_JERK                            = _UxGT("Jerk");
  PROGMEM Language_Str MSG_VA_JERK                         = _UxGT("V") LCD_STR_A _UxGT("-Jerk");
  PROGMEM Language_Str MSG_VB_JERK                         = _UxGT("V") LCD_STR_B _UxGT("-Jerk");
  PROGMEM Language_Str MSG_VC_JERK                         = _UxGT("V") LCD_STR_C _UxGT("-Jerk");
  PROGMEM Language_Str MSG_VE_JERK                         = _UxGT("Ve-Jerk");
  PROGMEM Language_Str MSG_JUNCTION_DEVIATION              = _UxGT("Desvi. Unión");
  PROGMEM Language_Str MSG_VMAX_A                          = _UxGT("Vmax ") LCD_STR_A;
  PROGMEM Language_Str MSG_VMAX_B                          = _UxGT("Vmax ") LCD_STR_B;
  PROGMEM Language_Str MSG_VMAX_C                          = _UxGT("Vmax ") LCD_STR_C;
  PROGMEM Language_Str MSG_VMAX_E                          = _UxGT("Vmax ") LCD_STR_E;
  PROGMEM Language_Str MSG_VMAX_EN                         = _UxGT("Vmax *");
  PROGMEM Language_Str MSG_VMIN                            = _UxGT("Vmin");
  PROGMEM Language_Str MSG_VTRAV_MIN                       = _UxGT("Vel. viaje min");
  PROGMEM Language_Str MSG_ACCELERATION                    = _UxGT("Acceleración");
  PROGMEM Language_Str MSG_AMAX_A                          = _UxGT("Acel. max") LCD_STR_A;
  PROGMEM Language_Str MSG_AMAX_B                          = _UxGT("Acel. max") LCD_STR_B;
  PROGMEM Language_Str MSG_AMAX_C                          = _UxGT("Acel. max") LCD_STR_C;
  PROGMEM Language_Str MSG_AMAX_E                          = _UxGT("Acel. max") LCD_STR_E;
  PROGMEM Language_Str MSG_AMAX_EN                         = _UxGT("Acel. max *");
  PROGMEM Language_Str MSG_A_RETRACT                       = _UxGT("Acel. retrac.");
  PROGMEM Language_Str MSG_A_TRAVEL                        = _UxGT("Acel. Viaje");
  PROGMEM Language_Str MSG_STEPS_PER_MM                    = _UxGT("Pasos/mm");
  PROGMEM Language_Str MSG_A_STEPS                         = LCD_STR_A _UxGT(" pasos/mm");
  PROGMEM Language_Str MSG_B_STEPS                         = LCD_STR_B _UxGT(" pasos/mm");
  PROGMEM Language_Str MSG_C_STEPS                         = LCD_STR_C _UxGT(" pasos/mm");
  PROGMEM Language_Str MSG_E_STEPS                         = _UxGT("E pasos/mm");
  PROGMEM Language_Str MSG_EN_STEPS                        = _UxGT("* pasos/mm");
  PROGMEM Language_Str MSG_MOTION                          = _UxGT("Movimiento");
  PROGMEM Language_Str MSG_ORLANDO                         = _UxGT("Orlando2");
  PROGMEM Language_Str MSG_INICIO                          = _UxGT("Inicio");
  PROGMEM Language_Str MSG_FILAMENT                        = _UxGT("Ajuste De Filamento");
  PROGMEM Language_Str MSG_VOLUMETRIC_ENABLED              = _UxGT("E en mm³");
  PROGMEM Language_Str MSG_FILAMENT_DIAM                   = _UxGT("Diámetro Fil.");
  PROGMEM Language_Str MSG_FILAMENT_DIAM_E                 = _UxGT("Diámetro Fil. *");
  PROGMEM Language_Str MSG_FILAMENT_UNLOAD                 = _UxGT("Descarga mm");
  PROGMEM Language_Str MSG_FILAMENT_LOAD                   = _UxGT("Carga mm");
  PROGMEM Language_Str MSG_ADVANCE_K                       = _UxGT("Avance K");
  PROGMEM Language_Str MSG_ADVANCE_K_E                     = _UxGT("Avance K *");
  PROGMEM Language_Str MSG_CONTRAST                        = _UxGT("Contraste LCD");
  PROGMEM Language_Str MSG_STORE_EEPROM                    = _UxGT("Guardar EEPROM");
  PROGMEM Language_Str MSG_LOAD_EEPROM                     = _UxGT("Cargar EEPROM");
  PROGMEM Language_Str MSG_RESTORE_DEFAULTS                = _UxGT("Rest. fábrica");
  PROGMEM Language_Str MSG_INIT_EEPROM                     = _UxGT("Inicializar EEPROM");
  PROGMEM Language_Str MSG_ERR_EEPROM_CRC                  = _UxGT("Err: EEPROM CRC");
  PROGMEM Language_Str MSG_ERR_EEPROM_INDEX                = _UxGT("Err: Índice EEPROM");
  PROGMEM Language_Str MSG_ERR_EEPROM_VERSION              = _UxGT("Err: Versión EEPROM");
  PROGMEM Language_Str MSG_MEDIA_UPDATE                    = _UxGT("Actualizar SD/USB");
  PROGMEM Language_Str MSG_REFRESH                         = LCD_STR_REFRESH  _UxGT("Recargar");
  PROGMEM Language_Str MSG_INFO_SCREEN                     = _UxGT("Pantalla de Inf.");
  PROGMEM Language_Str MSG_PREPARE                         = _UxGT("Preparar");
  PROGMEM Language_Str MSG_TUNE                            = _UxGT("Ajustar");
  PROGMEM Language_Str MSG_START_PRINT                     = _UxGT("Iniciar impresión");
  PROGMEM Language_Str MSG_BUTTON_NEXT                     = _UxGT("Siguinte");
  PROGMEM Language_Str MSG_BUTTON_INIT                     = _UxGT("Iniciar");
  PROGMEM Language_Str MSG_BUTTON_STOP                     = _UxGT("Parar");
  PROGMEM Language_Str MSG_BUTTON_PRINT                    = _UxGT("Imprimir");
  PROGMEM Language_Str MSG_BUTTON_RESET                    = _UxGT("Reiniciar");
  PROGMEM Language_Str MSG_BUTTON_DONE                     = _UxGT("Listo");
  PROGMEM Language_Str MSG_BUTTON_BACK                     = _UxGT("Retroceder");
  PROGMEM Language_Str MSG_BUTTON_PROCEED                  = _UxGT("Proceder");
  PROGMEM Language_Str MSG_STOP_PRINT                      = _UxGT("Detener impresión");
  PROGMEM Language_Str MSG_PRINTING_OBJECT                 = _UxGT("Imprimiendo Objeto");
  PROGMEM Language_Str MSG_CANCEL_OBJECT                   = _UxGT("Cancelar Objeto");
  PROGMEM Language_Str MSG_CANCEL_OBJECT_N                 = _UxGT("Cancelar Objeto =");
  PROGMEM Language_Str MSG_OUTAGE_RECOVERY                 = _UxGT("Rec. Fallo electrico");
  PROGMEM Language_Str MSG_MEDIA_MENU                      = _UxGT("Tarjeta Sd");
  PROGMEM Language_Str MSG_NO_MEDIA                        = _UxGT("SD/USB no presente");
  PROGMEM Language_Str MSG_DWELL                           = _UxGT("Reposo...");
  PROGMEM Language_Str MSG_USERWAIT                        = _UxGT("Pulsar para Reanudar");
  PROGMEM Language_Str MSG_PRINT_PAUSED                    = _UxGT("Impresión Pausada");
  PROGMEM Language_Str MSG_PRINTING                        = _UxGT("Imprimiendo...");
  PROGMEM Language_Str MSG_PRINT_DONE                      = _UxGT("Impresión Completada");
  PROGMEM Language_Str MSG_NO_MOVE                         = _UxGT("Sin movimiento");
  PROGMEM Language_Str MSG_KILLED                          = _UxGT("MUERTA");
  PROGMEM Language_Str MSG_STOPPED                         = _UxGT("DETENIDA");
  PROGMEM Language_Str MSG_CONTROL_RETRACT                 = _UxGT("Retraer mm");
  PROGMEM Language_Str MSG_CONTROL_RETRACT_SWAP            = _UxGT("Interc. Retraer mm");
  PROGMEM Language_Str MSG_CONTROL_RETRACTF                = _UxGT("Retraer  V");
  PROGMEM Language_Str MSG_CONTROL_RETRACT_ZHOP            = _UxGT("Levantar mm");
  PROGMEM Language_Str MSG_CONTROL_RETRACT_RECOVER         = _UxGT("DesRet mm");
  PROGMEM Language_Str MSG_CONTROL_RETRACT_RECOVER_SWAP    = _UxGT("Interc. DesRet mm");
  PROGMEM Language_Str MSG_CONTROL_RETRACT_RECOVERF        = _UxGT("DesRet V");
  PROGMEM Language_Str MSG_CONTROL_RETRACT_RECOVER_SWAPF   = _UxGT("S UnRet V");
  PROGMEM Language_Str MSG_AUTORETRACT                     = _UxGT("Retracción Auto.");
  PROGMEM Language_Str MSG_FILAMENT_SWAP_LENGTH            = _UxGT("Inter. longitud");
  PROGMEM Language_Str MSG_FILAMENT_PURGE_LENGTH           = _UxGT("Purgar longitud");
  PROGMEM Language_Str MSG_TOOL_CHANGE                     = _UxGT("Cambiar Herramienta");
  PROGMEM Language_Str MSG_TOOL_CHANGE_ZLIFT               = _UxGT("Aumentar Z");
  PROGMEM Language_Str MSG_SINGLENOZZLE_PRIME_SPEED        = _UxGT("Vel. de Cebado");
  PROGMEM Language_Str MSG_SINGLENOZZLE_RETRACT_SPEED      = _UxGT("Vel. de retracción");
  PROGMEM Language_Str MSG_FILAMENTCHANGE_E                = _UxGT("Cambiar Filamento *");
  
  PROGMEM Language_Str MSG_FILAMENTLOAD_E                  = _UxGT("Cargar Filamento *");
  
  PROGMEM Language_Str MSG_FILAMENTUNLOAD_E                = _UxGT("Descargar fil. *");
  PROGMEM Language_Str MSG_FILAMENTUNLOAD_ALL              = _UxGT("Descargar todo");
  PROGMEM Language_Str MSG_ATTACH_MEDIA                    = _UxGT("Iniciar SD/USB");
  PROGMEM Language_Str MSG_CHANGE_MEDIA                    = _UxGT("Cambiar SD/USB");
  PROGMEM Language_Str MSG_RELEASE_MEDIA                   = _UxGT("Lanzar SD/USB");
  PROGMEM Language_Str MSG_ZPROBE_OUT                      = _UxGT("Sonda Z fuera cama");
  PROGMEM Language_Str MSG_SKEW_FACTOR                     = _UxGT("Factor de desviación");
  PROGMEM Language_Str MSG_BLTOUCH                         = _UxGT("BLTouch");
  PROGMEM Language_Str MSG_BLTOUCH_SELFTEST                = _UxGT("Auto-Prueba");
  PROGMEM Language_Str MSG_BLTOUCH_RESET                   = _UxGT("Reiniciar");
  PROGMEM Language_Str MSG_BLTOUCH_STOW                    = _UxGT("Subir pistón");
  PROGMEM Language_Str MSG_BLTOUCH_DEPLOY                  = _UxGT("Bajar pistón");
  PROGMEM Language_Str MSG_BLTOUCH_SW_MODE                 = _UxGT("Modo Software");
  PROGMEM Language_Str MSG_BLTOUCH_5V_MODE                 = _UxGT("Modo 5V");
  PROGMEM Language_Str MSG_BLTOUCH_OD_MODE                 = _UxGT("Modo OD");
  PROGMEM Language_Str MSG_BLTOUCH_MODE_STORE              = _UxGT("Modo almacenar");
  PROGMEM Language_Str MSG_BLTOUCH_MODE_STORE_5V           = _UxGT("Poner BLTouch a 5V");
  PROGMEM Language_Str MSG_BLTOUCH_MODE_STORE_OD           = _UxGT("Poner BLTouch a OD");
  PROGMEM Language_Str MSG_BLTOUCH_MODE_ECHO               = _UxGT("Informe de drenaje");
  PROGMEM Language_Str MSG_BLTOUCH_MODE_CHANGE             = _UxGT("PELIGRO: ¡Una mala configuración puede producir daños! ¿Proceder igualmente?");
  PROGMEM Language_Str MSG_TOUCHMI_PROBE                   = _UxGT("TouchMI");
  PROGMEM Language_Str MSG_TOUCHMI_INIT                    = _UxGT("Iniciar TouchMI");
  PROGMEM Language_Str MSG_TOUCHMI_ZTEST                   = _UxGT("Test de desfase Z");
  PROGMEM Language_Str MSG_TOUCHMI_SAVE                    = _UxGT("Guardar");
  PROGMEM Language_Str MSG_MANUAL_DEPLOY_TOUCHMI           = _UxGT("Subir TouchMI");
  PROGMEM Language_Str MSG_MANUAL_DEPLOY                   = _UxGT("Subir Sonda Z");
  PROGMEM Language_Str MSG_MANUAL_STOW                     = _UxGT("Bajar Sonda Z");
  PROGMEM Language_Str MSG_HOME_FIRST                      = _UxGT("Origen %s%s%s Prim.");
  PROGMEM Language_Str MSG_ZPROBE_OFFSETS                  = _UxGT("Desf. Sonda");
  PROGMEM Language_Str MSG_ZPROBE_XOFFSET                  = _UxGT("Desf. Sonda X");
  PROGMEM Language_Str MSG_ZPROBE_YOFFSET                  = _UxGT("Desf. Sonda Y");
  PROGMEM Language_Str MSG_BABYSTEP_X                      = _UxGT("Micropaso X");
  PROGMEM Language_Str MSG_BABYSTEP_Y                      = _UxGT("Micropaso Y");
  PROGMEM Language_Str MSG_BABYSTEP_Z                      = _UxGT("Micropaso Z");
  PROGMEM Language_Str MSG_BABYSTEP_TOTAL                  = _UxGT("Total");
  PROGMEM Language_Str MSG_ENDSTOP_ABORT                   = _UxGT("Cancelado - Endstop");
  PROGMEM Language_Str MSG_HEATING_FAILED_LCD              = _UxGT("Calent. fallido");
  PROGMEM Language_Str MSG_ERR_REDUNDANT_TEMP              = _UxGT("Err: TEMP. REDUN.");
  PROGMEM Language_Str MSG_THERMAL_RUNAWAY                 = _UxGT("FUGA TÉRMICA");
  PROGMEM Language_Str MSG_THERMAL_RUNAWAY_BED             = _UxGT("FUGA TÉRMICA CAMA");
  PROGMEM Language_Str MSG_THERMAL_RUNAWAY_CHAMBER         = _UxGT("FUGA TÉRMICA CAMARA");
  PROGMEM Language_Str MSG_ERR_MAXTEMP                     = _UxGT("Err:TEMP. MÁX");
  PROGMEM Language_Str MSG_ERR_MINTEMP                     = _UxGT("Err:TEMP. MIN");
  PROGMEM Language_Str MSG_HALTED                          = _UxGT("IMPRESORA DETENIDA");
  PROGMEM Language_Str MSG_PLEASE_RESET                    = _UxGT("Por favor, reinicie");
  PROGMEM Language_Str MSG_SHORT_DAY                       = _UxGT("d"); // One character only
  PROGMEM Language_Str MSG_SHORT_HOUR                      = _UxGT("h"); // One character only
  PROGMEM Language_Str MSG_SHORT_MINUTE                    = _UxGT("m"); // One character only
  
  PROGMEM Language_Str MSG_COOLING                         = _UxGT("Enfriando...");
  PROGMEM Language_Str MSG_BED_HEATING                     = _UxGT("Calentando Cama...");
  PROGMEM Language_Str MSG_BED_COOLING                     = _UxGT("Enfriando Cama...");
  PROGMEM Language_Str MSG_CHAMBER_HEATING                 = _UxGT("Calentando Cámara...");
  PROGMEM Language_Str MSG_CHAMBER_COOLING                 = _UxGT("Enfriando Cámara...");
  PROGMEM Language_Str MSG_DELTA_CALIBRATE                 = _UxGT("Calibración Delta");
  PROGMEM Language_Str MSG_DELTA_CALIBRATE_X               = _UxGT("Calibrar X");
  PROGMEM Language_Str MSG_DELTA_CALIBRATE_Y               = _UxGT("Calibrar Y");
  PROGMEM Language_Str MSG_DELTA_CALIBRATE_Z               = _UxGT("Calibrar Z");
  PROGMEM Language_Str MSG_DELTA_CALIBRATE_CENTER          = _UxGT("Calibrar Centro");
  PROGMEM Language_Str MSG_DELTA_SETTINGS                  = _UxGT("Configuración Delta");
  PROGMEM Language_Str MSG_DELTA_HEIGHT_CALIBRATE          = _UxGT("Est. Altura Delta");
  PROGMEM Language_Str MSG_DELTA_Z_OFFSET_CALIBRATE        = _UxGT("Ajustar Sonda Z");
  PROGMEM Language_Str MSG_DELTA_DIAG_ROD                  = _UxGT("Barra Diagonal");
  PROGMEM Language_Str MSG_DELTA_HEIGHT                    = _UxGT("Altura");
  PROGMEM Language_Str MSG_DELTA_RADIUS                    = _UxGT("Radio");
  PROGMEM Language_Str MSG_INFO_MENU                       = _UxGT("Info. Impresora");
  PROGMEM Language_Str MSG_INFO_PRINTER_MENU               = _UxGT("Info. Impresora");
  PROGMEM Language_Str MSG_3POINT_LEVELING                 = _UxGT("Nivelando 3puntos");
  PROGMEM Language_Str MSG_LINEAR_LEVELING                 = _UxGT("Nivelando Lineal");
  PROGMEM Language_Str MSG_BILINEAR_LEVELING               = _UxGT("Nivelando Bilineal");
  PROGMEM Language_Str MSG_UBL_LEVELING                    = _UxGT("Nivelando UBL");
  PROGMEM Language_Str MSG_MESH_LEVELING                   = _UxGT("Nivelando en Mallado");
  PROGMEM Language_Str MSG_INFO_BOARD_MENU                 = _UxGT("Info. Controlador");
  PROGMEM Language_Str MSG_INFO_THERMISTOR_MENU            = _UxGT("Termistores");
  PROGMEM Language_Str MSG_INFO_EXTRUDERS                  = _UxGT("Extrusores");
  PROGMEM Language_Str MSG_INFO_BAUDRATE                   = _UxGT("Baudios");
  PROGMEM Language_Str MSG_INFO_PROTOCOL                   = _UxGT("Protocolo");
  PROGMEM Language_Str MSG_INFO_RUNAWAY_OFF                = _UxGT("Vig. Fuga Térm.: OFF");
  PROGMEM Language_Str MSG_INFO_RUNAWAY_ON                 = _UxGT("Vig. Fuga Térm.: ON");

  PROGMEM Language_Str MSG_CASE_LIGHT                      = _UxGT("Luz cabina");
  PROGMEM Language_Str MSG_CASE_LIGHT_BRIGHTNESS           = _UxGT("Brillo cabina");
  PROGMEM Language_Str MSG_KILL_EXPECTED_PRINTER           = _UxGT("Impresora incorrecta");

  #if LCD_WIDTH >= 20
    PROGMEM Language_Str MSG_INFO_PRINT_COUNT              = _UxGT("Cont. de impresión");
    PROGMEM Language_Str MSG_INFO_COMPLETED_PRINTS         = _UxGT("Completadas");
    PROGMEM Language_Str MSG_INFO_PRINT_TIME               = _UxGT("Tiempo total de imp.");
    PROGMEM Language_Str MSG_INFO_PRINT_LONGEST            = _UxGT("Impresión más larga");
    PROGMEM Language_Str MSG_INFO_PRINT_FILAMENT           = _UxGT("Total Extruido");
  #else
    PROGMEM Language_Str MSG_INFO_PRINT_COUNT              = _UxGT("Impresiones");
    PROGMEM Language_Str MSG_INFO_COMPLETED_PRINTS         = _UxGT("Completadas");
    PROGMEM Language_Str MSG_INFO_PRINT_TIME               = _UxGT("Total");
    PROGMEM Language_Str MSG_INFO_PRINT_LONGEST            = _UxGT("Más larga");
    PROGMEM Language_Str MSG_INFO_PRINT_FILAMENT           = _UxGT("Extruido");
  #endif

  PROGMEM Language_Str MSG_INFO_MIN_TEMP                   = _UxGT("Temp. Mínima");
  PROGMEM Language_Str MSG_INFO_MAX_TEMP                   = _UxGT("Temp. Máxima");
  PROGMEM Language_Str MSG_INFO_PSU                        = _UxGT("F. Aliment.");
  PROGMEM Language_Str MSG_DRIVE_STRENGTH                  = _UxGT("Fuerza de empuje");
  PROGMEM Language_Str MSG_DAC_PERCENT_X                   = _UxGT("X Driver %");
  PROGMEM Language_Str MSG_DAC_PERCENT_Y                   = _UxGT("Y Driver %");
  PROGMEM Language_Str MSG_DAC_PERCENT_Z                   = _UxGT("Z Driver %");
  PROGMEM Language_Str MSG_DAC_PERCENT_E                   = _UxGT("E Driver %");
  PROGMEM Language_Str MSG_ERROR_TMC                       = _UxGT("ERROR CONEX. TMC");
  PROGMEM Language_Str MSG_DAC_EEPROM_WRITE                = _UxGT("Escribe DAC EEPROM");
  PROGMEM Language_Str MSG_FILAMENT_CHANGE_HEADER          = _UxGT("CAMBIAR FILAMENTO");
  PROGMEM Language_Str MSG_FILAMENT_CHANGE_HEADER_PAUSE    = _UxGT("IMPRESIÓN PAUSADA");
  PROGMEM Language_Str MSG_FILAMENT_CHANGE_HEADER_LOAD     = _UxGT("CARGAR FILAMENTO");
  PROGMEM Language_Str MSG_FILAMENT_CHANGE_HEADER_UNLOAD   = _UxGT("DESCARGAR FILAMENTO");
  PROGMEM Language_Str MSG_FILAMENT_CHANGE_OPTION_HEADER   = _UxGT("OPC. REINICIO:");
  PROGMEM Language_Str MSG_FILAMENT_CHANGE_OPTION_PURGE    = _UxGT("Purgar más");
  PROGMEM Language_Str MSG_FILAMENT_CHANGE_OPTION_RESUME   = _UxGT("Continuar imp.");
  PROGMEM Language_Str MSG_FILAMENT_CHANGE_NOZZLE          = _UxGT("  Boquilla: ");
  PROGMEM Language_Str MSG_RUNOUT_DISTANCE_MM              = _UxGT("Dist. filamento mm");
  PROGMEM Language_Str MSG_KILL_HOMING_FAILED              = _UxGT("Ir a origen Fallado");
  PROGMEM Language_Str MSG_LCD_PROBING_FAILED              = _UxGT("Sondeo Fallado");

  PROGMEM Language_Str MSG_MMU2_CHOOSE_FILAMENT_HEADER     = _UxGT("ELIJE FILAMENTO");
  PROGMEM Language_Str MSG_MMU2_MENU                       = _UxGT("MMU");
  PROGMEM Language_Str MSG_KILL_MMU2_FIRMWARE              = _UxGT("¡Actu. MMU Firmware!");
  PROGMEM Language_Str MSG_MMU2_NOT_RESPONDING             = _UxGT("MMU Necesita Cuidado");
  PROGMEM Language_Str MSG_MMU2_RESUME                     = _UxGT("Continuar imp.");
  PROGMEM Language_Str MSG_MMU2_RESUMING                   = _UxGT("Resumiendo...");
  PROGMEM Language_Str MSG_MMU2_LOAD_FILAMENT              = _UxGT("Cargar Filamento");
  PROGMEM Language_Str MSG_MMU2_LOAD_ALL                   = _UxGT("Cargar Todo");
  PROGMEM Language_Str MSG_MMU2_LOAD_TO_NOZZLE             = _UxGT("Cargar hasta boqui.");
  PROGMEM Language_Str MSG_MMU2_EJECT_FILAMENT             = _UxGT("Expulsar Filamento");
  PROGMEM Language_Str MSG_MMU2_EJECT_FILAMENT_N           = _UxGT("Expulsar Filamento ~");
  PROGMEM Language_Str MSG_MMU2_UNLOAD_FILAMENT            = _UxGT("Descargar Filamento");
  PROGMEM Language_Str MSG_MMU2_LOADING_FILAMENT           = _UxGT("Cargando Fil. %i...");
  PROGMEM Language_Str MSG_MMU2_EJECTING_FILAMENT          = _UxGT("Expulsando Fil. ...");
  PROGMEM Language_Str MSG_MMU2_UNLOADING_FILAMENT         = _UxGT("Descargando Fil....");
  PROGMEM Language_Str MSG_MMU2_ALL                        = _UxGT("Todo");
  PROGMEM Language_Str MSG_MMU2_FILAMENT_N                 = _UxGT("Filamento ~");
  PROGMEM Language_Str MSG_MMU2_RESET                      = _UxGT("Reiniciar MMU");
  PROGMEM Language_Str MSG_MMU2_RESETTING                  = _UxGT("Reiniciando MMU...");
  PROGMEM Language_Str MSG_MMU2_EJECT_RECOVER              = _UxGT("Retirar, y pulsar");

  PROGMEM Language_Str MSG_MIX                             = _UxGT("Mezcla");
  PROGMEM Language_Str MSG_MIX_COMPONENT_N                 = _UxGT("Componente =");
  PROGMEM Language_Str MSG_MIXER                           = _UxGT("Miezclador");
  PROGMEM Language_Str MSG_GRADIENT                        = _UxGT("Degradado");
  PROGMEM Language_Str MSG_FULL_GRADIENT                   = _UxGT("Degradado Total");
  PROGMEM Language_Str MSG_TOGGLE_MIX                      = _UxGT("Mezcla Conmutada");
  PROGMEM Language_Str MSG_CYCLE_MIX                       = _UxGT("Mezcla Cíclica");
  PROGMEM Language_Str MSG_GRADIENT_MIX                    = _UxGT("Mezcla de Degradado");
  PROGMEM Language_Str MSG_REVERSE_GRADIENT                = _UxGT("Degradado inverso");
  PROGMEM Language_Str MSG_ACTIVE_VTOOL                    = _UxGT("Activar Herr.V");
  PROGMEM Language_Str MSG_START_VTOOL                     = _UxGT("Inicio Herr.V");
  PROGMEM Language_Str MSG_END_VTOOL                       = _UxGT("   Fin Herr.V");
  PROGMEM Language_Str MSG_GRADIENT_ALIAS                  = _UxGT("Alias Herr.V");
  PROGMEM Language_Str MSG_RESET_VTOOLS                    = _UxGT("Reiniciar Herr.V");
  PROGMEM Language_Str MSG_COMMIT_VTOOL                    = _UxGT("Cometer mezc. Herr.V");
  PROGMEM Language_Str MSG_VTOOLS_RESET                    = _UxGT("Herr.V reiniciados");
  PROGMEM Language_Str MSG_START_Z                         = _UxGT("Inicio Z:");
  PROGMEM Language_Str MSG_END_Z                           = _UxGT("   Fin Z:");

  PROGMEM Language_Str MSG_GAMES                           = _UxGT("Juegos");
  PROGMEM Language_Str MSG_BRICKOUT                        = _UxGT("Brickout");
  PROGMEM Language_Str MSG_INVADERS                        = _UxGT("Invaders");
  PROGMEM Language_Str MSG_SNAKE                           = _UxGT("Sn4k3");
  PROGMEM Language_Str MSG_MAZE                            = _UxGT("Maze");

  #if LCD_HEIGHT >= 4
    PROGMEM Language_Str MSG_ADVANCED_PAUSE_WAITING        = _UxGT(MSG_2_LINE("Pulsar el botón para", "reanudar impresión"));
    PROGMEM Language_Str MSG_PAUSE_PRINT_PARKING           = _UxGT(MSG_1_LINE("Aparcando..."));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_INIT          = _UxGT(MSG_3_LINE("Esperando para", "iniciar el cambio", "de filamento"));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_INSERT        = _UxGT(MSG_3_LINE("Inserte el filamento", "y pulse el botón", "para continuar..."));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_HEAT          = _UxGT(MSG_2_LINE("Pulse el botón para", "calentar la boquilla"));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_HEATING       = _UxGT(MSG_2_LINE("Calentando boquilla", "Espere por favor..."));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_UNLOAD        = _UxGT(MSG_2_LINE("Espere para", "liberar el filamento"));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_LOAD          = _UxGT(MSG_2_LINE("Espere para", "cargar el filamento"));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_PURGE         = _UxGT(MSG_2_LINE("Espere para", "purgar el filamento"));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_CONT_PURGE    = _UxGT(MSG_2_LINE("Pulse para finalizar", "la purga de filamen."));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_RESUME        = _UxGT(MSG_2_LINE("Esperando impresora", "para reanudar..."));
  #else
    PROGMEM Language_Str MSG_ADVANCED_PAUSE_WAITING        = _UxGT(MSG_1_LINE("Pulse para continuar"));
    PROGMEM Language_Str MSG_PAUSE_PRINT_PARKING           = _UxGT(MSG_1_LINE("Aparcando..."));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_INIT          = _UxGT(MSG_1_LINE("Por Favor espere..."));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_INSERT        = _UxGT(MSG_1_LINE("Inserte y Pulse"));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_HEAT          = _UxGT(MSG_1_LINE("Pulse para Calentar"));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_HEATING       = _UxGT(MSG_1_LINE("Calentando..."));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_UNLOAD        = _UxGT(MSG_1_LINE("Liberando..."));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_LOAD          = _UxGT(MSG_1_LINE("Cargando..."));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_PURGE         = _UxGT(MSG_1_LINE("Purgando..."));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_CONT_PURGE    = _UxGT(MSG_1_LINE("Pulse para finalizar"));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_RESUME        = _UxGT(MSG_1_LINE("Reanudando..."));
  #endif
  PROGMEM Language_Str MSG_TMC_DRIVERS                     = _UxGT("Controladores TMC");
  PROGMEM Language_Str MSG_TMC_CURRENT                     = _UxGT("Amperaje Controlador");
  PROGMEM Language_Str MSG_TMC_HYBRID_THRS                 = _UxGT("Límite Hibrido");
  PROGMEM Language_Str MSG_TMC_HOMING_THRS                 = _UxGT("Origen sin sensores");
  PROGMEM Language_Str MSG_TMC_STEPPING_MODE               = _UxGT("Modo de pasos");
  PROGMEM Language_Str MSG_TMC_STEALTH_ENABLED             = _UxGT("StealthChop Habilit.");
  PROGMEM Language_Str MSG_SERVICE_IN                      = _UxGT(" dentro:");
  PROGMEM Language_Str MSG_BACKLASH                        = _UxGT("Backlash");
  PROGMEM Language_Str MSG_BACKLASH_A                      = LCD_STR_A;
  PROGMEM Language_Str MSG_BACKLASH_B                      = LCD_STR_B;
  PROGMEM Language_Str MSG_BACKLASH_C                      = LCD_STR_C;
  PROGMEM Language_Str MSG_BACKLASH_CORRECTION             = _UxGT("Corrección");
  PROGMEM Language_Str MSG_BACKLASH_SMOOTHING              = _UxGT("Suavizado");


  //Palabras agregadas para el menu de kuttercraft
  ////////////////////////////////////////////////
  PROGMEM Language_Str MSG_HEATER_TIMEOUT                  = _UxGT("T. de esp. Calent.");
  PROGMEM Language_Str MSG_REHEAT                          = _UxGT("Recalentar");
  PROGMEM Language_Str MSG_REHEATING                       = _UxGT("Recalentando...");

  PROGMEM Language_Str MSG_PAUSE_PRINT                     = _UxGT("Pausar impresión");
  PROGMEM Language_Str MSG_PRINT_ABORTED                   = _UxGT("Impresión cancelada");
  PROGMEM Language_Str MSG_PRINT_CANCELAR                  = _UxGT("Cancelar Impresión");
  PROGMEM Language_Str MSG_PRINT_CANCELANDO                = _UxGT("Cancelando Impresión");
  PROGMEM Language_Str MSG_VELOCITY                        = _UxGT("Velocidad");
  PROGMEM Language_Str MSG_VELOCITY_MENU                   = _UxGT("Cambiar Velocidad");
  PROGMEM Language_Str MSG_RESET_PRINTER                   = _UxGT("Reiniciar Impresora");

  PROGMEM Language_Str MSG_SELECT                          = _UxGT("Seleccione");
  PROGMEM Language_Str MSG_SELECT_E                        = _UxGT("Seleccionar *");
  PROGMEM Language_Str MSG_TEMPERATURE                     = _UxGT("Temperatura");
  PROGMEM Language_Str MSG_LA_TEMPERATURE                  = _UxGT("La Temperatura");
  PROGMEM Language_Str MSG_FLOW_MENU                       = _UxGT("Modificar Flujo");
  
  PROGMEM Language_Str MSG_SALIR                           = _UxGT("Salir");
  PROGMEM Language_Str MSG_VOLVER                          = _UxGT("Volver");

  PROGMEM Language_Str MSG_MANUALES                        = _UxGT("Manuales");
  PROGMEM Language_Str MSG_PREDETERMINADO                  = _UxGT("Predeterminado");
  PROGMEM Language_Str MSG_PRESET                          = _UxGT("Preset");
  PROGMEM Language_Str MSG_PRESET_PLA                      = _UxGT("Preset PLA");
  PROGMEM Language_Str MSG_PRESET_ABS                      = _UxGT("Preset ABS");
  PROGMEM Language_Str MSG_PRESET_FLEX                     = _UxGT("Preset FLEX");
  PROGMEM Language_Str MSG_PRESET_NYLON                    = _UxGT("Preset NYLON");
  
  PROGMEM Language_Str MSG_HEATING                         = _UxGT("Calentando...");
  PROGMEM Language_Str MSG_POR_FAVOR_ESPERE                = _UxGT("Por Favor Espere");

  PROGMEM Language_Str MSG_FILAMENTCHANGE                  = _UxGT("Cambiar Filamento");
  PROGMEM Language_Str MSG_FILAMENTLOAD                    = _UxGT("Cargar Filamento");
  PROGMEM Language_Str MSG_CARGANDO_FILAMENTO              = _UxGT("Cargando Filamento");
  PROGMEM Language_Str MSG_FILAMENTUNLOAD                  = _UxGT("Retirar Filamento");
  PROGMEM Language_Str MSG_RETIRANDO_FILAMENTO             = _UxGT("Retirando Filamento");
  PROGMEM Language_Str MSG_RESUME_PRINT                    = _UxGT("Reanudar Impresión");

  PROGMEM Language_Str MSG_NOZZLE                          = _UxGT("Boquilla");
  PROGMEM Language_Str MSG_BED                             = _UxGT("Cama");
  PROGMEM Language_Str MSG_BED_HOT                         = _UxGT("Cama Caliente");
  PROGMEM Language_Str MSG_FAN_SPEED                       = _UxGT("Ventilador");
  PROGMEM Language_Str MSG_COOLDOWN                        = _UxGT("Enfriar");

  PROGMEM Language_Str MSG_LED_CONTROL                     = _UxGT("Encender LED");
  PROGMEM Language_Str MSG_LED_APAGAR                      = _UxGT("Apagar LED");

  PROGMEM Language_Str MSG_CAMBIAR_VERSION                 = _UxGT("Cambiar Version");//"Cambiar Version"
  PROGMEM Language_Str MSG_BORRAR_ESTADISTICAS             = _UxGT("Borrar Estadistica");//Borrar Estadistica"
  
  //movimiento
  PROGMEM Language_Str MSG_MOVE_AXIS                       = _UxGT("Mover Ejes");
  PROGMEM Language_Str MSG_AUTO_HOME                       = _UxGT("Llevar Al Origen");
  PROGMEM Language_Str MSG_AUTO_HOME_ACTION                = _UxGT("Llevando Al Origen");
  PROGMEM Language_Str MSG_MOVE_X                          = _UxGT("Mover X");
  PROGMEM Language_Str MSG_MOVE_Y                          = _UxGT("Mover Y");
  PROGMEM Language_Str MSG_MOVE_Z                          = _UxGT("Mover Z");
  PROGMEM Language_Str MSG_MOVE_Z_DIST                     = _UxGT("Mover %smm");
  PROGMEM Language_Str MSG_MOVE_01MM                       = _UxGT("Mover 0.1mm");
  PROGMEM Language_Str MSG_MOVE_1MM                        = _UxGT("Mover 1mm");
  PROGMEM Language_Str MSG_MOVE_10MM                       = _UxGT("Mover 5mm");
  PROGMEM Language_Str MSG_AUTO_HOME_X                     = _UxGT("Origen X");
  PROGMEM Language_Str MSG_AUTO_HOME_Y                     = _UxGT("Origen Y"); 
  PROGMEM Language_Str MSG_AUTO_HOME_Z                     = _UxGT("Origen Z");
  PROGMEM Language_Str MSG_LEVEL_BED_HOMING                = _UxGT("Origen XYZ");
  PROGMEM Language_Str MSG_PROBING_MESH                    = _UxGT("Midiendo Punto");

  //Calicracion
  PROGMEM Language_Str MSG_LEVEL_X_AXIS                    = _UxGT("Nivel Eje X");
  PROGMEM Language_Str MSG_CALIBRATE                       = _UxGT("Calibrar");
  PROGMEM Language_Str MSG_CALIBRAR_OFFSET                 = _UxGT("Calibrar Offset");
  PROGMEM Language_Str MSG_CALIBRAR_CAMA                   = _UxGT("Calibrar Cama");
  PROGMEM Language_Str MSG_MODIFICAR_OFFSET                = _UxGT("Modificar Offset");
  PROGMEM Language_Str MSG_ALINEAR_Z                       = _UxGT("Alineando Eje Z");
  PROGMEM Language_Str MSG_POSICIONADO_Z                   = _UxGT("Posicionando Eje Z");
  PROGMEM Language_Str MSG_MAPA_CAMA                       = _UxGT("Mapa De Cama");
  PROGMEM Language_Str MSG_SUBIR_BAJAR                     = _UxGT("Subir Y Bajar Eje");

  PROGMEM Language_Str MSG_MAPA_CAMA_COMPLETAR             = _UxGT("Completar Mapa");
  PROGMEM Language_Str MSG_MAPA_CAMA_EDITAR                = _UxGT("Editar Mapa De Cama");
  PROGMEM Language_Str MSG_MAPA_CAMA_CALIBRAR              = _UxGT("Calibrar Mapa De Cama");

  PROGMEM Language_Str MSG_CALIBRATE_MANUAL                = _UxGT("Calibracion Manual");
  PROGMEM Language_Str MSG_AUTO_CALIBRATE                  = _UxGT("Calibracion Auto.");
  PROGMEM Language_Str MSG_CALIBRANDO                      = _UxGT("Calibrando");
  PROGMEM Language_Str MSG_AUTO_Z_ALIGN                    = _UxGT("Calibrando Altura Eje");
  PROGMEM Language_Str MSG_SUBIENDO_EJE                    = _UxGT("Subiendo Eje Z");
  PROGMEM Language_Str MSG_ZPROBE_ZOFFSET                  = _UxGT("Offset Z:");

  PROGMEM Language_Str MSG_ALINIACION_Z_ADV_01             = _UxGT("Advertencia el Eje Z");
  PROGMEM Language_Str MSG_ALINIACION_Z_ADV_02             = _UxGT("va  a colisionar con");
  PROGMEM Language_Str MSG_ALINIACION_Z_ADV_03             = _UxGT("la parte superion");
  PROGMEM Language_Str MSG_ALINIACION_Z_ADV_04             = _UxGT("los motores vibraran");

  //STORE
  PROGMEM Language_Str MSG_STORE                           = _UxGT("Kuttercraft Store");
  PROGMEM Language_Str MSG_STORE_WEB                       = _UxGT("kuttercraft.com/store");

  PROGMEM Language_Str MSG_VERCION                         = _UxGT("Versión");
  PROGMEM Language_Str MSG_INFO_STATS_MENU                 = _UxGT("Estadísticas");
  PROGMEM Language_Str MSG_LOGROS                          = _UxGT("Logros");

  PROGMEM Language_Str MSG_IDIOMA                          = _UxGT("Idioma           [ES");

  PROGMEM Language_Str MSG_DELTA_AUTO_CALIBRATE_ON         = _UxGT("Auto Calibración [ON");
  PROGMEM Language_Str MSG_DELTA_AUTO_CALIBRATE_OFF        = _UxGT("Auto Calibración[OFF");

  PROGMEM Language_Str MSG_INFORMACION_COORD               = _UxGT("Información   [Coord");
  PROGMEM Language_Str MSG_INFORMACION_CAPAS               = _UxGT("Información   [Capas");

  PROGMEM Language_Str MSG_SENSOR_INDUCTIVO                = _UxGT("Sensor    [Inductivo");
  PROGMEM Language_Str MSG_FINAL_DE_CARRERA                = _UxGT("Sensor      [Endstop");

  PROGMEM Language_Str MSG_TIPO_EXTRU_BMG                  = _UxGT("Extrusor        [BMG");
  PROGMEM Language_Str MSG_TIPO_EXTRU_MK8                  = _UxGT("Extrusor        [MK8");

  PROGMEM Language_Str MSG_GUARDADO_ON                     = _UxGT("Guardado         [ON");
  PROGMEM Language_Str MSG_GUARDADO_OFF                    = _UxGT("Guardado        [OFF");

  PROGMEM Language_Str MSG_RUNOUT_SENSOR_ON                = _UxGT("Sens. Filamento  [ON");
  PROGMEM Language_Str MSG_RUNOUT_SENSOR_OFF               = _UxGT("Sens. Filamento [OFF");

  PROGMEM Language_Str MSG_ENCODER_ON                      = _UxGT("Encoder         [IZD");
  PROGMEM Language_Str MSG_ENCODER_OFF                     = _UxGT("Encoder         [DER");

  PROGMEM Language_Str MSG_VARILLA_8MM                     = _UxGT("Paso Varrilla   [8mm");
  PROGMEM Language_Str MSG_VARILLA_4MM                     = _UxGT("Paso Varrilla   [4mm");

  PROGMEM Language_Str MSG_KUTTERMELODY_ON                 = _UxGT("Kuttermelody     [ON");
  PROGMEM Language_Str MSG_KUTTERMELODY_OFF                = _UxGT("Kuttermelody    [OFF");

  PROGMEM Language_Str MSG_TMC2130_CONFI                   = _UxGT("TMC Configuracion");

  PROGMEM Language_Str MSG_PID_AUTOTUNE                    = _UxGT("Ajustar PID");
  PROGMEM Language_Str MSG_CONFIG_FABRICA                  = _UxGT("Config. Fabrica");
  PROGMEM Language_Str MSG_ENVIAR_GCODE                    = _UxGT("Enviar Gcode");
  PROGMEM Language_Str MSG_SISTEMA                         = _UxGT("Sistema");
  PROGMEM Language_Str MSG_SERIE                           = _UxGT("Serie:");
  PROGMEM Language_Str MSG_INDUSTRIA                       = _UxGT("INDUSTRIA ARGENTINA");
  PROGMEM Language_Str MSG_VER_VERSION                     = _UxGT("Versión:");
  PROGMEM Language_Str MSG_VER_MODELO                      = _UxGT("Modelo:");

  //Promociones o descuentos
  PROGMEM Language_Str MSG_FILAMENTO_USADO                 = _UxGT("Filamento Usado");
  PROGMEM Language_Str MSG_KILOMETRO                       = _UxGT("Kilometros:");
  PROGMEM Language_Str MSG_METRO                           = _UxGT("Metros:");
  PROGMEM Language_Str MSG_CENTIMETRO                      = _UxGT("Centimetros:");
  PROGMEM Language_Str MSG_TIEMPO_DE_IMPRESION             = _UxGT("Tiempo De Impresion");
  PROGMEM Language_Str MSG_TIEMPO_YEAR                     = _UxGT("Años:");
  PROGMEM Language_Str MSG_TIEMPO_DIAS                     = _UxGT("Días:");
  PROGMEM Language_Str MSG_TIEMPO_HORAS                    = _UxGT("Horas:");
  PROGMEM Language_Str MSG_TIEMPO_MINUTOS                  = _UxGT("Minutos:");
  PROGMEM Language_Str MSG_IMPRESIONES                     = _UxGT("Impresiones");
  PROGMEM Language_Str MSG_TOTAL                           = _UxGT("Total:");
  PROGMEM Language_Str MSG_TERMINADAS                      = _UxGT("Terminadas:");
  PROGMEM Language_Str MSG_INCOMPLETAS                     = _UxGT("Incompletas:");
  PROGMEM Language_Str MSG_NO_LOGROS                       = _UxGT("No Hay Logros");
  PROGMEM Language_Str MSG_TU_PUEDES                       = _UxGT("Sigue Intentándo");
  PROGMEM Language_Str MSG_LOGRO_OBT                       = _UxGT("Logro Obtenido");
  PROGMEM Language_Str MSG_HAZ_IMPRESO                     = _UxGT("Haz Impreso Tus");
  PROGMEM Language_Str MSG_FELICITACIONES                  = _UxGT("Felicitaciones!!!");
  PROGMEM Language_Str MSG_CUPON_DE                        = _UxGT("Cupon De");
  PROGMEM Language_Str MSG_DESCUENTO                       = _UxGT("Descuento");
  PROGMEM Language_Str MSG_WEB_PROMO                       = _UxGT("kuttercraft.com/promo");
  PROGMEM Language_Str MSG_VER_CONDICIONES                 = _UxGT("Ver Condiciones En:");

  PROGMEM Language_Str MSG_BUTTON_ACEPTAR                  = _UxGT("Aceptar");
  PROGMEM Language_Str MSG_BUTTON_CANCEL                   = _UxGT("Cancelar");
  PROGMEM Language_Str MSG_BUTTON_ADVERTENCIA              = _UxGT("Advertencia");

  //alerta de carteles
  //PROGMEM Language_Str MSG_CARTEL_AUTOLEVEL_01             = _UxGT("[OFF]Use Endstop Z");
  //PROGMEM Language_Str MSG_CARTEL_AUTOLEVEL_02             = _UxGT("Para calibrar");
  //PROGMEM Language_Str MSG_CARTEL_AUTOLEVEL_03             = _UxGT("[ON]Cuidado Endstop Z");
  //PROGMEM Language_Str MSG_CARTEL_AUTOLEVEL_04             = _UxGT("No debe activarse");

  PROGMEM Language_Str MSG_CARTEL_AUTOLEVEL_01             = _UxGT("Se Dejará De Usar");
  PROGMEM Language_Str MSG_CARTEL_AUTOLEVEL_02             = _UxGT("El Mapa De Cama");
  PROGMEM Language_Str MSG_CARTEL_AUTOLEVEL_03             = _UxGT("El Mapa De Cama");
  PROGMEM Language_Str MSG_CARTEL_AUTOLEVEL_04             = _UxGT("Corregira Las Alturas");

  PROGMEM Language_Str MSG_NO_SE_USARA                     = _UxGT("No Se Usara El");
  PROGMEM Language_Str MSG_MAPEO_CAMA                      = _UxGT("Mapeo De Cama");
  PROGMEM Language_Str MSG_SE_USARA                        = _UxGT("Se Usara El");

  PROGMEM Language_Str MSG_CARTEL_SENSOR_01                = _UxGT("Desactivar Sensor");
  PROGMEM Language_Str MSG_CARTEL_SENSOR_02                = _UxGT("De Filamento");
  PROGMEM Language_Str MSG_CARTEL_SENSOR_03                = _UxGT("Activar Sensor");
  PROGMEM Language_Str MSG_CARTEL_SENSOR_04                = _UxGT("Pausara La Maquina");

  PROGMEM Language_Str MSG_CARTEL_ENDSTOP_01               = _UxGT("Dejará De Medir Con");
  PROGMEM Language_Str MSG_CARTEL_ENDSTOP_02               = _UxGT("El Sensor Inductivo");
  PROGMEM Language_Str MSG_CARTEL_ENDSTOP_03               = _UxGT("Cuidado Endstop Z");
  PROGMEM Language_Str MSG_CARTEL_ENDSTOP_04               = _UxGT("No debe activarse");

  PROGMEM Language_Str MSG_CARTEL_EPROM_01                 = _UxGT("Restablecer");
  PROGMEM Language_Str MSG_CARTEL_EPROM_02                 = _UxGT("Reiniciar Seteos Fabr");
  PROGMEM Language_Str MSG_CARTEL_EPROM_03                 = _UxGT("Sera Permanente");

  PROGMEM Language_Str MSG_NO_DISPONIBLE                   = _UxGT("Opcione No Disponible");
  PROGMEM Language_Str MSG_SERA_AGREGADO                   = _UxGT("Sera Agregado En");
  PROGMEM Language_Str MSG_FUTURA_ACTUALIZACION            = _UxGT("Futura Actualización");




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  PROGMEM Language_Str MSG_LOGRO_PZ                        = _UxGT("Logros Por Piezas");
  PROGMEM Language_Str MSG_LOGRO_KM                        = _UxGT("Logros Por Km");
  
  //Lista De Logros
  

  //logros____descuentos__
  PROGMEM Language_Str MSG_EN_FILAMENTO                    = _UxGT("En Filamento");
  PROGMEM Language_Str MSG_EN_RESPUESTOS                   = _UxGT("En Respuestos");
  PROGMEM Language_Str MSG_EN_INSUMOS                      = _UxGT("En Insumos");
  PROGMEM Language_Str MSG_EN_MAQUINAS                     = _UxGT("En Maquinas");
  PROGMEM Language_Str MSG_EN_NUESTRA_TIENDA               = _UxGT("En Nuestra Tienda");
  PROGMEM Language_Str MSG_SERVICIO_TECNICO                = _UxGT("Servicio Tecnico");
  PROGMEM Language_Str MSG_UN_ENVIO_GRATIS                 = _UxGT("Un Envio Gratis!!!");
  PROGMEM Language_Str MSG_EN_GRILON3                      = _UxGT("En GriloN3");
  PROGMEM Language_Str MSG_EN_BOQUILLAS                    = _UxGT("En Boquillas");

  PROGMEM Language_Str MSG_GUARDAR_CONFI                   = _UxGT("Guardar Confi."); 
  PROGMEM Language_Str MSG_GUARDAR_CONFI_0                 = _UxGT("Se Ha Guardado"); 
  PROGMEM Language_Str MSG_GUARDAR_CONFI_1                 = _UxGT("Correctamente"); //click para salir
  PROGMEM Language_Str MSG_CLICK_PARA_SALIR                = _UxGT("Click Para Salir");

  PROGMEM Language_Str MSG_ERROR_SENSOR_IND_0              = _UxGT("Error: No Se Puede");//Error no se puede 
  PROGMEM Language_Str MSG_ERROR_SENSOR_IND_1              = _UxGT("Apagar El Sensor");
  PROGMEM Language_Str MSG_ERROR_SENSOR_IND_2              = _UxGT("Auto Calibración:ON");


  
}
