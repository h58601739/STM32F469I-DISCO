#ifndef CIRCULAR_VALUE_INDICATOR_HPP
#define CIRCULAR_VALUE_INDICATOR_HPP

#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/containers/ListLayout.hpp>
#include <touchgfx/widgets/TextureMapper.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/canvas/Circle.hpp>

#if !defined(USE_BPP) || USE_BPP==16
#include <touchgfx/widgets/canvas/PainterRGB565Bitmap.hpp>
#elif USE_BPP==24
#include <touchgfx/widgets/canvas/PainterRGB888Bitmap.hpp>
#elif defined(LCD8BPP_ABGR2222)
#include <touchgfx/widgets/canvas/PainterABGR2222Bitmap.hpp>
#elif defined(LCD8BPP_RGBA2222)
#include <touchgfx/widgets/canvas/PainterRGBA2222Bitmap.hpp>
#elif defined(LCD8BPP_BGRA2222)
#include <touchgfx/widgets/canvas/PainterBGRA2222Bitmap.hpp>
#elif defined(LCD8BPP_ARGB2222) || USE_BPP==8
#include <touchgfx/widgets/canvas/PainterARGB2222Bitmap.hpp>
#elif USE_BPP==4
#include <touchgfx/widgets/canvas/PainterGRAY4Bitmap.hpp>
#elif USE_BPP==2
#include <touchgfx/widgets/canvas/PainterGRAY2Bitmap.hpp>
#else
#error Unknown USE_BPP
#endif

using namespace touchgfx;

class CircularValueIndicator : public Container
{
public:
    CircularValueIndicator();
    virtual ~CircularValueIndicator();

    void setValue(int percentage);
    int getValue()
    {
        return value;
    }

private:
    static const int MIN_DEGREE = -138;
    static const int MAX_DEGREE = 138;

    Image background;
    TextureMapper arrow;

    TextAreaWithOneWildcard potentiometerText;
    Unicode::UnicodeChar potentiometerTextBuffer[5];
    TextArea potentiometerPercentageText;

    Circle circle;

    int value;

#if !defined(USE_BPP) || USE_BPP==16
    PainterRGB565Bitmap myBitmapPainterCircle;
    PainterRGB565Bitmap myBitmapPainterGlow;
#elif USE_BPP==24
    PainterRGB888Bitmap myBitmapPainterCircle;
    PainterRGB888Bitmap myBitmapPainterGlow;
#elif defined(LCD8BPP_ABGR2222)
    PainterABGR2222Bitmap myBitmapPainterCircle;
    PainterABGR2222Bitmap myBitmapPainterGlow;
#elif defined(LCD8BPP_RGBA2222)
    PainterRGBA2222Bitmap myBitmapPainterCircle;
    PainterRGBA2222Bitmap myBitmapPainterGlow;
#elif defined(LCD8BPP_BGRA2222)
    PainterBGRA2222Bitmap myBitmapPainterCircle;
    PainterBGRA2222Bitmap myBitmapPainterGlow;
#elif defined(LCD8BPP_ARGB2222) || USE_BPP==8
    PainterARGB2222Bitmap myBitmapPainterCircle;
    PainterARGB2222Bitmap myBitmapPainterGlow;
#elif USE_BPP==4
    PainterGRAY4Bitmap myBitmapPainterCircle;
    PainterGRAY4Bitmap myBitmapPainterGlow;
#elif USE_BPP==2
    PainterGRAY2Bitmap myBitmapPainterCircle;
    PainterGRAY2Bitmap myBitmapPainterGlow;
#else
#error Unknown USE_BPP
#endif

    void updatePotentiometerText(int value);
};

#endif /* CIRCULAR_VALUE_INDICATOR_HPP */
