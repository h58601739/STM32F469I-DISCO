#ifndef ROOM_CONTROL_WHEEL_HPP
#define ROOM_CONTROL_WHEEL_HPP

#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/button.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/canvas/Circle.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#if !defined(USE_BPP) || USE_BPP==16
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#elif USE_BPP==24
#include <touchgfx/widgets/canvas/PainterRGB888.hpp>
#elif defined(LCD8BPP_ABGR2222)
#include <touchgfx/widgets/canvas/PainterABGR2222.hpp>
#elif defined(LCD8BPP_RGBA2222)
#include <touchgfx/widgets/canvas/PainterRGBA2222.hpp>
#elif defined(LCD8BPP_BGRA2222)
#include <touchgfx/widgets/canvas/PainterBGRA2222.hpp>
#elif defined(LCD8BPP_ARGB2222) || USE_BPP==8
#include <touchgfx/widgets/canvas/PainterARGB2222.hpp>
#elif USE_BPP==4
#include <touchgfx/widgets/canvas/PainterGRAY4.hpp>
#elif USE_BPP==2
#include <touchgfx/widgets/canvas/PainterGRAY2.hpp>
#else
#error Unknown USE_BPP
#endif

using namespace touchgfx;

class RoomControlWheel : public Container
{
public:
    RoomControlWheel();
    virtual ~RoomControlWheel();

    void handleClickEvent(const ClickEvent& evt);
    void handleDragEvent(const DragEvent& evt);

    void updateArcEnd(int newDegreeValue);
    void showKnob(int newDegreeValue);

    int getValue();
protected:
    Circle circle;
    Circle knob;

#if !defined(USE_BPP) || USE_BPP==16
    PainterRGB565 circleColorPainter;
    PainterRGB565 knobColorPainter;
#elif USE_BPP==24
    PainterRGB888 circleColorPainter;
    PainterRGB888 knobColorPainter;
#elif defined(LCD8BPP_ABGR2222)
    PainterABGR2222 circleColorPainter;
    PainterABGR2222 knobColorPainter;
#elif defined(LCD8BPP_RGBA2222)
    PainterRGBA2222 circleColorPainter;
    PainterRGBA2222 knobColorPainter;
#elif defined(LCD8BPP_BGRA2222)
    PainterBGRA2222 circleColorPainter;
    PainterBGRA2222 knobColorPainter;
#elif defined(LCD8BPP_ARGB2222) || USE_BPP==8
    PainterARGB2222 circleColorPainter;
    PainterARGB2222 knobColorPainter;
#elif USE_BPP==4
    PainterGRAY4 circleColorPainter;
    PainterGRAY4 knobColorPainter;
#elif USE_BPP==2
    PainterGRAY2 circleColorPainter;
    PainterGRAY2 knobColorPainter;
#else
#error Unknown USE_BPP
#endif

    TextAreaWithOneWildcard percent;
    Unicode::UnicodeChar percentBuffer[4];
    TextArea percentSign;

    void setSelectedPosition(int newX, int newY);
};

#endif /* ROOM_CONTROL_WHEEL_HPP */
