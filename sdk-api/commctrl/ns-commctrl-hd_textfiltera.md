# HD_TEXTFILTERA structure

## Description

Contains information about header control text filters.

## Members

### `pszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to the buffer containing the filter.

### `cchTextMax`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value specifying the maximum size, in characters, for an edit control buffer.

## Remarks

> [!NOTE]
> The commctrl.h header defines HD_TEXTFILTER as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).