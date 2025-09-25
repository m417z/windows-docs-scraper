# LCMapStringW function

## Description

For a locale specified by identifier, maps one input character string to another using a specified transformation, or generates a sort key for the input string.

**Note** For interoperability reasons, the application should prefer the [LCMapStringEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcmapstringex) function to **LCMapString** because Microsoft is migrating toward the use of locale names instead of locale identifiers for new locales. This recommendation applies especially to custom locales, including those created by Microsoft. Any application that will be run only on Windows Vista and later should use [LCMapStringEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcmapstringex).

## Parameters

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

The following custom locale identifiers are also supported.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

### `dwMapFlags` [in]

Flags specifying the type of transformation to use during string mapping or the type of sort key to generate. For detailed definitions, see the *dwMapFlags* parameter of [LCMapStringEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcmapstringex).

### `lpSrcStr` [in]

Pointer to a source string that the function maps or uses for sort key generation. This string cannot have a size of 0.

### `cchSrc` [in]

Size, in characters, of the source string indicated by *lpSrcStr*. The size of the source string can include the terminating null character, but does not have to. If the terminating null character is included, the mapping behavior of the function is not greatly affected because the terminating null character is considered to be unsortable and always maps to itself.

The application can set the parameter to any negative value to specify that the source string is null-terminated. In this case, if **LCMapString** is being used in its string-mapping mode, the function calculates the string length itself, and null-terminates the mapped string indicated by *lpDestStr*.

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

## Return value

If the function succeeds when used for string mapping, it returns the number of characters in the translated string (see *cchSrc* and *cchDest* for more details).

If the function succeeds when used to generate sort keys, it returns the number of bytes in the sort key.

This function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

This function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

See Remarks for [LCMapStringEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcmapstringex).

The ANSI version of **LCMapString** maps strings to and from Unicode based on the default Windows (ANSI) code page associated with the specified locale. When the ANSI version of this function is used with a Unicode-only locale, the function can succeed because the operating system uses the CP_ACP value, representing the system default Windows ANSI code page. However, characters that are undefined in the system code page appear in the string as a question mark (?).

> [!NOTE]
> The winnls.h header defines LCMapString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw)

[FindNLSString](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-findnlsstring)

[GetNLSVersion](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnlsversion)

[Handling Sorting in Your Applications](https://learn.microsoft.com/windows/desktop/Intl/handling-sorting-in-your-applications)

[LCMapStringEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-lcmapstringex)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)