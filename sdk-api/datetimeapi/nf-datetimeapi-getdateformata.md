# GetDateFormatA function

## Description

Formats a date as a date string for a locale specified by the locale identifier. The function formats either a specified date or the local system date.

**Note** For interoperability reasons, the application should prefer the [GetDateFormatEx](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-getdateformatex) function to **GetDateFormat** because Microsoft is migrating toward the use of locale names instead of locale identifiers for new locales. Any application that will be run only on Windows Vista and later should use [GetDateFormatEx](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-getdateformatex).

## Parameters

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale this function formats the date string for. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

### `dwFlags` [in]

Flags specifying date format options. For detailed definitions, see the *dwFlags* parameter of [GetDateFormatEx](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-getdateformatex).

### `lpDate` [in, optional]

Pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the date information to format. The application sets this parameter to **NULL** if the function is to use the current local system date.

### `lpFormat` [in, optional]

Pointer to a format picture string that is used to form the date. Possible values for the format picture string are defined in [Day, Month, Year, and Era Format Pictures](https://learn.microsoft.com/windows/desktop/Intl/day--month--year--and-era-format-pictures).

The function uses the specified locale only for information not specified in the format picture string, for example, the day and month names for the locale. The application can set this parameter to **NULL** to format the string according to the date format for the specified locale.

### `lpDateStr` [out, optional]

Pointer to a buffer in which this function retrieves the formatted date string.

### `cchDate` [in]

Size, in characters, of the *lpDateStr* buffer. The application can set this parameter to 0 to return the buffer size required to hold the formatted date string. In this case, the buffer indicated by *lpDateStr* is not used.

## Return value

Returns the number of characters written to the *lpDateStr* buffer if successful. If the *cchDate* parameter is set to 0, the function returns the number of characters required to hold the formatted date string, including the terminating null character.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

**Note** This API is being updated to support the May 2019 Japanese era change. If your application supports the Japanese calendar, you should validate that it properly handles the new era. See [Prepare your application for the Japanese era change](https://learn.microsoft.com/windows/uwp/design/globalizing/japanese-era-change) for more information.

See Remarks for [GetDateFormatEx](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-getdateformatex).

When the ANSI version of this function is used with a Unicode-only locale identifier, the function can succeed because the operating system uses the system code page. However, characters that are undefined in the system code page appear in the string as a question mark ("?").

**Starting with Windows 8:** **GetDateFormat** is declared in Datetimeapi.h. Before Windows 8, it was declared in Winnls.h.

> [!NOTE]
> The datetimeapi.h header defines GetDateFormat as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Day, Month, Year, and Era Format Pictures](https://learn.microsoft.com/windows/desktop/Intl/day--month--year--and-era-format-pictures)

[EnumCalendarInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoa)

[EnumDateFormatsEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexa)

[GetCalendarInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcalendarinfoa)

[GetDateFormatEx](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-getdateformatex)

[GetLocaleInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoa)

[GetTimeFormat](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-gettimeformata)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)