# StrCSpnA function

## Description

Searches a string for the first occurrence of any of a group of characters. The search method is case-sensitive, and the terminating **NULL** character is included within the search pattern match.

## Parameters

### `pszStr` [in]

Type: **PCTSTR**

A pointer to the null-terminated string to be searched.

### `pszSet` [in]

Type: **PCTSTR**

A pointer to a null-terminated string that contains the characters to search for.

## Return value

Type: **int**

Returns the index of the first occurrence in *pszStr* of any character from *pszSet*, or the length of *pszStr* if no match is found.

## Remarks

The return value of this function is equal to the length of the initial substring in *pszStr* that does not include any characters from *pszSet*.

> [!NOTE]
> The shlwapi.h header defines StrCSpn as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).