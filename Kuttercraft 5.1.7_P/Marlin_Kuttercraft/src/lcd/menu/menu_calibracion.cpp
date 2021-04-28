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
#include "menu_calibracion.h"

#include "../../module/motion.h"
#include "../../feature/babystep.h"
#include "../../module/planner.h"
#include "../../MarlinCore.h"
#include "../../feature/tmc_util.h"

#include "menu.h"
#include "../dogm/ultralcd_DOGM.h"
#include "../mapa_bit/bitmap_kuttercraft.h"
#include "../../module/settings.h"
#include "../../module/probe.h"
#include "../../module/endstops.h"

#include "../../gcode/gcode.h"
#include "../../gcode/queue.h"
#include "../../feature/bedlevel/bedlevel.h"


//constructores de menu
void init_boto(int medida_boton_, int espaciado_, int cantidad_, int altura_, int columna_bit_ = 3);
void crear_boton(const u8g_pgm_uint8_t* img_mapa_bit, const u8g_pgm_uint8_t* img_mapa_bit_2, PGM_P utf8_str_P, screenFunc_t screen, const uint16_t encoder = 0);
void opciones_no_disponible(screenFunc_t screen, const uint16_t encoder = 0);
void crear_marco_superior(PGM_P utf8_str_P, int altura = 0, int largo = 9);
void crear_texto_centrado(PGM_P utf8_str_P, int altura = 0);
void crear_espera();
void removeSpacesInPlace(char* str);

//SALIDA
void menu_main();
void menu_calibracion_auto();

//gcode.process_subcommands_now(ubl_lcd_gcode);
//los mapa de calibracion no se activan de forma automatica hay que hacer que sea asi

//////////////////////////////
//Inicio de Auto calibracion//
//////////////////////////////
bool solo_calibracion = true;
//genera un nuevo mapa de calibracion
//con el valor del offset actual
//y lo guarda en memoria
void auto_calibracion_espera(){
    //NO se vuelve al status y se sigue actualizando
    MarlinUI::defer_return_to_status = true;
    MarlinUI::lcdDrawUpdate = LCDVIEW_CALL_REDRAW_NEXT;
    
    crear_texto_centrado(Language_es::MSG_CALIBRANDO, 20);

    crear_marco_superior(PSTR(MarlinUI::contenedor_str), 53, 11);

    //crea la barra de espera
    crear_espera();

    if(MarlinUI::salida_de_menu){
        //completa el ultimo punto
        unified_bed_leveling::completar_mapa();
        queue.inject_P(PSTR("G29 A\nM420 S1\nM500"));
        
        if(solo_calibracion){
            MarlinUI::goto_screen(menu_calibracion_auto, 3);
        }else{
            solo_calibracion = true;
            MarlinUI::goto_screen(menu_calibracion_auto, 1);
        }
    }
    
}
void auto_calibracion(){
    MarlinUI::contenedor_str[0] = '\0';
    MarlinUI::salida_de_menu = false;
    strcpy(MarlinUI::contenedor_str, GET_TEXT(MSG_AUTO_HOME_ACTION));

    queue.inject_P(PSTR("G28\nG29 P1"));
    MarlinUI::goto_screen(auto_calibracion_espera);
}
///////////////////////////
//Fin de Auto calibracion//
///////////////////////////

