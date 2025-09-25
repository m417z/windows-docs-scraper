# GetWindowDpiAwarenessContext function

## Description

Returns the [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) associated with a window.

## Parameters

### `hwnd` [in]

The window to query.

## Return value

The [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) for the provided window. If the window is not valid, the return value is **NULL**.

## Remarks

**Important**

The return value of **GetWindowDpiAwarenessContext** is not affected by the [DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_awareness) of the current thread. It only indicates the context of the window specified by the *hwnd* input parameter.

## See also

[DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_awareness)

[GetAwarenessFromDpiAwarenessContext](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getawarenessfromdpiawarenesscontext)