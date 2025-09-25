# PathFindFileNameW function

## Description

Searches a path for a file name.

## Parameters

### `pszPath` [in]

Type: **PTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the path to search.

## Return value

Type: **PTSTR**

Returns a pointer to the address of the string if successful, or a pointer to the beginning of the path otherwise.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathFindFileName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).