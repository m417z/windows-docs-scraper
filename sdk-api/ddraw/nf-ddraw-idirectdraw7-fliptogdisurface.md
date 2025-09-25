# IDirectDraw7::FlipToGDISurface

## Description

Makes the surface that the GDI writes to the primary surface.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOTFOUND

## Remarks

You can call **FlipToGDISurface** at the end of a page-flipping application to ensure that the display memory that the GDI writes to is visible.

You can also use **FlipToGDISurface** to make the GDI surface the primary surface so that normal windows, such as dialog boxes, can be displayed in full-screen mode. The hardware must have the [DDCAPS2_CANRENDERWINDOWED](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddcaps_dx3) capability.

**FlipToGDISurface** disables stereo autoflipping.

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)