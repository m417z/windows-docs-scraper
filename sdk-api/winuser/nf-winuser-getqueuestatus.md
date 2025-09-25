# GetQueueStatus function

## Description

Retrieves the type of messages found in the calling thread's message queue.

## Parameters

### `flags` [in]

Type: **UINT**

The types of messages for which to check. This parameter can be one or more of the following values.

| Value | Meaning |
|-------|---------|
| **QS\_KEY**<br>0x0001 | A [WM\_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup), [WM\_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown), [WM\_SYSKEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeyup), or [WM\_SYSKEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-syskeydown) message is in the queue. |
| **QS\_MOUSEMOVE**<br>0x0002 | A [WM\_MOUSEMOVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousemove) message is in the queue. |
| **QS\_MOUSEBUTTON**<br>0x0004 | A mouse-button message ([WM\_LBUTTONUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-lbuttonup), [WM\_RBUTTONDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-rbuttondown), and so on). |
| **QS\_POSTMESSAGE**<br>0x0008 | A posted message (other than those listed here) is in the queue. For more information, see [PostMessage](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-postmessagew).<br>This value is cleared when you call [GetMessage](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getmessage) or [PeekMessage](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-peekmessagew), whether or not you are filtering messages. |
| **QS\_TIMER**<br>0x0010 | A [WM\_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer) message is in the queue. |
| **QS\_PAINT**<br>0x0020 | A [WM\_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message is in the queue. |
| **QS\_SENDMESSAGE**<br>0x0040 | A message sent by another thread or application is in the queue. For more information, see [SendMessage](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-sendmessagew). |
| **QS\_HOTKEY**<br>0x0080 | A [WM\_HOTKEY](https://learn.microsoft.com/windows/desktop/inputdev/wm-hotkey) message is in the queue. |
| **QS\_ALLPOSTMESSAGE**<br>0x0100 | A posted message (other than those listed here) is in the queue. For more information, see [PostMessage](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-postmessagew).<br>This value is cleared when you call GetMessage or PeekMessage without filtering messages. |
| **QS\_RAWINPUT**<br>0x0400 | Windows XP and newer: A raw input message is in the queue. For more information, see [Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input). |
| **QS\_TOUCH**<br>0x0800 | Windows 8 and newer: A touch input message is in the queue. For more information, see [Touch Input](https://learn.microsoft.com/windows/win32/wintouch/windows-touch-portal). |
| **QS\_POINTER**<br>0x1000 | Windows 8 and newer: A pointer input message is in the queue. For more information, see [Pointer Input](https://learn.microsoft.com/windows/win32/inputmsg/messages-and-notifications-portal). |
| **QS\_MOUSE**<br>(QS\_MOUSEMOVE \| QS\_MOUSEBUTTON) | A [WM\_MOUSEMOVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousemove) message or mouse-button message ([WM\_LBUTTONUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-lbuttonup), [WM\_RBUTTONDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-rbuttondown), and so on). |
| **QS\_INPUT**<br>(QS\_MOUSE \| QS\_KEY \| QS\_RAWINPUT \| QS\_TOUCH \| QS\_POINTER) | An input message is in the queue. |
| **QS\_ALLEVENTS**<br>(QS\_INPUT \| QS\_POSTMESSAGE \| QS\_TIMER \| QS\_PAINT \| QS\_HOTKEY) | An input, [WM\_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer), [WM\_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint), [WM\_HOTKEY](https://learn.microsoft.com/windows/desktop/inputdev/wm-hotkey), or posted message is in the queue. |
| **QS\_ALLINPUT**<br>(QS\_INPUT \| QS\_POSTMESSAGE \| QS\_TIMER \| QS\_PAINT \| QS\_HOTKEY \| QS\_SENDMESSAGE) | Any message is in the queue. |

## Return value

Type: **DWORD**

The high-order word of the return value indicates the types of messages currently in the queue. The low-order word indicates the types of messages that have been added to the queue and that are still in the queue since the last call to the **GetQueueStatus**, [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage), or [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) function.

## Remarks

The presence of a QS_ flag in the return value does not guarantee that a subsequent call to the [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage) or [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) function will return a message. **GetMessage** and **PeekMessage** perform some internal filtering that may cause the message to be processed internally. For this reason, the return value from **GetQueueStatus** should be considered only a hint as to whether **GetMessage** or **PeekMessage** should be called.

The **QS_ALLPOSTMESSAGE** and **QS_POSTMESSAGE** flags differ in when they are cleared. **QS_POSTMESSAGE** is cleared when you call [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage) or [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea), whether or not you are filtering messages. **QS_ALLPOSTMESSAGE** is cleared when you call **GetMessage** or **PeekMessage** without filtering messages (*wMsgFilterMin* and *wMsgFilterMax* are 0). This can be useful when you call **PeekMessage** multiple times to get messages in different ranges.

## See also

**Conceptual**

[GetInputState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getinputstate)

[GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)

**Reference**