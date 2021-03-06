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

#include "../../inc/MarlinConfig.h"

#if HAS_GRAPHICAL_TFT

#include "tft_queue.h"
#include "tft.h"
#include "tft_image.h"

uint8_t TFT_Queue::queue[];
uint8_t *TFT_Queue::end_of_queue = queue;
uint8_t *TFT_Queue::current_task = NULL;
uint8_t *TFT_Queue::last_task = NULL;

void TFT_Queue::reset() {
  tft.abort();

  end_of_queue = queue;
  current_task = NULL;
  last_task = NULL;
}

void TFT_Queue::async() {
  if (current_task == NULL) return;
  queueTask_t *task = (queueTask_t *)current_task;

  // Check IO busy status
  if (tft.is_busy()) return;

  if (task->state == TASK_STATE_COMPLETED) {
    task = (queueTask_t *)task->nextTask;
    current_task = (uint8_t *)task;
  }

  finish_sketch();

  switch (task->type) {
    case TASK_END_OF_QUEUE: reset();      break;
    case TASK_FILL:         fill(task);   break;
    case TASK_CANVAS:       canvas(task); break;
  }
}

void TFT_Queue::finish_sketch() {
  if (last_task == NULL) return;
  queueTask_t *task = (queueTask_t *)last_task;

  if (task->state == TASK_STATE_SKETCH) {
    *end_of_queue = TASK_END_OF_QUEUE;
    task->nextTask = end_of_queue;
    task->state = TASK_STATE_READY;

    if (current_task == NULL) current_task = (uint8_t *)task;
  }
}

void TFT_Queue::fill(queueTask_t *task) {
  uint16_t count;
  parametersFill_t *task_parameters = (parametersFill_t *)(((uint8_t *)task) + sizeof(queueTask_t));

  if (task->state == TASK_STATE_READY) {
    tft.set_window(task_parameters->x, task_parameters->y, task_parameters->x + task_parameters->width - 1, task_parameters->y + task_parameters->height - 1);
    task->state = TASK_STATE_IN_PROGRESS;
  }

  if (task_parameters->count > 65535) {
    count = 65535;
    task_parameters->count -= 65535;
  }
  else {
    count = task_parameters->count;
    task_parameters->count = 0;
    task->state = TASK_STATE_COMPLETED;
  }

  tft.write_multiple(task_parameters->color, count);
}

void TFT_Queue::canvas(queueTask_t *task) {
  parametersCanvas_t *task_parameters = (parametersCanvas_t *)(((uint8_t *)task) + sizeof(queueTask_t));

  uint16_t i;
  uint8_t *item = ((uint8_t *)task_parameters) + sizeof(parametersCanvas_t);

  if (task->state == TASK_STATE_READY) {
    task->state = TASK_STATE_IN_PROGRESS;
    Canvas.New(task_parameters->x, task_parameters->y, task_parameters->width, task_parameters->height);
  }
  Canvas.Continue();

  for (i = 0; i < task_parameters->count; i++) {
    switch (*item) {
      case CANVAS_SET_BACKGROUND:
        Canvas.SetBackground(((parametersCanvasBackground_t *)item)->color);
        item += sizeof(parametersCanvasBackground_t);
        break;
      case CANVAS_ADD_TEXT:
        Canvas.AddText(((parametersCanvasText_t *)item)->x, ((parametersCanvasText_t *)item)->y, ((parametersCanvasText_t *)item)->color, item + sizeof(parametersCanvasText_t), ((parametersCanvasText_t *)item)->maxWidth);
        item += sizeof(parametersCanvasText_t) + ((parametersCanvasText_t *)item)->stringLength;
        break;

      case CANVAS_ADD_IMAGE:
        MarlinImage image;
        uint16_t *colors;
        colorMode_t color_mode;

        image = ((parametersCanvasImage_t *)item)->image;
        colors = (uint16_t *)(item + sizeof(parametersCanvasImage_t));
        Canvas.AddImage(((parametersCanvasImage_t *)item)->x, ((parametersCanvasImage_t *)item)->y, image, colors);

        item = (uint8_t *)colors;
        color_mode = Images[image].colorMode;

        switch (color_mode) {
          case GREYSCALE1:
            item += sizeof(uint16_t);
            break;
          case GREYSCALE2:
            item += sizeof(uint16_t) * 3;
            break;
          case GREYSCALE4:
            item += sizeof(uint16_t) * 15;
            break;
          default:
            break;
        }
        break;

      case CANVAS_ADD_BAR:
        Canvas.AddBar(((parametersCanvasBar_t *)item)->x, ((parametersCanvasBar_t *)item)->y, ((parametersCanvasBar_t *)item)->width, ((parametersCanvasBar_t *)item)->height, ((parametersCanvasBar_t *)item)->color);
        item += sizeof(parametersCanvasBar_t);
        break;
      case CANVAS_ADD_RECTANGLE:
        Canvas.AddRectangle(((parametersCanvasRectangle_t *)item)->x, ((parametersCanvasRectangle_t *)item)->y, ((parametersCanvasRectangle_t *)item)->width, ((parametersCanvasRectangle_t *)item)->height, ((parametersCanvasRectangle_t *)item)->color);
        item += sizeof(parametersCanvasRectangle_t);
        break;
    }
  }

  if (Canvas.ToScreen()) task->state = TASK_STATE_COMPLETED;
}


