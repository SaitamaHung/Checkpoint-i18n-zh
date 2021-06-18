#include "c2d.hpp"
#include <stdio.h>

C2D_Font c2d_font;
int c2d_bools = 0;

Result c2d::fontInit() {
    if(c2d_bools) return 2;
    c2d_bools = 1;
    auto str = "sdmc:/font/hkj_full.bcfnt";
    FILE* file = fopen(str, "rb");
    if (file) goto labo;
    str = "sdmc:/font/hkj_std.bcfnt";
    file = fopen(str, "rb");
    if (file) goto labo;
    goto die;
    labo:
    fclose(file);
    c2d_font = C2D_FontLoad(str);
    //if(!c2d_font) c2d_font = C2D_FontLoad("sdmc:/font/hkj_std.bcfnt");
    return 0;
    die:
    return 1;
}

C2D_Font c2d::getFont() {
    return c2d_font;
}