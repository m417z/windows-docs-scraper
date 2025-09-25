# SetThreadDpiAwarenessContext function

## Description

Set the DPI awareness for the current thread to the provided value.

## Parameters

### `dpiContext` [in]

The new [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) for the current thread. This context includes the [DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_awareness) value.

## Return value

The old [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) for the thread. If the *dpiContext* is invalid, the thread will not be updated and the return value will be **NULL**. You can use this value to restore the old **DPI_AWARENESS_CONTEXT** after overriding it with a predefined value.

## Remarks

Use this API to change the [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) for the thread from the default value for the app.

## See also

[DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_awareness)