/////////////////////////////
//Inicio de calibrar offset//
/////////////////////////////
void menu_calibracion_();
void mover_eje_z() {
  //NO se vuelve al status y se sigue actualizando
  MarlinUI::defer_return_to_status = true;
  MarlinUI::lcdDrawUpdate = LCDVIEW_CALL_REDRAW_NEXT;

  if (ui.encoderPosition && !ui.manual_move.processing) {
    
    float min, max;
    soft_endstop.get_manual_axis_limits(Z_AXIS, min, max);

    const float diff = float(int32_t(ui.encoderPosition)) * ui.manual_move.menu_scale;


    current_position[Z_AXIS] += diff;
    if (int32_t(ui.encoderPosition) < 0)
      NOLESS(current_position[Z_AXIS], -5);
    else
      NOMORE(current_position[Z_AXIS], 5);

    ui.manual_move.soon(Z_AXIS);
  }
  
  ui.encoderPosition = 0;

  if (ui.should_draw()) {
    const float pos = NATIVE_TO_LOGICAL(
      ui.manual_move.processing ? destination[Z_AXIS] : current_position[Z_AXIS] + TERN0(IS_KINEMATIC, ui.manual_move.offset),
      Z_AXIS
    );
      MenuEditItemBase::draw_edit_screen(GET_TEXT(MSG_MOVE_Z), ui.manual_move.menu_scale >= 0.1f ? ftostr41sign(pos) : ftostr63(pos));
  }

  if (ui.use_click()){
    MarlinUI::contenedor_str[0] = '\0'; //vacia la lista
    //cambia el valor de offset
    // y lo guarda
    
    //strcpy(MarlinUI::contenedor_str, "M851 Z");
    //strcat(MarlinUI::contenedor_str, ftostr63(current_position[Z_AXIS]));
    //strcat(MarlinUI::contenedor_str, "M500\n");

    probe.offset.z = current_position[Z_AXIS];
    
    (void)settings.save();
    (void)settings.load();
    
    queue.inject_P(PSTR(MarlinUI::contenedor_str));

    
    
    if(planner.leveling_active){
        MarlinUI::goto_screen(auto_calibracion, 1);
    }else{
        
        queue.inject_P(PSTR("G1 Z5"));
        MarlinUI::goto_screen(menu_calibracion_, 1);
    }

  }
}

void espera_posicion_offset(){
    //NO se vuelve al status y se sigue actualizando
    MarlinUI::defer_return_to_status = true;
    MarlinUI::lcdDrawUpdate = LCDVIEW_CALL_REDRAW_NEXT;

    crear_texto_centrado(Language_es::MSG_AUTO_HOME_ACTION, 20);
    //crea la barra de espera
    crear_espera();

    if(current_position[Z_AXIS] == 0){
        MarlinUI::goto_screen(mover_eje_z, 1);
    }

}
void calibrar_offset(){
    //Este Comando deveria depender del offset
    //arreglar en el futuro
    solo_calibracion = false;
    queue.inject_P(PSTR("M851 Z0\nG28\nG1 Z0"));//\nG91\nG1 X44 Y-44 Z1 F1500\nG90
    ui.manual_move.menu_scale = 0.025;
    MarlinUI::goto_screen(espera_posicion_offset, 1);
}
//////////////////////////
//Fin de calibrar offset//
//////////////////////////


//////////////////////////////
//Inicio de modificar offset//
float valor_offset = 0; //valor de guardado
//menu que muestra el valor del offset y permite cambiarlo.
void modificar_valor_offset(){
    //NO se vuelve al status y se sigue actualizando
    MarlinUI::defer_return_to_status = true;
    MarlinUI::lcdDrawUpdate = LCDVIEW_CALL_REDRAW_NEXT;
    
    if (ui.encoderPosition && !ui.manual_move.processing) {
        float valor_suma = float(int32_t(ui.encoderPosition)) * ui.manual_move.menu_scale;
        valor_offset = valor_offset + valor_suma;

        if (int32_t(ui.encoderPosition) < 0)
            NOLESS(valor_offset, -5);
        else
            NOMORE(valor_offset, 5);
    }
  
    ui.encoderPosition = 0;

    if (ui.should_draw()) {
        MenuEditItemBase::draw_edit_screen(GET_TEXT(MSG_MOVE_Z), ftostr63(valor_offset));
    }

    if (ui.use_click()){
        MarlinUI::contenedor_str[0] = '\0'; //vacia la lista
        //cambia el valor de offset
        // y lo guarda
        strcpy(MarlinUI::contenedor_str, "M851 Z");
        strcat(MarlinUI::contenedor_str, ftostr63(valor_offset));
        strcat(MarlinUI::contenedor_str, "\nM500\n");

        queue.inject_P(PSTR(MarlinUI::contenedor_str));
        MarlinUI::goto_screen(menu_calibracion_auto, 2);
        
    }
}

