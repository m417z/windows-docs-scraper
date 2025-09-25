# CompareStringW function

## Description

Compares two character strings, for a [locale](https://learn.microsoft.com/windows/desktop/Intl/locales-and-languages) specified by identifier.

**Caution** Using **CompareString** incorrectly can compromise the security of your application. Strings that are not compared correctly can produce invalid input. For example, the function can raise security issues when used for a non-linguistic comparison, because two strings that are distinct in their binary representation can be linguistically equivalent. The application should test strings for validity before using them, and should provide error handlers. For more information, see [Security Considerations: International Features](https://learn.microsoft.com/windows/desktop/Intl/security-considerations--international-features).

**Note** For compatibility with Unicode, your applications should prefer [CompareStringEx](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringex) or the Unicode version of **CompareString**. Another reason for preferring [CompareStringEx](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringex) is that Microsoft is migrating toward the use of locale names instead of locale identifiers for new locales, for interoperability reasons. Any application that will be run only on Windows Vista and later should use [CompareStringEx](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringex).

## Parameters

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) of the locale used for the comparison. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

### `dwCmpFlags` [in]

Flags that indicate how the function compares the two strings. For detailed definitions, see the *dwCmpFlags* parameter of [CompareStringEx](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringex).

### `lpString1` [in]

Pointer to the first string to compare.

### `cchCount1` [in]

Length of the string indicated by *lpString1*, excluding the terminating null character. This value represents bytes for the ANSI version of the function and wide characters for the Unicode version. The application can supply a negative value if the string is null-terminated. In this case, the function determines the length automatically.

### `lpString2` [in]

Pointer to the second string to compare.

### `cchCount2` [in]

Length of the string indicated by *lpString2*, excluding the terminating null character. This value represents bytes for the ANSI version of the function and wide characters for the Unicode version. The application can supply a negative value if the string is null-terminated. In this case, the function determines the length automatically.

## Return value

Returns the values described for [CompareStringEx](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringex).

## Remarks

See Remarks for [CompareStringEx](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringex).

If your application is calling the ANSI version of **CompareString**, the function converts parameters via the default code page of the supplied locale. Thus, an application can never use **CompareString** to handle UTF-8 text.

Normally, for case-insensitive comparisons, **CompareString** maps the lowercase "i" to the uppercase "I", even when the locale is Turkish or Azerbaijani. The NORM_LINGUISTIC_CASING flag overrides this behavior for Turkish or Azerbaijani. If this flag is specified in conjunction with Turkish or Azerbaijani, LATIN SMALL LETTER DOTLESS I (U+0131) is the lowercase form of LATIN CAPITAL LETTER I (U+0049) and LATIN SMALL LETTER I (U+0069) is the lowercase form of LATIN CAPITAL LETTER I WITH DOT ABOVE (U+0130).

**Starting with Windows 8:** The ANSI version of the function is declared in Winnls.h, and the Unicode version is declared in Stringapiset.h. Before Windows 8, both versions were declared in Winnls.h.

## See also

[CompareStringEx](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringex)

[Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[Security Considerations: International Features](https://learn.microsoft.com/windows/desktop/Intl/security-considerations--international-features)

[Using Unicode Normalization to Represent Strings](https://learn.microsoft.com/windows/desktop/Intl/using-unicode-normalization-to-represent-strings)