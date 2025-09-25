# IDirectDraw7::GetCaps

## Description

Retrieves the capabilities of the device driver for the hardware and the hardware emulation layer (HEL).

## Parameters

### `unnamedParam1` [out]

A pointer to a [DDCAPS](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddcaps_dx3) structure that receives the capabilities of the hardware, as reported by the device driver. Set this parameter to NULL if you do not want to retrieve device driver capabilities.

### `unnamedParam2` [out]

A pointer to a [DDCAPS](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddcaps_dx3) structure that receives the capabilities of the HEL. Set this parameter to NULL if you do not want to retrieve HEL capabilities.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS

You can set only one of the two parameters to NULL to exclude it. If you set both to NULL, the method fails and returns DDERR_INVALIDPARAMS.

## Remarks

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)