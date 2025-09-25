# StrChrIW function

## Description

Searches a string for the first occurrence of a character that matches the specified character. The comparison is not case-sensitive.

## Parameters

### `pszStart` [in]

Type: **PTSTR**

A pointer to the string to be searched.

### `wMatch`

Type: **TCHAR**

The character to be used for comparison.

## Return value

Type: **PTSTR**

Returns the address of the first occurrence of the character in the string if successful, or **NULL** otherwise.

## Remarks

The comparison assumes *pszStart* points to the start of a null-terminated string.

> [!NOTE]
> The shlwapi.h header defines StrChrI as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).