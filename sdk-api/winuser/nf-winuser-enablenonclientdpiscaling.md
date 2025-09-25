# EnableNonClientDpiScaling function

## Description

In high-DPI displays, enables automatic display scaling of the non-client area portions of the specified top-level window. Must be called during the initialization of that window.

**Note** Applications running at a [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) of **DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2** automatically scale their non-client areas by default. They do not need to call this function.

## Parameters

### `hwnd` [in]

The window that should have automatic scaling enabled.

## Return value

If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Calling this function will enable non-client scaling for an individual top-level window with [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) of **DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE**. If instead you are not using per-window awareness, and your entire process is running in **DPI_AWARENESS_PER_MONITOR_AWARE** mode, calling this function will enable non-client scaling in top-level windows in your process.

If neither of those are true, or if you call this method from any other window, then it will fail and return a value of zero.

Non-client scaling for top-level windows is not enabled by default. You must call this API to enable it for each individual top-level window for which you wish to have the non-client area scale automatically. Once you do, there is no way to disable it. Enabling non-client scaling means that all the areas drawn by the system for the window will automatically scale in response to DPI changes on the window. That includes areas like the caption bar, the scrollbars, and the menu bar. You want to call **EnableNonClientDpiScaling** when you want the operating system to be responsible for rendering these areas automatically at the correct size based on the DPI of the monitor.

Calling this function enables non-client scaling for top-level windows only. Child windows are unaffected.

This function must be called from WM_NCCREATE during the initialization of a new window. An example call might look like this:

```
case WM_NCCREATE:
{
    EnableNonClientDpiScaling(hwnd);
    return (DefWindowProc(hwnd, message, wParam, lParam));
}
```