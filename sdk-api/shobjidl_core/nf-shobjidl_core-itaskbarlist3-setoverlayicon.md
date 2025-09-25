# ITaskbarList3::SetOverlayIcon

## Description

Applies an overlay to a taskbar button to indicate application status or a notification to the user.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle of the window whose associated taskbar button receives the overlay. This handle must belong to a calling process associated with the button's application and must be a valid **HWND** or the call is ignored.

### `hIcon` [in]

Type: **HICON**

The handle of an icon to use as the overlay. This should be a small icon, measuring 16x16 pixels at 96 dpi. If an overlay icon is already applied to the taskbar button, that existing overlay is replaced.

This value can be **NULL**. How a **NULL** value is handled depends on whether the taskbar button represents a single window or a group of windows.

* If the taskbar button represents a single window, the overlay icon is removed from the display.
* If the taskbar button represents a group of windows and a previous overlay is still available (received earlier than the current overlay, but not yet freed by a **NULL** value), then that previous overlay is displayed in place of the current overlay.

It is the responsibility of the calling application to free *hIcon* when it is no longer needed. This can generally be done after you call **SetOverlayIcon** because the taskbar makes and uses its own copy of the icon.

### `pszDescription` [in]

Type: **LPCWSTR**

A pointer to a string that provides an alt text version of the information conveyed by the overlay, for accessibility purposes.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In versions of Windows earlier than Windows 7, applications often used icons in the notification area of the taskbar to display application status and notifications to the user. The Windows 7 taskbar allows an application to provide that same sort of user feedback through its taskbar button, centralizing more of the application information in one place. These overlays are similar to existing overlays used for shortcut icons or security notifications, displayed at the lower-right corner of the button.

The following illustration shows an overlay (the small, green square that indicates the user status as "Available") applied to the far-right taskbar button.

![Screen shot of the Windows Messenger taskbar button with an overlay to indicate an Available status](https://learn.microsoft.com/windows/win32/api/shobjidl_core/images/TaskbarOverlay.png)
Icon overlays serve as a contextual notification of status, and are intended to negate the need for a separate notification area status icon to communicate that information to the user. The application designer must decide during the development cycle which method—icon overlay or notification area status icon—best serves that application. Overlay icons are intended to supply important, long-standing status or notifications such as network status, messenger status, or new mail. They should not be frequently changed, nor should they be animated.

To display an overlay icon, the taskbar must be in the default large icon mode. If the taskbar is configured through **Taskbar and Start Menu Properties** to show small icons, overlays cannot be applied and calls to this method are ignored.

Because a single overlay is applied to the taskbar button instead of to the individual window thumbnails, this is a per-group feature rather than per-window. Requests for overlay icons can be received from individual windows in a taskbar group, but they do not queue. The last overlay received is the overlay shown. If the last overlay received is removed, the overlay that it replaced is restored so long as it is still active. As an example, windows 1, 2, and 3 set, in order, overlays A, B, and C. Because overlay C was received last, it is shown on the taskbar button. Window 2 calls **SetOverlayIcon** with a **NULL** value to remove overlay B. Window 3 then does the same to remove overlay C. Because window 1's overlay A is still active, that overlay is then displayed on the taskbar button.

If Windows Explorer shuts down unexpectedly, overlays are not restored when Windows Explorer is restored. The application should wait to receive the **TaskbarButtonCreated** message that indicates that Windows Explorer has restarted and the taskbar button has been re-created, and then call **SetOverlayIcon** again to reapply the overlay.

## See also

[ITaskbarList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist)

[ITaskbarList2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist2)

[ITaskbarList3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist3)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)