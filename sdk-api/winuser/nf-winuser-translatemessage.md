# TranslateMessage function

## Description

Translates virtual-key messages into character messages. The character messages are posted to the calling thread's message queue, to be read the next time the thread calls the [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage) or [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) function.

## Parameters

### `lpMsg` [in]

Type: **const [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)***

A pointer to an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure that contains message information retrieved from the calling thread's message queue by using the [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage) or [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) function.

## Return value

Type: **BOOL**

If the message is translated (that is, a character message is posted to the thread's message queue), the return value is nonzero.

If the message is [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown), [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup), [WM_SYSKEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeydown), or [WM_SYSKEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeyup), the return value is nonzero, regardless of the translation.

If the message is not translated (that is, a character message is not posted to the thread's message queue), the return value is zero.

## Remarks

The **TranslateMessage** function does not modify the message pointed to by the *lpMsg* parameter.

[WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown) and [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup) combinations produce a [WM_CHAR](https://learn.microsoft.com/windows/desktop/inputdev/wm-char) or [WM_DEADCHAR](https://learn.microsoft.com/windows/desktop/inputdev/wm-deadchar) message. [WM_SYSKEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeydown) and [WM_SYSKEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeyup) combinations produce a [WM_SYSCHAR](https://learn.microsoft.com/windows/desktop/menurc/wm-syschar) or [WM_SYSDEADCHAR](https://learn.microsoft.com/windows/desktop/inputdev/wm-sysdeadchar) message.

**TranslateMessage** produces [WM_CHAR](https://learn.microsoft.com/windows/desktop/inputdev/wm-char) messages only for keys that are mapped to ASCII characters by the keyboard driver.

If applications process virtual-key messages for some other purpose, they should not call **TranslateMessage**. For instance, an application should not call **TranslateMessage** if the [TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translateacceleratora) function returns a nonzero value. Note that the application is responsible for retrieving and dispatching input messages to the dialog box. Most applications use the main message loop for this. However, to permit the user to move to and to select controls by using the keyboard, the application must call [IsDialogMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-isdialogmessagea). For more information, see [Dialog Box Keyboard Interface](https://learn.microsoft.com/windows/desktop/dlgbox/dlgbox-programming-considerations).

#### Examples

For an example, see [Creating a Message Loop](https://learn.microsoft.com/windows/desktop/winmsg/using-messages-and-message-queues).

## See also

- [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)
- [IsDialogMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-isdialogmessagea)
- [Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)
- [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)
- [TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translateacceleratora)
- [WM_CHAR](https://learn.microsoft.com/windows/desktop/inputdev/wm-char)
- [WM_DEADCHAR](https://learn.microsoft.com/windows/desktop/inputdev/wm-deadchar)
- [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown)
- [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup)
- [WM_SYSCHAR](https://learn.microsoft.com/windows/desktop/menurc/wm-syschar)
- [WM_SYSDEADCHAR](https://learn.microsoft.com/windows/desktop/inputdev/wm-sysdeadchar)
- [WM_SYSKEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeydown)
- [WM_SYSKEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeyup)
- [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)