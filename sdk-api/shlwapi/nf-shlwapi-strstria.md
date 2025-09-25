# StrStrIA function

## Description

Finds the first occurrence of a substring within a string. The comparison is not case-sensitive.

## Parameters

### `pszFirst` [in]

Type: **PTSTR**

A pointer to the null-terminated string being searched.

### `pszSrch` [in]

Type: **PCTSTR**

A pointer to the substring to search for.

## Return value

Type: **PTSTR**

Returns the address of the first occurrence of the matching substring if successful, or **NULL** otherwise.

## Remarks

> [!NOTE]
> The shlwapi.h header defines StrStrI as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).