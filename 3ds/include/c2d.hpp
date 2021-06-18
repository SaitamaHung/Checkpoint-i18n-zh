
#ifndef C2D_HPP
#define C2D_HPP

//extern C2D_Font font;
#include <citro2d.h>
#include <3ds.h>

namespace c2d {
    C2D_Font getFont();
    Result fontInit();
}

#endif