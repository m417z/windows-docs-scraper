# GetDC function

## Description

The **GetDC** function retrieves a handle to a device context (DC) for the client area of a specified window or for the entire screen. You can use the returned handle in subsequent GDI functions to draw in the DC. The device context is an opaque data structure, whose values are used internally by GDI.

The [GetDCEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdcex) function is an extension to **GetDC**, which gives an application more control over how and whether clipping occurs in the client area.

## Parameters

### `hWnd` [in]

A handle to the window whose DC is to be retrieved. If this value is **NULL**, **GetDC** retrieves the DC for the entire screen.

## Return value

If the function succeeds, the return value is a handle to the DC for the specified window's client area.

If the function fails, the return value is **NULL**.

## Remarks

The **GetDC** function retrieves a common, class, or private DC depending on the class style of the specified window. For class and private DCs, **GetDC** leaves the previously assigned attributes unchanged. However, for common DCs, **GetDC** assigns default attributes to the DC each time it is retrieved. For example, the default font is System, which is a bitmap font. Because of this, the handle to a common DC returned by **GetDC** does not tell you what font, color, or brush was used when the window was drawn. To determine the font, call [GetTextFace](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextfacea).

Note that the handle to the DC can only be used by a single thread at any one time.

After painting with a common DC, the [ReleaseDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-releasedc) function must be called to release the DC. Class and private DCs do not have to be released. **ReleaseDC** must be called from the same thread that called **GetDC**. The number of DCs is limited only by available memory.

#### Examples

For an example, see [Drawing with the Mouse](https://learn.microsoft.com/windows/desktop/gdi/drawing-with-the-mouse).

## See also

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[GetDCEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdcex)

[GetTextFace](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextfacea)

[GetWindowDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowdc)

[ReleaseDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-releasedc)

[WindowFromDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-windowfromdc)