# SETTEXTEX structure

## Description

Specifies which code page (if any) to use in setting text, whether the text replaces all the text in the control or just the selection, and whether the undo state is to be preserved. This structure is used with the [EM_SETTEXTEX](https://learn.microsoft.com/windows/win32/controls/em-settextex) message.

## Members

### `flags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Option flags. It can be any reasonable combination of the following flags.

| Value | Meaning |
| --- | --- |
| **ST_DEFAULT**<br><br>0x00 | Deletes the undo stack, discards rich-text formatting, replaces all text. |
| **ST_KEEPUNDO**<br><br>0x01 | Keeps the undo stack. |
| **ST_SELECTION**<br><br>0x02 | Replaces selection and keeps rich-text formatting. |
| **ST_NEWCHARS**<br><br>0x04 | Act as if new characters are being entered. |
| **ST_UNICODE**<br><br>0x08 | The text is UTF-16 (the **WCHAR** data type). |
| **ST_PLACEHOLDERTEXT**<br><br>0x10 | Placeholder text that is visible only when focus is not on the RichEdit control and the control does not contain any user-specified text. |
| **ST_PLAINTEXTONLY**<br><br>0x20 | RichEdit control supports plain text only. |

### `codepage`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The code page used to translate the text to Unicode. If **codepage** is 1200 (Unicode code page), no translation is done. If **codepage** is CP_ACP, the system code page is used.

## See also

[EM_SETTEXTEX](https://learn.microsoft.com/windows/win32/controls/em-settextex)