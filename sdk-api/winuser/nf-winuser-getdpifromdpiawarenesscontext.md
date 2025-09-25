# GetDpiFromDpiAwarenessContext function

## Description

Retrieves the DPI from a given [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) handle. This enables you to determine the DPI of a thread without needed to examine a window created within that thread.

## Parameters

### `value`

The **DPI_AWARENESS_CONTEXT** handle to examine.

## Return value

The DPI value associated with the **DPI_AWARENESS_CONTEXT** handle.

## Remarks

[DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) handles associated with values of **DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE** and **DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2** will return a value of 0 for their DPI. This is because the DPI of a per-monitor-aware window can change, and the actual DPI cannot be returned without the window's HWND.

## See also

[DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context)