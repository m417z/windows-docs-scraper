# SetThreadDpiHostingBehavior function

## Description

Sets the thread's [DPI_HOSTING_BEHAVIOR](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_hosting_behavior). This behavior allows windows created in the thread to host child windows with a different **DPI_AWARENESS_CONTEXT**.

## Parameters

### `value`

The new [DPI_HOSTING_BEHAVIOR](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_hosting_behavior) value for the current thread.

## Return value

The previous [DPI_HOSTING_BEHAVIOR](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_hosting_behavior) for the thread. If the hosting behavior passed in is invalid, the thread will not be updated and the return value will be **DPI_HOSTING_BEHAVIOR_INVALID**. You can use this value to restore the old **DPI_HOSTING_BEHAVIOR** after overriding it with a predefined value.

## Remarks

[DPI_HOSTING_BEHAVIOR](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_hosting_behavior) enables a mixed content hosting behavior, which allows parent windows created in the thread to host child windows with a different [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) value. This property only effects new windows created within this thread while the mixed hosting behavior is active. A parent window with this hosting behavior is able to host child windows with different **DPI_AWARENESS_CONTEXT** values, regardless of whether the child windows have mixed hosting behavior enabled.

This hosting behavior does not allow for windows with per-monitor **DPI_AWARENESS_CONTEXT** values to be hosted until windows with **DPI_AWARENESS_CONTEXT** values of system or unaware.

To avoid unexpected outcomes, a thread's **DPI_HOSTING_BEHAVIOR** should be changed to support mixed hosting behaviors only when creating a new window which needs to support those behaviors. Once that window is created, the hosting behavior should be switched back to its default value.

This API is used to change the thread's **DPI_HOSTING_BEHAVIOR** from its default value. This is only necessary if your app needs to host child windows from plugins and third-party components that do not support per-monitor-aware context. This is most likely to occur if you are updating complex applications to support per-monitor **DPI_AWARENESS_CONTEXT** behaviors.

Enabling mixed hosting behavior will not automatically adjust the thread's **DPI_AWARENESS_CONTEXT** to be compatible with legacy content. The thread's awareness context must still be manually changed before new windows are created to host such content.

## See also

[DPI_HOSTING_BEHAVIOR](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_hosting_behavior)

[GetThreadDpiHostingBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getthreaddpihostingbehavior)

[GetWindowDpiHostingBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowdpihostingbehavior)