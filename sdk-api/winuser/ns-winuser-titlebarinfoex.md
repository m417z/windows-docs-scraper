# TITLEBARINFOEX structure

## Description

Expands on the information described in the [TITLEBARINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-titlebarinfo) structure by including the coordinates of each element of the title bar.

This structure is sent with the [WM_GETTITLEBARINFOEX](https://learn.microsoft.com/windows/desktop/menurc/wm-gettitlebarinfoex) message.

## Members

### `cbSize`

Type: **DWORD**

The size of the structure, in bytes. Set this member to `sizeof(TITLEBARINFOEX)` before sending with the [WM_GETTITLEBARINFOEX](https://learn.microsoft.com/windows/desktop/menurc/wm-gettitlebarinfoex) message.

### `rcTitleBar`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The bounding rectangle of the title bar. The rectangle is expressed in screen coordinates and includes all titlebar elements except the window menu.

### `rgstate`

Type: **DWORD[CCHILDREN_TITLEBAR+1]**

An array that receives a **DWORD** value for each element of the title bar. The following are the title bar elements represented by the array.

| Index | Title Bar Element |
| --- | --- |
| 0 | The title bar itself. |
| 1 | Reserved. |
| 2 | Minimize button. |
| 3 | Maximize button. |
| 4 | Help button. |
| 5 | Close button. |

Each array element is a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **STATE_SYSTEM_FOCUSABLE**<br><br>0x00100000 | The element can accept the focus. |
| **STATE_SYSTEM_INVISIBLE**<br><br>0x00008000 | The element is invisible. |
| **STATE_SYSTEM_OFFSCREEN**<br><br>0x00010000 | The element has no visible representation. |
| **STATE_SYSTEM_UNAVAILABLE**<br><br>0x00000001 | The element is unavailable. |
| **STATE_SYSTEM_PRESSED**<br><br>0x00000008 | The element is in the pressed state. |

### `rgrect`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)[CCHILDREN_TITLEBAR+1]**

An array that receives a structure for each element of the title bar. The structures are expressed in screen coordinates. The following are the title bar elements represented by the array.

| Index | Title Bar Element |
| --- | --- |
| 0 | Reserved. |
| 1 | Reserved. |
| 2 | Minimize button. |
| 3 | Maximize button. |
| 4 | Help button. |
| 5 | Close button. |

## See also

**Conceptual**

**Reference**

[WM_GETTITLEBARINFOEX](https://learn.microsoft.com/windows/desktop/menurc/wm-gettitlebarinfoex)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)