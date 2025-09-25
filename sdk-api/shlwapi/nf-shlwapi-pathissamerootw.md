# PathIsSameRootW function

## Description

Compares two paths to determine if they have a common root component.

## Parameters

### `pszPath1` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the first path to be compared.

### `pszPath2` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the second path to be compared.

## Return value

Type: **BOOL**

Returns **TRUE** if both strings have the same root component, or **FALSE** otherwise. If *pszPath1* contains only the server and share, this function also returns **FALSE**.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathIsSameRoot as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).