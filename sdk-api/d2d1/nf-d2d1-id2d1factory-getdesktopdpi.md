## Description

> [!IMPORTANT]
> **ID2D1Factory::GetDesktopDpi** is deprecated. For a desktop app, instead use [GetDpiForWindow](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getdpiforwindow). For a Universal Windows Platform (UWP) app, instead use [DisplayInformation::LogicalDpi](https://learn.microsoft.com/uwp/api/windows.graphics.display.displayinformation.logicaldpi).

Retrieves the current desktop dots per inch (DPI). To refresh this value, call [ReloadSystemMetrics](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1factory-reloadsystemmetrics).

## Parameters

### `dpiX` [out]

Type: **FLOAT***

When this method returns, contains the horizontal DPI of the desktop. You must allocate storage for this parameter.

### `dpiY` [out]

Type: **FLOAT***

When this method returns, contains the vertical DPI of the desktop. You must allocate storage for this parameter.

## Remarks

Use this method to obtain the system DPI when setting physical pixel values, such as when you specify the size of a window.

## See also

* [GetDpiForWindow](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getdpiforwindow)
* [ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory)
* [How to ensure that your application displays properly on a high-DPI display](https://learn.microsoft.com/windows/win32/Direct2D/how-to--size-a-window-properly-for-high-dpi-displays)