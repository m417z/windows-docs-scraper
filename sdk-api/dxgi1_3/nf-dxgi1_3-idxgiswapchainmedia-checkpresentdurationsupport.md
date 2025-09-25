# IDXGISwapChainMedia::CheckPresentDurationSupport

## Description

Queries the graphics driver for a supported frame present duration corresponding to a custom refresh rate.

## Parameters

### `DesiredPresentDuration`

Indicates the frame duration to check. This value is the duration of one frame at the desired refresh rate, specified in hundreds of nanoseconds. For example, set this field to 167777 to check for 60 Hz refresh rate support.

### `pClosestSmallerPresentDuration` [out]

A variable that will be set to the closest supported frame present duration that's smaller than the requested value, or zero if the device does not support any lower duration.

### `pClosestLargerPresentDuration` [out]

A variable that will be set to the closest supported frame present duration that's larger than the requested value, or zero if the device does not support any higher duration.

## Return value

This method returns S_OK on success, or a DXGI error code on failure.

## Remarks

If the DXGI output adapter does not support custom refresh rates (for example, an external display) then the display driver will set upper and lower bounds to (0, 0).

## See also

[IDXGISwapChainMedia](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgiswapchainmedia)