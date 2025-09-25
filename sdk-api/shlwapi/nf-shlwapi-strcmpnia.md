# StrCmpNIA function

## Description

Compares a specified number of characters from the beginning of two strings to determine if they are the same. The comparison is not case-sensitive. The **StrNCmpI** macro differs from this function in name only.

## Parameters

### `psz1` [in]

Type: **PCTSTR**

A pointer to the first null-terminated string to be compared.

### `psz2` [in]

Type: **PCTSTR**

A pointer to the second null-terminated string to be compared.

### `nChar` [in]

Type: **int**

The number of characters from the beginning of each string to be compared.

## Return value

Type: **int**

Returns zero if the strings are identical. Returns a positive value if the first *nChar* characters of the string pointed to by *psz1* are greater than those from the string pointed to by *psz2*. It returns a negative value if the first *nChar* characters of the string pointed to by *psz1* are less than those from the string pointed to by *psz2*.

## Remarks

> [!NOTE]
> The shlwapi.h header defines StrCmpNI as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).