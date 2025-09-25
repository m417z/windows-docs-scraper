# MULTIKEYHELPA structure

## Description

Specifies a keyword to search for and the keyword table to be searched by Windows Help.

## Members

### `mkSize`

Type: **DWORD**

The structure size, in bytes.

### `mkKeylist`

Type: **TCHAR**

A single character that identifies the keyword table to search.

### `szKeyphrase`

Type: **TCHAR[1]**

A null-terminated text string that specifies the keyword to locate in the keyword table.

## See also

[WinHelp](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-winhelpa)

## Remarks

> [!NOTE]
> The winuser.h header defines MULTIKEYHELP as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).