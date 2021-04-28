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

extern const uint8_t fan_fast0_64x64x4[2048] = {
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x77, 0x77, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x78, 0x89, 0x98, 0x88, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x77, 0x8A, 0xBD, 0xEF, 0xFE, 0xEC, 0xBA, 0x87, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x89, 0xAC, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEC, 0x97, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x79, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x87, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x89, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xD8, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x78, 0xBD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x78, 0x9C, 0xED, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x87, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x8A, 0xDE, 0xDD, 0xCE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA5, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x78, 0xBD, 0xED, 0xDD, 0xDD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA5, 0x68, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x8A, 0xDD, 0xDD, 0xDD, 0xDC, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA5, 0x68, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0xAC, 0xDD, 0xDD, 0xDD, 0xDD, 0xCD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x85, 0x68, 0x88, 0x87, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x79, 0xCB, 0xCD, 0xDD, 0xDD, 0xDD, 0xDC, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0x65, 0x68, 0x88, 0x78, 0x88, 0x78, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x87, 0x8B, 0xCA, 0xAC, 0xDD, 0xDD, 0xDD, 0xDD, 0xCE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 0x55, 0x68, 0x87, 0x8A, 0xBA, 0x87, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x78, 0xAC, 0xBA, 0xAA, 0xBC, 0xDD, 0xDD, 0xDD, 0xCD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE6, 0x55, 0x78, 0x78, 0xAC, 0xBB, 0x97, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x79, 0xCB, 0xAA, 0xAA, 0xAA, 0xBC, 0xDD, 0xDD, 0xDC, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA5, 0x56, 0x78, 0x8A, 0xCB, 0xAA, 0xA8, 0x78, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x87, 0x8B, 0xCA, 0xAA, 0xAA, 0xAA, 0xAA, 0xCD, 0xDD, 0xDC, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0x65, 0x57, 0x87, 0x9C, 0xBA, 0xAA, 0xB9, 0x67, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x87, 0x9B, 0xBA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAB, 0xDD, 0xDD, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x55, 0x67, 0x79, 0xBB, 0xBA, 0xAA, 0xAA, 0x77, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x87, 0x9C, 0xBA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xBD, 0xDD, 0xCE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x95, 0x55, 0x77, 0x9B, 0xCB, 0xAA, 0xAA, 0xAA, 0x96, 0x78, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x89, 0xAA, 0xAB, 0xAA, 0xAA, 0xAA, 0xAA, 0xAB, 0xDD, 0xCE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0x55, 0x56, 0x79, 0xBC, 0xBA, 0xAA, 0xAA, 0xAA, 0xA6, 0x68, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x87, 0x67, 0x88, 0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0xCD, 0xCD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC5, 0x55, 0x68, 0xAB, 0xCB, 0xAA, 0xAA, 0xAA, 0xAB, 0xB8, 0x68, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x87, 0x55, 0x55, 0x56, 0x78, 0x9A, 0xAA, 0xAA, 0xBD, 0xCE, 0xFF, 0xFD, 0xDE, 0xFF, 0xFC, 0x65, 0x56, 0x9B, 0xCB, 0xBA, 0xAA, 0xAA, 0xAB, 0xCD, 0xDB, 0x67, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x76, 0x65, 0x55, 0x55, 0x57, 0x9A, 0xAA, 0xAC, 0xDE, 0xFB, 0x86, 0x67, 0x8C, 0xE8, 0x77, 0x8A, 0xCC, 0xBA, 0xAA, 0xAA, 0xAA, 0xCD, 0xDD, 0xDD, 0x86, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x77, 0x65, 0x55, 0x58, 0xAA, 0xAB, 0xDD, 0x95, 0x55, 0x55, 0x56, 0x68, 0xAA, 0xBB, 0xBB, 0xAA, 0xAA, 0xAA, 0xCD, 0xDD, 0xDD, 0xDD, 0x95, 0x78, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x77, 0x76, 0x55, 0x7A, 0xAB, 0xC8, 0x55, 0x57, 0x87, 0x55, 0x56, 0xAC, 0xAA, 0xAA, 0xAA, 0xAB, 0xCD, 0xDD, 0xDD, 0xDD, 0xDD, 0xB5, 0x68, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x78, 0x88, 0x88, 0x88, 0x76, 0x56, 0xAB, 0x95, 0x55, 0xAE, 0xFF, 0xB7, 0x65, 0x7C, 0xDC, 0xCB, 0xCC, 0xCD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xC6, 0x57, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x87, 0x8A, 0xCD, 0xEE, 0xEE, 0xED, 0xCB, 0x96, 0x89, 0x65, 0x5A, 0xFF, 0xFF, 0xFC, 0x77, 0x9C, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xC6, 0x57, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x79, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xDB, 0x65, 0x6E, 0xFF, 0xFF, 0xFE, 0x77, 0x9E, 0xEC, 0xCD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDC, 0xCC, 0xCD, 0xC6, 0x57, 0x88,
  0x88, 0x88, 0x88, 0x87, 0xAF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x65, 0x8F, 0xFF, 0xFF, 0xFF, 0x75, 0x9F, 0xFF, 0xDD, 0xCC, 0xCC, 0xCC, 0xCC, 0xDD, 0xDD, 0xDD, 0xC6, 0x57, 0x88,
  0x88, 0x88, 0x88, 0x78, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x65, 0x8E, 0xFF, 0xFF, 0xFE, 0x65, 0x8F, 0xFF, 0xFF, 0xEE, 0xDD, 0xDD, 0xEE, 0xEF, 0xFF, 0xFF, 0xD6, 0x57, 0x88,
  0x88, 0x88, 0x88, 0x7A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x85, 0x7A, 0xFF, 0xFF, 0xFA, 0x55, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xD6, 0x57, 0x88,
  0x88, 0x88, 0x88, 0x7B, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xB5, 0x77, 0x9D, 0xFD, 0xA5, 0x55, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xD6, 0x57, 0x88,
  0x88, 0x88, 0x88, 0x7B, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x67, 0x66, 0x66, 0x55, 0x58, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC5, 0x57, 0x88,
  0x88, 0x88, 0x88, 0x7B, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x97, 0x75, 0x55, 0x56, 0x9E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x95, 0x57, 0x88,
  0x88, 0x88, 0x88, 0x7A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xA8, 0x66, 0x8D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x65, 0x67, 0x88,
  0x88, 0x88, 0x88, 0x79, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEC, 0xCB, 0xBE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x55, 0x67, 0x88,
  0x88, 0x88, 0x88, 0x78, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDC, 0xDD, 0xCB, 0x7A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0x55, 0x68, 0x88,
  0x88, 0x88, 0x88, 0x87, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xED, 0xCD, 0xDB, 0xA9, 0x57, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE6, 0x55, 0x78, 0x88,
  0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xCC, 0xDD, 0xBA, 0xA8, 0x55, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xB5, 0x56, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x87, 0x8D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEC, 0xDD, 0xDC, 0xAA, 0xA7, 0x55, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x85, 0x57, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x7A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDC, 0xDD, 0xDB, 0xAA, 0xA7, 0x56, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0x65, 0x67, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x78, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xCD, 0xDD, 0xCA, 0xAA, 0xA7, 0x56, 0x7C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x55, 0x68, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x87, 0xAF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xDD, 0xDD, 0xCA, 0xAA, 0xA7, 0x56, 0x79, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA5, 0x55, 0x78, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x7B, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEC, 0xDD, 0xDD, 0xBA, 0xAA, 0xA8, 0x56, 0x87, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x55, 0x56, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x76, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDC, 0xDD, 0xDD, 0xBA, 0xAA, 0xB9, 0x56, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE6, 0x55, 0x67, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x86, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xCD, 0xDD, 0xDD, 0xBA, 0xAA, 0xA9, 0x56, 0x88, 0x7A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x85, 0x55, 0x78, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x67, 0xEF, 0xFF, 0xFF, 0xFE, 0xCD, 0xDD, 0xDD, 0xBA, 0xAA, 0xAA, 0x76, 0x88, 0x76, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE8, 0x55, 0x56, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x86, 0x7E, 0xFF, 0xFF, 0xFD, 0xCD, 0xDD, 0xDD, 0xBA, 0xAA, 0xAA, 0x85, 0x78, 0x87, 0x6B, 0xFF, 0xFF, 0xFF, 0xFD, 0x75, 0x55, 0x67, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x67, 0xDF, 0xFF, 0xEC, 0xDD, 0xDD, 0xDD, 0xBA, 0xAA, 0xAA, 0xA6, 0x68, 0x88, 0x76, 0xAE, 0xFF, 0xFE, 0xA6, 0x55, 0x56, 0x78, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x76, 0x6B, 0xFF, 0xDC, 0xDD, 0xDD, 0xDD, 0xBA, 0xAA, 0xAA, 0xA7, 0x68, 0x88, 0x86, 0x56, 0x89, 0x86, 0x55, 0x55, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x65, 0x8B, 0xDD, 0xDD, 0xDD, 0xDD, 0xBA, 0xAA, 0xAA, 0xA9, 0x57, 0x88, 0x88, 0x65, 0x55, 0x55, 0x55, 0x56, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x76, 0x55, 0x8B, 0xDD, 0xDD, 0xDD, 0xAA, 0xAA, 0xAA, 0xAA, 0x66, 0x88, 0x88, 0x87, 0x65, 0x55, 0x56, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x65, 0x56, 0x8B, 0xDD, 0xDC, 0xAA, 0xAA, 0xAA, 0xBA, 0x65, 0x78, 0x88, 0x88, 0x87, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x65, 0x55, 0x79, 0x99, 0x99, 0xAA, 0xAA, 0x97, 0x55, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x65, 0x55, 0x55, 0x56, 0x66, 0x66, 0x65, 0x55, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x66, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x76, 0x66, 0x66, 0x66, 0x66, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88
};

