//#include <stdbool.h>

typedef union _RGBQUAD {
    COLORREF rgb;
    struct {
        BYTE r;
        BYTE g;
        BYTE b;
        BYTE Reserved;
    };
} _RGBQUAD, *PRGBQUAD;

int red = 0, green = 0, blue = 0;
bool ifblue = false;

COLORREF Hue(int length)
{
    if (red != length) {
        red++;
        if (ifblue)
            return RGB(red, 0, length);
        else
            return RGB(red, 0, 0);
    }
    else if (green != length) {
        green++;
        return RGB(length, green, 0);
    }
    else if (blue != length) {
        blue++;
        return RGB(0, length, blue);
    }
    else {
        red = green = blue = 0;
        ifblue = true;
        return RGB(0, 0, 0);
    }
}