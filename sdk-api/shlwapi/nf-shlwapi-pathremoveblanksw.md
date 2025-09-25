# PathRemoveBlanksW function

## Description

Removes all leading and trailing spaces from a string.

## Parameters

### `pszPath` [in, out]

Type: **LPTSTR**

A pointer to a null-terminated string of length MAX_PATH from which to strip all leading and trailing spaces.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathRemoveBlanks as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).