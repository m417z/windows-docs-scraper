# PathStripPathW function

## Description

Removes the path portion of a fully qualified path and file.

## Parameters

### `pszPath` [in, out]

Type: **LPTSTR**

A pointer to a null-terminated string of length MAX_PATH that contains the path and file name. When this function returns successfully, the string contains only the file name, with the path removed.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathStripPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).