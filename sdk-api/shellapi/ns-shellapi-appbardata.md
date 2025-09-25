# APPBARDATA structure

## Description

Contains information about a system appbar message.

## Members

### `cbSize`

Type: **DWORD**

The size of the structure, in bytes.

### `hWnd`

Type: **HWND**

The handle to the appbar window. Not all messages use this member. See the individual message page to see if you need to provide an **hWind** value.

### `uCallbackMessage`

Type: **UINT**

An application-defined message identifier. The application uses the specified identifier for notification messages that it sends to the appbar identified by the **hWnd** member. This member is used when sending the [ABM_NEW](https://learn.microsoft.com/windows/desktop/shell/abm-new) message.

### `uEdge`

Type: **UINT**

A value that specifies an edge of the screen. This member is used when sending one of these messages:

* [ABM_GETAUTOHIDEBAR](https://learn.microsoft.com/windows/desktop/shell/abm-getautohidebar)
* [ABM_SETAUTOHIDEBAR](https://learn.microsoft.com/windows/desktop/shell/abm-setautohidebar)
* [ABM_GETAUTOHIDEBAREX](https://learn.microsoft.com/windows/desktop/shell/abm-getautohidebarex)
* [ABM_SETAUTOHIDEBAREX](https://learn.microsoft.com/windows/desktop/shell/abm-setautohidebarex)
* [ABM_QUERYPOS](https://learn.microsoft.com/windows/desktop/shell/abm-querypos)
* [ABM_SETPOS](https://learn.microsoft.com/windows/desktop/shell/abm-setpos)

This member can be one of the following values.

#### ABE_BOTTOM

Bottom edge.

#### ABE_LEFT

Left edge.

#### ABE_RIGHT

Right edge.

#### ABE_TOP

Top edge.

### `rc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure whose use varies depending on the message:

* [ABM_GETTASKBARPOS](https://learn.microsoft.com/windows/desktop/shell/abm-gettaskbarpos), [ABM_QUERYPOS](https://learn.microsoft.com/windows/desktop/shell/abm-querypos), [ABM_SETPOS](https://learn.microsoft.com/windows/desktop/shell/abm-setpos): The bounding rectangle, in screen coordinates, of an appbar or the Windows taskbar.
* [ABM_GETAUTOHIDEBAREX](https://learn.microsoft.com/windows/desktop/shell/abm-getautohidebarex), [ABM_SETAUTOHIDEBAREX](https://learn.microsoft.com/windows/desktop/shell/abm-setautohidebarex): The monitor on which the operation is being performed. This information can be retrieved through the [GetMonitorInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmonitorinfoa) function.

### `lParam`

Type: **LPARAM**

A message-dependent value. This member is used with these messages:

* [ABM_SETAUTOHIDEBAR](https://learn.microsoft.com/windows/desktop/shell/abm-setautohidebar)
* [ABM_SETAUTOHIDEBAREX](https://learn.microsoft.com/windows/desktop/shell/abm-setautohidebarex)
* [ABM_SETSTATE](https://learn.microsoft.com/windows/desktop/shell/abm-setstate)

See the individual message pages for details.