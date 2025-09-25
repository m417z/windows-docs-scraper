# ScreenSaverProc function

## Description

Receives messages sent to the specified screen saver window.

## Parameters

### `hWnd`

Type: **HWND**

An identifier of the window.

### `message`

Type: **UINT**

A message sent to the screen saver window.

### `wParam`

Type: **WPARAM**

Additional message-specific information.

### `lParam`

Type: **LPARAM**

Additional message-specific information.

## Return value

Type: **LONG**

The return value is the result of the message processing and depends on the message sent.

## Remarks

A screen saver's **ScreenSaverProc** window procedure should use the [DefScreenSaverProc](https://learn.microsoft.com/windows/desktop/api/scrnsave/nf-scrnsave-defscreensaverproc) function instead of the [DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca) function to provide default message processing. The **DefScreenSaverProc** function passes any messages that do not affect screen saver operations to **DefWindowProc**.

The **ScreenSaverProc** function must be exported by including it in the EXPORTS statement in the application's module-definition (.def) file.