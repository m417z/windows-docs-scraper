# DefMDIChildProcW function

## Description

Provides default processing for any window message that the window procedure of a multiple-document interface (MDI) child window does not process. A window message not processed by the window procedure must be passed to the **DefMDIChildProc** function, not to the [DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca) function.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the MDI child window.

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

The return value specifies the result of the message processing and depends on the message.

## Remarks

The **DefMDIChildProc** function assumes that the parent window of the MDI child window identified by the *hWnd* parameter was created with the **MDICLIENT** class.

When an application's window procedure does not handle a message, it typically passes the message to the [DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca) function to process the message. MDI applications use the [DefFrameProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defframeproca) and **DefMDIChildProc** functions instead of **DefWindowProc** to provide default message processing. All messages that an application would usually pass to **DefWindowProc** (such as nonclient messages and the [WM_SETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-settext) message) should be passed to **DefMDIChildProc** instead. In addition, **DefMDIChildProc** also handles the following messages.

| Message | Response |
| --- | --- |
| [WM_CHILDACTIVATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-childactivate) | Performs activation processing when MDI child windows are sized, moved, or displayed. This message must be passed. |
| [WM_GETMINMAXINFO](https://learn.microsoft.com/windows/desktop/winmsg/wm-getminmaxinfo) | Calculates the size of a maximized MDI child window, based on the current size of the MDI client window. |
| [WM_MENUCHAR](https://learn.microsoft.com/windows/desktop/menurc/wm-menuchar) | Passes the message to the MDI frame window. |
| [WM_MOVE](https://learn.microsoft.com/windows/desktop/winmsg/wm-move) | Recalculates MDI client scroll bars if they are present. |
| [WM_SETFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-setfocus) | Activates the child window if it is not the active MDI child window. |
| [WM_SIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-size) | Performs operations necessary for changing the size of a window, especially for maximizing or restoring an MDI child window. Failing to pass this message to the **DefMDIChildProc** function produces highly undesirable results. |
| [WM_SYSCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-syscommand) | Handles window menu commands: **SC_NEXTWINDOW**, **SC_PREVWINDOW**, **SC_MOVE**, **SC_SIZE**, and **SC_MAXIMIZE**. |

> [!NOTE]
> The winuser.h header defines DefMDIChildProc as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[DefFrameProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defframeproca)

[DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca)

[Multiple Document Interface](https://learn.microsoft.com/windows/desktop/winmsg/multiple-document-interface)

**Reference**

[WM_CHILDACTIVATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-childactivate)

[WM_GETMINMAXINFO](https://learn.microsoft.com/windows/desktop/winmsg/wm-getminmaxinfo)

[WM_MENUCHAR](https://learn.microsoft.com/windows/desktop/menurc/wm-menuchar)

[WM_MOVE](https://learn.microsoft.com/windows/desktop/winmsg/wm-move)

[WM_SETFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-setfocus)

[WM_SETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-settext)

[WM_SIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-size)

[WM_SYSCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-syscommand)