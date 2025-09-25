# KBDLLHOOKSTRUCT structure

## Description

Contains information about a low-level keyboard input event.

## Members

### `vkCode`

Type: **DWORD**

A [virtual-key code](https://learn.microsoft.com/windows/desktop/inputdev/virtual-key-codes). The code must be a value in the range 1 to 254.

### `scanCode`

Type: **DWORD**

A hardware scan code for the key.

### `flags`

Type: **DWORD**

The extended-key flag, event-injected flags, context code, and transition-state flag. This member is specified as follows. An application can use the following values to test the keystroke flags. Testing LLKHF_INJECTED (bit 4) will tell you whether the event was injected. If it was, then testing LLKHF_LOWER_IL_INJECTED (bit 1) will tell you whether or not the event was injected from a process running at lower integrity level.

| Value | Meaning |
| --- | --- |
| **LLKHF_EXTENDED**<br><br>(KF_EXTENDED >> 8) | Test the extended-key flag. |
| **LLKHF_LOWER_IL_INJECTED**<br><br>0x00000002 | Test the event-injected (from a process running at lower integrity level) flag. |
| **LLKHF_INJECTED**<br><br>0x00000010 | Test the event-injected (from any process) flag. |
| **LLKHF_ALTDOWN**<br><br>(KF_ALTDOWN >> 8) | Test the context code. |
| **LLKHF_UP**<br><br>(KF_UP >> 8) | Test the transition-state flag. |

The following table describes the layout of this value.

| Bits | Description |
| --- | --- |
| 0 | Specifies whether the key is an extended key, such as a function key or a key on the numeric keypad. The value is 1 if the key is an extended key; otherwise, it is 0. |
| 1 | Specifies whether the event was injected from a process running at lower integrity level. The value is 1 if that is the case; otherwise, it is 0. Note that bit 4 is also set whenever bit 1 is set. |
| 2-3 | Reserved. |
| 4 | Specifies whether the event was injected. The value is 1 if that is the case; otherwise, it is 0. Note that bit 1 is not necessarily set when bit 4 is set. |
| 5 | The context code. The value is 1 if the ALT key is pressed; otherwise, it is 0. |
| 6 | Reserved. |
| 7 | The transition state. The value is 0 if the key is pressed and 1 if it is being released. |

### `time`

Type: **DWORD**

The time stamp for this message, equivalent to what [GetMessageTime](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessagetime) would return for this message.

### `dwExtraInfo`

Type: **ULONG_PTR**

Additional information associated with the message.

## See also

**Conceptual**

[Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks)

[LowLevelKeyboardProc](https://learn.microsoft.com/windows/win32/winmsg/lowlevelkeyboardproc)

**Reference**

[SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa)