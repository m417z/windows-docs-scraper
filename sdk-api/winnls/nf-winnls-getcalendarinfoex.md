# GetCalendarInfoEx function

## Description

Retrieves information about a calendar for a locale specified by name.

**Note** The application should call this function in preference to [GetCalendarInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcalendarinfoa) if designed to run only on Windows Vista and later.

**Note** This function can retrieve data that changes between releases, for example, due to a custom locale. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

## Parameters

### `lpLocaleName` [in, optional]

Pointer to a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names), or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `Calendar` [in]

[Calendar identifier](https://learn.microsoft.com/windows/desktop/Intl/calendar-identifiers).

### `lpReserved` [in, optional]

Reserved; must be **NULL**.

### `CalType` [in]

Type of information to retrieve. For more information, see [Calendar Type Information](https://learn.microsoft.com/windows/desktop/Intl/calendar-type-information).

**Note** **GetCalendarInfoEx** returns only one string if this parameter specifies CAL_IYEAROFFSETRANGE or CAL_SERASTRING. In both cases the current era is returned.

For CAL_NOUSEROVERRIDE, the function ignores any value set by [SetCalendarInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setcalendarinfoa) and uses the database settings for the current system default locale. This type is relevant only in the combination CAL_NOUSEROVERRIDE | CAL_ITWODIGITYEARMAX. CAL_ITWODIGITYEARMAX is the only value that can be set by **SetCalendarInfo**.

### `lpCalData` [out, optional]

Pointer to a buffer in which this function retrieves the requested data as a string. If CAL_RETURN_NUMBER is specified in *CalType*, this parameter must retrieve **NULL**.

### `cchData` [in]

Size, in characters, of the *lpCalData* buffer. The application can set this parameter to 0 to return the required size for the calendar data buffer. In this case, the *lpCalData* parameter is not used. If CAL_RETURN_NUMBER is specified for *CalType*, the value of *cchData* must be 0.

### `lpValue` [out, optional]

Pointer to a variable that receives the requested data as a number. If CAL_RETURN_NUMBER is specified in *CalType*, then *lpValue* must not be **NULL**. If CAL_RETURN_NUMBER is not specified in *CalType*, then *lpValue* must be **NULL**.

## Return value

Returns the number of characters retrieved in the *lpCalData* buffer if successful. If the function succeeds, *cchData* is set to 0, and CAL_RETURN_NUMBER is not specified, the return value is the size of the buffer required to hold the locale information. If the function succeeds, *cchData* is set to 0, and CAL_RETURN_NUMBER is specified, the return value is the size of the value written to the *lpValue* parameter. This size is always 2.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

**Note** This API is being updated to support the May 2019 Japanese era change. If your application supports the Japanese calendar, you should validate that it properly handles the new era. See [Prepare your application for the Japanese era change](https://learn.microsoft.com/windows/uwp/design/globalizing/japanese-era-change) for more information.

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

## See also

[Calendar Type Information](https://learn.microsoft.com/windows/desktop/Intl/calendar-type-information)

[GetCalendarInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcalendarinfoa)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)

[SetCalendarInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setcalendarinfoa)