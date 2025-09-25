# IDirectDraw7::SetDisplayMode

## Description

Sets the mode of the display-device hardware.

## Parameters

### `unnamedParam1` [in]

Width of the new display mode.

### `unnamedParam2` [in]

Height of the new display mode.

### `unnamedParam3` [in]

Bits per pixel (bpp) of the new display mode.

### `unnamedParam4` [in]

Refresh rate of the new display mode. Set this value to 0 to request the default refresh rate for the driver.

### `unnamedParam5` [in]

This value consists of flags that describe additional options. Currently, the only valid flag is DDSDM_STANDARDVGAMODE, which causes the method to set Mode 13, instead of Mode X 320x200x8 mode. If you are setting another resolution, bit depth, or a Mode X mode, do not use this flag; instead, set the parameter to 0.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_GENERIC
* DDERR_INVALIDMODE
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_LOCKEDSURFACES
* DDERR_NOEXCLUSIVEMODE
* DDERR_SURFACEBUSY
* DDERR_UNSUPPORTED
* DDERR_UNSUPPORTEDMODE
* DDERR_WASSTILLDRAWING

## Remarks

This method must be called by the same thread that created the application window.

If another application changes the display mode, the primary surface is lost, and the method returns DDERR_SURFACELOST until the primary surface is recreated to match the new display mode.

As part of the prior-version **IDirectDraw** interface, this method did not include the *dwRefreshRate* and *dwFlags* parameters.

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)