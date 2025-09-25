# GetCurrencyFormatW function

## Description

Formats a number string as a currency string for a locale specified by identifier.

**Note** For interoperability reasons, the application should prefer the [GetCurrencyFormatEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcurrencyformatex) function to **GetCurrencyFormat** because Microsoft is migrating toward the use of locale names instead of locale identifiers for new locales. Any application that runs only on Windows Vista and later should use [GetCurrencyFormatEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcurrencyformatex).

## Parameters

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale for which this function formats the currency string. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

### `dwFlags` [in]

Flags controlling currency format. The application must set this parameter to 0 if *lpFormat* is not set to **NULL**. In this case, the function formats the string using user overrides to the default currency format for the locale. If *lpFormat* is set to **NULL**, the application can specify [LOCALE_NOUSEROVERRIDE](https://learn.microsoft.com/windows/desktop/Intl/locale-nouseroverride) to format the string using the system default currency format for the specified locale.

**Caution** Use of [LOCALE_NOUSEROVERRIDE](https://learn.microsoft.com/windows/desktop/Intl/locale-nouseroverride) is strongly discouraged as it disables user preferences.

### `lpValue` [in]

For details, see the *lpValue* parameter of [GetCurrencyFormatEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcurrencyformatex).

### `lpFormat` [in, optional]

Pointer to a [CURRENCYFMT](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-currencyfmta) structure that contains currency formatting information. All members of the structure must contain appropriate values. The application can set this parameter to **NULL** if function is to use the currency format of the specified locale. If this parameter is not set to **NULL**, the function uses the specified locale only for formatting information not specified in the [CURRENCYFMT](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-currencyfmta) structure, for example, the string value for the negative sign used by the locale.

### `lpCurrencyStr` [out, optional]

Pointer to a buffer in which this function retrieves the formatted currency string.

### `cchCurrency` [in]

Size, in characters, of the *lpCurrencyStr* buffer. The application sets this parameter to 0 if the function is to return the size of the buffer required to hold the formatted currency string. In this case, the *lpCurrencyStr* parameter is not used.

## Return value

Returns the number of characters retrieved in the buffer indicated by *lpCurrencyStr* if successful. If the *cchCurrency* parameter is set to 0, the function returns the size of the buffer required to hold the formatted currency string, including a terminating null character.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function can retrieve data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

When the ANSI version of this function is used with a Unicode-only locale identifier, the call can succeed because the operating system uses the system code page. However, characters that are undefined in the system code page appear in the string as a question mark (?).

> [!NOTE]
> The winnls.h header defines GetCurrencyFormat as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CURRENCYFMT](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-currencyfmta)

[GetCurrencyFormatEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcurrencyformatex)

[GetNumberFormat](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnumberformata)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)