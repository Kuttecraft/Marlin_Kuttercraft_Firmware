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
#include "../ultralcd.h"
#include "../dogm/fontdata/fontdata_ISO10646_1.h"

int medida_boton = 0;
int espaciado = 0;
int cantidad = 0;
int altura = 0;
int numero_boton_id = 0;
int columna_bit = 3;
int numero_de_descuento = 0;

//estables la forma del boton y como tiene que ser generado
void init_boto(int medida_boton_, int espaciado_, int cantidad_, int altura_, int columna_bit_ = 3){
  medida_boton = medida_boton_;
  espaciado = espaciado_;
  cantidad = cantidad_;
  altura = altura_;
  numero_boton_id = 0;
  columna_bit = columna_bit_;
}

//tamaño del boton, cantidad de espacio entre botones, cantidad de botones, numero del boton
int centrar_botones(int numero_boton){
  int medida_auxiliar = ((medida_boton + espaciado) * cantidad) - espaciado;
  //112
  medida_auxiliar = (128 - medida_auxiliar) / 2;

  if(numero_boton == 0){
    return medida_auxiliar;
  }else{
    return medida_auxiliar + ((medida_boton + espaciado) * numero_boton);
  }
}

int centrar_texto(int numero, int grande_de_letra = 6){
  return (128 - (numero * grande_de_letra)) / 2;
}

int cantidad_de_digitos(int numero_x){
  if(numero_x < 10){
    return 1;
    
  }else if (numero_x < 100){
    return 2;

  }else if (numero_x < 1000){
    return 3;

  }
  return 0;
}


//lcd_put_wchar(':');
//dibuja el Boton segun el estado correspondiente
void crear_boton(const u8g_pgm_uint8_t* img_mapa_bit, const u8g_pgm_uint8_t* img_mapa_bit_2, PGM_P utf8_str_P, screenFunc_t screen, const uint16_t encoder = 0){

  int aux_id  = numero_boton_id;
  int aux_altura = altura;

  //supera el maximo de fila? a la segunda fila
  if((cantidad - 1) < aux_id){
    aux_id = aux_id - cantidad;
    aux_altura = aux_altura + medida_boton + espaciado;
  }

  //estado del boton
  if(numero_boton_id == encoderLine){

    u8g.drawBox(0, 54, 128, 11); // caja inferior
    //imagen
    u8g.drawBitmapP(centrar_botones(aux_id), aux_altura, columna_bit, medida_boton, img_mapa_bit_2);

    //cantidad de letras
    unsigned int numero__de_letras = strlen(utf8_str_P);
    numero__de_letras =  (128 - (numero__de_letras * 6)) / 2;

    //texto
    u8g.setColorIndex(0); // set to white on black
    lcd_moveto(numero__de_letras, 62);   // posicion del texto
    lcd_put_u8str_P(PSTR(utf8_str_P)); // el texto
    u8g.setColorIndex(1); // restore black on white

    if(ui.use_click()){
      MarlinUI::goto_screen(screen, encoder);
    }
  }else
  {
    u8g.drawBitmapP(centrar_botones(aux_id), aux_altura, columna_bit, medida_boton, img_mapa_bit);
  }

  //incrementa el id
  numero_boton_id++;
}
int valor_total_id(){
  return numero_boton_id;
}
void crear_marco_superior(PGM_P utf8_str_P, int altura = 0, int largo = 9){
  
  u8g.drawBox(0, altura, 128, largo); //Marco superior
  lcd_moveto(centrar_texto(strlen(utf8_str_P)), 8 + altura);
    
  u8g.setColorIndex(0);
  lcd_put_u8str_P(PSTR(utf8_str_P));
  u8g.setColorIndex(1);

}
void crear_texto_centrado(PGM_P utf8_str_P, int altura = 0){
  lcd_moveto(centrar_texto(strlen(utf8_str_P)), 8 + altura);
  lcd_put_u8str_P(PSTR(utf8_str_P));
}

