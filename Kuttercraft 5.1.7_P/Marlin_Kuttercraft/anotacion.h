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

/*

//primera Prueba
    se imprime un "5mm_calibration_steps"
    tiempo cura: 25 minutos
    tiempo real: 36 minutos
    //Configuracion
        todo los valores son estanda
        calibracion automatica: off
        final de carrera: on
        cama: aluminio (no parece afectar a la calidad)
        relleno: 10%
        altura: 0.2mm

        notas:
            *Se puede apreciar que las esquinas estan agrandadas -
            como si estubiera mas gorada la linea -
            (¿sera las aceleraciones?) -
            como si el volumen no fuera constante.
            *la costura de capas sale hacia afuera como si tubiera -
            cebo adicional, parece eastar tirando mas material
            *
            *esta haciendo una rectraccion por cada linia de relleno
        
        Pieza finalizada:
            *la pieza tiene gosting de una linia en los dobleces-
            y una desaparecion en otras dos lineas 
            *el mayor problema parece ser la inconcistencia -
            en las capas como si variara la altura o el flujo -
            de imprecion, revisare el bmg porque este parece tener -
            la polea de plastico inclinada.

    

//segunda Prueba
    se imprime un "xyzCalibration_cube"
    tiempo cura: 26 minutos
    tiempo real: 37 minutos 41s
    //Configuracion
        todo los valores son estanda
        calibracion automatica: off
        final de carrera: on
        cama: aluminio (no parece afectar a la calidad)
        relleno: 10%
        altura: 0.2mm

    notas:
        *no se toco el bmg todavia
        *las esquinas se notan engordandas
        *no tiene casi gosting
        *el mayor problema es el defajasaje de capa

    Pieza finalizada:
        *seria una hermosa pieza si ni tubiera tanto defasaje de capas -
         

//*Se modifica la maquina
    *se tocan los tcm
    *para que el voltaje se paresca a los de los pololus
    *pololus (X:0.70, Y:0.70, Z1.00, E0.95) TMC (X:0.70, Y:0.70, Z1.00, E0.95)
    *Se pone a imprimir denuevo la misma pieza sin cambiar nada

//tercera Prueba
    se imprime un "xyzCalibration_cube"
    tiempo cura: 26 minutos
    tiempo real: 36 minutos
    //Configuracion
        todo los valores son estanda
        calibracion automatica: off
        final de carrera: on
        cama: aluminio (no parece afectar a la calidad)
        relleno: 10%
        altura: 0.2mm

    notas:
        *no se toco el bmg todavia

    Pieza finalizada:
        *la pieza salio con menos inconcistencias esta mas pareja -
        pero se cree que esto no fue por el cambio de amperaje

//*Se modifica el amperaje por fimrware
    *los nuevos aperejes son (X:1000,Y:1000,Z1600,E1080)

//Cuarta Prueba
    se imprime un "xyzCalibration_cube"
    tiempo cura: 26 minutos
    tiempo real: 36 minutos
    //Configuracion
        todo los valores son estanda
        calibracion automatica: off
        final de carrera: on
        cama: aluminio (no parece afectar a la calidad)
        relleno: 10%
        altura: 0.2mm

    notas:
        *no se toco el bmg todavia

    Pieza finalizada:
        *la pieza sale peor que la enterior se trabo el extrusor -
        causanto linaeas de faltante de material bastante grandes -
        pero termino de imprimir

//*Se desarma el BMG se descubre que la polear de platico esta mal puesta -
    a causa de esto se parte el ruleman del bastago
    *se remplaza un BMG transtarente en este el e3d queda suelto
    *se vuelve a desarmar para ponerle cinta 
    *se cambia la boquilla por otra porque se ve que estra estruyendo 0.8mm -
    de siametro de filamento
    *con la nueva boquilla esto no cambia ¿TAL VEZ SEA LO NORMAL?
    *se baja el amperaje del Z a Z:1200 se notaba que el eje se paraba-
    tal vez a causa de sobre temperatura

//Quinta Prueba
    se imprime un "xyzCalibration_cube"
    tiempo cura: 26 minutos
    tiempo real: -- minutos
    //Configuracion
        todo los valores son estanda
        calibracion automatica: off
        final de carrera: on
        cama: aluminio (no parece afectar a la calidad)
        relleno: 10%
        altura: 0.2mm

    Pieza finalizada:
        *mejor no es una gran mejora pero esta un poco mejor


//*Se desactiva el S_CURVE_ACCELERATION encontre informacion que dice que da peores resultado -
    abria que investigar mas
    *se desactiva el CLASSIC_JERK y se remplara por JUNCTION_DEVIATION_MM 0.022

//Sesta Prueba
    se imprime un "xyzCalibration_cube"
    tiempo cura: 26 minutos
    tiempo real: -- minutos
    //Configuracion
        todo los valores son estanda
        calibracion automatica: off
        final de carrera: on
        cama: aluminio (no parece afectar a la calidad)
        relleno: 10%
        altura: 0.2mm

    Pieza finalizada:
        *el defasaje de capas parece aver mejorado
        *aparecio un ligero gostin en la pieza
        *las capas estan mas aliniadas

//*Se modifica DEFAULT_ACCELERATION 500 > 1000
    *DEFAULT_TRAVEL_ACCELERATION 500 > 2000
    *DEFAULT_RETRACT_ACCELERATION 1000 > 500
    *DEFAULT_MAX_ACCELERATION 250 > 500

//Setima Prueba
    se imprime un "xyzCalibration_cube"
    tiempo cura: 26 minutos
    tiempo real: -- minutos
    //Configuracion
        todo los valores son estanda
        calibracion automatica: off
        final de carrera: on
        cama: aluminio (no parece afectar a la calidad)
        relleno: 10%
        altura: 0.2mm

    Pieza finalizada:
        *muy parecido al resultado anterior pero con mucho mas gostin
//

* JUNCTION_DEVIATION_MM 0.05
//octava Prueba
    se imprime un "xyzCalibration_cube"
    tiempo cura: 26 minutos
    tiempo real: -- minutos
    //Configuracion
        todo los valores son estanda
        calibracion automatica: off
        final de carrera: on
        cama: aluminio (no parece afectar a la calidad)
        relleno: 10%
        altura: 0.2mm

    Pieza finalizada:
        *se nota un error en el z como si se estubiera traando el eje -
        una linea es una distancia regular de tiempo

*/