//setea los valores para modificar el offset
void modificar_offset(){
    valor_offset = probe.offset.z;
    ui.manual_move.menu_scale = 0.025;
    MarlinUI::goto_screen(modificar_valor_offset);
}
//Fin de modificar offset//
///////////////////////////

////////////////////////
//inicio aliniar eje z//

float obtener_valor_actual_z(){
    //encargado de mostrar la posicion actual real del eje z
    get_cartesian_from_steppers();
    xyze_pos_t npos = cartes;
    const xyze_pos_t lpos = npos.asLogical();

    return lpos.z;
}

void menu_calibracion_endstop();

void salida_z_espera_home(){
    MarlinUI::defer_return_to_status = true;
    MarlinUI::lcdDrawUpdate = LCDVIEW_CALL_REDRAW_NEXT;

    crear_espera();
    crear_texto_centrado(Language_es::MSG_AUTO_HOME_ACTION, 20);
    crear_marco_superior(PSTR(Language_es::MSG_POSICIONADO_Z), 53, 11);

    if (all_axes_homed()){
        if(planner.leveling_active){
            MarlinUI::goto_screen(menu_calibracion_auto, 4);
        }else{
            MarlinUI::goto_screen(menu_calibracion_endstop, 2);
        }
    }

}

void subir_eje_z(){
    MarlinUI::defer_return_to_status = true;
    MarlinUI::lcdDrawUpdate = LCDVIEW_CALL_REDRAW_NEXT;

    float min, max;
    soft_endstop.get_manual_axis_limits(Z_AXIS, min, max);

    crear_espera();
    crear_texto_centrado(Language_es::MSG_SUBIENDO_EJE, 20);
    crear_marco_superior(PSTR(Language_es::MSG_AUTO_Z_ALIGN), 53, 11);

    //si son iguales sigue subiendo el eje
    //salida por cumplimineto de limite
    if(obtener_valor_actual_z() >= max + 40){
        set_all_unhomed();
        queue.inject_P(G28_STR);

        MarlinUI::goto_screen(salida_z_espera_home);
    }

    current_position.z += 1;
    line_to_current_position(3000);
    
    //MarlinUI::goto_screen(auto_calibracion, 4);
}

//encargado de esperar a que el eje z llegue a la posicion indicada
void espera_eje_z(){
    MarlinUI::defer_return_to_status = true;
    MarlinUI::lcdDrawUpdate = LCDVIEW_CALL_REDRAW_NEXT;

    float min, max;
    soft_endstop.get_manual_axis_limits(Z_AXIS, min, max);

    crear_espera();
    crear_texto_centrado(Language_es::MSG_ALINEAR_Z, 20); //Language_es::MSG_ALINEAR_Z
    crear_marco_superior(PSTR(Language_es::MSG_POSICIONADO_Z), 53, 11);

    //espera a que llegue al posicion
    if(obtener_valor_actual_z() >= max - 50){
        MarlinUI::goto_screen(subir_eje_z);
    }
}
//crea los comando para posicionar el eje z en la parte superir
void aliniar_eje_z(){

    float min, max;                                         ///
    soft_endstop.get_manual_axis_limits(Z_AXIS, min, max);  ///Obtiene el maximo y el minimo de area de imprecion

    MarlinUI::contenedor_str[0] = '\0'; //vacia la lista

    strcpy(MarlinUI::contenedor_str, "G28\nG1 X120 Z");
    strcat(MarlinUI::contenedor_str, ftostr63(max - 40));
    strcat(MarlinUI::contenedor_str, " F3000");

    queue.inject_P(PSTR(MarlinUI::contenedor_str));

    MarlinUI::goto_screen(espera_eje_z);
    
}
void advertencia_aliniar_eje_z(){
    crear_marco_superior(PSTR(Language_es::MSG_ALINEAR_Z),0,11);

    crear_texto_centrado(Language_es::MSG_ALINIACION_Z_ADV_01, 14);
    crear_texto_centrado(Language_es::MSG_ALINIACION_Z_ADV_02, 22);
    crear_texto_centrado(Language_es::MSG_ALINIACION_Z_ADV_03, 31);
    crear_texto_centrado(Language_es::MSG_ALINIACION_Z_ADV_04, 40);

    if(ui.use_click()){
      MarlinUI::goto_screen(aliniar_eje_z);
    }
}
//inicio aliniar eje z//
////////////////////////

