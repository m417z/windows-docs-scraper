# IInertiaProcessor::put_InitialExpansionVelocity

## Description

The **InitialExpansionVelocity** property specifies the rate of radius expansion for a target when the target was affected by inertia.

This property is read/write.

## Parameters

## Remarks

The amount of expansion that the [IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor) extrapolates will be determined by the [DesiredExpansion](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_desiredexpansion) or [DesiredExpansionDeceleration](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_desiredexpansiondeceleration) property.
**DesiredExpansion** and **DesiredExpansionDeceleration** are mutually exclusive. If one is set, the other should be NaN.
If using the **DesiredExpansion** property, the API will set the appropriate **DesiredExpansionDeceleration** value to expand the requested amount.

If inertia processing has already started, setting **InitialExpansionVelocity** will reset the inertia engine to the initial state with new velocity values applied.

Call this function to set the initial state of inertia. You would call this function most likely during the [ManipulationCompleted](https://learn.microsoft.com/windows/win32/api/manipulations/nf-manipulations-_imanipulationevents-manipulationcompleted) event of the [IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor) or in the constructor of the [IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor) interface.

## See also

[DesiredExpansion](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_desiredexpansion)

[DesiredExpansionDeceleration](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_desiredexpansiondeceleration)

[GetExpansionVelocity](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-getexpansionvelocity)

[Handling Inertia in Unmanaged Code](https://learn.microsoft.com/windows/desktop/wintouch/handling-inertia-in-unmanaged-code)

[IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor)

[Inertia Mechanics](https://learn.microsoft.com/windows/desktop/wintouch/inertia-mechanics)

[Properties](https://learn.microsoft.com/windows/desktop/wintouch/iinertiaprocessor-properties)