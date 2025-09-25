# GetWindowDpiHostingBehavior function

## Description

Returns the [DPI_HOSTING_BEHAVIOR](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_hosting_behavior) of the specified window.

## Parameters

### `hwnd`

The handle for the window to examine.

## Return value

The [DPI_HOSTING_BEHAVIOR](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_hosting_behavior) of the specified window.

## Remarks

This API allows you to examine the hosting behavior of a window after it has been created. A window's hosting behavior is the hosting behavior of the thread in which the window was created, as set by a call to [SetThreadDpiHostingBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddpihostingbehavior). This is a permanent value and cannot be changed after the window is created, even if the thread's hosting behavior is changed.

## See also

[DPI_HOSTING_BEHAVIOR](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_hosting_behavior)

[GetThreadDpiHostingBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getthreaddpihostingbehavior)

[SetThreadDpiHostingBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddpihostingbehavior)