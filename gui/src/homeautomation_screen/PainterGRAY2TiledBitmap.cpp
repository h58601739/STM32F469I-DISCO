#include <gui/homeautomation_screen/PainterGRAY2TiledBitmap.hpp>
#include <platform/driver/lcd/LCD4bpp.hpp>

bool PainterGRAY2TiledBitmap::renderInit()
{
    bitmapGRAY2Pointer = 0;

    int bitmapY = (currentY % bitmapRectToFrameBuffer.height);

    bitmapGRAY2Pointer = bitmap.getData();
    if (!bitmapGRAY2Pointer)
    {
        return false;
    }
    bitmapGRAY2Pointer += (bitmapY * bitmapRectToFrameBuffer.width + 3) / 4;

    return true;
}

bool PainterGRAY2TiledBitmap::renderNext(uint8_t& gray, uint8_t& alpha)
{
    int oldCurrentX = currentX; // Save old X
    currentX %= bitmapRectToFrameBuffer.width; // Get X inside bitmap
    bool result = PainterGRAY2Bitmap::renderNext(gray, alpha);
    currentX = oldCurrentX;
    return result;
}