/////////////////////
//inicio mapa de cama

//variables auxiliar
static uint8_t n_edit_pts = 1;
static int8_t x_plot = 0, y_plot = 0; // May be negative during move
void _lcd_ubl_map_edit_cmd_();
void menu_calibracion_printer();

/**
 * UBL LCD "radar" map point editing
 */

void _lcd_ubl_map_edit_cmd_() {
   unified_bed_leveling::ajustar_punto_mapa(x_plot,y_plot);
}

/**
 * UBL LCD Map Movement
 */
void ubl_map_move_to_xy_() {

  // Set the nozzle position to the mesh point
  current_position.set(ubl.mesh_index_to_xpos(x_plot), ubl.mesh_index_to_ypos(y_plot));

  // Use the built-in manual move handler
  ui.manual_move.soon(ALL_AXES);
}

inline int32_t grid_index(const uint8_t x, const uint8_t y) {
  return (GRID_MAX_POINTS_X) * y + x;
}


//muestra  el mapa de cama
void ubl_map_screen_() {
    // static millis_t next_move = 0;
    // const millis_t ms = millis();

    uint8_t x, y;

    if (ui.first_page) {

        // On click send "G29 P4 ..." to edit the Z value
        //salida a calibrar punto
        if(int32_t(ui.encoderPosition) == -1){
            if (ui.use_click()) {
                const bool esta_imprimiendo = printingIsActive();
                if(MarlinUI::mover_a_punto){
                    MarlinUI::goto_screen(menu_calibracion_auto, 6);
                }else{
                    if (!esta_imprimiendo && !printingIsPaused()) {
                        MarlinUI::goto_screen(menu_calibracion_auto, 5);
                    }else{
                        MarlinUI::goto_screen(menu_calibracion_printer, 2);
                    }
                }
                return;
            }
        
        }else{
            if (ui.use_click()) {
                _lcd_ubl_map_edit_cmd_();
                return;
            }
        }

        ui.defer_status_screen();

        #if IS_KINEMATIC
        // Index of the mesh point upon entry
        const int32_t old_pos_index = grid_index(x_plot, y_plot);
        // Direction from new (unconstrained) encoder value
        const int8_t step_dir = int32_t(ui.encoderPosition) < old_pos_index ? -1 : 1;
        #endif

        do {
            // Now, keep the encoder position within range
            if (int32_t(ui.encoderPosition) < -1) ui.encoderPosition = GRID_MAX_POINTS + TERN(TOUCH_SCREEN, ui.encoderPosition, -1);
            if (int32_t(ui.encoderPosition) > GRID_MAX_POINTS - 1) ui.encoderPosition = TERN(TOUCH_SCREEN, ui.encoderPosition - GRID_MAX_POINTS, 0);

            if(int32_t(ui.encoderPosition) == -1){
                // Draw the grid point based on the encoder
                x = 0 % (GRID_MAX_POINTS_X);
                y = 0 / (GRID_MAX_POINTS_X);
            }else{
                    // Draw the grid point based on the encoder
                x = ui.encoderPosition % (GRID_MAX_POINTS_X);
                y = ui.encoderPosition / (GRID_MAX_POINTS_X);
            }

            // Validate if needed
            #if IS_KINEMATIC
                const xy_pos_t xy = { ubl.mesh_index_to_xpos(x), ubl.mesh_index_to_ypos(y) };
                if (position_is_reachable(xy)) break; // Found a valid point
                ui.encoderPosition += step_dir;       // Test the next point
            #endif
        } while(ENABLED(IS_KINEMATIC));

        // Determine number of points to edit
        #if IS_KINEMATIC
        n_edit_pts = 9; // TODO: Delta accessible edit points
        #else
        const bool xc = WITHIN(x, 1, GRID_MAX_POINTS_X - 2),
                    yc = WITHIN(y, 1, GRID_MAX_POINTS_Y - 2);
        n_edit_pts = yc ? (xc ? 9 : 6) : (xc ? 6 : 4); // Corners
        #endif

        // Refresh is also set by encoder movement
        //if (int32_t(ui.encoderPosition) != grid_index(x, y))
        //  ui.refresh(LCDVIEW_CALL_REDRAW_NEXT);
    }

    if(int32_t(ui.encoderPosition) == -1){
        // Draw the grid point based on the encoder
        x = 0 % (GRID_MAX_POINTS_X);
        y = 0 / (GRID_MAX_POINTS_X);
    }else{
        // Draw the grid point based on the encoder
        x = ui.encoderPosition % (GRID_MAX_POINTS_X);
        y = ui.encoderPosition / (GRID_MAX_POINTS_X);
    }
        
    //dibuja el mapa de cama
    if (ui.should_draw()) ui.ubl_plot(x, y);
    

    // Add a move if needed to match the grid point
    if (x != x_plot || y != y_plot) {
        x_plot = x; y_plot = y;   // The move is always posted, so update the grid point now
        if(int32_t(ui.encoderPosition) != -1){
            if(MarlinUI::mover_a_punto) ubl_map_move_to_xy_();     // Sets up a "manual move"
        }
        
        ui.refresh(LCDVIEW_CALL_REDRAW_NEXT); // Clean up a half drawn box
    }
}


