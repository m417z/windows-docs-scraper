# StrPBrkW function

## Description

Searches a string for the first occurrence of a character contained in a specified buffer. This search does not include the terminating null character.

## Parameters

### `psz` [in]

Type: **PTSTR**

A pointer to the null-terminated string to be searched.

### `pszSet` [in]

Type: **PCTSTR**

A pointer to a null-terminated character buffer that contains the characters for which to search.

## Return value

Type: **PTSTR**

Returns the address in *psz* of the first occurrence of a character contained in the buffer at *pszSet*, or **NULL** if no match is found.

## Remarks

> [!NOTE]
> The shlwapi.h header defines StrPBrk as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).