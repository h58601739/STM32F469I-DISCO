#include <gui/common/FrontendApplication.hpp>
#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <touchgfx/hal/HAL.hpp>

#ifdef SIMULATOR
#include <ctime>
#ifndef _MSC_VER
#include <sys/time.h>
#endif /* _MSC_VER*/
#else

static volatile long lastUs;
extern uint32_t SystemCoreClock;
static int freqMHz;
#endif /* SIMULATOR */

Model::Model() :
    modelListener(0),
    mcuLoadActive(true),
    selectedDemoScreen(Defines::GAME2D),
    previousSelectedMenuType(Defines::ANIMATING_BUTTONS_MENU),
    scanPotentiometer(false),
    tickCounter(0),
    brightnessValue(100),
    lastBrightnessValue(100),
    dateYear(0),
    dateMonth(1),
    dateDay(23)
{
#ifndef SIMULATOR
    lastUs = touchgfx::HAL::getInstance()->getCPUCycles();
    freqMHz = SystemCoreClock / 1000000;
#endif
}

#ifndef SIMULATOR
//extern volatile uint32_t mcu_load_pct;
static uint8_t mcuLoadLast = 0;
#endif // SIMULATOR

void Model::tick()
{
    tickCounter++;

    lastSecondValue = currentTime.seconds;
#ifdef SIMULATOR
#ifdef _MSC_VER
    time_t rawtime;
    struct tm timenow;
    time(&rawtime);
    localtime_s(&timenow, &rawtime);

    currentTime.hours = timenow.tm_hour;
    currentTime.minutes = timenow.tm_min;
    currentTime.seconds = timenow.tm_sec;
    currentTime.milliseconds = 0;

#else
    timeval timenow;
    gettimeofday(&timenow, NULL);

    currentTime.hours = (timenow.tv_sec / 60 / 60) % 24;
    currentTime.minutes = (timenow.tv_sec / 60) % 60;
    currentTime.seconds = timenow.tv_sec % 60;
    currentTime.milliseconds = timenow.tv_usec / 1000;
#endif  /*_MSC_VER*/
#else
    static int milliseconds = 123456;
    uint8_t mcuLoadPct = touchgfx::HAL::getInstance()->getMCULoadPct();
    if (mcuLoadLast != /*mcu_load_pct*/ mcuLoadPct)
    {
        mcuLoadLast = mcuLoadPct;
        modelListener->mcuLoadUpdated(mcuLoadLast);
    }

    // Simulated time on target. Requires the mcu instrumentation class
    // to be implemented in a similar manner.
    // Correct implementation is to use the RTC instead but as this
    // is a generic demo this is not possible.
    long now = touchgfx::HAL::getInstance()->getCPUCycles();
    milliseconds += (now - lastUs + freqMHz / 2) / freqMHz / 1000;
    lastUs = now;
    currentTime.hours = (milliseconds / 1000 / 60 / 60) % 24;
    currentTime.minutes = (milliseconds / 1000 / 60) % 60;
    currentTime.seconds = (milliseconds / 1000) % 60;
    currentTime.milliseconds = milliseconds % 1000;

#endif /* SIMULATOR */
    if ((modelListener != 0) && (scanPotentiometer))
    {
        modelListener->newPotentiometerValue(getPotentiometerValue());
    }

    if ((tickCounter % 20) == 0)
    {
        modelListener->updateTime(currentTime.hours, currentTime.minutes, currentTime.seconds);
    }
}

void Model::screenSaverMinorTick()
{
    modelListener->screenSaverMinorTick();
}

void Model::screenSaverMajorTick()
{
    modelListener->screenSaverMajorTick();
}

int Model::getPotentiometerValue()
{
    int newSimulatedPotentiometerValue = currentTime.getValueInSeconds() % 101;
    return newSimulatedPotentiometerValue;
}

void Model::setBrightnessValue(uint8_t value)
{
    // No actual interaction with HW in this demo
    // Interact with actual HW/drivers to achieve this

    if (value != lastBrightnessValue)
    {
        lastBrightnessValue = value;

        touchgfx_printf("New brightness: %d\r\n", lastBrightnessValue);
    }
}

uint8_t Model::getBrightnessValue()
{
    return brightnessValue;
}

void Model::setTime(uint8_t hour, uint8_t minute, uint8_t second)
{
    // Nothing is done here in this demo.
    // Interact with RTC or other HW component
}

void Model::setDate(uint16_t year, uint8_t month, uint8_t day)
{
    dateYear = year;
    dateMonth = month;
    dateDay = day;
}
