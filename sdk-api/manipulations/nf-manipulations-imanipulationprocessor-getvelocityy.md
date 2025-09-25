# IManipulationProcessor::GetVelocityY

## Description

Calculates and returns the vertical velocity.

## Parameters

### `velocityY` [out]

The calculated vertical velocity.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an HRESULT error code such as **E_FAIL**.

## Remarks

This value is useful when you are using the [IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor) interface. You should pass this value when the manipulation completes.

## See also

[GetVelocityX](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-getvelocityx)

[IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor)

[InitialVelocityY](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-get_initialvelocityy)

[Methods](https://learn.microsoft.com/windows/desktop/wintouch/mtmethods)