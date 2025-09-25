# IDirectDrawGammaControl::SetGammaRamp

## Description

Sets the red, green, and blue gamma ramps for the primary surface.

## Parameters

### `unnamedParam1` [in]

Flag that indicates whether gamma calibration is required. Set this parameter to DDSGR_CALIBRATE to request that the calibrator adjust the gamma ramp according to the physical properties of the display, which makes the result identical on all computers. If calibration is not needed, set this parameter to 0.

### `unnamedParam2` [in]

A pointer to a [DDGAMMARAMP](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddgammaramp) structure that contains the new red, green, and blue gamma ramp entries. Each array maps color values in the frame buffer to the color values to be passed to the digital-to-analog converter (DAC).

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_EXCEPTION
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_OUTOFMEMORY

## Remarks

Not all systems support gamma calibration. To determine whether gamma calibration is supported, call [IDirectDraw7::GetCaps](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-getcaps) and examine the **dwCaps2** member of the associated [DDCAPS](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddcaps_dx3) structure after the method returns. If the DDCAPS2_CANCALIBRATEGAMMA capability flag is present, gamma calibration is supported.

Calibrating gamma ramps incurs some processing overhead and should not be used frequently.

Including the DDSGR_CALIBRATE flag in the *dwFlags* parameter when running on computers that do not support gamma calibration does not cause this method to fail. The method succeeds and sets new gamma ramp values without calibration.

## See also

[IDirectDrawGammaControl](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawgammacontrol)