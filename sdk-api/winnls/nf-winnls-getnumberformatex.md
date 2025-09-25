# GetNumberFormatEx function

## Description

Formats a number string as a number string customized for a locale specified by name.

**Note** The application should call this function in preference to [GetNumberFormat](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnumberformata) if designed to run only on Windows Vista and later.

**Note** This function can format data that changes between releases, for example, due to a custom locale. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

## Parameters

### `lpLocaleName` [in, optional]

Pointer to a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names), or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `dwFlags` [in]

Flags controlling the operation of the function. The application must set this parameter to 0 if *lpFormat* is not set to **NULL**. In this case, the function formats the string using user overrides to the default number format for the locale. If *lpFormat* is set to **NULL**, the application can specify [LOCALE_NOUSEROVERRIDE](https://learn.microsoft.com/windows/desktop/Intl/locale-nouseroverride) to format the string using the system default number format for the specified locale.

**Caution** Use of LOCALE_NOUSEROVERRIDE is strongly discouraged as it disables user preferences.

### `lpValue` [in]

Pointer to a null-terminated string containing the number string to format. This string can only contain the following characters. All other characters are invalid. The function returns an error if the string indicated by *lpValue* deviates from these rules.

* Characters "0" through "9".
* One decimal point (dot) if the number is a floating-point value.
* A minus sign in the first character position if the number is a negative value.

### `lpFormat` [in, optional]

Pointer to a [NUMBERFMT](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-numberfmta) structure that contains number formatting information, with all members set to appropriate values. If the application does not set this parameter to **NULL**, the function uses the locale only for formatting information not specified in the structure, for example, the locale string value for the negative sign.

### `lpNumberStr` [out, optional]

Pointer to a buffer in which this function retrieves the formatted number string. Alternatively, this parameter contains **NULL** if *cchNumber* is set to 0. In this case, the function returns the required size for the number string buffer.

### `cchNumber` [in]

Size, in characters, for the number string buffer indicated by *lpNumberStr*. Alternatively, the application can set this parameter to 0. In this case, the function returns the required size for the number string buffer and does not use the *lpNumberStr* parameter.

## Return value

Returns the number of characters retrieved in the buffer indicated by *lpNumberStr* if successful. If the *cchNumber* parameter is set to 0, the function returns the number of characters required to hold the formatted number string, including a terminating null character.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.
* ERROR_OUTOFMEMORY. Not enough storage was available to complete this operation.

## Remarks

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

## See also

[GetNumberFormat](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getnumberformata)

[NUMBERFMT](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-numberfmta)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)