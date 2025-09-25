# GetRandomRgn function

## Description

The **GetRandomRgn** function copies the system clipping region of a specified device context to a specific region.

## Parameters

### `hdc` [in]

A handle to the device context.

### `hrgn` [in]

A handle to a region. Before the function is called, this identifies an existing region. After the function returns, this identifies a copy of the current system region. The old region identified by *hrgn* is overwritten.

### `i` [in]

This parameter must be SYSRGN.

## Return value

If the function succeeds, the return value is 1. If the function fails, the return value is -1. If the region to be retrieved is **NULL**, the return value is 0. If the function fails or the region to be retrieved is **NULL**, *hrgn* is not initialized.

## Remarks

When using the SYSRGN flag, note that the system clipping region might not be current because of window movements. Nonetheless, it is safe to retrieve and use the system clipping region within the [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)-[EndPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-endpaint) block during [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) processing. In this case, the system region is the intersection of the update region and the current visible area of the window. Any window movement following the return of **GetRandomRgn** and before **EndPaint** will result in a new **WM_PAINT** message. Any other use of the SYSRGN flag may result in painting errors in your application.

The region returned is in screen coordinates.

## See also

[BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)

[Clipping Functions](https://learn.microsoft.com/windows/desktop/gdi/clipping-functions)

[Clipping Overview](https://learn.microsoft.com/windows/desktop/gdi/clipping)

[EndPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-endpaint)

[ExtSelectClipRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extselectcliprgn)

[GetClipBox](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getclipbox)

[GetClipRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcliprgn)

[GetRegionData](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getregiondata)

[OffsetRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-offsetrgn)