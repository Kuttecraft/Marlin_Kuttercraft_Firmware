import os
import sys
import fileinput
from tempfile import mkstemp 
from shutil import move 



rootDir = '.'
result = {}  # Declaramos el diccionario

ultimo_nombre = ""
ultima_dereccion = ""

def kutter_rizacion(ultima_dereccion_, ultimo_nombre_):
    ruta_  = os.path.join(ultima_dereccion_, ultimo_nombre_)
    ruta_copia  = os.path.join(ultima_dereccion_, "copia.h")

    archi_org = open(ruta_, 'r', encoding="utf-8")
    archi_cop = open(ruta_copia, 'w', encoding="utf-8")


    archi_cop.write("/**************************************************/\n")
    archi_cop.write("/*╔╗╔═╦╗ ╔╦════╦════╦═══╦═══╦═══╦═══╦═══╦═══╦════╗*/\n")
    archi_cop.write("/*║║║╔╣║ ║║╔╗╔╗║╔╗╔╗║╔══╣╔═╗║╔═╗║╔═╗║╔═╗║╔══╣╔╗╔╗║*/\n")
    archi_cop.write("/*║╚╝╝║║ ║╠╝║║╚╩╝║║╚╣╚══╣╚═╝║║ ╚╣╚═╝║║ ║║╚══╬╝║║╚╝*/\n")
    archi_cop.write("/*║╔╗║║║ ║║ ║║   ║║ ║╔══╣╔╗╔╣║ ╔╣╔╗╔╣╚═╝║╔══╝ ║║  */\n")
    archi_cop.write("/*║║║╚╣╚═╝║ ║║   ║║ ║╚══╣║║╚╣╚═╝║║║╚╣╔═╗║║    ║║  */\n")
    archi_cop.write("/*╚╝╚═╩═══╝ ╚╝   ╚╝ ╚═══╩╝╚═╩═══╩╝╚═╩╝ ╚╩╝    ╚╝  */\n")
    archi_cop.write("/*             ╔═╗                                */\n")
    archi_cop.write("/*             ║╔╝                                */\n")
    archi_cop.write("/*            ╔╝╚╦╦═╦╗╔╦╗╔╗╔╦══╦═╦══╗             */\n")
    archi_cop.write("/*            ╚╗╔╬╣╔╣╚╝║╚╝╚╝║╔╗║╔╣║═╣             */\n")
    archi_cop.write("/*             ║║║║║║║║╠╗╔╗╔╣╔╗║║║║═╣             */\n")
    archi_cop.write("/*             ╚╝╚╩╝╚╩╩╝╚╝╚╝╚╝╚╩╝╚══╝             */\n")
    archi_cop.write("/**************************************************/\n")
    archi_cop.write("\n")

    for i in archi_org.readlines():
        if(i.find("* Marlin 3D Printer Firmware") != -1):
            archi_cop.write(" *\n")
            archi_cop.write(" * Firmware Modificado Por Kuttercraft\n")
            archi_cop.write(" * Copyright (c) 2021 Kuttercraft [https://www.kuttercraft.com]\n")
            archi_cop.write(" *\n")
            archi_cop.write(i)
        else:
            archi_cop.write(i)


    archi_cop.close()
    archi_org.close()

    os.remove(ruta_)
    move(ruta_copia, ruta_)


ALLOWED_EXTENSIONS = set(["h","cpp"])

def allowed_file(filename):
    return "." in filename and filename.rsplit(".",1)[1] in ALLOWED_EXTENSIONS

for dirName, subdirList, fileList in os.walk(rootDir):
    filenames = []  # Declaramos la lista en la que se almacenarán los nombres de archivo.
    for fname in fileList:
        filenames.append(fname)  # Añadimos el nombre de archivo a la lista
    result[dirName] = filenames  # y por último seteamos el diccionario (como clave está el directorio y como valor los archivos.

for dir, fileList in result.items():
    ultima_dereccion = dir
    for fname in fileList:
        ultimo_nombre = fname
        if(allowed_file(ultimo_nombre)):
            print(os.path.join(ultima_dereccion, ultimo_nombre))
            kutter_rizacion(ultima_dereccion, ultimo_nombre)



"""
/**************************************************/\n
/*╔╗╔═╦╗ ╔╦════╦════╦═══╦═══╦═══╦═══╦═══╦═══╦════╗*/\n
/*║║║╔╣║ ║║╔╗╔╗║╔╗╔╗║╔══╣╔═╗║╔═╗║╔═╗║╔═╗║╔══╣╔╗╔╗║*/\n
/*║╚╝╝║║ ║╠╝║║╚╩╝║║╚╣╚══╣╚═╝║║ ╚╣╚═╝║║ ║║╚══╬╝║║╚╝*/\n
/*║╔╗║║║ ║║ ║║   ║║ ║╔══╣╔╗╔╣║ ╔╣╔╗╔╣╚═╝║╔══╝ ║║  */\n
/*║║║╚╣╚═╝║ ║║   ║║ ║╚══╣║║╚╣╚═╝║║║╚╣╔═╗║║    ║║  */\n
/*╚╝╚═╩═══╝ ╚╝   ╚╝ ╚═══╩╝╚═╩═══╩╝╚═╩╝ ╚╩╝    ╚╝  */\n
/*             ╔═╗                                */\n
/*             ║╔╝                                */\n
/*            ╔╝╚╦╦═╦╗╔╦╗╔╗╔╦══╦═╦══╗             */\n
/*            ╚╗╔╬╣╔╣╚╝║╚╝╚╝║╔╗║╔╣║═╣             */\n
/*             ║║║║║║║║╠╗╔╗╔╣╔╗║║║║═╣             */\n
/*             ╚╝╚╩╝╚╩╩╝╚╝╚╝╚╝╚╩╝╚══╝             */\n
/**************************************************/\n
"""
#text_file = open(os.path.join(ultima_dereccion, ultimo_nombre), 'r')

#for i in text_file:
#    print(i)

#fileToSearch = 'D:\dummy1.txt'