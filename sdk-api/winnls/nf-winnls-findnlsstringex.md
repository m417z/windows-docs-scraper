# FindNLSStringEx function

## Description

Locates a Unicode string (wide characters) or its equivalent in another Unicode string for a locale specified by name.

**Caution** Because strings with very different binary representations can compare as identical, this function can raise certain security concerns. For more information, see the discussion of comparison functions in [Security Considerations: International Features](https://learn.microsoft.com/windows/desktop/Intl/security-considerations--international-features).

## Parameters

### `lpLocaleName` [in, optional]

Pointer to a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names), or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `dwFindNLSStringFlags` [in]

Flags specifying details of the find operation. These flags are mutually exclusive, with FIND_FROMSTART being the default. The application can specify just one of the find flags with any of the filtering flags defined in the next table. If the application does not specify a flag, the function uses the default comparison for the specified locale. As discussed in [Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications), there is no binary comparison mode.

| Value | Meaning |
| --- | --- |
| **FIND_FROMSTART** | Search the string, starting with the first character of the string. |
| **FIND_FROMEND** | Search the string in the reverse direction, starting with the last character of the string. |
| **FIND_STARTSWITH** | Test to find out if the value specified by *lpStringValue* is the first value in the source string indicated by *lpStringSource*. |
| **FIND_ENDSWITH** | Test to find out if the value specified by *lpStringValue* is the last value in the source string indicated by *lpStringSource*. |

The application can use the filtering flags defined below in combination with a find flag.

| Value | Meaning |
| --- | --- |
| **LINGUISTIC_IGNORECASE** | Ignore case in the search, as linguistically appropriate. For more information, see the Remarks section. |
| **LINGUISTIC_IGNOREDIACRITIC** | Ignore diacritics, as linguistically appropriate. For more information, see the Remarks section.<br><br>**Note** This flag does not always produce predictable results when used with decomposed characters, that is, characters in which a base character and one or more nonspacing characters each have distinct code point values. |
| **NORM_IGNORECASE** | Ignore case in the search. For more information, see the Remarks section. |
| **NORM_IGNOREKANATYPE** | Do not differentiate between hiragana and katakana characters. Corresponding hiragana and katakana characters compare as equal. |
| **NORM_IGNORENONSPACE** | Ignore nonspacing characters. For more information, see the Remarks section. |
| **NORM_IGNORESYMBOLS** | Ignore symbols and punctuation. |
| **NORM_IGNOREWIDTH** | Ignore the difference between half-width and full-width characters, for example, C a t == cat. The full-width form is a formatting distinction used in Chinese and Japanese scripts. |
| **NORM_LINGUISTIC_CASING** | Use linguistic rules for casing, instead of file system rules (default). For more information, see the Remarks section. |

### `lpStringSource` [in]

Pointer to the source string, in which the function searches for the string specified by *lpStringValue*.

### `cchSource` [in]

Size, in characters excluding the terminating null character, of the string indicated by *lpStringSource*. The application cannot specify 0 or any negative number other than -1 for this parameter. The application specifies -1 if the source string is null-terminated and the function should calculate the size automatically.

### `lpStringValue` [in]

Pointer to the search string, for which the function searches in the source string.

### `cchValue` [in]

Size, in characters excluding the terminating null character, of the string indicated by *lpStringValue*. The application cannot specify 0 or any negative number other than -1 for this parameter. The application specifies -1 if the search string is null-terminated and the function should calculate the size automatically.

### `pcchFound` [out, optional]

Pointer to a buffer containing the length of the string that the function finds. The string can be either longer or shorter than the search string. If the function fails to find the search string, this parameter is not modified.

The function can retrieve **NULL** in this parameter. In this case, the function makes no indication if the length of the found string differs from the length of the source string.

Note that the value of *pcchFound* is often identical to the value provided in *cchValue*, but can differ in the following cases:

* The value provided in *cchValue* is negative.
* The strings are equivalent, but have different lengths. For example, "A" plus "Combining Ring" (U+0041 U+030A) is equivalent to the "A Ring" (U+00c5).

### `lpVersionInformation` [in, optional]

Reserved; must be **NULL**.

### `lpReserved` [in, optional]

Reserved; must be **NULL**.

### `sortHandle` [in, optional]

Reserved; must be 0.

## Return value

Returns a 0-based index into the source string indicated by *lpStringSource* if successful. In combination with the value in *pcchFound*, this index provides the exact location of the entire found string in the source string. A return value of 0 is an error-free index into the source string, and the matching string is in the source string at offset 0.

The function returns -1 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.
* ERROR_SUCCESS. The action completed successfully but yielded no results.

## Remarks

This function provides a variety of search options, including search direction, character equivalence filtering, and locale-specific filtering. Note that equivalence depends on the locale and flags specified in the call to the function. The filtering flags can alter the results of the search. For example, the potential matches increase when the function ignores case or diacritic marks when performing the search.

By default, this function maps the lowercase "i" to the uppercase "I", even when the *Locale* parameter specifies Turkish (Turkey) or Azerbaijani (Azerbaijan). To override this behavior for Turkish or Azerbaijani, the application should specify NORM_LINGUISTIC_CASING. If this flag is specified for the correct locale, "ı" (lowercase dotless I) is the lowercase form of "I" (uppercase dotless I) and "i" (lowercase dotted I) is the lowercase form of "ı" (uppercase dotted I).

For many scripts (notably Latin scripts), NORM_IGNORENONSPACE coincides with LINGUISTIC_IGNOREDIACRITIC and NORM_IGNORECASE coincides with LINGUISTIC_IGNORECASE, with the following exceptions:

* NORM_IGNORENONSPACE ignores any secondary distinction, whether or not it is a diacritic. Scripts for Korean, Japanese, Chinese, Indic languages, and others use this distinction for purposes other than diacritics. LINGUISTIC_IGNOREDIACRITIC ignores only actual diacritics, instead of simply ignoring the second sorting weight.
* NORM_IGNORECASE ignores any tertiary distinction, whether or not it is actually linguistic case. For example, in Arabic and Indic scripts, this flag distinguishes alternate forms of a character. However, the differences do not correspond to linguistic case. LINGUISTIC_IGNORECASE ignores only actual linguistic casing, instead of ignoring the third sorting weight.

In contrast to other NLS API functions, which return 0 for failure, this function returns -1 if it fails. On success, it returns a 0-based index. Use of this index helps the function avoid off-by-one errors and one-character buffer overruns.

This function is one of the few NLS functions that calls [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) even when it succeeds. It makes this call to clear the last error in a thread when it fails to match the search string. This clears the value returned by **GetLastError**.

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

## See also

[CompareStringEx](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringex)

[FindNLSString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-findnlsstring)

[Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications)

[LCMapStringEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcmapstringex)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[Security Considerations: International Features](https://learn.microsoft.com/windows/desktop/Intl/security-considerations--international-features)