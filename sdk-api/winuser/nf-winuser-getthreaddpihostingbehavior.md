# GetThreadDpiHostingBehavior function

## Description

Retrieves the [DPI_HOSTING_BEHAVIOR](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_hosting_behavior) from the current thread.

## Return value

The [DPI_HOSTING_BEHAVIOR](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_hosting_behavior) of the current thread.

## Remarks

This API returns the hosting behavior set by an earlier call of [SetThreadDpiHostingBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddpihostingbehavior), or **DPI_HOSTING_BEHAVIOR_DEFAULT** if no earlier call has been made.

## See also

[DPI_HOSTING_BEHAVIOR](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_hosting_behavior)

[GetWindowDpiHostingBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowdpihostingbehavior)

[SetThreadDpiHostingBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddpihostingbehavior)