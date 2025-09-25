# ENCORRECTTEXT structure

## Description

Contains information about the selected text to be corrected.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr) structure. The **code** member of this structure identifies the notification code being sent.

### `chrg`

Type: **[CHARRANGE](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charrange)**

A [CHARRANGE](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charrange) structure that specifies the range of selected characters.

### `seltyp`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value specifying the contents of the new selection. This member is SEL_EMPTY if the selection is empty or one or more of the following values.

| Value | Meaning |
| --- | --- |
| **SEL_TEXT** | The new selection contains text. |
| **SEL_OBJECT** | The new selection contains at least one COM object. |
| **SEL_MULTICHAR** | The new selection contains more than one character of text. |
| **SEL_MULTIOBJECT** | The new selection contains more than one COM object. |

## See also

[EN_CORRECTTEXT](https://learn.microsoft.com/windows/win32/controls/en-correcttext)