extern const uint8_t fan_fast1_64x64x4[2048] = {
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x66, 0x66, 0x66, 0x66, 0x66, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x75, 0x55, 0x55, 0x55, 0x55, 0x55, 0x56, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x75, 0x55, 0x66, 0x66, 0x66, 0x55, 0x55, 0x55, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x75, 0x57, 0x9A, 0xAA, 0xA9, 0x99, 0x99, 0x75, 0x55, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x77, 0x88, 0x88, 0x88, 0x75, 0x6A, 0xBA, 0xAA, 0xAA, 0xAC, 0xDD, 0xDB, 0x86, 0x55, 0x68, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x76, 0x55, 0x55, 0x67, 0x88, 0x88, 0x86, 0x6A, 0xAA, 0xAA, 0xAA, 0xAD, 0xDD, 0xDD, 0xDB, 0x85, 0x56, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x76, 0x55, 0x55, 0x55, 0x55, 0x68, 0x88, 0x87, 0x59, 0xAA, 0xAA, 0xAA, 0xBD, 0xDD, 0xDD, 0xDD, 0xDB, 0x85, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x65, 0x55, 0x56, 0x89, 0x86, 0x56, 0x88, 0x88, 0x67, 0xAA, 0xAA, 0xAA, 0xBD, 0xDD, 0xDD, 0xDC, 0xDF, 0xFB, 0x66, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x76, 0x55, 0x56, 0xAE, 0xFF, 0xFE, 0xA6, 0x78, 0x88, 0x66, 0xAA, 0xAA, 0xAA, 0xBD, 0xDD, 0xDD, 0xDC, 0xEF, 0xFF, 0xD7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x87, 0x65, 0x55, 0x7D, 0xFF, 0xFF, 0xFF, 0xFB, 0x67, 0x88, 0x75, 0x8A, 0xAA, 0xAA, 0xBD, 0xDD, 0xDD, 0xCD, 0xFF, 0xFF, 0xFE, 0x76, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x86, 0x55, 0x58, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xB6, 0x78, 0x86, 0x7A, 0xAA, 0xAA, 0xBD, 0xDD, 0xDD, 0xCE, 0xFF, 0xFF, 0xFF, 0xE7, 0x68, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x75, 0x55, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 0x78, 0x86, 0x59, 0xAA, 0xAA, 0xBD, 0xDD, 0xDD, 0xCF, 0xFF, 0xFF, 0xFF, 0xFE, 0x76, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x87, 0x65, 0x56, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x87, 0x86, 0x59, 0xBA, 0xAA, 0xBD, 0xDD, 0xDC, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xD6, 0x78, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x86, 0x55, 0x5C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC7, 0x86, 0x58, 0xAA, 0xAA, 0xBD, 0xDD, 0xDC, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0x78, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x75, 0x55, 0xAF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0x76, 0x57, 0xAA, 0xAA, 0xCD, 0xDD, 0xDD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA7, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x65, 0x58, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x76, 0x57, 0xAA, 0xAA, 0xCD, 0xDD, 0xCE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xD8, 0x78, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x87, 0x65, 0x6D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x86, 0x57, 0xAA, 0xAB, 0xDD, 0xDC, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 0x78, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x87, 0x55, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xB5, 0x57, 0xAA, 0xAC, 0xDD, 0xDC, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0x87, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x86, 0x55, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xD5, 0x58, 0xAA, 0xBD, 0xDC, 0xCE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x97, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x75, 0x56, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x59, 0xAB, 0xDD, 0xCD, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC7, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x65, 0x59, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 0x7B, 0xCD, 0xDC, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE8, 0x78, 0x88, 0x88,
  0x88, 0x87, 0x65, 0x5C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xBB, 0xCC, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0x78, 0x88, 0x88,
  0x88, 0x87, 0x65, 0x6E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0x86, 0x68, 0xAD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 0x78, 0x88, 0x88,
  0x88, 0x87, 0x55, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x96, 0x55, 0x55, 0x77, 0x9E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0x78, 0x88, 0x88,
  0x88, 0x87, 0x55, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x55, 0x56, 0x66, 0x67, 0x68, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0x78, 0x88, 0x88,
  0x88, 0x87, 0x56, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xB5, 0x55, 0xAD, 0xFD, 0x97, 0x75, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0x78, 0x88, 0x88,
  0x88, 0x87, 0x56, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x95, 0x5A, 0xFF, 0xFF, 0xFA, 0x75, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 0x78, 0x88, 0x88,
  0x88, 0x87, 0x56, 0xDF, 0xFF, 0xFF, 0xEE, 0xED, 0xDD, 0xDE, 0xEF, 0xFF, 0xFF, 0x85, 0x6E, 0xFF, 0xFF, 0xFE, 0x85, 0x6E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE8, 0x78, 0x88, 0x88,
  0x88, 0x87, 0x56, 0xCD, 0xDD, 0xDD, 0xDC, 0xCC, 0xCC, 0xCC, 0xCD, 0xDF, 0xFF, 0x95, 0x7F, 0xFF, 0xFF, 0xFF, 0x85, 0x6F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA7, 0x88, 0x88, 0x88,
  0x88, 0x87, 0x56, 0xCD, 0xCC, 0xCC, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xCC, 0xEE, 0x97, 0x7E, 0xFF, 0xFF, 0xFE, 0x65, 0x6B, 0xDE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xD9, 0x78, 0x88, 0x88, 0x88,
  0x88, 0x87, 0x56, 0xCD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDC, 0x97, 0x7C, 0xFF, 0xFF, 0xFA, 0x55, 0x69, 0x86, 0x9B, 0xCD, 0xEE, 0xEE, 0xED, 0xCA, 0x87, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x87, 0x56, 0xCD, 0xDD, 0xDD, 0xDD, 0xDD, 0xDD, 0xCC, 0xCB, 0xCC, 0xDC, 0x75, 0x67, 0xBF, 0xFE, 0xA5, 0x55, 0x9B, 0xA6, 0x56, 0x78, 0x88, 0x88, 0x88, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x65, 0xBD, 0xDD, 0xDD, 0xDD, 0xDD, 0xCB, 0xAA, 0xAA, 0xAA, 0xAC, 0xA6, 0x55, 0x57, 0x87, 0x55, 0x58, 0xCB, 0xAA, 0x75, 0x56, 0x77, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x75, 0x9D, 0xDD, 0xDD, 0xDD, 0xCA, 0xAA, 0xAA, 0xAB, 0xBB, 0xBA, 0xA8, 0x66, 0x55, 0x55, 0x55, 0x9D, 0xDB, 0xAA, 0xA8, 0x55, 0x55, 0x67, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x86, 0x8D, 0xDD, 0xDD, 0xCA, 0xAA, 0xAA, 0xAA, 0xBC, 0xCA, 0x87, 0x78, 0xEC, 0x87, 0x66, 0x8B, 0xFE, 0xDC, 0xAA, 0xAA, 0x97, 0x55, 0x55, 0x55, 0x66, 0x78, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x87, 0x6B, 0xDD, 0xCB, 0xAA, 0xAA, 0xAA, 0xBB, 0xCB, 0x96, 0x55, 0x6C, 0xFF, 0xFE, 0xDD, 0xFF, 0xFE, 0xCD, 0xBA, 0xAA, 0xAA, 0x98, 0x76, 0x55, 0x55, 0x57, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x68, 0xBB, 0xAA, 0xAA, 0xAA, 0xAB, 0xCB, 0xA8, 0x65, 0x55, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xCD, 0xCA, 0xAA, 0xAA, 0xAA, 0xAA, 0x98, 0x87, 0x67, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x66, 0xAA, 0xAA, 0xAA, 0xAA, 0xBC, 0xB9, 0x76, 0x55, 0x5B, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xCD, 0xDB, 0xAA, 0xAA, 0xAA, 0xAA, 0xAB, 0xAA, 0xA9, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x76, 0x9A, 0xAA, 0xAA, 0xAB, 0xCB, 0x97, 0x75, 0x55, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xCD, 0xDD, 0xBA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xBC, 0x97, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x87, 0x7A, 0xAA, 0xAA, 0xBB, 0xB9, 0x77, 0x65, 0x57, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCD, 0xDD, 0xDB, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xBB, 0x97, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x87, 0x69, 0xBA, 0xAA, 0xBC, 0x97, 0x87, 0x55, 0x6D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDC, 0xDD, 0xDD, 0xCA, 0xAA, 0xAA, 0xAA, 0xAA, 0xCB, 0x87, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x78, 0xAA, 0xAB, 0xCA, 0x88, 0x76, 0x55, 0xAF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEC, 0xDD, 0xDD, 0xDC, 0xBA, 0xAA, 0xAA, 0xAB, 0xC9, 0x78, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x87, 0x9B, 0xBC, 0xA8, 0x78, 0x75, 0x56, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xCD, 0xDD, 0xDD, 0xDC, 0xBA, 0xAA, 0xBC, 0xA8, 0x78, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x87, 0x8A, 0xBA, 0x87, 0x88, 0x65, 0x5A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xCD, 0xDD, 0xDD, 0xDD, 0xDC, 0xAA, 0xCB, 0x87, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x78, 0x88, 0x78, 0x88, 0x65, 0x6D, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDC, 0xDD, 0xDD, 0xDD, 0xDD, 0xCB, 0xC9, 0x78, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x77, 0x88, 0x88, 0x65, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xCD, 0xDD, 0xDD, 0xDD, 0xDC, 0xA7, 0x78, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x65, 0xAF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDC, 0xDD, 0xDD, 0xDD, 0xDA, 0x87, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x65, 0xAF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xDD, 0xDD, 0xED, 0xB8, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x75, 0xAF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xCD, 0xDE, 0xDA, 0x87, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xED, 0xEC, 0x98, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x7C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xB8, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x78, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xB9, 0x87, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x8C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC9, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x9C, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEC, 0xA9, 0x87, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x77, 0x8A, 0xBC, 0xEE, 0xFF, 0xED, 0xBA, 0x87, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x78, 0x88, 0x99, 0x88, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x77, 0x77, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88
};

#endif // HAS_GRAPHICAL_TFT
