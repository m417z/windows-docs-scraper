# IntlStrEqNIW macro

## Description

Performs a case-insensitive comparison of a specified number of characters from the beginning of two localized strings.

## Parameters

### `s1` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string.

### `s2` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string.

### `nChar` [in]

Type: **int**

The number of characters to be compared, starting from the beginning of the strings.

## Remarks

This function retrieves the thread locale and uses [CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw) to do a case-insensitive comparison of the first *nChar* characters. It is equivalent to:

``` syntax
IntlStrEqWorker(FALSE, pszStr1, pszStr2, nChar)
```

> [!NOTE]
> The shlwapi.h header defines IntlStrEqNI as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[IntlStrEqWorker](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-intlstreqworkera)