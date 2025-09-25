# SetProcessDPIAware function

## Description

Sets the process-default DPI awareness to system-DPI awareness. This is equivalent to calling [SetProcessDpiAwarenessContext](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setprocessdpiawarenesscontext) with a [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) value of DPI_AWARENESS_CONTEXT_SYSTEM_AWARE.

> [!NOTE]
> It is recommended that you set the process-default DPI awareness via application manifest, not an API call. See [Setting the default DPI awareness for a process](https://learn.microsoft.com/windows/win32/hidpi/setting-the-default-dpi-awareness-for-a-process) for more information. Setting the process-default DPI awareness via API call can lead to unexpected application behavior.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero. Otherwise, the return value is zero.

## Remarks

For more information, see [Setting the default DPI awareness for a process](https://learn.microsoft.com/windows/win32/hidpi/setting-the-default-dpi-awareness-for-a-process).

## See also

[Setting the default DPI awareness for a process](https://learn.microsoft.com/windows/win32/hidpi/setting-the-default-dpi-awareness-for-a-process)