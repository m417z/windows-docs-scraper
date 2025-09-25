# FindNLSString function

## Description

Locates a Unicode string (wide characters) or its equivalent in another Unicode string for a locale specified by identifier.

**Caution** Because strings with very different binary representations can compare as identical, this function can raise certain security concerns. For more information, see the discussion of comparison functions in [Security Considerations: International Features](https://learn.microsoft.com/windows/desktop/Intl/security-considerations--international-features).

**Note** For interoperability reasons, the application should prefer the [FindNLSStringEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-findnlsstringex) function because Microsoft is migrating toward the use of locale names instead of locale identifiers for new locales. Although **FindNLSString** supports custom locales, most applications should use [FindNLSStringEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-findnlsstringex) for this type of support.

## Parameters

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create an identifier or use one of the following predefined values.

* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

**Windows Vista and later:** The following custom locale identifiers are also supported.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

### `dwFindNLSStringFlags` [in]

Flags specifying details of the find operation. For detailed definitions, see the *dwFindNLSStringFlags* parameter of [FindNLSStringEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-findnlsstringex).

### `lpStringSource` [in]

Pointer to the source string, in which the function searches for the string specified by *lpStringValue*.

### `cchSource` [in]

Size, in characters excluding the terminating null character, of the string indicated by *lpStringSource*. The application cannot specify 0 or any negative number other than -1 for this parameter. The application specifies -1 if the source string is null-terminated and the function should calculate the size automatically.

### `lpStringValue` [in]

Pointer to the search string, for which the function searches in the source string.

### `cchValue` [in]

Size, in characters excluding the terminating null character, of the string indicated by *lpStringValue*. The application cannot specify 0 or any negative number other than -1 for this parameter. The application specifies -1 if the search string is null-terminated and the function should calculate the size automatically.

### `pcchFound` [out, optional]

Pointer to a buffer containing the length of the string that the function finds. For details, see the *pcchFound* parameter of [FindNLSStringEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-findnlsstringex).

## Return value

Returns a 0-based index into the source string indicated by *lpStringSource* if successful. In combination with the value in *pcchFound*, this index provides the exact location of the entire found string in the source string. A return value of 0 is an error-free index into the source string, and the matching string is in the source string at offset 0.

The function returns -1 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.
* ERROR_SUCCESS. The action completed successfully but yielded no results.

## Remarks

See Remarks for [FindNLSStringEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-findnlsstringex).

## See also

[CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw)

[FindNLSStringEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-findnlsstringex)

[Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications)

[LCMapString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcmapstringa)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[Security Considerations: International Features](https://learn.microsoft.com/windows/desktop/Intl/security-considerations--international-features)