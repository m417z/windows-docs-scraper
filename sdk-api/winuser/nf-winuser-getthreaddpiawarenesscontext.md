# GetThreadDpiAwarenessContext function

## Description

Gets the [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) for the current thread.

## Return value

The current [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) for the thread.

## Remarks

This method will return the latest [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) sent to [SetThreadDpiAwarenessContext](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddpiawarenesscontext). If **SetThreadDpiAwarenessContext** was never called for this thread, then the return value will equal the default **DPI_AWARENESS_CONTEXT** for the process.

## See also

[DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_awareness)

[GetAwarenessFromDpiAwarenessContext](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getawarenessfromdpiawarenesscontext)

[SetThreadDpiAwarenessContext](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddpiawarenesscontext)