# StrSpnA function

## Description

Obtains the length of a substring within a string that consists entirely of characters contained in a specified buffer.

## Parameters

### `psz` [in]

Type: **PCTSTR**

A pointer to the null-terminated string that is to be searched.

### `pszSet` [in]

Type: **PCTSTR**

A pointer to a null-terminated character buffer that contains the set of characters for which to search.

## Return value

Type: **int**

Returns the length, in characters, of the matching string or zero if no match is found.

## Remarks

> [!NOTE]
> The shlwapi.h header defines StrSpn as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).