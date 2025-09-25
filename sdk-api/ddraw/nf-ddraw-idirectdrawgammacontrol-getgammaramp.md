# IDirectDrawGammaControl::GetGammaRamp

## Description

Retrieves the red, green, and blue gamma ramps for the primary surface.

## Parameters

### `unnamedParam1` [in]

Currently not used and must be set to 0.

### `unnamedParam2` [in, out]

A pointer to a [DDGAMMARAMP](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddgammaramp) structure that receives the current red, green, and blue gamma ramps. Each array maps color values in the frame buffer to the color values to be passed to the digital-to-analog converter (DAC).

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_EXCEPTION
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS

## Remarks

## See also

[IDirectDrawGammaControl](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawgammacontrol)