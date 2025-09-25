# GETTEXTEX structure

## Description

Contains information used in getting text from a rich edit control. This structure used with the [EM_GETTEXTEX](https://learn.microsoft.com/windows/desktop/Controls/em-gettextex) message.

## Members

### `cb`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size, in bytes, of the buffer used to store the retrieved text.

### `flags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value specifying a text operation. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **GT_DEFAULT** | All text is retrieved according to the following criteria: <br><br>* Carriage returns (U+000D) are not translated into CRLF (U+000D U+000A).<br>* Table and math-object structure characters are removed (see **GT_RAWTEXT**).<br>* Hidden text is included.<br>* List numbers are not included. |
| **GT_NOHIDDENTEXT** | Hidden text is not included in the retrieved text. |
| **GT_RAWTEXT** | Text is retrieved exactly as it appears in memory. This includes special structure characters for table row and cell delimiters (see Remarks for [EM_INSERTTABLE](https://learn.microsoft.com/windows/desktop/Controls/em-inserttable)) as well as math object delimiters (start delimiter U+FDD0, argument delimiter U+FDEE, and end delimiter U+FDDF) and object markers (U+FFFC). This maintains character-position alignment between the retrieved text and the text in memory. |
| **GT_SELECTION** | Retrieve the text for the current selection. |
| **GT_USECRLF** | When copying text, translate each CR into a CR/LF. |

### `codepage`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Code page used in the translation. It is **CP_ACP** for ANSI code page and 1200 for Unicode.

### `lpDefaultChar`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The character used if a wide character cannot be represented in the specified code page. It is used only if the code page is **not** 1200 (Unicode). If this member is **NULL**, a system default value is used.

### `lpUsedDefChar`

Type: **[LPBOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A flag that indicates whether the default character (**lpDefaultChar**) was used. This member is used only if the code page is not 1200 or **CP_UTF8** (Unicode). The flag is **TRUE** if one or more wide characters in the source string cannot be represented in the specified code page. Otherwise, the flag is **FALSE**. This member can be NULL.

## Remarks

The [EM_GETTEXTEX](https://learn.microsoft.com/windows/desktop/Controls/em-gettextex) message is faster when both **lpDefaultChar** and **lpUsedDefChar** are **NULL**.

## See also

[EM_GETTEXTEX](https://learn.microsoft.com/windows/desktop/Controls/em-gettextex)