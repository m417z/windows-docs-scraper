# LogicalToPhysicalPoint function

## Description

Converts the logical coordinates of a point in a window to physical coordinates.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window whose transform is used for the conversion. Top level windows are fully supported. In the case of child windows, only the area of overlap between the parent and the child window is converted.

### `lpPoint` [in, out]

Type: **LPPOINT**

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that specifies the logical coordinates to be converted. The new physical coordinates are copied into this structure if the function succeeds.

## Remarks

Windows Vista introduces the concept of physical coordinates. Desktop Window Manager (DWM) scales non-dots per inch (dpi) aware windows when the display is high dpi. The window seen on the screen corresponds to the physical coordinates. The application continues to work in logical space. Therefore, the application's view of the window is different from that which appears on the screen. For scaled windows, logical and physical coordinates are different.

**LogicalToPhysicalPoint** is a transformation API that can be called by a process that declares itself as dpi aware. The function uses the window identified by the *hWnd* parameter and the logical coordinates given in the [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure to compute the physical coordinates.

The **LogicalToPhysicalPoint** function replaces the logical coordinates in the [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure with the physical coordinates. The physical coordinates are relative to the upper-left corner of the screen. The coordinates have to be inside the client area of *hWnd*.

On all platforms, **LogicalToPhysicalPoint** will fail on a window that has either 0 width or height; an application must first establish a non-0 width and height by calling, for example, [MoveWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-movewindow). On some versions of Windows (including Windows 7), **LogicalToPhysicalPoint** will still fail if **MoveWindow** has been called after a call to [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow) with **SH_HIDE** has hidden the window.

In Windows 8, system–DPI aware applications translate between physical and logical space using PhysicalToLogicalPoint and LogicalToPhysicalPoint. In Windows 8.1, the additional virtualization of the system and inter-process communications means that for the majority of applications, you do not need these APIs. As a result, in Windows 8.1, PhysicalToLogicalPoint and LogicalToPhysicalPoint no longer transform points. The system returns all points to an application in its own coordinate space.
This behavior preserves functionality for the majority of applications, but there are some exceptions in which you must make changes to ensure that the application works as expected.
In those cases, use [PhysicalToLogicalPointForPerMonitorDPI](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-physicaltologicalpointforpermonitordpi) and [LogicalToPhysicalPointForPerMonitorDPI.](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-logicaltophysicalpointforpermonitordpi)