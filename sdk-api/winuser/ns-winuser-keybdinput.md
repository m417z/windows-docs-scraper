# KEYBDINPUT structure

## Description

Contains information about a simulated keyboard event.

## Members

### `wVk`

Type: **WORD**

A [virtual-key code](https://learn.microsoft.com/windows/desktop/inputdev/virtual-key-codes). The code must be a value in the range 1 to 254. If the **dwFlags** member specifies **KEYEVENTF_UNICODE**, **wVk** must be 0.

### `wScan`

Type: **WORD**

A hardware scan code for the key. If **dwFlags** specifies **KEYEVENTF_UNICODE**, **wScan** specifies a Unicode character which is to be sent to the foreground application.

### `dwFlags`

Type: **DWORD**

Specifies various aspects of a keystroke. This member can be certain combinations of the following values.

| Value | Meaning |
| --- | --- |
| **KEYEVENTF_EXTENDEDKEY**<br><br>0x0001 | If specified, the **wScan** scan code consists of a sequence of two bytes, where the first byte has a value of 0xE0. See [Extended-Key Flag](https://learn.microsoft.com/windows/win32/inputdev/about-keyboard-input#extended-key-flag) for more info. |
| **KEYEVENTF_KEYUP**<br><br>0x0002 | If specified, the key is being released. If not specified, the key is being pressed. |
| **KEYEVENTF_SCANCODE**<br><br>0x0008 | If specified, **wScan** identifies the key and **wVk** is ignored. |
| **KEYEVENTF_UNICODE**<br><br>0x0004 | If specified, the system synthesizes a **VK_PACKET** keystroke. The **wVk** parameter must be zero. This flag can only be combined with the **KEYEVENTF_KEYUP** flag. For more information, see the Remarks section. |

### `time`

Type: **DWORD**

The time stamp for the event, in milliseconds. If this parameter is zero, the system will provide its own time stamp.

### `dwExtraInfo`

Type: **ULONG_PTR**

An additional value associated with the keystroke. Use the [GetMessageExtraInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessageextrainfo) function to obtain this information.

## Remarks

 **INPUT_KEYBOARD** supports nonkeyboard-input methods—such as handwriting recognition or voice recognition—as if it were text input by using the **KEYEVENTF_UNICODE** flag. If **KEYEVENTF_UNICODE** is specified, [SendInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendinput) sends a [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown) or [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup) message to the foreground thread's message queue with *wParam* equal to **VK_PACKET**. Once [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage) or [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) obtains this message, passing the message to
[TranslateMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translatemessage) posts a [WM_CHAR](https://learn.microsoft.com/windows/desktop/inputdev/wm-char) message with the Unicode character originally specified by **wScan**. This Unicode character will automatically be converted to the appropriate ANSI value if it is posted to an ANSI window.

Set the **KEYEVENTF_SCANCODE** flag to define keyboard input in terms of the scan code. This is useful for simulating a physical keystroke regardless of which keyboard is currently being used. You can also pass the **KEYEVENTF_EXTENDEDKEY** flag if the scan code is an extended key. The virtual key value of a key can change depending on the current keyboard layout or what other keys were pressed, but the scan code will always be the same.

## See also

- [GetMessageExtraInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessageextrainfo)
- [INPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-input)
- [SendInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendinput)
- [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)