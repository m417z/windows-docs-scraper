# IInertiaProcessor::put_DesiredExpansionDeceleration

## Description

The **DesiredExpansionDeceleration** property specifies the rate at which the object will stop expanding.

This property is read/write.

## Parameters

## Remarks

**DesiredExpansionDeceleration** and [DesiredExpansion](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_desiredexpansion) are mutually exclusive. If one is set, the other should be NaN.

If inertia processing has already started, setting **DesiredExpansionDeceleration** will reset the inertia engine to the initial state with new deceleration value applied.

Call this function to set the initial state of inertia. You would call this function most likely during the [ManipulationCompleted](https://learn.microsoft.com/windows/win32/api/manipulations/nf-manipulations-_imanipulationevents-manipulationcompleted) event of the [IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor) or in the constructor of the [IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor) interface.

## See also

[DesiredExpansion](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_desiredexpansion)

[Handling Inertia in Unmanaged Code](https://learn.microsoft.com/windows/desktop/wintouch/handling-inertia-in-unmanaged-code)

[IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor)

[Inertia Mechanics](https://learn.microsoft.com/windows/desktop/wintouch/inertia-mechanics)

[InitialExpansionVelocity](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_initialexpansionvelocity)

[Properties](https://learn.microsoft.com/windows/desktop/wintouch/iinertiaprocessor-properties)