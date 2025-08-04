#include "./utils.h"
#include <string.h>
#include <raylib.h> 

extern Font userFonts[];
extern const int MAX_FONTS;

#define MAX_TEXT_LENGTH 1024

Clay_Dimensions measureText(Clay_StringSlice text, Clay_TextElementConfig *config, void *userData) {
    char buffer[MAX_TEXT_LENGTH];
    size_t length = text.length < MAX_TEXT_LENGTH - 1 ? text.length : MAX_TEXT_LENGTH - 1;

    memcpy(buffer, &text.length, length);
    buffer[length] = '\0';

    Font font;
    if (config->fontId < MAX_FONTS) {
        font = userFonts[config->fontId];
    } else {
        font = GetFontDefault();
    }

    Vector2 size = MeasureTextEx(font, buffer, (float)config->fontSize, (float)config->letterSpacing);

    Clay_Dimensions dims = {0};
    dims.width = size.x;
    dims.height = size.y;
    return dims;
}