//dibuja el realizando home
void _ubl_map_screen_homing_() {
  ui.defer_status_screen();
  _lcd_draw_homing();
  if (all_axes_homed() || !MarlinUI::mover_a_punto) {
        ubl.lcd_map_control = true;     // Return to the map screen after editing Z
        ui.goto_screen(ubl_map_screen_, grid_index(x_plot, y_plot)); // Pre-set the encoder value
        ui.manual_move.menu_scale = 0;  // Immediate move
        if(MarlinUI::mover_a_punto)
            ubl_map_move_to_xy_();           // Move to current mesh point
        ui.manual_move.menu_scale = 1;  // Delayed moves
  }
}

//Inicio realiza el home de los ejes
void _ubl_goto_map_screen_() {
    if (planner.movesplanned()) return;     // The ACTION_ITEM will do nothing

    if(MarlinUI::mover_a_punto){
        if (!all_axes_known()) {
            set_all_unhomed();
            queue.inject_P(G28_STR);
        }
    }

    

    ui.goto_screen(_ubl_map_screen_homing_); // Go to the "Homing" screen
}

void ver_mapa_de_cama(){
    MarlinUI::mover_a_punto = false;
    ui.goto_screen(_ubl_goto_map_screen_,0);
}
void mover_mapa_de_cama(){
    MarlinUI::mover_a_punto = true;
    ui.goto_screen(_ubl_goto_map_screen_,0);
}
//inicio mapa de cama
/////////////////////
void completar_mapa_de_cama(){
    unified_bed_leveling::completar_mapa();
    queue.inject_P(PSTR("M117 Las Partes Faltantes Del Mapa Se Han Completado"));
    MarlinUI::goto_screen(MarlinUI::status_screen);
}

float nuevo_offset_real = 0;
//calibracion de offset
void calibrar_offset_tiempo_real() {
    //NO se vuelve al status y se sigue actualizando
    MarlinUI::defer_return_to_status = true;
    MarlinUI::lcdDrawUpdate = LCDVIEW_CALL_REDRAW_NEXT;
    
    if (ui.encoderPosition) {
        const int16_t steps = int16_t(ui.encoderPosition) * (BABYSTEP_SIZE_Z);
        const float diff = float(int32_t(ui.encoderPosition)) * ui.manual_move.menu_scale;

        nuevo_offset_real += diff;
        
        ui.encoderPosition = 0;
        ui.refresh(LCDVIEW_REDRAW_NOW);

        babystep.add_steps(Z_AXIS, steps);
    }

    if (ui.should_draw()) {
      MenuEditItemBase::draw_edit_screen(Language_es::MSG_ZPROBE_ZOFFSET, ftostr63(probe.offset.z + nuevo_offset_real));
    }

    //salida
    if (ui.use_click()){
        probe.offset.z = probe.offset.z + nuevo_offset_real;
        nuevo_offset_real = 0;
        (void)settings.save();

        return MarlinUI::goto_screen(menu_calibracion_printer,1);
    }
}
///////////////////////////
//Incio calibracion manual
int numero_de_punto_medir = 0;
void calibrar_off_menu();
void calibrar_off_menu_endstop();

