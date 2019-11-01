#ifndef PAINTERGRAY2TILEDBITMAP_HPP
#define PAINTERGRAY2TILEDBITMAP_HPP

#include <stdint.h>
#include <touchgfx/widgets/canvas/PainterGRAY2Bitmap.hpp>
#include <touchgfx/Bitmap.hpp>
#include <touchgfx/transforms/DisplayTransformation.hpp>

using namespace touchgfx;

/**
 * @class PainterGRAY2TiledBitmap PainterGRAY2TiledBitmap.hpp touchgfx/widgets/canvas/PainterGRAY2TiledBitmap.hpp
 *
 * @brief A Painter that will paint using a bitmap.
 *
 *        PainterGRAY2TiledBitmap will take the color for a given point in the shape from a bitmap.
 *        Please be aware, the the bitmap is used by the CWR (not Shape), so any rotation you
 *        might specify for a Canvas Widget (e.g. Shape) is not applied to the bitmap as CWR is
 *        not aware of this rotation.
 *
 * @see AbstractPainter
 */
class PainterGRAY2TiledBitmap : public PainterGRAY2Bitmap
{
public:
protected:
    virtual bool renderInit();
    virtual bool renderNext(uint8_t& gray, uint8_t& alpha);
}; // class PainterGRAY2TiledBitmap

#endif // PAINTERGRAY2TILEDBITMAP_HPP
