# DefScreenSaverProc function

## Description

Provides default processing for any messages that a screen saver application does not process.

## Parameters

### `hWnd`

Type: **HWND**

The identifier of the screen saver window.

### `msg`

Type: **UINT**

The message to be processed. The **DefScreenSaverProc** function responds to messages that affect the screen saver's operation, as detailed in the Remarks section.

If a screen saver application must perform a different action in response to any of these messages, the application's [ScreenSaverProc](https://learn.microsoft.com/windows/desktop/api/scrnsave/nf-scrnsave-screensaverproc) window procedure should process the message.

### `wParam`

Type: **WPARAM**

Additional message-specific information.

### `lParam`

Type: **LPARAM**

Additional message-specific information.

## Return value

Type: **LONG**

The return value specifies the result of the message processing and depends on the message sent.

## Remarks

A screen saver application's [ScreenSaverProc](https://learn.microsoft.com/windows/desktop/api/scrnsave/nf-scrnsave-screensaverproc) window procedure should use **DefScreenSaverProc** instead of the [DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca) function to provide default message processing. The **DefScreenSaverProc** function passes any messages that do not affect screen saver operation to **DefWindowProc**.

The following table describes how the **DefScreenSaverProc** processes a variety of window messages.

| Message | Description |
| --- | --- |
| [WM_ACTIVATE](https://learn.microsoft.com/windows/desktop/inputdev/wm-activate), [WM_ACTIVATEAPP](https://learn.microsoft.com/windows/desktop/winmsg/wm-activateapp), [WM_NCACTIVATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-ncactivate) | Closes the screen saver if the *wParam* parameter is **FALSE**. A *wParam* value of **FALSE** indicates that the screen saver is losing the input focus. The screen saver is closed by sending a [WM_CLOSE](https://learn.microsoft.com/windows/desktop/winmsg/wm-close) message. |
| [WM_SETCURSOR](https://learn.microsoft.com/windows/desktop/menurc/wm-setcursor) | Removes the cursor from the screen by setting the cursor to **NULL**. |
| [WM_LBUTTONDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-lbuttondown), [WM_RBUTTONDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-rbuttondown), [WM_MBUTTONDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-mbuttondown), [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown), [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup), [WM_MOUSEMOVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousemove) | Calls the [PostQuitMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postquitmessage) function to close the screen saver. |
| [WM_DESTROY](https://learn.microsoft.com/windows/desktop/winmsg/wm-destroy) | Posts a [WM_CLOSE](https://learn.microsoft.com/windows/desktop/winmsg/wm-close) message to close the screen saver window. |
| [WM_SYSCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-syscommand) | Returns **FALSE** if the *wParam* parameter of [WM_SYSCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-syscommand) is either **SC_CLOSE** or **SC_SCREENSAVE**. |