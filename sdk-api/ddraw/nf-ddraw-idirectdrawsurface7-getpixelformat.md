## Description

Retrieves the color and pixel format of this surface.

## Parameters

### `unnamedParam1` [out]

A pointer to a [DDPIXELFORMAT](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddpixelformat) structure that receives a detailed description of the current pixel and color space format of this surface.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_INVALIDSURFACETYPE

## Remarks

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)