# DdGetDC function

## Description

[This function is subject to change with each operating system revision. Instead, use the DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.]

Wrapper for the [NtGdiDdGetDC](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-ntgdiddgetdc) function and returns a Windows Graphics Device Interface (GDI)
device context (DC) that represents the Microsoft DirectDraw surface indicated.

**GdiEntry7** is defined as an alias for this function.

## Parameters

### `pSurfaceLocal`

Pointer to the DirectDraw surface for which a DC is requested.

### `pColorTable`

Optional pointer to a 256-entry array of [PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85)) structures. If the color table is null, and the surface and display mode are both 8 bits per pixel, the DC shares the color table of the device.

## Return value

If successful, this function returns a valid **HDC**; otherwise it returns **NULL**.

## Remarks

If both the surface and the current display mode are palletized at 8 bits per pixel, the DC can be given the special property that its color table is shared by the color table of the display device. Applications are advised to call [IDirectDrawSurface7::GetDC](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-getdc) instead, which provides the same functionality in a manner independent of the operating system.

The returned DC must be freed by a call to [NtGdiDdReleaseDC](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-ntgdiddreleasedc) or **GdiEntry8**.

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)