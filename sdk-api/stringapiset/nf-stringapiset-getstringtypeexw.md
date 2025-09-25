# GetStringTypeExW function

## Description

Retrieves character type information for the characters in the specified source string. For each character in the string, the function sets one or more bits in the corresponding 16-bit element of the output array. Each bit identifies a given character type, for example, letter, digit, or neither.

> [!NOTE]
> This API may have incomplete/outdated information for certain Unicode characters, particularly those in the supplementary range. For more accurate and comprehensive Unicode character type information, consider using equivalent ICU APIs such as [u_charType](https://unicode-org.github.io/icu-docs/apidoc/dev/icu4c/uchar_8h.html#a53f7567680cb6d92489d6e7750c90284), [u_islower](https://unicode-org.github.io/icu-docs/apidoc/dev/icu4c/uchar_8h.html#a65980f5668ed1df7f183a090f62b0e61), [u_isspace](https://unicode-org.github.io/icu-docs/apidoc/dev/icu4c/uchar_8h.html#a48dd198b451e691cf81eb41831474ddc), and [u_ispunct](https://unicode-org.github.io/icu-docs/apidoc/dev/icu4c/uchar_8h.html#add0409f1e6cbbc84dda50c45cc3e7302). For guidance on using ICU APIs on Windows, see [Getting Started with ICU on Windows](https://learn.microsoft.com/windows/win32/intl/international-components-for-unicode--icu-#getting-started).

## Parameters

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale. This value uniquely defines the ANSI code page. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

**Windows Vista and later:** The following custom locale identifiers are also supported.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

### `dwInfoType` [in]

Flags specifying the character type information to retrieve. For possible flag values, see the *dwInfoType* parameter of [GetStringTypeW](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-getstringtypew). For detailed information about the character type bits, see Remarks for [GetStringTypeW](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-getstringtypew).

### `lpSrcStr` [in]

Pointer to the string for which to retrieve the character types. The string is assumed to be null-terminated if *cchSrc* is set to any negative value.

### `cchSrc` [in]

Size, in characters, of the string indicated by *lpSrcStr*. The size refers to bytes for the ANSI version of the function or wide characters for the Unicode version. If the size includes a terminating null character, the function retrieves character type information for that character. If the application sets the size to any negative integer, the source string is assumed to be null-terminated and the function calculates the size automatically with an additional character for the null termination.

### `lpCharType` [out]

Pointer to an array of 16-bit values. The length of this array must be large enough to receive one 16-bit value for each character in the source string. If *cchSrc* is not a negative number, *lpCharType* should be an array of words with *cchSrc* elements. If *cchSrc* is set to a negative number, *lpCharType* is an array of words with *lpSrcStr* + 1 elements. When the function returns, this array contains one word corresponding to each character in the source string.

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* **ERROR_INVALID_FLAGS**. The values supplied for flags were not valid.
* **ERROR_INVALID_PARAMETER**. Any of the parameter values was invalid.

## Remarks

> [!IMPORTANT]
> Using the **GetStringTypeEx** function incorrectly can compromise the security of your application. To avoid a buffer overflow, the application must set the output buffer size correctly. For more security information, see [Security Considerations: Windows User Interface](https://learn.microsoft.com/windows/desktop/AppUIStart/sec-ui).

Unlike its close relatives [GetStringTypeA](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getstringtypea) and [GetStringTypeW](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-getstringtypew), this function exhibits appropriate ANSI or Unicode behavior through the use of the #define UNICODE switch. This is the recommended function for character type retrieval.

For an overview of the use of the string functions, see [Strings](https://learn.microsoft.com/windows/desktop/menurc/strings).

Using the ANSI code page for the supplied locale, this function translates the source string from ANSI to Unicode. It then analyzes each Unicode character for character type information.

The ANSI version of this function converts the source string to Unicode and calls the
corresponding [GetStringTypeW](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-getstringtypew) function. Thus the words in the output buffer correspond not to the original ANSI string but to its Unicode equivalent. The conversion from ANSI to Unicode can result in a change in string length, for example, a pair of ANSI characters can map to a single
Unicode character. Therefore, the correspondence between the words in the output buffer and the characters in the original ANSI string is not one-to-one in all cases, for example, multibyte strings. Thus, the ANSI version of this function is of limited use for multi-character strings. The Unicode version of the function is recommended instead.

This function circumvents a limitation caused by the difference in parameters between [GetStringTypeA](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getstringtypea) and [GetStringTypeW](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-getstringtypew). Because of the parameter difference, an application cannot automatically invoke the proper ANSI or Unicode version of a **GetStringType*** function through the use of the #define UNICODE switch. On the other hand, **GetStringTypeEx**, behaves properly with regard to that switch. Thus it is the recommended function.

When the ANSI version of this function is used with a Unicode-only locale identifier, the function can succeed because the operating system uses the system code page. However, characters that are undefined in the system code page appear in the string as a question mark (?).

The values of the *lpSrcStr* and *lpCharType* parameters must not be the same. If they are the same, the function fails with **ERROR_INVALID_PARAMETER**.

The *Locale* parameter is only used to perform string conversion to Unicode. It has nothing to do with the CTYPE* values supplied by the application. These values are solely determined by Unicode code points, and do not vary on a locale basis. For example, Greek letters are specified as C1_ALPHA for any value of *Locale*.

## See also

[GetStringTypeW](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-getstringtypew)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)