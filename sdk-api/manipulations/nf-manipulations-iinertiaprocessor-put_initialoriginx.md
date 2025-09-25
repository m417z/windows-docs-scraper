# IInertiaProcessor::put_InitialOriginX

## Description

The **InitialOriginX** property specifies the starting horizontal location for a target with inertia.

This property is read/write.

## Parameters

## Remarks

A user can manipulate an object to set the **InitialOriginX** to be outside of the elastic bounds.
Setting **InitialOriginX** to a value outside of the elastic bounds will cause an exception to be thrown.
To prevent users from setting the origin out of bounds, check that **InitialOriginX** is valid before
setting it on an [IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor) interface. If Inertia processing has already started, calling put_InitialOriginX()
will reset the inertia state to initial time stamp.

All locations used for the inertia and manipulation processor are relative. If you want to use screen coordinates,
you pass screen coordinates to the manipulation (or inertia) processor; if you want to use absolute coordinates,
you pass those into the processor you are using.

Call this function to set the initial state of inertia. You would call this function most likely during the [ManipulationCompleted](https://learn.microsoft.com/windows/win32/api/manipulations/nf-manipulations-_imanipulationevents-manipulationcompleted) event of the [IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor) or in the constructor of the [IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor) interface.

## See also

[Handling Inertia in Unmanaged Code](https://learn.microsoft.com/windows/desktop/wintouch/handling-inertia-in-unmanaged-code)

[IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor)

[Inertia Mechanics](https://learn.microsoft.com/windows/desktop/wintouch/inertia-mechanics)

[InitialOriginY](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_initialoriginy)

[Properties](https://learn.microsoft.com/windows/desktop/wintouch/iinertiaprocessor-properties)