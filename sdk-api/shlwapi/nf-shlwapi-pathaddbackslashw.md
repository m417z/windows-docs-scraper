# PathAddBackslashW function

## Description

Adds a backslash to the end of a string to create the correct syntax for a path. If the source path already has a trailing backslash, no backslash will be added.

**Note** Misuse of this function can lead to a buffer overrun. We recommend the use of the safer [PathCchAddBackslash](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchaddbackslash) or [PathCchAddBackslashEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchaddbackslashex) function in its place.

## Parameters

### `pszPath` [in, out]

Type: **LPTSTR**

A pointer to a buffer with a string that represents a path. The size of this buffer must be set to MAX_PATH to ensure that it is large enough to hold the returned string.

## Return value

Type: **LPTSTR**

A pointer that, when this function returns successfully, points to the new string's terminating null character. If the backslash could not be appended due to inadequate buffer size, this value is **NULL**.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathAddBackslash as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).