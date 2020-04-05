//
// Copyright(C) 2005-2014 Simon Howard
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//

#include <stdlib.h>
#include <string.h>

#include "doomkeys.hpp"

#include "txt_button.hpp"
#include "txt_gui.hpp"
#include "txt_io.hpp"
#include "txt_main.hpp"
#include "txt_utf8.hpp"
#include "txt_window.hpp"

static void TXT_ButtonSizeCalc(TXT_UNCAST_ARG(button))
{
    TXT_CAST_ARG(txt_button_t, button);

    button->widget.w = TXT_UTF8_Strlen(button->label);
    button->widget.h = 1;
}

static void TXT_ButtonDrawer(TXT_UNCAST_ARG(button))
{
    TXT_CAST_ARG(txt_button_t, button);
    int i;
    int w;

    w = button->widget.w;

    TXT_SetWidgetBG(button);

    TXT_DrawString(button->label);

    for (i = TXT_UTF8_Strlen(button->label); i < w; ++i)
    {
        TXT_DrawString(" ");
    }
}

static void TXT_ButtonDestructor(TXT_UNCAST_ARG(button))
{
    TXT_CAST_ARG(txt_button_t, button);

    free(button->label);
}

static int TXT_ButtonKeyPress(TXT_UNCAST_ARG(button), int key)
{
    TXT_CAST_ARG(txt_button_t, button);

    if (key == KEY_ENTER)
    {
        TXT_EmitSignal(button, "pressed");
        return 1;
    }
    
    return 0;
}

static void TXT_ButtonMousePress(TXT_UNCAST_ARG(button), int x, int y, int b)
{
    TXT_CAST_ARG(txt_button_t, button);

    if (b == TXT_MOUSE_LEFT)
    {
        // Equivalent to pressing enter

        TXT_ButtonKeyPress(button, KEY_ENTER);
    }
}

txt_widget_class_t txt_button_class =
{
    TXT_AlwaysSelectable,
    TXT_ButtonSizeCalc,
    TXT_ButtonDrawer,
    TXT_ButtonKeyPress,
    TXT_ButtonDestructor,
    TXT_ButtonMousePress,
    NULL,
};

void TXT_SetButtonLabel(txt_button_t *button, const char *label)
{
    free(button->label);
    button->label = strdup(label);
}

txt_button_t *TXT_NewButton(const char *label)
{
    txt_button_t *button;

    button = malloc(sizeof(txt_button_t));

    TXT_InitWidget(button, &txt_button_class);
    button->label = strdup(label);

    return button;
}

// Button with a callback set automatically

txt_button_t *TXT_NewButton2(const char *label, TxtWidgetSignalFunc func,
                             void *user_data)
{
    txt_button_t *button;

    button = TXT_NewButton(label);

    TXT_SignalConnect(button, "pressed", func, user_data);

    return button;
}

