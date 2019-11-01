#ifndef PATTERN_WIDGET_HPP
#define PATTERN_WIDGET_HPP

#include <touchgfx/containers/Container.hpp>
#include "touchgfx/widgets/TextArea.hpp"

#if !defined(USE_BPP) || USE_BPP==16
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565Bitmap.hpp>
#elif USE_BPP==24
#include <touchgfx/widgets/canvas/PainterRGB888.hpp>
#include <touchgfx/widgets/canvas/PainterRGB888Bitmap.hpp>
#elif defined(LCD8BPP_ABGR2222)
#include <touchgfx/widgets/canvas/PainterABGR2222.hpp>
#include <touchgfx/widgets/canvas/PainterABGR2222Bitmap.hpp>
#elif defined(LCD8BPP_RGBA2222)
#include <touchgfx/widgets/canvas/PainterRGBA2222.hpp>
#include <touchgfx/widgets/canvas/PainterRGBA2222Bitmap.hpp>
#elif defined(LCD8BPP_BGRA2222)
#include <touchgfx/widgets/canvas/PainterBGRA2222.hpp>
#include <touchgfx/widgets/canvas/PainterBGRA2222Bitmap.hpp>
#elif defined(LCD8BPP_ARGB2222) || USE_BPP==8
#include <touchgfx/widgets/canvas/PainterARGB2222.hpp>
#include <touchgfx/widgets/canvas/PainterARGB2222Bitmap.hpp>
#elif USE_BPP==4
#include <touchgfx/widgets/canvas/PainterGRAY4.hpp>
#include <touchgfx/widgets/canvas/PainterGRAY4Bitmap.hpp>
#elif USE_BPP==2
#include <touchgfx/widgets/canvas/PainterGRAY2.hpp>
#include <touchgfx/widgets/canvas/PainterGRAY2Bitmap.hpp>
#else
#error Unknown USE_BPP
#endif
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/AnimatedImage.hpp>

using namespace touchgfx;

class LoginWidget : public touchgfx::Container
{
public:
    LoginWidget();
    virtual ~LoginWidget() { }

    virtual void handleDragEvent(const touchgfx::DragEvent& evt);
    virtual void handleClickEvent(const touchgfx::ClickEvent& evt);
    virtual void handleTickEvent();

    void setSolution(touchgfx::Vector<uint8_t, 9> solution_);
    void setBitmapsAndHitBoxes(BitmapId begin, BitmapId end, uint16_t hitboxWidth, uint16_t hitboxHeight);
    void showTrace(touchgfx::Vector<uint8_t, 9> solution_);

    void setSuccessCallback(touchgfx::GenericCallback<>& callback)
    {
        successCallback = &callback;
    }

    void setFailureCallback(touchgfx::GenericCallback<>& callback)
    {
        failureCallback = &callback;
    }

    void reset();

    void setMaxAllowedAttempts(uint8_t attempts);
    void showBannerContent(const char* text, uint8_t ms);
    void setBannerPosition(uint16_t x, uint16_t y);

private:
    static const uint8_t NR_OF_MARKERS = 9;
    static const uint8_t DISTANCE_BETWEEN_MARKERS = 105;
    static const uint8_t MIN_ACCEPTED_INPUT_SIZE = 4;
    static const uint8_t HITBOX_SIZE = 40;
    static const uint8_t TRACE_DISPLAY_TIME = 100;
    static const uint8_t BANNER_DISPLAY_TIME = 42;
    static const uint8_t TRACE_LINE_THICKNESS = 2;
    static const uint8_t CANVAS_X_BEGIN = 42;
    static const uint8_t CANVAS_Y_BEGIN = 55;

    Box background;
    Box hitBoxes[NR_OF_MARKERS];
    AnimatedImage images[NR_OF_MARKERS];

    bool patternStarted;
    bool solutionFailed;
    bool success;
    bool tracing;

    uint16_t solutionMinLength;
    uint8_t failedAttempts;
    uint8_t maxAllowedAttempts;

    touchgfx::Line line[NR_OF_MARKERS];
    int tickCounter;

    //future: operands ==, !=,
    Vector<uint8_t, NR_OF_MARKERS> solution;
    Vector<uint8_t, NR_OF_MARKERS> input;
    uint8_t completedEdges;

    Bitmap inactive;
    Bitmap active;

    TextArea headerTxt;
    TextArea bannerTxt;
    GenericCallback<>* successCallback; //voidaction callback
    GenericCallback<>* failureCallback; //future: Send back number of failed attempts
    Callback<LoginWidget, const AnimatedImage&> animationEndedCallback;

    // Painters for the different Canvas Widgets
#if !defined(USE_BPP) || USE_BPP==16
    PainterRGB565 myColorPainter;
    PainterRGB565Bitmap myBitmapPainter;
    PainterRGB565Bitmap myBitmapPainter2;
#elif USE_BPP==24
    PainterRGB888 myColorPainter;
    PainterRGB888Bitmap myBitmapPainter;
    PainterRGB888Bitmap myBitmapPainter2;
#elif defined(LCD8BPP_ABGR2222)
    PainterABGR2222 myColorPainter;
    PainterABGR2222Bitmap myBitmapPainter;
    PainterABGR2222Bitmap myBitmapPainter2;
#elif defined(LCD8BPP_RGBA2222)
    PainterRGBA2222 myColorPainter;
    PainterRGBA2222Bitmap myBitmapPainter;
    PainterRGBA2222Bitmap myBitmapPainter2;
#elif defined(LCD8BPP_BGRA2222)
    PainterBGRA2222 myColorPainter;
    PainterBGRA2222Bitmap myBitmapPainter;
    PainterBGRA2222Bitmap myBitmapPainter2;
#elif defined(LCD8BPP_ARGB2222) || USE_BPP==8
    PainterARGB2222 myColorPainter;
    PainterARGB2222Bitmap myBitmapPainter;
    PainterARGB2222Bitmap myBitmapPainter2;
#elif USE_BPP==4
    PainterGRAY4 myColorPainter;
    PainterGRAY4Bitmap myBitmapPainter;
    PainterGRAY4Bitmap myBitmapPainter2;
#elif USE_BPP==2
    PainterGRAY2 myColorPainter;
    PainterGRAY2Bitmap myBitmapPainter;
    PainterGRAY2Bitmap myBitmapPainter2;
#else
#error Unknown USE_BPP
#endif

    void activateNode(uint8_t id, bool completeNext = false);
    void showSolutionFailureBanner();
    void showPatternTooSmallBanner();
    void showHintBanner();
    void showSolutionSuccessBanner();

    void animationEnded(const AnimatedImage& source);
    void updateBannerText(TypedTextId textId);
    uint16_t getTextCenterXCoord(TextArea& ta);
    void processAnswer();
    void resetTimer();
};

#endif
