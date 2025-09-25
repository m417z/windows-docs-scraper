# StrRChrIA function

## Description

Searches a string for the last occurrence of a specified character. The comparison is not case-sensitive.

## Parameters

### `pszStart` [in]

Type: **PTSTR**

A pointer to the null-terminated string to be searched.

### `pszEnd` [in, optional]

Type: **PCTSTR**

A pointer into the source string that defines the range of the search. Set *pszEnd* to point to a character in the string and the search will stop with the preceding character. Set *pszEnd* to **NULL** to search the entire string.

### `wMatch`

Type: **TCHAR**

The character to search for.

## Return value

Type: **PTSTR**

Returns a pointer to the last occurrence of the character in the string, if successful, or **NULL** if not.

## Remarks

The comparison assumes that *pszEnd* points to the end of the string.

> [!NOTE]
> The shlwapi.h header defines StrRChrI as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).