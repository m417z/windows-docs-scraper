# PrintWindow function

## Description

The **PrintWindow** function copies a visual window into the specified device context (DC), typically a printer DC.

## Parameters

### `hwnd`

A handle to the window that will be copied.

### `hdcBlt`

A handle to the device context.

### `nFlags`

The drawing options. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PW_CLIENTONLY** | Only the client area of the window is copied to *hdcBlt*. By default, the entire window is copied. |

## Return value

If the function succeeds, it returns a nonzero value.

If the function fails, it returns zero.

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The application that owns the window referenced by hWnd processes the **PrintWindow** call and renders the image in the device context that is referenced by *hdcBlt*. The application receives a [WM_PRINT](https://learn.microsoft.com/windows/desktop/gdi/wm-print) message or, if the **PW_PRINTCLIENT** flag is specified, a [WM_PRINTCLIENT](https://learn.microsoft.com/windows/desktop/gdi/wm-printclient) message.
For more information, see **WM_PRINT** and **WM_PRINTCLIENT**.

## See also

[Painting and Drawing Messages](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-messages)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[WM_PRINT](https://learn.microsoft.com/windows/desktop/gdi/wm-print)

[WM_PRINTCLIENT](https://learn.microsoft.com/windows/desktop/gdi/wm-printclient)