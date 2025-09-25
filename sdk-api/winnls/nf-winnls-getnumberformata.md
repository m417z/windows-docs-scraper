# GetNumberFormatA function

## Description

Formats a number string as a number string customized for a locale specified by identifier.

**Note** For interoperability reasons, the application should prefer the [GetNumberFormatEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnumberformatex) function to **GetNumberFormat** because Microsoft is migrating toward the use of locale names instead of locale identifiers for new locales. Any application that runs only on Windows Vista and later should use **GetNumberFormatEx**.

## Parameters

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

### `dwFlags` [in]

Flags controlling the operation of the function. The application must set this parameter to 0 if *lpFormat* is not set to **NULL**. In this case, the function formats the string using user overrides to the default number format for the locale. If *lpFormat* is set to **NULL**, the application can specify [LOCALE_NOUSEROVERRIDE](https://learn.microsoft.com/windows/desktop/Intl/locale-nouseroverride) to format the string using the system default number format for the specified locale.

**Caution** Use of LOCALE_NOUSEROVERRIDE is strongly discouraged as it disables user preferences.

### `lpValue` [in]

Pointer to a null-terminated string containing the number string to format. This string can only contain the following characters. All other characters are invalid. The function returns an error if the string indicated by *lpValue* deviates from these rules.

* Characters "0" through "9".
* One decimal point (dot) if the number is a floating-point value.
* A minus sign in the first character position if the number is a negative value.

### `lpFormat` [in, optional]

Pointer to a [NUMBERFMT](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-numberfmta) structure that contains number formatting information, with all members set to appropriate values. If this parameter does is not set to **NULL**, the function uses the locale only for formatting information not specified in the structure, for example, the locale-specific string value for the negative sign.

### `lpNumberStr` [out, optional]

Pointer to a buffer in which this function retrieves the formatted number string.

### `cchNumber` [in]

Size, in TCHAR values, for the number string buffer indicated by *lpNumberStr*. Alternatively, the application can set this parameter to 0. In this case, the function returns the required size for the number string buffer, and does not use the *lpNumberStr* parameter.

## Return value

Returns the number of TCHAR values retrieved in the buffer indicated by *lpNumberStr* if successful. If the *cchNumber* parameter is set to 0, the function returns the number of characters required to hold the formatted number string, including a terminating null character.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.
* ERROR_OUTOFMEMORY. Not enough storage was available to complete this operation.

## Remarks

This function can retrieve data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

When the ANSI version of this function is used with a Unicode-only locale identifier, the function can succeed because the operating system uses the system code page. However, characters that are undefined in the system code page appear in the string as a question mark (?).

> [!NOTE]
> The winnls.h header defines GetNumberFormat as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetNumberFormatEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnumberformatex)

[NUMBERFMT](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-numberfmta)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)