void calibrar_off_mover_a_punto(){
    char str_X[16], str_Y[16];

    if(numero_de_punto_medir == 1){
        sprintf_P(MarlinUI::contenedor_str, PSTR("G1 X%s Y%s F3000\n"),
                dtostrf(50, 1, 3, str_X),
                dtostrf(70, 1, 3, str_Y)
                );
        queue.inject_P(MarlinUI::contenedor_str);

    }else if(numero_de_punto_medir == 3){
        sprintf_P(MarlinUI::contenedor_str, PSTR("G1 X%s Y%s F3000\n"),
                dtostrf(X_BED_SIZE - 30, 1, 3, str_X),
                dtostrf(70, 1, 3, str_Y)
                );
        queue.inject_P(MarlinUI::contenedor_str);

    }else if(numero_de_punto_medir == 4){
        sprintf_P(MarlinUI::contenedor_str, PSTR("G1 X%s Y%s F3000\n"),
                dtostrf(70, 1, 3, str_X),
                dtostrf(Y_BED_SIZE - 70, 1, 3, str_Y)
                );
        queue.inject_P(MarlinUI::contenedor_str);

    }else if(numero_de_punto_medir == 2){
        sprintf_P(MarlinUI::contenedor_str, PSTR("G1 X%s Y%s F3000\n"),
                dtostrf(X_BED_SIZE - 30, 1, 3, str_X),
                dtostrf(Y_BED_SIZE - 70, 1, 3, str_Y)
                );
        queue.inject_P(MarlinUI::contenedor_str);
    }
}

void calibrar_off_ubicar(bool se_suma_se_resta){

    if(se_suma_se_resta){
        numero_de_punto_medir += 1;
    }else{
        numero_de_punto_medir -= 1;
    }

    if(numero_de_punto_medir > 4 || numero_de_punto_medir < 1){
        queue.inject_P(PSTR("G1 Z5"));
        MarlinUI::goto_screen(menu_main, 4);

    }else{
        queue.inject_P(PSTR("G1 Z5"));
        queue.advance();
        calibrar_off_mover_a_punto();
        queue.advance();

        queue.inject_P(PSTR("G1 Z0"));
        queue.advance();

        current_position[Z_AXIS] += probe.offset.z;

        ui.manual_move.soon(Z_AXIS);

        if(MarlinUI::inductivo_final_carrera){//calibrar_off_menu_endstop
            MarlinUI::goto_screen(calibrar_off_menu);
        }else{
            MarlinUI::goto_screen(calibrar_off_menu_endstop);
        }
    }
}


void calibrar_off_resta_punto(){
    calibrar_off_ubicar(false);
}

void calibrar_off_sumar_punto(){
    calibrar_off_ubicar(true);
}

void subir_hacer_home(){
    queue.inject_P(PSTR("G1 Z5 F500"));
    queue.advance();
    queue.inject_P(PSTR("G1 Z0 F500"));
    queue.advance();
    
    current_position[Z_AXIS] += probe.offset.z;
    ui.manual_move.soon(Z_AXIS);
    safe_delay(2000);
    MarlinUI::goto_screen(calibrar_off_menu,1);
}

void subir_hacer_subir_endstop(){
    queue.inject_P(PSTR("G1 Z15 F1000\nG28 Z\nG1 Z0"));
    MarlinUI::goto_screen(calibrar_off_menu_endstop, 1);
}


