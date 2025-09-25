# PathSearchAndQualifyA function

## Description

Determines if a given path is correctly formatted and fully qualified.

## Parameters

### `pszPath` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the path to search.

### `pszBuf` [out]

Type: **LPTSTR**

A pointer to a null-terminated string of length MAX_PATH that contains the path to be referenced.

### `cchBuf` [in]

Type: **UINT**

The size of the buffer pointed to by *pszFullyQualifiedPath*, in characters.

## Return value

Type: **BOOL**

Returns **TRUE** if the path is qualified, or **FALSE** otherwise.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathSearchAndQualify as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).