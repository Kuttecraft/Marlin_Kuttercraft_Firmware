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

#include "../../../inc/MarlinConfigPre.h"

#if HAS_GRAPHICAL_TFT

extern const uint8_t flowrate_32x32x4[512] = {
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x77, 0x77, 0x88, 0x88, 0x88, 0x87, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x77, 0x77, 0x88, 0x88, 0x88, 0x87, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x77, 0x78, 0xCE, 0xEB, 0x77, 0x77, 0x87, 0x7C, 0xEA, 0x78, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x87, 0x89, 0x77, 0xEF, 0xFD, 0x67, 0xA8, 0x77, 0x7E, 0xFB, 0x77, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x78, 0xDF, 0xBA, 0xFF, 0xFE, 0x8B, 0xFD, 0x87, 0x7D, 0xFA, 0x56, 0x87, 0x77, 0x88, 0x88,
  0x87, 0x8D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC7, 0x7D, 0xFA, 0x56, 0x77, 0x87, 0x77, 0x88,
  0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC6, 0x7D, 0xFA, 0x56, 0x9C, 0xDC, 0x97, 0x78,
  0x87, 0x78, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0x65, 0x6D, 0xFA, 0x59, 0xFF, 0xFF, 0xFB, 0x77,
  0x88, 0x89, 0xEF, 0xFF, 0xA7, 0x7B, 0xFF, 0xFD, 0x76, 0x5D, 0xF9, 0x7F, 0xFF, 0xFF, 0xFF, 0x97,
  0x7A, 0xDF, 0xFF, 0xFA, 0x55, 0x55, 0xCF, 0xFF, 0xEC, 0x9C, 0xF9, 0x9F, 0xFF, 0xFF, 0xFF, 0xC6,
  0x7C, 0xFF, 0xFF, 0xF7, 0x55, 0x55, 0x8F, 0xFF, 0xFF, 0xAC, 0xF9, 0xBF, 0xFD, 0x6C, 0xFF, 0xE5,
  0x7C, 0xFF, 0xFF, 0xF7, 0x56, 0x77, 0xAF, 0xFF, 0xFF, 0x9B, 0xF9, 0xBF, 0xFE, 0x8D, 0xFF, 0xE5,
  0x7A, 0xDE, 0xFF, 0xFB, 0x56, 0x77, 0xDF, 0xFF, 0xED, 0x8C, 0xF9, 0x8F, 0xFF, 0xFF, 0xFF, 0xB5,
  0x87, 0x67, 0xEF, 0xFF, 0xA8, 0x9C, 0xFF, 0xFD, 0x76, 0x5D, 0xF9, 0x6D, 0xFF, 0xFF, 0xFE, 0x75,
  0x88, 0x66, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0x65, 0x5C, 0xFA, 0x57, 0xDF, 0xFF, 0xD8, 0x55,
  0x87, 0x7D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC6, 0x6D, 0xFA, 0x55, 0x68, 0xA9, 0x65, 0x55,
  0x87, 0x8D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC6, 0x7D, 0xFA, 0x56, 0x65, 0x55, 0x55, 0x56,
  0x88, 0x78, 0xDF, 0xA8, 0xFF, 0xFE, 0x8A, 0xFC, 0x65, 0x6D, 0xFA, 0x56, 0x77, 0x65, 0x56, 0x67,
  0x88, 0x87, 0x78, 0x55, 0xEF, 0xFD, 0x55, 0x86, 0x55, 0x5D, 0xFA, 0x56, 0x88, 0x77, 0x77, 0x88,
  0x88, 0x88, 0x65, 0x55, 0xBE, 0xEA, 0x55, 0x55, 0x55, 0x6B, 0xD8, 0x56, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x77, 0x66, 0x76, 0x65, 0x56, 0x76, 0x68, 0xA9, 0x88, 0x88, 0x78, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x87, 0x77, 0x76, 0x55, 0x56, 0x87, 0x7B, 0xFF, 0xFF, 0xFB, 0x78, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x87, 0x66, 0x67, 0x88, 0x78, 0xEF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x78, 0x88, 0x87, 0xAF, 0xFF, 0x95, 0x56, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x7D, 0xFD, 0x65, 0x56, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x79, 0xF8, 0x55, 0x67, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x96, 0x55, 0x78, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x65, 0x56, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x76, 0x67, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88
};

#endif // HAS_GRAPHICAL_TFT
