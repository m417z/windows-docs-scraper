# StrRStrIA function

## Description

Searches for the last occurrence of a specified substring within a string. The comparison is not case-sensitive.

## Parameters

### `pszSource` [in]

Type: **PTSTR**

A pointer to a **null**-terminated source string.

### `pszLast` [in, optional]

Type: **PCTSTR**

A pointer into the source string that defines the range of the search. Set *pszLast* to point to a character in the source string, and the search will stop with the preceding character. Set *pszLast* to **NULL** to search the entire source string.

### `pszSrch` [in]

Type: **PCTSTR**

A pointer to the substring to search for.

## Return value

Type: **PTSTR**

Returns the address of the last occurrence of the substring if successful, or **NULL** otherwise.

## Remarks

> [!NOTE]
> The shlwapi.h header defines StrRStrI as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).