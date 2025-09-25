# MSGFILTER structure

## Description

Contains information about a keyboard or mouse event. A rich edit control sends this structure to its parent window as part of an [EN_MSGFILTER](https://learn.microsoft.com/windows/win32/controls/en-msgfilter) notification code, enabling the parent to change the message or prevent it from being processed.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr)**

The **code** member of the [NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr) structure is the [EN_MSGFILTER](https://learn.microsoft.com/windows/win32/controls/en-msgfilter) notification code that identifies the message being sent.

### `msg`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Keyboard or mouse message identifier.

### `wParam`

Type: **[WPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The
**wParam** parameter of the message.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The
**lParam** parameter of the message.

## See also

[EN_MSGFILTER](https://learn.microsoft.com/windows/win32/controls/en-msgfilter)