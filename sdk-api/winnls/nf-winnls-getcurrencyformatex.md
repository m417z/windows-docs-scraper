# GetCurrencyFormatEx function

## Description

Formats a number string as a currency string for a locale specified by name.

**Note** The application should call this function in preference to [GetCurrencyFormat](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcurrencyformata) if designed to run only on Windows Vista and later.

**Note** This function can format data that changes between releases, for example, due to a custom locale. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

## Parameters

### `lpLocaleName` [in, optional]

Pointer to a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names) or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `dwFlags` [in]

Flags controlling the operation of the function. The application must set this parameter to 0 if *lpFormat* is not set to **NULL**. In this case, the function formats the string using user overrides to the default currency format for the locale. If *lpFormat* is set to **NULL**, the application can specify [LOCALE_NOUSEROVERRIDE](https://learn.microsoft.com/windows/desktop/Intl/locale-nouseroverride) to format the string using the system default currency format for the specified locale.

**Caution** Use of [LOCALE_NOUSEROVERRIDE](https://learn.microsoft.com/windows/desktop/Intl/locale-nouseroverride) is strongly discouraged as it disables user preferences.

### `lpValue` [in]

Pointer to a null-terminated string containing the number string to format. This string can contain only the following characters. All other characters are invalid. The function returns an error if the string deviates from these rules.

* Characters "0" through "9"
* One decimal point (dot) if the number is a floating-point value
* A minus sign in the first character position if the number is a negative value

### `lpFormat` [in, optional]

Pointer to a [CURRENCYFMT](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-currencyfmta) structure that contains currency formatting information. All members of the structure must contain appropriate values. The application can set this parameter to **NULL** if function is to use the currency format of the specified locale. If this parameter is not set to **NULL**, the function uses the specified locale only for formatting information not specified in the **CURRENCYFMT** structure, for example, the string value for the negative sign used by the locale.

### `lpCurrencyStr` [out, optional]

Pointer to a buffer in which this function retrieves the formatted currency string.

### `cchCurrency` [in]

Size, in characters, of the *lpCurrencyStr* buffer. The application can set this parameter to 0 to return the size of the buffer required to hold the formatted currency string. In this case, the buffer indicated by *lpCurrencyStr* is not used.

## Return value

Returns the number of characters retrieved in the buffer indicated by *lpCurrencyStr* if successful. If the *cchCurrency* parameter is 0, the function returns the size of the buffer required to hold the formatted currency string, including a terminating null character.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

## See also

[CURRENCYFMT](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-currencyfmta)

[GetCurrencyFormat](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcurrencyformata)

[GetNumberFormatEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnumberformatex)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)