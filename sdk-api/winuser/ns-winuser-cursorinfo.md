# CURSORINFO structure

## Description

Contains global cursor information.

## Members

### `cbSize`

Type: **DWORD**

The size of the structure, in bytes. The caller must set this to `sizeof(CURSORINFO)`.

### `flags`

Type: **DWORD**

The cursor state. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | The cursor is hidden. |
| **CURSOR_SHOWING**<br><br>0x00000001 | The cursor is showing. |
| **CURSOR_SUPPRESSED**<br><br>0x00000002 | **Windows 8**: The cursor is suppressed. This flag indicates that the system is not drawing the cursor because the user is providing input through touch or pen instead of the mouse. |

### `hCursor`

Type: **HCURSOR**

A handle to the cursor.

### `ptScreenPos`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

A structure that receives the screen coordinates of the cursor.

## See also

**Conceptual**

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)

[GetCursorInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcursorinfo)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

**Reference**