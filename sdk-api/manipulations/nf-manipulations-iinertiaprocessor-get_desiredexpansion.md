# IInertiaProcessor::get_DesiredExpansion

## Description

The **DesiredExpansion** property specifies the desired change in the object's average radius.

This property is read/write.

## Parameters

## Remarks

**DesiredExpansion** and [DesiredExpansionDeceleration](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_desiredexpansiondeceleration) are mutually exclusive. If one is set, the other should be NaN.

If inertia processing has already started, setting **DesiredExpansion** will reset the inertia engine to the initial state with new deceleration value applied.

Call this function to set the initial state of inertia. You would call this function most likely during the [ManipulationCompleted](https://learn.microsoft.com/windows/win32/api/manipulations/nf-manipulations-_imanipulationevents-manipulationcompleted) event of the [IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor) or in the constructor of the [IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor) interface.

## See also

[DesiredExpansionDeceleration](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_desiredexpansiondeceleration)

[Handling Inertia in Unmanaged Code](https://learn.microsoft.com/windows/desktop/wintouch/handling-inertia-in-unmanaged-code)

[IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor)

[Inertia Mechanics](https://learn.microsoft.com/windows/desktop/wintouch/inertia-mechanics)

[InitialExpansionVelocity](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_initialexpansionvelocity)

[Properties](https://learn.microsoft.com/windows/desktop/wintouch/iinertiaprocessor-properties)