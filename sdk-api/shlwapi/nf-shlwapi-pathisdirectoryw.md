# PathIsDirectoryW function

## Description

Verifies that a path is a valid directory.

## Parameters

### `pszPath` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the path to verify.

## Return value

Type: **BOOL**

Returns (BOOL)FILE_ATTRIBUTE_DIRECTORY if the path is a valid directory; otherwise, **FALSE**.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathIsDirectory as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).