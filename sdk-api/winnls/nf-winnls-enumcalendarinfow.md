# EnumCalendarInfoW function

## Description

Enumerates calendar information for a specified locale.

**Note** To receive a calendar identifier in addition to calendar information, the application should use the [EnumCalendarInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoexa) function. Another reason for preferring this function is that Microsoft is migrating toward the use of locale names instead of locale identifiers for new locales, for interoperability reasons.

**Note** Any application that will be run only on Windows Vista and later should use [EnumCalendarInfoExEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoexex) in preference to **EnumCalendarInfo**.

## Parameters

### `lpCalInfoEnumProc` [in]

Pointer to an application-defined callback function. For more information, see [EnumCalendarInfoProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317806(v=vs.85)).

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale for which to retrieve calendar information. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

### `Calendar` [in]

[Calendar identifier](https://learn.microsoft.com/windows/desktop/Intl/calendar-identifiers) that specifies the calendar for which information is requested. Note that this identifier can be ENUM_ALL_CALENDARS, to enumerate all calendars that are associated with the locale.

### `CalType` [in]

Type of calendar information. For more information, see [Calendar Type Information](https://learn.microsoft.com/windows/desktop/Intl/calendar-type-information). Only one calendar type can be specified per call to this function, except where noted.

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

See Remarks for [EnumCalendarInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoexa).

> [!NOTE]
> The winnls.h header defines EnumCalendarInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Calendar Type Information](https://learn.microsoft.com/windows/desktop/Intl/calendar-type-information)

[EnumCalendarInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoexa)

[EnumCalendarInfoExEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoexex)

[EnumCalendarInfoProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317806(v=vs.85))

[EnumDateFormats](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsa)

[MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)