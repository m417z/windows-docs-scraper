# IInertiaProcessor::put_InitialVelocityY

## Description

The **InitialVelocityY** property specifies the initial movement of the target object on the vertical axis.

This property is read/write.

## Parameters

## Remarks

If inertia processing has already started, setting **InitialVelocityY** will reset the inertia engine to the initial state with new velocity values applied.

Call this function to set the initial state of inertia. You would call this function most likely during the [ManipulationCompleted](https://learn.microsoft.com/windows/win32/api/manipulations/nf-manipulations-_imanipulationevents-manipulationcompleted) event of the [IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor) or in the constructor of the [IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor) interface.

## See also

[GetVelocityY](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-getvelocityy)

[Handling Inertia in Unmanaged Code](https://learn.microsoft.com/windows/desktop/wintouch/handling-inertia-in-unmanaged-code)

[IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor)

[Inertia Mechanics](https://learn.microsoft.com/windows/desktop/wintouch/inertia-mechanics)

[InitialVelocityX](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_initialvelocityx)

[Properties](https://learn.microsoft.com/windows/desktop/wintouch/iinertiaprocessor-properties)