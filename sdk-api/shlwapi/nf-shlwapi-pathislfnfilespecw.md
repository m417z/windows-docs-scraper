# PathIsLFNFileSpecW function

## Description

Determines whether a file name is in long format.

## Parameters

### `pszName` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the file name to be tested.

## Return value

Type: **BOOL**

Returns **TRUE** if *pszName* exceeds the number of characters allowed by the 8.3 format, or **FALSE** otherwise.

## See also

[PathIsFileSpec](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathisfilespeca)

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathIsLFNFileSpec as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).