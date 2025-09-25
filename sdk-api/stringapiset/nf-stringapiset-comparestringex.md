# CompareStringEx function

## Description

Compares two Unicode (wide character) strings, for a [locale](https://learn.microsoft.com/windows/desktop/Intl/locales-and-languages) specified by name.

**Caution** Using **CompareStringEx** incorrectly can compromise the security of your application. Strings that are not compared correctly can produce invalid input. Test strings to make sure they are valid before using them, and provide error handlers. For more information, see [Security Considerations: International Features](https://learn.microsoft.com/windows/desktop/Intl/security-considerations--international-features).

**Note** The application should call this function in preference to [CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw) if designed to run only on Windows Vista and later.

## Parameters

### `lpLocaleName` [in, optional]

Pointer to a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names), or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `dwCmpFlags` [in]

Flags that indicate how the function compares the two strings. By default, these flags are not set. This parameter can specify a combination of any of the following values, or it can be set to 0 to obtain the default behavior.

| Flag | Meaning |
| --- | --- |
| **LINGUISTIC_IGNORECASE** | Ignore case, as linguistically appropriate. |
| **LINGUISTIC_IGNOREDIACRITIC** | Ignore nonspacing characters, as linguistically appropriate.<br><br>**Note** This flag does not always produce predictable results when used with decomposed characters, that is, characters in which a base character and one or more nonspacing characters each have distinct code point values. |
| **NORM_IGNORECASE** | Ignore case. For many scripts (notably Latin scripts), NORM_IGNORECASE coincides with LINGUISTIC_IGNORECASE.<br><br>**Note** NORM_IGNORECASE ignores any tertiary distinction, whether it is actually linguistic case or not. For example, in Arabic and Indic scripts, this distinguishes alternate forms of a character, but the differences do not correspond to linguistic case. LINGUISTIC_IGNORECASE causes the function to ignore only actual linguistic casing, instead of ignoring the third sorting weight.<br><br>**Note** With this flag set, the function ignores the distinction between the wide and narrow forms of the CJK compatibility characters. |
| **NORM_IGNOREKANATYPE** | Do not differentiate between hiragana and katakana characters. Corresponding hiragana and katakana characters compare as equal. |
| **NORM_IGNORENONSPACE** | Ignore nonspacing characters. For many scripts (notably Latin scripts), NORM_IGNORENONSPACE coincides with LINGUISTIC_IGNOREDIACRITIC.<br><br>**Note** NORM_IGNORENONSPACE ignores any secondary distinction, whether it is a diacritic or not. Scripts for Korean, Japanese, Chinese, and Indic languages, among others, use this distinction for purposes other than diacritics. LINGUISTIC_IGNOREDIACRITIC causes the function to ignore only actual diacritics, instead of ignoring the second sorting weight.<br><br>**Note** NORM_IGNORENONSPACE only has an effect for locales in which accented characters are sorted in a second pass from main characters. Normally all characters in the string are first compared without regard to accents and, if the strings are equal, a second pass over the strings is performed to compare accents. This flag causes the second pass to not be performed. For locales that sort accented characters in the first pass, this flag has no effect. |
| **NORM_IGNORESYMBOLS** | Ignore symbols and punctuation. |
| **NORM_IGNOREWIDTH** | Ignore the difference between half-width and full-width characters, for example, C a t == cat. The full-width form is a formatting distinction used in Chinese and Japanese scripts. |
| **NORM_LINGUISTIC_CASING** | Use the default linguistic rules for casing, instead of file system rules. Note that most scenarios for **CompareStringEx** use this flag. This flag does not have to be used when your application calls [CompareStringOrdinal](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringordinal). |
| **SORT_DIGITSASNUMBERS** | **Windows 7:** Treat digits as numbers during sorting, for example, sort "2" before "10". |
| **SORT_STRINGSORT** | Treat punctuation the same as symbols. |

### `lpString1` [in]

Pointer to the first string to compare.

### `cchCount1` [in]

Length of the string indicated by *lpString1*, excluding the terminating null character. The application can supply a negative value if the string is null-terminated. In this case, the function determines the length automatically.

### `lpString2` [in]

Pointer to the second string to compare.

### `cchCount2` [in]

Length of the string indicated by *lpString2*, excluding the terminating null character. The application can supply a negative value if the string is null-terminated. In this case, the function determines the length automatically.

### `lpVersionInformation` [in, optional]

Pointer to an [NLSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-nlsversioninfoex) structure that contains the version information about the relevant NLS capability; usually retrieved from [GetNLSVersionEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversionex).

**Windows Vista, Windows 7:** Reserved; must set to **NULL**.

### `lpReserved` [in, optional]

Reserved; must set to **NULL**.

### `lParam` [in, optional]

Reserved; must be set to 0.

## Return value

Returns one of the following values if successful. To maintain the C runtime convention of comparing strings, the value 2 can be subtracted from a nonzero return value. Then, the meaning of <0, ==0, and >0 is consistent with the C runtime.

* CSTR_LESS_THAN. The string indicated by *lpString1* is less in lexical value than the string indicated by *lpString2*.
* CSTR_EQUAL. The string indicated by *lpString1* is equivalent in lexical value to the string indicated by *lpString2*. The two strings are equivalent for sorting purposes, although not necessarily identical.
* CSTR_GREATER_THAN. The string indicated by *lpString1* is greater in lexical value than the string indicated by *lpString2*.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_FLAGS. The values supplied for flags were invalid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

Both [CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw) and **CompareStringEx** are optimized to run at the highest speed when *dwCmpFlags* is set to 0 or NORM_IGNORECASE, *cchCount1* and *cchCount2* are set to -1, and the locale does not support any linguistic compressions, as when traditional Spanish sorting treats "ch" as a single character.

Both [CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw) and **CompareStringEx** ignore Arabic kashidas during the comparison. Thus, if two strings are identical except for the presence of kashidas, the function returns CSTR_EQUAL.

When the application uses the NORM_IGNORENONSPACE and NORM_IGNORECASE flags with the sorting function, the flags can sometimes interfere with string comparisons. This situation might result for a locale that does not support non-spacing characters or case, but uses equivalent weight levels to handle other important operations. In such cases, your application should use the LINGUISTIC_IGNOREDIACRITIC and LINGUISTIC_IGNORECASE flags. These flags provide linguistically appropriate results for sorting code points that use case and diacritic marks, and have no impact on other code points.

**Beginning in Windows Vista:**  Both [CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw) and **CompareStringEx** can retrieve data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

**Beginning in Windows 8:** **CompareStringEx** is declared in Stringapiset.h. Before Windows 8, it was declared in Winnls.h.

**Note** The behavior of sorting can change between Windows releases. For example, there may be new Unicode code points created. Use [GetNlsVersionEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversionex) to discover if the sort version has changed.

#### Examples

An example showing the use of this function can be found in [NLS: Name-based APIs Sample](https://learn.microsoft.com/windows/desktop/Intl/nls--name-based-apis-sample).

## See also

[CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw)

[Custom Locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales)

[Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[Security Considerations: International Features](https://learn.microsoft.com/windows/desktop/Intl/security-considerations--international-features)

[Using Unicode Normalization to Represent Strings](https://learn.microsoft.com/windows/desktop/Intl/using-unicode-normalization-to-represent-strings)