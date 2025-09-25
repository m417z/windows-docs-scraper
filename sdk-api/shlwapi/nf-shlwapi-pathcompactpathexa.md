# PathCompactPathExA function

## Description

Truncates a path to fit within a certain number of characters by replacing path components with ellipses.

## Parameters

### `pszOut` [out]

Type: **LPTSTR**

The address of the string that has been altered.

### `pszSrc` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of length MAX_PATH that contains the path to be altered.

### `cchMax` [in]

Type: **UINT**

The maximum number of characters to be contained in the new string, including the terminating null character. For example, if *cchMax* = 8, the resulting string can contain a maximum of 7 characters plus the terminating null character.

### `dwFlags` [in]

Type: **DWORD**

## Return value

Type: **BOOL**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Remarks

The '/' separator will be used instead of '\' if the original string used it. If *pszSrc* points to a file name that is too long, instead of a path, the file name will be truncated to *cchMax* characters, including the ellipsis and the terminating **NULL** character. For example, if the input file name is "My Filename" and *cchMax* is 10, **PathCompactPathEx** will return "My Fil...".

> [!NOTE]
> The shlwapi.h header defines PathCompactPathEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).