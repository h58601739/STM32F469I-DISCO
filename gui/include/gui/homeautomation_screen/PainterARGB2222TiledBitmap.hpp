#ifndef PAINTERARGB2222TILEDBITMAP_HPP
#define PAINTERARGB2222TILEDBITMAP_HPP

#include <stdint.h>
#include <touchgfx/widgets/canvas/PainterARGB2222Bitmap.hpp>
#include <touchgfx/Bitmap.hpp>
#include <touchgfx/transforms/DisplayTransformation.hpp>

using namespace touchgfx;

/**
 * @class PainterARGB2222TiledBitmap PainterARGB2222TiledBitmap.hpp touchgfx/widgets/canvas/PainterARGB2222TiledBitmap.hpp
 *
 * @brief A Painter that will paint using a bitmap.
 *
 *        PainterARGB2222TiledBitmap will take the color for a given point in the shape from a bitmap.
 *        Please be aware, the the bitmap is used by the CWR (not Shape), so any rotation you
 *        might specify for a Canvas Widget (e.g. Shape) is not applied to the bitmap as CWR is
 *        not aware of this rotation.
 *
 * @see AbstractPainter
 */
class PainterARGB2222TiledBitmap : public PainterARGB2222Bitmap
{
public:
protected:
    virtual bool renderInit();
    virtual bool renderNext(uint8_t& red, uint8_t& green, uint8_t& blue, uint8_t& alpha);
}; // class PainterARGB2222TiledBitmap

#endif // PAINTERARGB2222TILEDBITMAP_HPP