//variables para el menu de espera
int contador_de_diferencia = 0;
int ultimo_valor_contador = 0;
bool alternador_de_bit = false;

void crear_espera(){
  contador_de_diferencia++;

  //allterna entre las dos imagenes
  if(alternador_de_bit){
    u8g.drawBitmapP(13,30,13,7,barra_carga_01);
  }else
  {
    u8g.drawBitmapP(13,30,13,7,barra_carga_04);
  }
   

  //atrasa la actualizacion de la imagen para no molestar
  if(contador_de_diferencia >= ultimo_valor_contador + 10){
    ultimo_valor_contador = contador_de_diferencia;

    //genera un alternador por tiempo
    if(alternador_de_bit){
      alternador_de_bit = false;
    }else
    {
      alternador_de_bit = true;
    }
    
  }

  //avita que se rompa encaso de que tarde mucho tiempo 
  if(contador_de_diferencia >= 1000){
    contador_de_diferencia = 0;
    ultimo_valor_contador = 0;
  }

}

int rango_encoder(uint32_t valor_maximo, uint32_t valor_minimo = 0){
  if(valor_maximo == valor_minimo){
    MarlinUI::encoderPosition = valor_maximo;
  }
  
  if(MarlinUI::encoderPosition >= 1000){
    MarlinUI::encoderPosition = 0;
  }
  if(MarlinUI::encoderPosition >= valor_maximo){
    MarlinUI::encoderPosition = valor_maximo;
  }
  if(MarlinUI::encoderPosition <= valor_minimo){
    MarlinUI::encoderPosition = valor_minimo;
  }
  return MarlinUI::encoderPosition;
}


void removeSpacesInPlace(char* str) {
     size_t str_len = strlen(str); // para tener strlen se debe incluir <string.h>
     char result [str_len];
     size_t p = 0; size_t i = 0;
     for (i = 0; i < str_len; ++i)
      {
        if (str[i] != ' ')
        { // result necesita su propio posicionador o iremos dejando agujeros
          result[p] = str[i];
          // Sólo avanzamos la posición p si se realiza la inserción
          p++;
        }
      }
      // funciones como printf buscan el caracter 0
      // aunque dejamos str con el mismo tamaño en memoria, ponemos la
      // marca de fin de la cadena en donde corresponde
      if (p < str_len) str[p] = '\0';
      // Reescribimos str con el contenido de result
      for (i = 0; i < p; ++i)
      {
         str[i] = result[i];
      }
}
void set_numero_de_descuento(int numero){
  numero_de_descuento = numero;
}
void crear_descuento(PGM_P utf8_str_P_1, PGM_P utf8_str_P_2, PGM_P utf8_str_P_3){
  if(numero_boton_id == numero_de_descuento){
    u8g.drawBox(0, 56, 128, 8);
    u8g.drawBox(36, 1, 57, 1);
    u8g.drawBox(36, 4, 57, 1);
    u8g.drawBox(36, 23, 57, 1);
    u8g.drawBox(36, 26, 57, 1);
    //x, y, columnas, filas, mapa
    u8g.drawBitmapP(27, 1, 2, 26,ticket_izq);
    u8g.drawBitmapP(93, 1, 2, 26,ticket_der);

    u8g.setFont(ISO10646_1_5x7);
    lcd_moveto(41, 13);
    lcd_put_u8str_P(PSTR(Language_es::MSG_CUPON_DE));

    lcd_moveto(38, 22);
    lcd_put_u8str_P(PSTR(Language_es::MSG_DESCUENTO));
    u8g.setFont(u8g_font_5x8);
    
    //pk31245-1245
    u8g.setPrintPos(34, 34);
    lcd_put_u8str_P(PSTR("pk31245-1245"));


    u8g.setColorIndex(0);
    lcd_moveto(11, 63);
    lcd_put_u8str_P(PSTR(Language_es::MSG_WEB_PROMO));
    u8g.setColorIndex(1);


    lcd_moveto(16, 55);
    lcd_put_u8str_P(PSTR(Language_es::MSG_VER_CONDICIONES));

    //u8g.setPrintPos(21, 48);
    lcd_moveto(29, 41);
    lcd_put_u8str_P(PSTR("Descuento: "));

    lcd_put_u8str_P(PSTR(utf8_str_P_1));

    lcd_moveto(centrar_texto(strlen(utf8_str_P_2) + strlen(utf8_str_P_3), 5), 48);
    lcd_put_u8str_P(PSTR(utf8_str_P_2));
    lcd_put_u8str_P(PSTR(utf8_str_P_3));
  }
  u8g.setFont(ISO10646_1_5x7);
  numero_boton_id++;
}

