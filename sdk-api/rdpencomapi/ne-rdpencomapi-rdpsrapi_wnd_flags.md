# RDPSRAPI_WND_FLAGS enumeration

## Description

Defines values for the type of window. These flags can be retrieved from the [IRDPSRAPIWindow](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiwindow) interface that represents each Win32 window.

The list of windows on the sharing user session can be retrieved on both the sharer and the viewer through the [IRDPSRAPIApplicationFilter](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiapplicationfilter) interface by calling the [get_Windows](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapiapplicationfilter-get_windows) method.

## Constants

### `WND_FLAG_PRIVILEGED:1`

The window is part of an application that runs at a higher level than the current process. This flag indicates that the window cannot be shared. Applications can use this flag to prevent the user from sharing it either by disabling the entry for the window in the user interface or by not showing the entry.

## See also

[Windows Desktop Sharing Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/rdp/windows-desktop-sharing-enumerations)