# PathGetDriveNumberA function

## Description

Searches a path for a drive letter within the range of 'A' to 'Z' and returns the corresponding drive number.

## Parameters

### `pszPath` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the path to be searched.

## Return value

Type: **int**

Returns 0 through 25 (corresponding to 'A' through 'Z') if the path has a drive letter, or -1 otherwise.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathGetDriveNumber as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).