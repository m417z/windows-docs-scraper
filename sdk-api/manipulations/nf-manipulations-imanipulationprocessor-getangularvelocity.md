# IManipulationProcessor::GetAngularVelocity

## Description

The **GetAngularVelocity** method calculates the rotational velocity that the target object is moving at.

## Parameters

### `angularVelocity` [out]

The calculated rotational velocity.

## Return value

Returns **S_OK** on success, otherwise returns an error code such as **E_FAIL**.

## Remarks

This value is useful when you are setting up the initial state of the [IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor) interface. You should pass this value when the manipulation completes.

This property is expressed in radians per millisecond if explicit timestamps are not specified by using calls to [ProcessMoveWithTime](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processmovewithtime), **ProcessMoveWithTime**, and [ProcessUpWithTime](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processupwithtime). Otherwise, this function uses radians per user defined time units.

## See also

[IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor)

[InitialAngularVelocity](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_initialangularvelocity)

[Methods](https://learn.microsoft.com/windows/desktop/wintouch/mtmethods)