void calibrar_off_menu(){
    ui.manual_move.menu_scale = 0.025;
    //encoderLine indica la pocision del encoder
    //establese el rango del encoder de 0 / x-1
    START_MENU();
    NEXT_ITEM_(3);
    END_MENU();

    init_boto(30, 5, 3, 17, 4); 

    crear_marco_superior(Language_es::MSG_CALIBRATE);

    crear_boton(volver_boton_a, volver_boton_b, Language_es::MSG_VOLVER,                calibrar_off_resta_punto);
    crear_boton(mesh_ajus_a,    mesh_ajus_b,    Language_es::MSG_SUBIR_BAJAR,           subir_hacer_home);
    crear_boton(seguir_boton_a, seguir_boton_b, Language_es::MSG_LEVEL_BED_NEXT_POINT,  calibrar_off_sumar_punto);
}

void calibrar_off_menu_endstop(){
    ui.manual_move.menu_scale = 0.025;
    //encoderLine indica la pocision del encoder
    //establese el rango del encoder de 0 / x-1
    START_MENU();
    NEXT_ITEM_(3);
    END_MENU();

    init_boto(30, 5, 3, 17, 4);

    crear_marco_superior(Language_es::MSG_CALIBRATE);

    crear_boton(volver_boton_a, volver_boton_b, Language_es::MSG_VOLVER,                calibrar_off_resta_punto);
    crear_boton(home_boton_a,    home_boton_b,  Language_es::MSG_SUBIR_BAJAR,           subir_hacer_subir_endstop);
    crear_boton(seguir_boton_a, seguir_boton_b, Language_es::MSG_LEVEL_BED_NEXT_POINT,  calibrar_off_sumar_punto);
}


void calibrar_off_espera_home(){

    //NO se vuelve al status y se sigue actualizando
    MarlinUI::defer_return_to_status = true;
    MarlinUI::lcdDrawUpdate = LCDVIEW_CALL_REDRAW_NEXT;

    crear_texto_centrado(Language_es::MSG_AUTO_HOME_ACTION, 20);
    //crea la barra de espera
    crear_espera();

    if(current_position[Z_AXIS] == 0){
        queue.inject_P(PSTR("G1 Z5 F3000"));
        queue.advance();

        queue.inject_P(PSTR("G1 X50 Y70 F3000"));
        queue.advance();

        queue.inject_P(PSTR("G1 Z0"));
        queue.advance();

        current_position[Z_AXIS] += probe.offset.z;
        ui.manual_move.soon(Z_AXIS);

        if(MarlinUI::inductivo_final_carrera){
            MarlinUI::goto_screen(calibrar_off_menu);
        }else{
            MarlinUI::goto_screen(calibrar_off_menu_endstop);
        }
    }

}

void calibrar_off_home(){
    numero_de_punto_medir = 1;
    solo_calibracion = false;
    queue.inject_P(PSTR("G28"));//\nG91\nG1 X44 Y-44 Z1 F1500\nG90\nG1 Z0
    ui.manual_move.menu_scale = 0.025;
    MarlinUI::goto_screen(calibrar_off_espera_home, 1);
}

//Final calibracion manual
//////////////////////////

//void _lcd_ubl_level_bed();
void menu_calibracion_auto(){
    //botones del menu//
    ////calibrar offset
    ////modificar offset
    ////mapa de calibracion(opcional)
    ////calibracion manual(opional)
    ////calibra
    ////aliniar eje

    MarlinUI::defer_return_to_status = false;
    solo_calibracion = true;
    //encoderLine indica la pocision del encoder
    //establese el rango del encoder de 0 / x-1
    START_MENU();
    NEXT_ITEM_(8);
    END_MENU();

    init_boto(23, 2, 4, 3);

    //crear_marco_superior(Language_es::MSG_CALIBRATE);

    crear_boton(boton_volver_a,         boton_volver_b,         Language_es::MSG_VOLVER,                menu_main,  4);
    crear_boton(calibrar_offset_a,      calibrar_offset_b,      Language_es::MSG_CALIBRAR_OFFSET,       calibrar_offset);
    crear_boton(modificar_offset_a,     modificar_offset_b,     Language_es::MSG_MODIFICAR_OFFSET,      modificar_offset);
    crear_boton(calibrar_automatico_a,  calibrar_automatico_b,  Language_es::MSG_AUTO_CALIBRATE,        auto_calibracion);
    crear_boton(completar_mapa_a,       completar_mapa_b,       Language_es::MSG_MAPA_CAMA_COMPLETAR,   completar_mapa_de_cama);  //mapa de cama
    crear_boton(editar_mapa_a,          editar_mapa_b,          Language_es::MSG_MAPA_CAMA_EDITAR,      ver_mapa_de_cama);  //mapa de cama
    crear_boton(calibrar_mapa_a,        calibrar_mapa_b,        Language_es::MSG_MAPA_CAMA_CALIBRAR,    mover_mapa_de_cama);//mapa de cama
    crear_boton(aliniar_eje_z_a,        aliniar_eje_z_b,        Language_es::MSG_ALINEAR_Z,             advertencia_aliniar_eje_z);

}

