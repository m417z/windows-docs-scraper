# IManipulationProcessor::GetVelocityX

## Description

Calculates and returns the horizontal velocity for the target object.

## Parameters

### `velocityX` [out]

The calculated horizontal velocity.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an HRESULT error code such as **E_FAIL**.

## Remarks

This value is useful when you are using the [IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor) interface. You should pass this value when the manipulation completes.

## See also

[GetVelocityY](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-getvelocityy)

[IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor)

[InitialVelocityX](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_initialvelocityx)

[Methods](https://learn.microsoft.com/windows/desktop/wintouch/mtmethods)