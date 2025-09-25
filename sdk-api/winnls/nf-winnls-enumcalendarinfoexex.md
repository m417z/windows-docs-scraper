# EnumCalendarInfoExEx function

## Description

Enumerates calendar information for a locale specified by name.

**Note** The application should call this function in preference to [EnumCalendarInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoa) or [EnumCalendarInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoexa) if designed to run only on Windows Vista and later.

**Note** This function can enumerate data that changes between releases, for example, due to a custom locale. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

## Parameters

### `pCalInfoEnumProcExEx` [in]

Pointer to an application-defined callback function. For more information, see [EnumCalendarInfoProcExEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317808(v=vs.85)).

### `lpLocaleName` [in, optional]

Pointer to a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names), or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `Calendar` [in]

[Calendar identifier](https://learn.microsoft.com/windows/desktop/Intl/calendar-identifiers) that specifies the calendar for which information is requested. Note that this identifier can be ENUM_ALL_CALENDARS, to enumerate all calendars that are associated with the locale.

### `lpReserved` [in, optional]

Reserved; must be **NULL**.

### `CalType` [in]

Type of calendar information. For more information, see [Calendar Type Information](https://learn.microsoft.com/windows/desktop/Intl/calendar-type-information). Only one calendar type can be specified per call to this function, except where noted.

### `lParam` [in]

Application-provided parameter to pass to the callback function. This value is especially useful for multi-threaded applications.

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function enumerates calendar information for all applicable calendars for the specified locale, or for a single requested calendar, depending on the value of the *Calendar* parameter. The function enumerates the calendar information by calling the specified application-defined callback function. It passes the callback function a pointer to a buffer containing the requested calendar information, a calendar identifier, and an application-defined parameter that is useful for multi-threaded applications. This process continues until **EnumCalendarInfoExEx** finds the last applicable calendar or the callback function returns **FALSE**.

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

## See also

[Calendar Type Information](https://learn.microsoft.com/windows/desktop/Intl/calendar-type-information)

[EnumCalendarInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoa)

[EnumCalendarInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoexa)

[EnumCalendarInfoProcExEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317808(v=vs.85))

[EnumDateFormatsExEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexex)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)