## Description

Attaches a palette object to (or detaches one from) a surface. The surface uses this palette for all subsequent operations. The palette change takes place immediately, without regard to refresh timing.

## Parameters

### `unnamedParam1` [in]

A pointer to the [IDirectDrawPalette](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawpalette) interface for the palette object to be used with this surface. If NULL, the current palette is detached.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_GENERIC
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_INVALIDPIXELFORMAT
* DDERR_INVALIDSURFACETYPE
* DDERR_NOEXCLUSIVEMODE
* DDERR_NOPALETTEATTACHED
* DDERR_NOPALETTEHW
* DDERR_NOT8BITCOLOR
* DDERR_SURFACELOST
* DDERR_UNSUPPORTED

## Remarks

When you call **SetPalette** to set a palette to a surface for the first time, **SetPalette** increments the palette's reference count; subsequent calls to **SetPalette** do not affect the palette's reference count. If you pass NULL as the *lpDDPalette* parameter, the palette is removed from the surface, and the palette's reference count is decremented. If you do not delete the palette, the surface automatically releases its reference to the palette when the surface itself is released. According to COM rules, your application must release any references that it holds to the palette when the object is no longer needed.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)

