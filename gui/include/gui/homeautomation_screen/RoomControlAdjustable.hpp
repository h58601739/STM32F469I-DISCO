#ifndef ROOM_CONTROL_ADJUSTABLE_HPP
#define ROOM_CONTROL_ADJUSTABLE_HPP

#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TouchArea.hpp>
#include <gui/homeautomation_screen/RoomControl.hpp>
#include <gui/homeautomation_screen/RoomControlWheel.hpp>
#include <touchgfx/widgets/canvas/Circle.hpp>

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

class RoomControlAdjustable : public RoomControl
{
public:
    RoomControlAdjustable();
    virtual ~RoomControlAdjustable();

private:
    int selectedItemIndex;

    uint8_t roomValues[NUMBER_OF_ROOMS];

    RoomControlWheel centerCircleControl;
    Circle circle[NUMBER_OF_ROOMS];

#if !defined(USE_BPP) || USE_BPP==16
    PainterRGB565 circleColorPainter;
#elif USE_BPP==24
    PainterRGB888 circleColorPainter;
#elif defined(LCD8BPP_ABGR2222)
    PainterABGR2222 circleColorPainter;
#elif defined(LCD8BPP_RGBA2222)
    PainterRGBA2222 circleColorPainter;
#elif defined(LCD8BPP_BGRA2222)
    PainterBGRA2222 circleColorPainter;
#elif defined(LCD8BPP_ARGB2222) || USE_BPP==8
    PainterARGB2222 circleColorPainter;
#elif USE_BPP==4
    PainterGRAY4 circleColorPainter;
#elif USE_BPP==2
    PainterGRAY2 circleColorPainter;
#else
#error Unknown USE_BPP
#endif

    TouchArea cancelSelectionTouchArea;

    void buttonClicked(const AbstractButton& source);

    bool isItemSelected();
    void updateRoomCircle(int index);
    void updateCenterCircle();
};

#endif /* ROOM_CONTROL_ADJUSTABLE_HPP */
