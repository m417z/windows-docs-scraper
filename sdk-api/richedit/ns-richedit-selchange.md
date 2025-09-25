# SELCHANGE structure

## Description

Contains information associated with an [EN_SELCHANGE](https://learn.microsoft.com/windows/win32/controls/en-selchange) notification code. A rich edit control sends this notification to its parent window when the current selection changes.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr)**

Notification header.

### `chrg`

Type: **[CHARRANGE](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charrange)**

New selection range.

### `seltyp`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value specifying the contents of the new selection. This member is SEL_EMPTY if the selection is empty or one or more of the following values.

| Value | Meaning |
| --- | --- |
| **SEL_TEXT** | Text. |
| **SEL_OBJECT** | At least one COM object. |
| **SEL_MULTICHAR** | More than one character of text. |
| **SEL_MULTIOBJECT** | More than one COM object. |

## See also

[EN_SELCHANGE](https://learn.microsoft.com/windows/win32/controls/en-selchange)