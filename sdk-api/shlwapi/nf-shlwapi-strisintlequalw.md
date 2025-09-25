# StrIsIntlEqualW function

## Description

Compares a specified number of characters from the beginning of two strings to determine if they are equal.

## Parameters

### `fCaseSens`

Type: **BOOL**

The case sensitivity of the comparison. If this value is nonzero, the comparison is case-sensitive. If this value is zero, the comparison is not case-sensitive.

### `pszString1` [in]

Type: **PCTSTR**

A pointer to the first null-terminated string to be compared.

### `pszString2` [in]

Type: **PCTSTR**

A pointer to the second null-terminated string to be compared.

### `nChar`

Type: **int**

The number of characters from the beginning of each string to be compared.

## Return value

Type: **BOOL**

**TRUE** if the first *nChar* characters from the two strings are equal; otherwise, **FALSE**.

## Remarks

You can set case sensitivity with the **StrIntlEqN** and **StrIntlEqNI** macros. **StrIntlEqN** performs a case-sensitive comparison, and **StrIntlEqNI** performs a case-insensitive comparison.

The syntax of the two macros is:

```
#define StrIntlEqN(s1, s2, nChar) StrIsIntlEqual(TRUE, s1, s2, nChar)
#define StrIntlEqNI(s1, s2, nChar) StrIsIntlEqual(FALSE, s1, s2, nChar)
```

> [!NOTE]
> The shlwapi.h header defines StrIsIntlEqual as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).