void crear_logro(PGM_P utf8_str_P_1, PGM_P utf8_str_P_2, PGM_P utf8_str_P_3){
  int valor_del_logro = 0;

  //si la pantalla de logros es llamada desde otro punto que no sea su funcion de muestra
  //esta muestra el ultimo logro sin pocibilidad de cambiar de logro
  if(MarlinUI::mostar_un_solo_logro == 1){
    valor_del_logro = MarlinUI::numero_de_logro_km - 1;
  }else if(MarlinUI::mostar_un_solo_logro == 2){
    valor_del_logro = MarlinUI::numero_de_logro_pz - 1;
  }else{
    valor_del_logro = encoderLine;
  }

  if(numero_boton_id == valor_del_logro){
    u8g.drawBox(26, 17, 76, 1);
    u8g.drawBox(26, 27, 76, 1);

    //x, y, columnas, filas, mapa
    u8g.drawBitmapP(12, 17, 2, 15,  bandera_izq);
    u8g.drawBitmapP(102, 17, 2, 15, bandera_der);
    //estrella
    u8g.drawBitmapP(54, 0, 3, 18, estrella);
    u8g.drawBitmapP(35, 5, 3, 18, estrella);
    u8g.drawBitmapP(73, 5, 3, 18, estrella);

    u8g.setColorIndex(0);
    u8g.drawBox(20, 18, 88, 9);
    u8g.setColorIndex(1);

    lcd_moveto(22, 26);
    lcd_put_u8str_P(PSTR(Language_es::MSG_LOGRO_OBT)); // el texto

    lcd_moveto(centrar_texto(strlen(utf8_str_P_1)), 41);
    lcd_put_u8str_P(PSTR(utf8_str_P_1)); // el texto

    lcd_moveto(centrar_texto(strlen(utf8_str_P_2)), 51);
    lcd_put_u8str_P(PSTR(utf8_str_P_2));

    crear_marco_superior(utf8_str_P_3, 55);
  }

  //incrementa el id
  numero_boton_id++;
}

void opciones_no_disponible(screenFunc_t screen, const uint16_t encoder = 0){
  crear_marco_superior(Language_es::MSG_NO_DISPONIBLE, 0, 11);

  crear_marco_superior(Language_es::MSG_SERA_AGREGADO, 42, 11);
  crear_marco_superior(Language_es::MSG_FUTURA_ACTUALIZACION, 53, 11);

  u8g.drawBitmapP(58, 20, 2, 15, no_logros_ico);

  if(ui.use_click()){
    MarlinUI::goto_screen(screen, encoder);
  }
}
 
//heramientas
//Escritura para pruebas
//lcd_put_u8str_P(PSTR("Hola")); // escritura por pantalla

//SERIAL_ECHOPGM("Hola"); //escritura por serial
//SERIAL_ECHOLN(contador_de_diferencia); // variables por serial
//serial_echopair_PGM(contador_de_diferencia);

//u8g.setColorIndex(0); // set to white on black



//NO se vuelve al status y se sigue actualizando
//MarlinUI::defer_return_to_status = true;
//MarlinUI::lcdDrawUpdate = LCDVIEW_CALL_REDRAW_NEXT;

#endif // MENU_KUTTERCRAFT
#endif // HAS_LCD_MENU