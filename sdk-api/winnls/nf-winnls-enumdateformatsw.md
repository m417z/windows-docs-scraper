# EnumDateFormatsW function

## Description

Enumerates the long date, short date, or year/month formats that are available for a specified locale.

**Note** To receive a calendar identifier in addition to date format information, the application should use the [EnumDateFormatsEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexa) function. Another reason for preferring this function is that Microsoft is migrating toward the use of locale names instead of locale identifiers for new locales, for interoperability reasons.

**Note** Any application that will be run only on Windows Vista or later should use [EnumDateFormatsExEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexex) in preference to **EnumDateFormats**.

## Parameters

### `lpDateFmtEnumProc` [in]

Pointer to an application-defined callback function. For more information, see [EnumDateFormatsProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317813(v=vs.85)).

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale for which to retrieve date format information. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create an identifier or use one of the following predefined values.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

### `dwFlags` [in]

Flag specifying date formats. For detailed definitions, see the *dwFlags* parameter of [EnumDateFormatsExEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexex).

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

**Note** This API is being updated to support the May 2019 Japanese era change. If your application supports the Japanese calendar, you should validate that it properly handles the new era. See [Prepare your application for the Japanese era change](https://learn.microsoft.com/windows/uwp/design/globalizing/japanese-era-change) for more information.

For details of operation of this function, see Remarks in [EnumDateFormatsEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexa).

**Note** To enumerate the date formats for locales with alternate calendars, the application should use [EnumDateFormatsEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexa).

> [!NOTE]
> The winnls.h header defines EnumDateFormats as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumDateFormatsEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexa)

[EnumDateFormatsExEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexex)

[EnumDateFormatsProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317813(v=vs.85))

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)