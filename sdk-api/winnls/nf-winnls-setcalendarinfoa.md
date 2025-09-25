# SetCalendarInfoA function

## Description

Sets an item of locale information for a calendar. For more information, see [Date and Calendar](https://learn.microsoft.com/windows/desktop/Intl/date-and-calendar).

## Parameters

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

The following custom locale identifiers are also supported.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

### `Calendar` [in]

[Calendar identifier](https://learn.microsoft.com/windows/desktop/Intl/calendar-identifiers) for the calendar for which to set information.

### `CalType` [in]

Type of calendar information to set. Only the following CALTYPE values are valid for this function. The CAL_USE_CP_ACP constant is only meaningful for the ANSI version of the function.

* CAL_USE_CP_ACP
* CAL_ITWODIGITYEARMAX

The application can specify only one calendar identifier per call to this function. An exception can be made if the application uses the binary OR operator to combine CAL_USE_CP_ACP with any valid CALTYPE value defined in [Calendar Type Information](https://learn.microsoft.com/windows/desktop/Intl/calendar-type-information).

### `lpCalData` [in]

Pointer to a null-terminated calendar information string. The information must be in the format of the specified calendar type.

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INTERNAL_ERROR. An unexpected error occurred in the function.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function only affects the user override portion of the calendar settings. It does not set the system defaults.

Calendar information is always passed as a null-terminated Unicode string in the Unicode version of this function, and as a null-terminated ANSI string in the ANSI version. No integers are allowed by this function. Any numeric values must be specified as either Unicode or ANSI text.

When the ANSI version of this function is used with a Unicode-only locale identifier, the function can succeed because the operating system uses the system code page. However, characters that are undefined in the system code page appear in the string as a question mark (?).

CAL_ITWODIGITYEARMAX can be used with any calendar, even if the calendar is not supported for the specified locale. To avoid complications, the application should call [EnumCalendarInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoa) to ensure that the calendar is supported for the locale of interest.

> [!NOTE]
> The winnls.h header defines SetCalendarInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumCalendarInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoa)

[GetCalendarInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcalendarinfoa)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)