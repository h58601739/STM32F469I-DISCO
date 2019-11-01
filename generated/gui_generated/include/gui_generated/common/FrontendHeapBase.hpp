/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDHEAPBASE_HPP
#define FRONTENDHEAPBASE_HPP

#include <common/Meta.hpp>
#include <common/Partition.hpp>
#include <mvp/MVPHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>








#include <gui/common/FrontendApplication.hpp>
#include <gui/model/Model.hpp>

#include <gui/mainmenucarousel_screen/MainMenuCarouselView.hpp>
#include <gui/mainmenucarousel_screen/MainMenuCarouselPresenter.hpp>
#include <gui/mainmenuanimatingbuttons_screen/MainMenuAnimatingButtonsView.hpp>
#include <gui/mainmenuanimatingbuttons_screen/MainMenuAnimatingButtonsPresenter.hpp>
#include <gui/controls_screen/ControlsView.hpp>
#include <gui/controls_screen/ControlsPresenter.hpp>
#include <gui/game2d_screen/Game2DView.hpp>
#include <gui/game2d_screen/Game2DPresenter.hpp>
#include <gui/game2048_screen/Game2048View.hpp>
#include <gui/game2048_screen/Game2048Presenter.hpp>
#include <gui/homeautomation_screen/HomeAutomationView.hpp>
#include <gui/homeautomation_screen/HomeAutomationPresenter.hpp>
#include <gui/settings_screen/SettingsView.hpp>
#include <gui/settings_screen/SettingsPresenter.hpp>


/**
 * This class provides the memory that shall be used for memory allocations
 * in the frontend. A single instance of the FrontendHeap is allocated once (in heap
 * memory), and all other frontend objects such as views, presenters and data model are
 * allocated within the scope of this FrontendHeap. As such, the RAM usage of the entire
 * user interface is sizeof(FrontendHeap).
 *
 * @note The FrontendHeap reserves memory for the most memory-consuming presenter and
 * view only. The largest of these classes are determined at compile-time using template
 * magic. As such, it is important to add all presenters, views and transitions to the
 * type lists in this class.
 *
 */
class FrontendHeapBase : public touchgfx::MVPHeap
{
public:
    /**
     * A list of all view types. Must end with meta::Nil.
     * @note All view types used in the application MUST be added to this list!
     */
    typedef touchgfx::meta::TypeList< MainMenuCarouselView,
            touchgfx::meta::TypeList< MainMenuAnimatingButtonsView,
            touchgfx::meta::TypeList< ControlsView,
            touchgfx::meta::TypeList< Game2DView,
            touchgfx::meta::TypeList< Game2048View,
            touchgfx::meta::TypeList< HomeAutomationView,
            touchgfx::meta::TypeList< SettingsView,
            touchgfx::meta::Nil > > > > > >
            > GeneratedViewTypes;

    /**
     * Determine (compile time) the View type of largest size.
     */
    typedef touchgfx::meta::select_type_maxsize< GeneratedViewTypes >::type MaxGeneratedViewType;

    /**
     * A list of all presenter types. Must end with meta::Nil.
     * @note All presenter types used in the application MUST be added to this list!
     */
    typedef touchgfx::meta::TypeList< MainMenuCarouselPresenter,
            touchgfx::meta::TypeList< MainMenuAnimatingButtonsPresenter,
            touchgfx::meta::TypeList< ControlsPresenter,
            touchgfx::meta::TypeList< Game2DPresenter,
            touchgfx::meta::TypeList< Game2048Presenter,
            touchgfx::meta::TypeList< HomeAutomationPresenter,
            touchgfx::meta::TypeList< SettingsPresenter,
            touchgfx::meta::Nil > > > > > >
            > GeneratedPresenterTypes;

    /**
     * Determine (compile time) the Presenter type of largest size.
     */
    typedef touchgfx::meta::select_type_maxsize< GeneratedPresenterTypes >::type MaxGeneratedPresenterType;

    /**
     * A list of all transition types. Must end with meta::Nil.
     * @note All transition types used in the application MUST be added to this list!
     */
    typedef touchgfx::meta::TypeList< touchgfx::NoTransition,
            touchgfx::meta::Nil
            > GeneratedTransitionTypes;

    /**
     * Determine (compile time) the Transition type of largest size.
     */
    typedef touchgfx::meta::select_type_maxsize< GeneratedTransitionTypes >::type MaxGeneratedTransitionType;

    virtual void gotoStartScreen(FrontendApplication& app)
    {
        app.gotoMainMenuCarouselScreenNoTransition();
    }
protected:
    FrontendHeapBase(touchgfx::AbstractPartition& presenters, touchgfx::AbstractPartition& views, touchgfx::AbstractPartition& transitions, FrontendApplication& app)
        : MVPHeap(presenters, views, transitions, app)
    {

    }

};

#endif // FRONTENDHEAPBASE_HPP
