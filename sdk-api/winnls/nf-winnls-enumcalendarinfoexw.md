# EnumCalendarInfoExW function

## Description

Enumerates calendar information for a locale specified by identifier.

**Note** Any application that runs only on Windows Vista and later should use [EnumCalendarInfoExEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoexex) in preference to this function.

## Parameters

### `lpCalInfoEnumProcEx` [in]

Pointer to an application-defined callback function. For more information, see [EnumCalendarInfoProcEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317807(v=vs.85)).

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale for which to retrieve calendar information. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create an identifier or use one of the following predefined values.

* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

**Windows Vista and later:** The following custom locale identifiers are also supported.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

### `Calendar` [in]

[Calendar identifier](https://learn.microsoft.com/windows/desktop/Intl/calendar-identifiers) that specifies the calendar for which information is requested. Note that this identifier can be ENUM_ALL_CALENDARS, to enumerate all calendars that are associated with the locale.

### `CalType` [in]

Type of calendar information. For more information, see [Calendar Type Information](https://learn.microsoft.com/windows/desktop/Intl/calendar-type-information). Only one calendar type can be specified per call to this function, except where noted.

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function enumerates calendar information for all applicable calendars for the specified locale, or for a single requested calendar, depending on the value of the *Calendar* parameter. The function enumerates the calendar information by calling the specified application-defined callback function. It passes the callback function a pointer to a buffer containing the requested calendar information. This process continues until **EnumCalendarInfoEx** finds the last applicable calendar or the callback function returns **FALSE**.

This function can enumerate data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

When the ANSI version of this function is used with a Unicode-only locale identifier, the function can succeed because the operating system uses the system code page. However, characters that are undefined in the system code page appear in the string as a question mark (?).

> [!NOTE]
> The winnls.h header defines EnumCalendarInfoEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Calendar Type Information](https://learn.microsoft.com/windows/desktop/Intl/calendar-type-information)

[EnumCalendarInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoa)

[EnumCalendarInfoExEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoexex)

[EnumCalendarInfoProcEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317807(v=vs.85))

[EnumDateFormats](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsa)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)