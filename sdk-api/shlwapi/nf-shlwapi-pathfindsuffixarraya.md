# PathFindSuffixArrayA function

## Description

Determines whether a given file name has one of a list of suffixes.

## Parameters

### `pszPath` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the file name to be tested. A full path can be used.

### `apszSuffix` [in]

Type: **const LPCTSTR***

An array of *iArraySize* string pointers. Each string pointed to is null-terminated and contains one suffix. The strings can be of variable lengths.

### `iArraySize` [in]

Type: **int**

The number of elements in the array pointed to by *apszSuffix*.

## Return value

Type: **LPCTSTR**

Returns a pointer to a string with the matching suffix if successful, or **NULL** if *pszPath* does not end with one of the specified suffixes.

## Remarks

This function uses a case-sensitive comparison. The suffix must match exactly.

> [!NOTE]
> The shlwapi.h header defines PathFindSuffixArray as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).