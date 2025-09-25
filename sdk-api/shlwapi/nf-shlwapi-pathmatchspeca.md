# PathMatchSpecA function

## Description

Searches a string using a Microsoft MS-DOS wildcard match type.

## Parameters

### `pszFile` [in]

Type: **LPCSTR**

A pointer to a null-terminated string that contains the path to be searched.

### `pszSpec` [in]

Type: **LPCSTR**

A pointer to a null-terminated string that contains the file type for which to search. For example, to test whether *pszFile* is a .doc file, *pszSpec* should be set to "*.doc".

## Return value

Type: **BOOL**

Returns **TRUE** if the string matches, or **FALSE** otherwise.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathMatchSpec as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).