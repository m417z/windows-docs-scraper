## Description

Retrieves the DirectDrawPalette object that is associated with this surface, and increments the reference count of the returned palette.

## Parameters

### `unnamedParam1` [out]

A pointer to a variable to receive a pointer to the palette object's [IDirectDrawPalette](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawpalette) interface.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_GENERIC
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOEXCLUSIVEMODE
* DDERR_NOPALETTEATTACHED
* DDERR_SURFACELOST
* DDERR_UNSUPPORTED

## Remarks

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)