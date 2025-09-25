# PathRemoveFileSpecW function

## Description

Removes the trailing file name and backslash from a path, if they are present.

**Note** This function is deprecated. We recommend the use of the [PathCchRemoveFileSpec](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchremovefilespec) function in its place.

## Parameters

### `pszPath` [in, out]

Type: **LPTSTR**

A pointer to a null-terminated string of length MAX_PATH that contains the path from which to remove the file name.

## Return value

Type: **BOOL**

Returns nonzero if something was removed, or zero otherwise.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathRemoveFileSpec as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).