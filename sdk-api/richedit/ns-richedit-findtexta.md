# FINDTEXTA structure

## Description

Contains information about a search operation in a rich edit control. This structure is used with the [EM_FINDTEXT](https://learn.microsoft.com/windows/win32/controls/em-findtext) message.

## Members

### `chrg`

Type: **[CHARRANGE](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charrange)**

The range of characters to search.

### `lpstrText`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The null-terminated string used in the find operation.

## See also

[CHARRANGE](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charrange)

[EM_FINDTEXT](https://learn.microsoft.com/windows/win32/controls/em-findtext)

[EM_FINDTEXTW](https://learn.microsoft.com/windows/win32/controls/em-findtextw)

**Reference**

## Remarks

> [!NOTE]
> The richedit.h header defines FINDTEXT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).