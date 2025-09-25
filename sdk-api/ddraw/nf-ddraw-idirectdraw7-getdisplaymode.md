## Description

Retrieves the current display mode.

## Parameters

### `unnamedParam1` [in]

A pointer to a [DDSURFACEDESC2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550340(v=vs.85)) structure that receives a description of the current surface.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_UNSUPPORTEDMODE

## Remarks

An application should not save the information that **GetDisplayMode** returns to restore the display mode on clean-up. The application should instead use the [IDirectDraw7::RestoreDisplayMode](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-restoredisplaymode) method to restore the mode on clean-up, thus avoiding mode-setting conflicts that could arise in a multiprocess environment.

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)