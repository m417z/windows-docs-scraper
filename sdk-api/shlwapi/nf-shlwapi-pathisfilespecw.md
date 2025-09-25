# PathIsFileSpecW function

## Description

Searches a path for any path-delimiting characters (for example, ':' or '\\' ). If there are no path-delimiting characters present, the path is considered to be a File Spec path.

## Parameters

### `pszPath` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the path to be searched.

## Return value

Type: **BOOL**

Returns **TRUE** if there are no path-delimiting characters within the path, or **FALSE** if there are path-delimiting characters.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathIsFileSpec as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).