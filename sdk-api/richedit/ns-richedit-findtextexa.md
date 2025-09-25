# FINDTEXTEXA structure

## Description

Contains information about text to search for in a rich edit control. This structure is used with the [EM_FINDTEXTEX](https://learn.microsoft.com/windows/win32/controls/em-findtextex) message.

## Members

### `chrg`

Type: **[CHARRANGE](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charrange)**

The range of characters to search. To search forward in the entire control, set **cpMin** to 0 and **cpMax** to -1.

### `lpstrText`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The null-terminated string to find.

### `chrgText`

Type: **[CHARRANGE](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charrange)**

The range of characters in which the text was found. If the text was not found, **cpMin** and **cpMax** are -1.

## See also

[EM_FINDTEXTEX](https://learn.microsoft.com/windows/win32/controls/em-findtextex)

[EM_FINDTEXTEXW](https://learn.microsoft.com/windows/win32/controls/em-findtextexw)

**Reference**

## Remarks

> [!NOTE]
> The richedit.h header defines FINDTEXTEX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).