# IInertiaProcessor::put_InitialRadius

## Description

The **InitialRadius** property specifies the distance from the edge of the target to its center before the object was changed.

This property is read/write.

## Parameters

## Remarks

If Inertia processing has already started, setting **InitialRadius** will reset the inertia engine to the initial state with new radius value applied.

Call this function to set initial state of inertia. You would call this function most likely during the [ManipulationCompleted](https://learn.microsoft.com/windows/win32/api/manipulations/nf-manipulations-_imanipulationevents-manipulationcompleted) event of the [IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor), or in the constructor of the [IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor) interface.

## See also

[Handling Inertia in Unmanaged Code](https://learn.microsoft.com/windows/desktop/wintouch/handling-inertia-in-unmanaged-code)

[IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor)

[Inertia Mechanics](https://learn.microsoft.com/windows/desktop/wintouch/inertia-mechanics)

[Properties](https://learn.microsoft.com/windows/desktop/wintouch/iinertiaprocessor-properties)