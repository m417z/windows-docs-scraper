# StrTrimA function

## Description

Removes specified leading and trailing characters from a string.

## Parameters

### `psz` [in, out]

Type: **PTSTR**

A pointer to the null-terminated string to be trimmed. When this function returns successfully, *psz* receives the trimmed string.

### `pszTrimChars` [in]

Type: **PCTSTR**

A pointer to a null-terminated string that contains the characters to trim from *psz*.

## Return value

Type: **BOOL**

**TRUE** if any characters were removed; otherwise, **FALSE**.

## Remarks

> [!NOTE]
> The shlwapi.h header defines StrTrim as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).