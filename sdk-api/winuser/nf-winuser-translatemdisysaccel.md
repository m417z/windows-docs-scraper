# TranslateMDISysAccel function

## Description

Processes accelerator keystrokes for window menu commands of the multiple-document interface (MDI) child windows associated with the specified MDI client window. The function translates [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup) and [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown) messages to [WM_SYSCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-syscommand) messages and sends them to the appropriate MDI child windows.

## Parameters

### `hWndClient` [in]

Type: **HWND**

A handle to the MDI client window.

### `lpMsg` [in]

Type: **LPMSG**

A pointer to a message retrieved by using the [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage) or [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) function. The message must be an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure and contain message information from the application's message queue.

## Return value

Type: **BOOL**

If the message is translated into a system command, the return value is nonzero.

If the message is not translated into a system command, the return value is zero.

## See also

- [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)
- [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)
- [Multiple Document Interface](https://learn.microsoft.com/windows/desktop/winmsg/multiple-document-interface)
- [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)
- [TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translateacceleratora)
- [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown)
- [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup)
- [WM_SYSCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-syscommand)
- [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)