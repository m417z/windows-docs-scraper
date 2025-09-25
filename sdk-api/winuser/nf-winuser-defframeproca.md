# DefFrameProcA function

## Description

Provides default processing for any window messages that the window procedure of a multiple-document interface (MDI) frame window does not process. All window messages that are not explicitly processed by the window procedure must be passed to the **DefFrameProc** function, not the [DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca) function.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the MDI frame window.

### `hWndMDIClient` [in]

Type: **HWND**

A handle to the MDI client window.

### `uMsg` [in]

Type: **UINT**

The message to be processed.

### `wParam` [in]

Type: **WPARAM**

Additional message-specific information.

### `lParam` [in]

Type: **LPARAM**

Additional message-specific information.

## Return value

Type: **LRESULT**

The return value specifies the result of the message processing and depends on the message. If the *hWndMDIClient* parameter is **NULL**, the return value is the same as for the [DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca) function.

## Remarks

When an application's window procedure does not handle a message, it typically passes the message to the [DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca) function to process the message. MDI applications use the **DefFrameProc** and [DefMDIChildProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defmdichildproca) functions instead of **DefWindowProc** to provide default message processing. All messages that an application would usually pass to **DefWindowProc** (such as nonclient messages and the [WM_SETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-settext) message) should be passed to **DefFrameProc** instead. The **DefFrameProc** function also handles the following messages.

| Message | Response |
| --- | --- |
| [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) | Activates the MDI child window that the user chooses. This message is sent when the user chooses an MDI child window from the window menu of the MDI frame window. The window identifier accompanying this message identifies the MDI child window to be activated. |
| [WM_MENUCHAR](https://learn.microsoft.com/windows/desktop/menurc/wm-menuchar) | Opens the window menu of the active MDI child window when the user presses the ALT+ – (minus) key combination. |
| [WM_SETFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-setfocus) | Passes the keyboard focus to the MDI client window, which in turn passes it to the active MDI child window. |
| [WM_SIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-size) | Resizes the MDI client window to fit in the new frame window's client area. If the frame window procedure sizes the MDI client window to a different size, it should not pass the message to the [DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca) function. |

> [!NOTE]
> The winuser.h header defines DefFrameProc as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[DefMDIChildProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defmdichildproca)

[DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca)

[Multiple Document Interface](https://learn.microsoft.com/windows/desktop/winmsg/multiple-document-interface)

**Reference**

[WM_SETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-settext)