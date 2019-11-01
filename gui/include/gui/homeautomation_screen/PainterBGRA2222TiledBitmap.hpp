#ifndef PAINTERBGRA2222TILEDBITMAP_HPP
#define PAINTERBGRA2222TILEDBITMAP_HPP

#include <stdint.h>
#include <touchgfx/widgets/canvas/PainterBGRA2222Bitmap.hpp>
#include <touchgfx/Bitmap.hpp>
#include <touchgfx/transforms/DisplayTransformation.hpp>

using namespace touchgfx;

/**
 * @class PainterBGRA2222TiledBitmap PainterBGRA2222TiledBitmap.hpp touchgfx/widgets/canvas/PainterBGRA2222TiledBitmap.hpp
 *
 * @brief A Painter that will paint using a bitmap.
 *
 *        PainterBGRA2222TiledBitmap will take the color for a given point in the shape from a bitmap.
 *        Please be aware, the the bitmap is used by the CWR (not Shape), so any rotation you
 *        might specify for a Canvas Widget (e.g. Shape) is not applied to the bitmap as CWR is
 *        not aware of this rotation.
 *
 * @see AbstractPainter
 */
class PainterBGRA2222TiledBitmap : public PainterBGRA2222Bitmap
{
public:
protected:
    virtual bool renderInit();
    virtual bool renderNext(uint8_t& red, uint8_t& green, uint8_t& blue, uint8_t& alpha);
}; // class PainterBGRA2222TiledBitmap

#endif // PAINTERBGRA2222TILEDBITMAP_HPP
