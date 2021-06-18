#include "font.hpp"
#include <string.h>
#include <stdio.h>
#include <malloc.h>

CFNT_s* font;
int bools = 0;

static Result FontLoad(CFNT_s** fontp, const char* filename){
    CFNT_s* &fonts = *fontp;
    FILE* f = fopen(filename, "rb");
    if (!f) return 1;
    CFNT_s ret;
    fread(&ret, 1, sizeof(CFNT_s), f);
    fonts=(CFNT_s *)linearAlloc(ret.fileSize);
    if (fonts)
	{
		memcpy(fonts, &ret, sizeof(CFNT_s));
		fread((u8*)(fonts) + sizeof(CFNT_s), 1, ret.fileSize - sizeof(CFNT_s), f);
	}
    fclose(f);
    return 0;
}

Result fontInit() {
    if(bools) return 2;
    bools = 1;
    if(R_FAILED(FontLoad(&font, "sdmc:/font/hkj_full.bcfnt"))) {
        if(R_FAILED(FontLoad(&font, "sdmc:/font/hkj_std.bcfnt"))) {
            font = NULL;
        }
        return 1;
    }
    return 0;
}

CFNT_s* getFont() {
    return font;
}