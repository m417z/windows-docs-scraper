# ENLINK structure

## Description

Contains information about an [EN_LINK](https://learn.microsoft.com/windows/win32/controls/en-link) notification code from a rich edit control.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr)**

The code member of this structure identifies the notification code being sent.

### `msg`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Identifier of the message that caused the rich edit control to send the [EN_LINK](https://learn.microsoft.com/windows/win32/controls/en-link) notification code.

### `wParam`

Type: **[WPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The **wParam** parameter of the message received by the rich edit control.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The **lParam** parameter of the message received by the rich edit control.

### `chrg`

Type: **[CHARRANGE](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charrange)**

The range of consecutive characters in the rich edit control that have the CFE_LINK effect.

## See also

[CHARRANGE](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charrange)

[EN_LINK](https://learn.microsoft.com/windows/win32/controls/en-link)

[NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr)

**Reference**