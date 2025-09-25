# ENPROTECTED structure

## Description

Contains information associated with an [EN_PROTECTED](https://learn.microsoft.com/windows/win32/controls/en-protected) notification code. A rich edit control sends this notification when the user attempts to edit protected text.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr) notification header.

### `msg`

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

Message that triggered the notification.

### `wParam`

Type: **[WPARAM](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The **wParam** parameter of the message.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The **lParam** parameter of the message.

### `chrg`

Type: **[CHARRANGE](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charrange)**

The current selection.

## See also

[EN_PROTECTED](https://learn.microsoft.com/windows/win32/controls/en-protected)