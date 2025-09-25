# PathRemoveBackslashW function

## Description

Removes the trailing backslash from a given path.

**Note** This function is deprecated. We recommend the use of the [PathCchRemoveBackslash](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchremovebackslash) or [PathCchRemoveBackslashEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchremovebackslashex) function in its place.

## Parameters

### `pszPath` [in, out]

Type: **LPTSTR**

A pointer to a null-terminated string of length MAX_PATH that contains the path from which to remove the backslash.

## Return value

Type: **LPTSTR**

A pointer that, when this function returns successfully and if a backslash has been removed, points to the terminating null character that has replaced the backslash at the end of the string. If the path did not include a trailing backslash, this value will point to the final character in the string.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathRemoveBackslash as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).