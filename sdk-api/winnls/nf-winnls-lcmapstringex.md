# LCMapStringEx function

## Description

For a locale specified by name, maps an input character string to another using a specified transformation, or generates a sort key for the input string.

**Note** The application should call this function in preference to [LCMapString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcmapstringa) if designed to run only on Windows Vista and later.

## Parameters

### `lpLocaleName` [in, optional]

Pointer to a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names), or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `dwMapFlags` [in]

Flag specifying the type of transformation to use during string mapping or the type of sort key to generate. This parameter can have the following values.

| Flag | Meaning |
| --- | --- |
| **LCMAP_BYTEREV**| Use byte reversal. For example, if the application passes in 0x3450 0x4822, the result is 0x5034 0x2248. |
| **LCMAP_FULLWIDTH** | Use Unicode (wide) characters where applicable. This flag and LCMAP_HALFWIDTH are mutually exclusive. With this flag, the mapping may use Normalization Form C even if an input character is already full-width. For example, the string "は゛" (which is already full-width) is normalized to "ば". See [Unicode normalization forms](http://www.unicode.org/reports/tr15/). |
|**LCMAP_HALFWIDTH** | Use narrow characters where applicable. This flag and LCMAP_FULLWIDTH are mutually exclusive. |
| **LCMAP_HIRAGANA** | Map all katakana characters to hiragana. This flag and LCMAP_KATAKANA are mutually exclusive. |
| **LCMAP_KATAKANA** | Map all hiragana characters to katakana. This flag and LCMAP_HIRAGANA are mutually exclusive. |
| **LCMAP_LINGUISTIC_CASING** | Use linguistic rules for casing, instead of file system rules (default). This flag is valid with LCMAP_LOWERCASE or LCMAP_UPPERCASE only. |
| **LCMAP_LOWERCASE** | For locales and scripts capable of handling uppercase and lowercase, map all characters to lowercase.
| **LCMAP_HASH** | Return a hash of the raw sort weights of a string.<br> <br>Strings that appear equivalent typically return the same hash (for example, "hello" and "HELLO" with LCMAP_IGNORECASE). However, some complex cases, such as East Asian languages, can have similar strings with identical weights that compare as equal but do not return the same hash.<br> <br>LCMAP_HASH requires that the output buffer be of size sizeof(int) |
| **LCMAP_SIMPLIFIED_CHINESE** | Map traditional Chinese characters to simplified Chinese characters. This flag and LCMAP_TRADITIONAL_CHINESE are mutually exclusive. |
| **LCMAP_SORTHANDLE** <br> **The use of a sort handle results in minimal performance improvements and is discouraged.** | Return a token representing the resolved sort parameters for the locale (like locale name), so future calls can pass `NULL` for the sort name and pass the previously queried sort handle as the last parameter (sortHandle) in subsequent calls to [CompareStringEx](https://learn.microsoft.com/windows/win32/api/stringapiset/nf-stringapiset-comparestringex) or [LCMapStringEx](https://learn.microsoft.com/windows/win32/api/winnls/nf-winnls-lcmapstringex).<br> <br>LCMAP_SORTHANDLE requires that the output buffer be of size sizeof(lparam) |
| **LCMAP_SORTKEY** | Produce a normalized sort key. If the LCMAP_SORTKEY flag is not specified, the function performs string mapping. For details of sort key generation and string mapping, see the Remarks section. |
| **LCMAP_TITLECASE** | Windows 7: Map all characters to title case, in which the first letter of each major word is capitalized. |
| **LCMAP_TRADITIONAL_CHINESE** | Map simplified Chinese characters to traditional Chinese characters. This flag and LCMAP_SIMPLIFIED_CHINESE are mutually exclusive. |
| **LCMAP_UPPERCASE** | For locales and scripts capable of handling uppercase and lowercase, map all characters to uppercase. |

The following flags can be used alone, with one another, or with the LCMAP_SORTKEY and/or LCMAP_BYTEREV flags. However, they cannot be combined with the other flags listed above.

| Flag | Meaning |
| --- | --- |
| **NORM_IGNORENONSPACE** | Ignore nonspacing characters. For many scripts (notably Latin scripts), NORM_IGNORENONSPACE coincides with LINGUISTIC_IGNOREDIACRITIC.<br><br>**Note** NORM_IGNORENONSPACE ignores any secondary distinction, whether it is a diacritic or not. Scripts for Korean, Japanese, Chinese, and Indic languages, among others, use this distinction for purposes other than diacritics. LINGUISTIC_IGNOREDIACRITIC causes the function to ignore only actual diacritics, instead of ignoring the second sorting weight. |
| **NORM_IGNORESYMBOLS** | Ignore symbols and punctuation. |

The flags listed below are used only with the LCMAP_SORTKEY flag.

| Flag | Meaning |
| --- | --- |
| **LINGUISTIC_IGNORECASE** | Ignore case, as linguistically appropriate. |
| **LINGUISTIC_IGNOREDIACRITIC** | Ignore nonspacing characters, as linguistically appropriate.<br><br>**Note** This flag does not always produce predictable results when used with decomposed characters, that is, characters in which a base character and one or more nonspacing characters each have distinct code point values. |
| **NORM_IGNORECASE** | Ignore case. For many scripts (notably Latin scripts), NORM_IGNORECASE coincides with LINGUISTIC_IGNORECASE.<br><br>**Note** NORM_IGNORECASE ignores any tertiary distinction, whether it is actually linguistic case or not. For example, in Arabic and Indic scripts, this flag distinguishes alternate forms of a character, but the differences do not correspond to linguistic case. LINGUISTIC_IGNORECASE causes the function to ignore only actual linguistic casing, instead of ignoring the third sorting weight.<br><br>**Note** For double-byte character set (DBCS) locales, NORM_IGNORECASE has an effect on all Unicode characters as well as narrow (one-byte) characters, including Greek and Cyrillic characters. |
| **NORM_IGNOREKANATYPE** | Do not differentiate between hiragana and katakana characters. Corresponding hiragana and katakana characters compare as equal. |
| **NORM_IGNOREWIDTH** | Ignore the difference between half-width and full-width characters, for example, C a t == cat. The full-width form is a formatting distinction used in Chinese and Japanese scripts. |
| **NORM_LINGUISTIC_CASING** | Use linguistic rules for casing, instead of file system rules (default). |
| **SORT_DIGITSASNUMBERS** | **Windows 7:** Treat digits as numbers during sorting, for example, sort "2" before "10". |
| **SORT_STRINGSORT** | Treat punctuation the same as symbols. |

### `lpSrcStr` [in]

Pointer to a source string that the function maps or uses for sort key generation. This string cannot have a size of 0.

### `cchSrc` [in]

Size, in characters, of the source string indicated by *lpSrcStr*. The size of the source string can include the terminating null character, but does not have to. If the terminating null character is included, the mapping behavior of the function is not greatly affected because the terminating null character is considered to be unsortable and always maps to itself.

The application can set this parameter to any negative value to specify that the source string is null-terminated. In this case, if **LCMapStringEx** is being used in its string-mapping mode, the function calculates the string length itself, and null-terminates the mapped string indicated by *lpDestStr*.

The application cannot set this parameter to 0.

### `lpDestStr` [out, optional]

Pointer to a buffer in which this function retrieves the mapped string or a sort key.

If the application is using the function to generate a sort key (LCMAP_SORTKEY):

- The sort key is stored in the buffer and treated as an opaque array of bytes. The stored values can include embedded 0 bytes at any position.
- The destination string can contain an odd number of bytes. The LCMAP_BYTEREV flag only reverses an even number of bytes. The last byte (odd-positioned) in the sort key is not reversed.

If the caller explicitly requests a subset of the string, the destination string does not include a terminating null character unless the caller specified it in *cchDest*.

If this function fails, the destination buffer might contain either partial results or no results at all. In this case, all results should be considered invalid.

> [!NOTE]
> When setting LCMAP_UPPERCASE or LCMAP_LOWERCASE, the destination string can use the same buffer as the source string. However, this is strongly discouraged, as some conditions may cause the returned cased string to be a different length.

### `cchDest` [in]

Size, in characters, of the destination string indicated by *lpDestStr*. If the application is using the function for string mapping, it supplies a character count for this parameter. If space for a terminating null character is included in *cchSrc*, *cchDest* must also include space for a terminating null character.

If the application is using the function to generate a sort key, it supplies a byte count for the size. This byte count must include space for the sort key 0x00 terminator.

The application can set *cchDest* to 0. In this case, the function does not use the *lpDestStr* parameter and returns the required buffer size for the mapped string or sort key.

### `lpVersionInformation` [in, optional]

Pointer to an [NLSVERSIONINFOEX](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-nlsversioninfoex) structure that contains the version information about the relevant NLS capability; usually retrieved from [GetNLSVersionEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversionex).

**Windows Vista, Windows 7:** Reserved; must set to NULL.

### `lpReserved` [in, optional]

Reserved; must be NULL.

### `sortHandle` [in, optional]

Reserved; must be 0.

> [!NOTE]
> [CompareStringEx](https://learn.microsoft.com/windows/win32/api/stringapiset/nf-stringapiset-comparestringex) and [LCMapStringEx](https://learn.microsoft.com/windows/win32/api/winnls/nf-winnls-lcmapstringex) can specify a sort handle (if the locale name is null). This use is discouraged for most apps.

## Return value

If the function succeeds when used for string mapping, it returns the number of characters in the translated string (see *cchSrc* and *cchDest* for more details).

If the function succeeds when used for generating a sort key, it returns the number of bytes in the sort key.

This function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

The application can use [LCMapString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcmapstringa) or **LCMapStringEx** to generate a sort key. To do this, the application specifies LCMAP_SORTKEY for the *dwMapFlags* parameter. For more information, see [Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications).

> [!NOTE]
> Sort keys are opaque byte streams. Callers should treat them as a byte array of the length returned by the API and not rely on any internal structure that may appear to be present. Zero, one or more of the bytes in the returned sort key could be 0. Absence or presence of a zero byte should not be expected.

Another way for your application to use [LCMapString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcmapstringa) or **LCMapStringEx** is in mapping strings. In this case, the application does not specify LCMAP_SORTKEY for the *dwMapFlags* parameter, but supplies some other combination of flags. For more information, see [Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications).

**Beginning in Windows Vista:** This function can handle data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

## See also

[CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw)

[FindNLSStringEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-findnlsstringex)

[GetNLSVersionEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversionex)

[Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications)

[LCMapString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcmapstringa)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)