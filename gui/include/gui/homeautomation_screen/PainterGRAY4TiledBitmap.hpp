#ifndef PAINTERGRAY4TILEDBITMAP_HPP
#define PAINTERGRAY4TILEDBITMAP_HPP

#include <stdint.h>
#include <touchgfx/widgets/canvas/PainterGRAY4Bitmap.hpp>
#include <touchgfx/Bitmap.hpp>
#include <touchgfx/transforms/DisplayTransformation.hpp>

using namespace touchgfx;

/**
 * @class PainterGRAY4TiledBitmap PainterGRAY4TiledBitmap.hpp touchgfx/widgets/canvas/PainterGRAY4TiledBitmap.hpp
 *
 * @brief A Painter that will paint using a bitmap.
 *
 *        PainterGRAY4TiledBitmap will take the color for a given point in the shape from a bitmap.
 *        Please be aware, the the bitmap is used by the CWR (not Shape), so any rotation you
 *        might specify for a Canvas Widget (e.g. Shape) is not applied to the bitmap as CWR is
 *        not aware of this rotation.
 *
 * @see AbstractPainter
 */
class PainterGRAY4TiledBitmap : public PainterGRAY4Bitmap
{
public:
protected:
    virtual bool renderInit();
    virtual bool renderNext(uint8_t& gray, uint8_t& alpha);
}; // class PainterGRAY4TiledBitmap

#endif // PAINTERGRAY4TILEDBITMAP_HPP