void TFT_Queue::fill(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color) {
  finish_sketch();

  queueTask_t *task = (queueTask_t *)end_of_queue;
  last_task = (uint8_t *)task;

  end_of_queue += sizeof(queueTask_t);
  parametersFill_t *task_parameters = (parametersFill_t *)end_of_queue;
  end_of_queue += sizeof(parametersFill_t);

  task_parameters->x = x;
  task_parameters->y = y;
  task_parameters->width = width;
  task_parameters->height = height;
  task_parameters->color = color;
  task_parameters->count = width * height;

  *end_of_queue = TASK_END_OF_QUEUE;
  task->nextTask = end_of_queue;
  task->state = TASK_STATE_READY;
  task->type = TASK_FILL;

  if (current_task == NULL) current_task = (uint8_t *)task;
}

void TFT_Queue::canvas(uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
  finish_sketch();

  queueTask_t *task = (queueTask_t *)end_of_queue;
  last_task = (uint8_t *) task;

  task->state = TASK_STATE_SKETCH;
  task->type = TASK_CANVAS;
  task->nextTask = NULL;

  end_of_queue += sizeof(queueTask_t);
  parametersCanvas_t *task_parameters = (parametersCanvas_t *)end_of_queue;
  end_of_queue += sizeof(parametersCanvas_t);

  task_parameters->x = x;
  task_parameters->y = y;
  task_parameters->width = width;
  task_parameters->height = height;
  task_parameters->count = 0;

  if (current_task == NULL) current_task = (uint8_t *)task;
}

void TFT_Queue::set_background(uint16_t color) {
  parametersCanvas_t *task_parameters = (parametersCanvas_t *)(((uint8_t *)last_task) + sizeof(queueTask_t));
  parametersCanvasBackground_t *parameters = (parametersCanvasBackground_t *)end_of_queue;

  parameters->type = CANVAS_SET_BACKGROUND;
  parameters->color = color;

  end_of_queue += sizeof(parametersCanvasBackground_t);
  task_parameters->count++;
}

void TFT_Queue::add_text(uint16_t x, uint16_t y, uint16_t color, uint8_t *string, uint16_t maxWidth) {
  parametersCanvas_t *task_parameters = (parametersCanvas_t *)(((uint8_t *)last_task) + sizeof(queueTask_t));
  parametersCanvasText_t *parameters = (parametersCanvasText_t *)end_of_queue;

  uint8_t *pointer = string;

  parameters->type = CANVAS_ADD_TEXT;
  parameters->x = x;
  parameters->y = y;
  parameters->color = color;
  parameters->stringLength = 0;
  parameters->maxWidth = maxWidth;

  end_of_queue += sizeof(parametersCanvasText_t);

  /* TODO: Deal with maxWidth */
  while ((*(end_of_queue++) = *pointer++) != 0x00);

  parameters->stringLength = pointer - string;
  task_parameters->count++;
}

