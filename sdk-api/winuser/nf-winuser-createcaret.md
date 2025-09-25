# CreateCaret function

## Description

Creates a new shape for the system caret and assigns ownership of the caret to the specified window. The caret shape can be a line, a block, or a bitmap.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window that owns the caret.

### `hBitmap` [in, optional]

Type: **HBITMAP**

A handle to the bitmap that defines the caret shape. If this parameter is **NULL**, the caret is solid. If this parameter is `(HBITMAP) 1`, the caret is gray. If this parameter is a bitmap handle, the caret is the specified bitmap. The bitmap handle must have been created by the [CreateBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbitmap), [CreateDIBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibitmap), or [LoadBitmap](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadbitmapa) function.
The caret is drawn to the screen via the XOR operation.

If *hBitmap* is a bitmap handle, **CreateCaret** ignores the *nWidth* and *nHeight* parameters; the bitmap defines its own width and height.
The application should not delete the *hBitmap* until the caret is destroyed or replaced by another caret.

### `nWidth` [in]

Type: **int**

The width of the caret, in logical units. If this parameter is zero, the width is set to the system-defined window border width. If *hBitmap* is a bitmap handle, **CreateCaret** ignores this parameter.

### `nHeight` [in]

Type: **int**

The height of the caret, in logical units. If this parameter is zero, the height is set to the system-defined window border height. If *hBitmap* is a bitmap handle, **CreateCaret** ignores this parameter.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The *nWidth* and *nHeight* parameters specify the caret's width and height, in logical units; the exact width and height, in pixels, depend on the window's mapping mode.

**CreateCaret** automatically destroys the previous caret shape, if any, regardless of the window that owns the caret. The caret is hidden until the application calls the [ShowCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showcaret) function to make the caret visible.

The system provides one caret per queue. A window should create a caret only when it has the keyboard focus or is active. The window should destroy the caret before losing the keyboard focus or becoming inactive.

### DPI Virtualization

This API does not participate in DPI virtualization. The width and height parameters are interpreted as logical sizes in terms of the window in question. The calling thread is not taken into consideration.

## See also

[Carets](https://learn.microsoft.com/windows/desktop/menurc/carets)

**Conceptual**

[CreateBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbitmap)

[CreateDIBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibitmap)

[DestroyCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroycaret)

[GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)

[HideCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-hidecaret)

[LoadBitmap](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadbitmapa)

**Other Resources**

**Reference**

[ShowCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showcaret)