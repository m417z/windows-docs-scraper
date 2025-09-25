# SetProcessDpiAwarenessContext function

## Description

Sets the current process to a specified dots per inch (dpi) awareness context. The DPI awareness contexts are from the [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) value.

> [!NOTE]
> It is recommended that you set the process-default DPI awareness via application manifest, not an API call. See [Setting the default DPI awareness for a process](https://learn.microsoft.com/windows/win32/hidpi/setting-the-default-dpi-awareness-for-a-process) for more information. Setting the process-default DPI awareness via API call can lead to unexpected application behavior.

## Parameters

### `value` [in]

A [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) handle to set.

## Return value

This function returns TRUE if the operation was successful, and FALSE otherwise. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Possible errors are **ERROR_INVALID_PARAMETER** for an invalid input, and **ERROR_ACCESS_DENIED** if the default API awareness mode for the process has already been set (via a previous API call or within the application manifest).

## Remarks

This API is a more advanced version of the previously existing [SetProcessDpiAwareness](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-setprocessdpiawareness) API, allowing for the process default to be set to the finer-grained [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) values. Most importantly, this allows you to programmatically set **Per Monitor v2** as the process default value, which is not possible with the previous API.

This method sets the default [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) for all threads within an application. Individual threads can have their DPI awareness changed from the default with the [SetThreadDpiAwarenessContext](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddpiawarenesscontext) method.

You must call this API before you call any APIs that depend on the DPI awareness (including before creating any UI in your process). Once API awareness is set for an app, any future calls to this API will fail. This is true regardless of whether you set the DPI awareness in the manifest or by using this API.

If the DPI awareness level is not set, the default value is **DPI_AWARENESS_CONTEXT_UNAWARE**.

## See also

[DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context)

[SetThreadDpiAwarenessContext](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddpiawarenesscontext)

[Setting the default DPI awareness for a process](https://learn.microsoft.com/windows/win32/hidpi/setting-the-default-dpi-awareness-for-a-process)