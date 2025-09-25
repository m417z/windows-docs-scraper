# PathIsDirectoryEmptyA function

## Description

Determines whether a specified path is an empty directory.

## Parameters

### `pszPath` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the path to be tested.

## Return value

Type: **BOOL**

Returns **TRUE** if *pszPath* is an empty directory. Returns **FALSE** if *pszPath* is not a directory, or if it contains at least one file other than "." or "..".

## Remarks

"C:\" is considered a directory.

> [!NOTE]
> The shlwapi.h header defines PathIsDirectoryEmpty as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PathIsDirectory](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathisdirectorya)