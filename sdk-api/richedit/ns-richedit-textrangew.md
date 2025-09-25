# TEXTRANGEW structure

## Description

A range of text from a rich edit control. This structure is filled in by the [EM_GETTEXTRANGE](https://learn.microsoft.com/windows/win32/controls/em-gettextrange) message. The buffer pointed to by the **lpstrText** member must be large enough to receive all characters and the terminating null character.

## Members

### `chrg`

Type: **[CHARRANGE](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charrange)**

The range of characters to retrieve.

### `lpstrText`

Type: **[LPSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The text.

## See also

[CHARRANGE](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charrange)

[EM_GETTEXTRANGE](https://learn.microsoft.com/windows/win32/controls/em-gettextrange)

**Reference**

## Remarks

> [!NOTE]
> The richedit.h header defines TEXTRANGE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).