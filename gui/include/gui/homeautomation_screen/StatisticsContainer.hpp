#ifndef STATISTICS_CONTAINER_HPP
#define STATISTICS_CONTAINER_HPP

#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <gui/homeautomation_screen/Graph.hpp>
#include <touchgfx/widgets/canvas/Circle.hpp>
#include <touchgfx/widgets/TiledImage.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

#if !defined(USE_BPP) || USE_BPP==16
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565Bitmap.hpp>
#include <gui/homeautomation_screen/PainterRGB565TiledBitmap.hpp>
#elif USE_BPP==24
#include <touchgfx/widgets/canvas/PainterRGB888.hpp>
#include <touchgfx/widgets/canvas/PainterRGB888Bitmap.hpp>
#include <gui/homeautomation_screen/PainterRGB888TiledBitmap.hpp>
#elif defined(LCD8BPP_ABGR2222)
#include <touchgfx/widgets/canvas/PainterABGR2222.hpp>
#include <touchgfx/widgets/canvas/PainterABGR2222Bitmap.hpp>
#include <gui/homeautomation_screen/PainterABGR2222TiledBitmap.hpp>
#elif defined(LCD8BPP_RGBA2222)
#include <touchgfx/widgets/canvas/PainterRGBA2222.hpp>
#include <touchgfx/widgets/canvas/PainterRGBA2222Bitmap.hpp>
#include <gui/homeautomation_screen/PainterRGBA2222TiledBitmap.hpp>
#elif defined(LCD8BPP_BGRA2222)
#include <touchgfx/widgets/canvas/PainterBGRA2222.hpp>
#include <touchgfx/widgets/canvas/PainterBGRA2222Bitmap.hpp>
#include <gui/homeautomation_screen/PainterBGRA2222TiledBitmap.hpp>
#elif defined(LCD8BPP_ARGB2222) || USE_BPP==8
#include <touchgfx/widgets/canvas/PainterARGB2222.hpp>
#include <touchgfx/widgets/canvas/PainterARGB2222Bitmap.hpp>
#include <gui/homeautomation_screen/PainterARGB2222TiledBitmap.hpp>
#elif USE_BPP==4
#include <touchgfx/widgets/canvas/PainterGRAY4.hpp>
#include <touchgfx/widgets/canvas/PainterGRAY4Bitmap.hpp>
#include <gui/homeautomation_screen/PainterGRAY4TiledBitmap.hpp>
#elif USE_BPP==2
#include <touchgfx/widgets/canvas/PainterGRAY2.hpp>
#include <touchgfx/widgets/canvas/PainterGRAY2Bitmap.hpp>
#include <gui/homeautomation_screen/PainterGRAY2TiledBitmap.hpp>
#else
#error Unknown USE_BPP
#endif

using namespace touchgfx;

class StatisticsContainer : public Container
{
public:
    StatisticsContainer();
    virtual ~StatisticsContainer();

    virtual void setup();

    virtual void handleTickEvent();
    virtual void handleClickEvent(const ClickEvent& evt);
    virtual void handleDragEvent(const DragEvent& evt);

    void update(int x);
private:
    enum
    {
        STAT_STATE_NONE,
        STAT_STATE_INIT,
        STAT_STATE_SHOW_OFF,
        STAT_STATE_READY
    };
    Image upper;
    TiledImage lower;
    Graph graph[3];
    Box verticalBar;
    Circle circle[3];

#if !defined(USE_BPP) || USE_BPP==16
    PainterRGB565 bgPainter;
    PainterRGB565Bitmap circlePainter[3];
    PainterRGB565TiledBitmap painter[3];
#elif USE_BPP==24
    PainterRGB888 bgPainter;
    PainterRGB888Bitmap circlePainter[3];
    PainterRGB888TiledBitmap painter[3];
#elif defined(LCD8BPP_ABGR2222)
    PainterABGR2222 bgPainter;
    PainterABGR2222Bitmap circlePainter[3];
    PainterABGR2222TiledBitmap painter[3];
#elif defined(LCD8BPP_RGBA2222)
    PainterRGBA2222 bgPainter;
    PainterRGBA2222Bitmap circlePainter[3];
    PainterRGBA2222TiledBitmap painter[3];
#elif defined(LCD8BPP_BGRA2222)
    PainterBGRA2222 bgPainter;
    PainterBGRA2222Bitmap circlePainter[3];
    PainterBGRA2222TiledBitmap painter[3];
#elif defined(LCD8BPP_ARGB2222) || USE_BPP==8
    PainterARGB2222 bgPainter;
    PainterARGB2222Bitmap circlePainter[3];
    PainterARGB2222TiledBitmap painter[3];
#elif USE_BPP==4
    PainterGRAY4 bgPainter;
    PainterGRAY4Bitmap circlePainter[3];
    PainterGRAY4TiledBitmap painter[3];
#elif USE_BPP==2
    PainterGRAY2 bgPainter;
    PainterGRAY2Bitmap circlePainter[3];
    PainterGRAY2TiledBitmap painter[3];
#else
#error Unknown USE_BPP
#endif

    Image icon[3];
    TextAreaWithOneWildcard pctValue[3];
    Unicode::UnicodeChar buffer[3][4];
    TextArea pctSign[3];
    static int yScale;
    int numValues;
    int statState;
    float randFreq[3][5];
    float randAdd[3][5];
    int tick;
};

#endif /* STATISTICS_CONTAINER_HPP */
