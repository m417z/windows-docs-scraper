# GetWindowDisplayAffinity function

## Description

Retrieves the current display affinity setting, from any process, for a given window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window.

### `pdwAffinity` [out]

Type: **DWORD***

A pointer to a variable that receives the display affinity setting.
See [SetWindowDisplayAffinity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowdisplayaffinity) for a list of affinity settings and their meanings.

## Return value

Type: **BOOL**

This function succeeds only when the window is layered and Desktop Windows Manager
is composing the desktop. If this function succeeds, it returns **TRUE**; otherwise, it returns **FALSE**.
To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function and [SetWindowDisplayAffinity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowdisplayaffinity) are designed to support the window content protection feature unique to Windows 7. This feature enables applications to protect their
own onscreen window content from being captured or copied via a specific set of public operating system features
and APIs. However, it works only when the Desktop Window Manager (DWM) is composing the desktop.

It is important to note that unlike a security feature or an implementation of Digital Rights Management (DRM), there is no guarantee that
using [SetWindowDisplayAffinity](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowdisplayaffinity)
and **GetWindowDisplayAffinity**, and other necessary functions such as [DwmIsCompositionEnabled](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmiscompositionenabled), will strictly protect windowed content, as in the case where someone takes a photograph of the screen.

## See also

**Conceptual**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)