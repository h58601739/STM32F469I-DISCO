#include <gui/homeautomation_screen/PainterGRAY4TiledBitmap.hpp>
#include <platform/driver/lcd/LCD4bpp.hpp>

bool PainterGRAY4TiledBitmap::renderInit()
{
    bitmapGRAY4Pointer = 0;

    int bitmapY = (currentY % bitmapRectToFrameBuffer.height);

    bitmapGRAY4Pointer = bitmap.getData();
    if (!bitmapGRAY4Pointer)
    {
        return false;
    }
    bitmapGRAY4Pointer += (bitmapY * bitmapRectToFrameBuffer.width + 1) / 2;

    return true;
}

bool PainterGRAY4TiledBitmap::renderNext(uint8_t& gray, uint8_t& alpha)
{
    int oldCurrentX = currentX; // Save old X
    currentX %= bitmapRectToFrameBuffer.width; // Get X inside bitmap
    bool result = PainterGRAY4Bitmap::renderNext(gray, alpha);
    currentX = oldCurrentX;
    return result;
}