void menu_calibracion_endstop(){
    probe.offset.z = 0; // dejamos el offset en cero para que no moleste

    MarlinUI::defer_return_to_status = false;
    solo_calibracion = true;

    ui.manual_move.menu_scale = 0.025;
    
    START_MENU();
    NEXT_ITEM_(3);
    END_MENU();

    init_boto(30, 5, 3, 17, 4);

    crear_marco_superior(Language_es::MSG_CALIBRATE);

    crear_boton(volver_boton_a, volver_boton_b, Language_es::MSG_VOLVER,            menu_main,  4);
    crear_boton(mesh_cont_a,    mesh_cont_b,    Language_es::MSG_CALIBRAR_CAMA,     calibrar_off_home);
    crear_boton(mesh_ajus_a,    mesh_ajus_a,    Language_es::MSG_CALIBRAR_CAMA,     advertencia_aliniar_eje_z);
    ///advertencia_aliniar_eje_z
}

void menu_calibracion_(){
    MarlinUI::defer_return_to_status = false;
    solo_calibracion = true;

    ui.manual_move.menu_scale = 0.025;
    //encoderLine indica la pocision del encoder
    //establese el rango del encoder de 0 / x-1
    START_MENU();
    NEXT_ITEM_(3);
    END_MENU();

    init_boto(30, 5, 3, 17, 4);

    crear_marco_superior(Language_es::MSG_CALIBRATE);

    crear_boton(volver_boton_a,     volver_boton_b,     Language_es::MSG_VOLVER,            menu_main,  4);
    crear_boton(calibrar_auto_a,    calibrar_auto_b,    Language_es::MSG_CALIBRAR_OFFSET,   calibrar_offset);
    crear_boton(autocalibracion_a,  autocalibracion_b,  Language_es::MSG_CALIBRAR_CAMA,     calibrar_off_home);
}

void menu_calibracion_printer();

void mapa_de_cama(){
    opciones_no_disponible(menu_calibracion_printer, 2);
}

void mapa_de_cama_redirigir(){
    MarlinUI::goto_screen(ver_mapa_de_cama);
}
void ver_mapa_de_cama_tiempo_real(){
    MarlinUI::mover_a_punto = false;
    ui.goto_screen(ubl_map_screen_,0);
}

//este menu se muestra mintras se imprime
//modificar offset
//mapa de cama
void menu_calibracion_printer(){
    MarlinUI::defer_return_to_status = false;
    solo_calibracion = true;

    ui.manual_move.menu_scale = 0.025;
    //encoderLine indica la pocision del encoder
    //establese el rango del encoder de 0 / x-1
    START_MENU();
    NEXT_ITEM_(3);
    END_MENU();

    init_boto(30, 5, 3, 17, 4);

    crear_marco_superior(Language_es::MSG_CALIBRATE);

    crear_boton(volver_boton_a,     volver_boton_b,     Language_es::MSG_VOLVER,            menu_main,  2);
    crear_boton(ajustar_offset_a,   ajustar_offset_b,   Language_es::MSG_MODIFICAR_OFFSET,  calibrar_offset_tiempo_real);
    crear_boton(ajuste_mapa_a,      ajuste_mapa_b,      Language_es::MSG_MAPA_CAMA,         ver_mapa_de_cama_tiempo_real);

 }

#endif // MENU_KUTTERCRAFT
#endif // HAS_LCD_MENU