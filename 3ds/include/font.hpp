#include <errno.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#include <3ds.h>
#include <citro3d.h>

extern CFNT_s* font_ttf;

static void FontLoad(const char* filename){
    
    FILE* f = fopen(filename, "rb");
    if (!f) return ;
    CFNT_s ret;
    fread(&ret, 1, sizeof(CFNT_s), f);
    font_ttf=(CFNT_s *)linearAlloc(ret.fileSize);
    if (font_ttf)
	{
		memcpy(font_ttf, &ret, sizeof(CFNT_s));
		fread((u8*)(font_ttf) + sizeof(CFNT_s), 1, ret.fileSize - sizeof(CFNT_s), f);
	}
    fclose(f);
}