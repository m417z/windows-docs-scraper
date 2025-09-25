# GUITHREADINFO structure

## Description

Contains information about a GUI thread.

## Members

### `cbSize`

Type: **DWORD**

The size of this structure, in bytes. The caller must set this member to `sizeof(GUITHREADINFO)`.

### `flags`

Type: **DWORD**

The thread state. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **GUI_CARETBLINKING**<br><br>0x00000001 | The caret's blink state. This bit is set if the caret is visible. |
| **GUI_INMENUMODE**<br><br>0x00000004 | The thread's menu state. This bit is set if the thread is in menu mode. |
| **GUI_INMOVESIZE**<br><br>0x00000002 | The thread's move state. This bit is set if the thread is in a move or size loop. |
| **GUI_POPUPMENUMODE**<br><br>0x00000010 | The thread's pop-up menu state. This bit is set if the thread has an active pop-up menu. |
| **GUI_SYSTEMMENUMODE**<br><br>0x00000008 | The thread's system menu state. This bit is set if the thread is in a system menu mode. |

### `hwndActive`

Type: **HWND**

A handle to the active window within the thread.

### `hwndFocus`

Type: **HWND**

A handle to the window that has the keyboard focus.

### `hwndCapture`

Type: **HWND**

A handle to the window that has captured the mouse.

### `hwndMenuOwner`

Type: **HWND**

A handle to the window that owns any active menus.

### `hwndMoveSize`

Type: **HWND**

A handle to the window in a move or size loop.

### `hwndCaret`

Type: **HWND**

A handle to the window that is displaying the caret.

### `rcCaret`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The caret's bounding rectangle, in client coordinates, relative to the window specified by the **hwndCaret** member.

## Remarks

This structure is used with the [GetGUIThreadInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getguithreadinfo) function to retrieve information about the active window or a specified GUI thread.

## See also

**Conceptual**

[GetGUIThreadInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getguithreadinfo)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)