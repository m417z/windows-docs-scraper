# MSLLHOOKSTRUCT structure

## Description

Contains information about a low-level mouse input event.

## Members

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The x- and y-coordinates of the cursor, in [per-monitor-aware](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-process_dpi_awareness) screen coordinates.

### `mouseData`

Type: **DWORD**

If the message is [WM_MOUSEWHEEL](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousewheel), the high-order word of this member is the wheel delta. The low-order word is reserved. A positive value indicates that the wheel was rotated forward, away from the user; a negative value indicates that the wheel was rotated backward, toward the user. One wheel click is defined as **WHEEL_DELTA**, which is 120.

If the message is [WM_XBUTTONDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-xbuttondown), [WM_XBUTTONUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-xbuttonup), [WM_XBUTTONDBLCLK](https://learn.microsoft.com/windows/desktop/inputdev/wm-xbuttondblclk), [WM_NCXBUTTONDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-ncxbuttondown), [WM_NCXBUTTONUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-ncxbuttonup), or [WM_NCXBUTTONDBLCLK](https://learn.microsoft.com/windows/desktop/inputdev/wm-ncxbuttondblclk), the high-order word specifies which X button was pressed or released, and the low-order word is reserved. This value can be one or more of the following values. Otherwise,
**mouseData** is not used.

| Value | Meaning |
| --- | --- |
| **XBUTTON1**<br><br>0x0001 | The first X button was pressed or released. |
| **XBUTTON2**<br><br>0x0002 | The second X button was pressed or released. |

### `flags`

Type: **DWORD**

The event-injected flags. An application can use the following values to test the flags. Testing LLMHF_INJECTED (bit 0) will tell you whether the event was injected. If it was, then testing LLMHF_LOWER_IL_INJECTED (bit 1) will tell you whether or not the event was injected from a process running at lower integrity level.

| Value | Meaning |
| --- | --- |
| **LLMHF_INJECTED**<br><br>0x00000001 | Test the event-injected (from any process) flag. |
| **LLMHF_LOWER_IL_INJECTED**<br><br>0x00000002 | Test the event-injected (from a process running at lower integrity level) flag. |

### `time`

Type: **DWORD**

The time stamp for this message.

### `dwExtraInfo`

Type: **ULONG_PTR**

Additional information associated with the message.

## See also

**Conceptual**

[Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks)

[LowLevelMouseProc](https://learn.microsoft.com/windows/win32/winmsg/lowlevelmouseproc)

**Other Resources**

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

**Reference**

[SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa)

[WM_MOUSEWHEEL](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousewheel)

[WM_NCXBUTTONDBLCLK](https://learn.microsoft.com/windows/desktop/inputdev/wm-ncxbuttondblclk)

[WM_NCXBUTTONDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-ncxbuttondown)

[WM_NCXBUTTONUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-ncxbuttonup)

[WM_XBUTTONDBLCLK](https://learn.microsoft.com/windows/desktop/inputdev/wm-xbuttondblclk)

[WM_XBUTTONDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-xbuttondown)

[WM_XBUTTONUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-xbuttonup)