# DispatchMessageW function

## Description

Dispatches a message to a window procedure. It is typically used to dispatch a message retrieved by the [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage) function.

## Parameters

### `lpMsg` [in]

Type: **const [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)***

A pointer to a structure that contains the message.

## Return value

Type: **LRESULT**

The return value specifies the value returned by the window procedure. Although its meaning depends on the message being dispatched, the return value generally is ignored.

## Remarks

The [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure must contain valid message values. If the *lpmsg* parameter points to a [WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer) message and the *lParam* parameter of the **WM_TIMER** message is not **NULL**, *lParam* points to a function that is called instead of the window procedure.

Note that the application is responsible for retrieving and dispatching input messages to the dialog box. Most applications use the main message loop for this. However, to permit the user to move to and to select controls by using the keyboard, the application must call [IsDialogMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-isdialogmessagea). For more information, see [Dialog Box Keyboard Interface](https://learn.microsoft.com/windows/desktop/dlgbox/dlgbox-programming-considerations).

#### Examples

For an example, see [Creating a Message Loop](https://learn.microsoft.com/windows/desktop/winmsg/using-messages-and-message-queues).

> [!NOTE]
> The winuser.h header defines DispatchMessage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)

[IsDialogMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-isdialogmessagea)

[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)

**Reference**

[TranslateMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translatemessage)

[WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer)