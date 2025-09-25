# IInertiaProcessor::get_InitialAngularVelocity

## Description

The **InitialAngularVelocity** property specifies the rotational (angular) velocity of the target when movement begins.

This property is read/write.

## Parameters

## Remarks

[DesiredRotation](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_desiredrotation) and [DesiredAngularDeceleration](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_desiredangulardeceleration) are mutually exclusive. If one is set, the other should be NaN. If the **DesiredRotation** property is set, the API will set the **DesiredAngularDeceleration** property so that the object will stop after the desired number of radians.
The unit of angular acceleration is radians.

If inertia processing has already started, setting **InitialAngularVelocity** will reset the inertia engine to the initial state with new velocity values applied.

Call this function to set the initial state of inertia. You would call this function most likely during the [ManipulationCompleted](https://learn.microsoft.com/windows/win32/api/manipulations/nf-manipulations-_imanipulationevents-manipulationcompleted) event of the [IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor) or in the constructor of the [IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor) interface.

## See also

[DesiredRotation](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_desiredrotation)

[GetAngularVelocity](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-getangularvelocity)

[Handling Inertia in Unmanaged Code](https://learn.microsoft.com/windows/desktop/wintouch/handling-inertia-in-unmanaged-code)

[IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor)

[Inertia Mechanics](https://learn.microsoft.com/windows/desktop/wintouch/inertia-mechanics)

[InitialExpansionVelocity](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_initialexpansionvelocity)

[Properties](https://learn.microsoft.com/windows/desktop/wintouch/iinertiaprocessor-properties)