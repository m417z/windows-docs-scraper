# IManipulationProcessor::GetExpansionVelocity

## Description

The **GetExpansionVelocity** method calculates the rate that the target object is expanding at.

## Parameters

### `expansionVelocity` [out]

The rate of expansion.

## Return value

Returns **S_OK** on success, otherwise returns an error code such as **E_FAIL**.

## Remarks

This value is useful when you are using the [IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor) interface. You should pass this value when the manipulation completes.

## See also

[IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor)

[InitialExpansionVelocity](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_initialexpansionvelocity)

[Methods](https://learn.microsoft.com/windows/desktop/wintouch/mtmethods)