void TFT_Queue::add_image(int16_t x, int16_t y, MarlinImage image, uint16_t *colors) {
  parametersCanvas_t *task_parameters = (parametersCanvas_t *)(((uint8_t *)last_task) + sizeof(queueTask_t));
  parametersCanvasImage_t *parameters = (parametersCanvasImage_t *)end_of_queue;

  parameters->type = CANVAS_ADD_IMAGE;
  parameters->x = x;
  parameters->y = y;
  parameters->image = image;

  end_of_queue += sizeof(parametersCanvasImage_t);
  task_parameters->count++;

  colorMode_t color_mode = Images[image].colorMode;

  if (color_mode == HIGHCOLOR) return;

  uint16_t *color = (uint16_t *)end_of_queue;
  uint8_t number_of_color = 0;

  switch (color_mode) {
    case GREYSCALE1:  number_of_color =  1; break;
    case GREYSCALE2:  number_of_color =  3; break;
    case GREYSCALE4:  number_of_color = 15; break;
    default:
      break;
  }

  while (number_of_color--) {
    *color++ = *colors++;
  }

  end_of_queue = (uint8_t *)color;
}

uint16_t gradient(uint16_t colorA, uint16_t colorB, uint16_t factor) {
  uint16_t red, green, blue;

  red   = (  RED(colorA) * factor +   RED(colorB) * (256 - factor)) >> 8;
  green = (GREEN(colorA) * factor + GREEN(colorB) * (256 - factor)) >> 8;
  blue  = ( BLUE(colorA) * factor +  BLUE(colorB) * (256 - factor)) >> 8;

  return RGB(red, green, blue);
}

void TFT_Queue::add_image(int16_t x, int16_t y, MarlinImage image, uint16_t color_main, uint16_t color_background, uint16_t color_shadow) {
  uint16_t colors[16];
  colorMode_t color_mode = Images[image].colorMode;
  uint16_t i;

  switch (color_mode) {
    case GREYSCALE1:
      colors[1] = color_main;
      break;
    case GREYSCALE2:
      for (i = 1; i < 4; i++)
        colors[i] = gradient(color_main, color_background, (i << 8) / 3);
      break;
    case GREYSCALE4:
      for (i = 1; i < 8; i++)
        colors[i] = gradient(color_background, color_shadow, i << 5);
      for (i = 8; i < 16; i++)
        colors[i] = gradient(color_main, color_background, ((i - 8) << 8) / 7);
      break;
    default:
      break;
  }

  add_image(x, y, image, colors + 1);
}

void TFT_Queue::add_bar(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color) {
  parametersCanvas_t *task_parameters = (parametersCanvas_t *)(((uint8_t *)last_task) + sizeof(queueTask_t));
  parametersCanvasBar_t *parameters = (parametersCanvasBar_t *)end_of_queue;

  parameters->type = CANVAS_ADD_BAR;
  parameters->x = x;
  parameters->y = y;
  parameters->width = width;
  parameters->height = height;
  parameters->color = color;

  end_of_queue += sizeof(parametersCanvasBar_t);
  task_parameters->count++;
}

void TFT_Queue::add_rectangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color) {
  parametersCanvas_t *task_parameters = (parametersCanvas_t *)(((uint8_t *)last_task) + sizeof(queueTask_t));
  parametersCanvasRectangle_t *parameters = (parametersCanvasRectangle_t *)end_of_queue;

  parameters->type = CANVAS_ADD_RECTANGLE;
  parameters->x = x;
  parameters->y = y;
  parameters->width = width;
  parameters->height = height;
  parameters->color = color;

  end_of_queue += sizeof(parametersCanvasRectangle_t);
  task_parameters->count++;
}

#endif // HAS_GRAPHICAL_TFT
