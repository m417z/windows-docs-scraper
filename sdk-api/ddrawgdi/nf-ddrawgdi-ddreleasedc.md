# DdReleaseDC function

## Description

[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.]

Wrapper for the [NtGdiDdReleaseDC](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-ntgdiddreleasedc) function and releases a device context (DC) previously obtained through [DdGetDC](https://learn.microsoft.com/windows/desktop/api/ddrawgdi/nf-ddrawgdi-ddgetdc) or **GdiEntry7**.

**GdiEntry8** is defined as an alias for this function.

## Parameters

### `pSurfaceLocal`

Pointer to the DirectDraw surface for which a DC was obtained.

## Return value

If successful, this function returns **TRUE**; otherwise it returns **FALSE**.

## Remarks

Applications that need to obtain a DC for a DirectDraw surface can use [IDirectDrawSurface7::GetDC](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-getdc), which exposes this functionality in a manner independent of the operating system.

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)