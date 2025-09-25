# INPUT structure

## Description

Used by [SendInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendinput) to store information for synthesizing input events such as keystrokes, mouse movement, and mouse clicks.

## Members

### `type`

Type: **DWORD**

The type of the input event. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INPUT_MOUSE**<br><br>0 | The event is a mouse event. Use the **mi** structure of the union. |
| **INPUT_KEYBOARD**<br><br>1 | The event is a keyboard event. Use the **ki** structure of the union. |
| **INPUT_HARDWARE**<br><br>2 | The event is a hardware event. Use the **hi** structure of the union. |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.mi`

Type: **[MOUSEINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-mouseinput)**

The information about a simulated mouse event.

### `DUMMYUNIONNAME.ki`

Type: **[KEYBDINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-keybdinput)**

The information about a simulated keyboard event.

### `DUMMYUNIONNAME.hi`

Type: **[HARDWAREINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-hardwareinput)**

The information about a simulated hardware event.

## Remarks

 **INPUT_KEYBOARD** supports nonkeyboard input methods, such as handwriting recognition or voice recognition, as if it were text input by using the **KEYEVENTF_UNICODE** flag. For more information, see the remarks section of [KEYBDINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-keybdinput).

## See also

**Conceptual**

[GetMessageExtraInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessageextrainfo)

[HARDWAREINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-hardwareinput)

[KEYBDINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-keybdinput)

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

[MOUSEINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-mouseinput)

**Reference**

[SendInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendinput)

[keybd_event](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-keybd_event)

[mouse_event](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mouse_event)