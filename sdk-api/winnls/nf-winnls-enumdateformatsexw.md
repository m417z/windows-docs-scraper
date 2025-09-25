# EnumDateFormatsExW function

## Description

Enumerates the long date, short date, or year/month formats that are available for a specified locale.

**Note** Any application that runs only on Windows Vista and later should use [EnumDateFormatsExEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexex) in preference to this function.

## Parameters

### `lpDateFmtEnumProcEx` [in]

Pointer to an application-defined callback function. For more information, see [EnumDateFormatsProcEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317814(v=vs.85)).

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale for which to retrieve date format information. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create an identifier or use one of the following predefined values.

* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

**Windows Vista and later:** The following custom locale identifiers are also supported.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

### `dwFlags` [in]

Flag specifying date formats. For detailed definitions, see the *dwFlags* parameter of [EnumDateFormatsExEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexex).

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

**Note** This API is being updated to support the May 2019 Japanese era change. If your application supports the Japanese calendar, you should validate that it properly handles the new era. See [Prepare your application for the Japanese era change](https://learn.microsoft.com/windows/uwp/design/globalizing/japanese-era-change) for more information.

The function enumerates the date formats by passing date format string pointers, one at a time, to the specified application-defined callback function. This process continues until **EnumDateFormatsEx** finds the last date format or the callback function returns **FALSE**.

This function enumerates all date formats for the specified locale, including alternate calendars, if any. However, the calendar identifier is not enumerated along with the date format, making formats for locales with alternate calendars difficult to use.

This function can enumerate data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

When the ANSI version of this function is used with a Unicode-only locale identifier, the function can succeed because the operating system uses the system code page. However, characters that are undefined in the system code page appear in the string as a question mark (?).

The application should use **EnumDateFormatsEx** (instead of [EnumDateFormats](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsa)) to enumerate date formats for locales with alternate calendars.

> [!NOTE]
> The winnls.h header defines EnumDateFormatsEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumDateFormats](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsa)

[EnumDateFormatsExEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexex)

[EnumDateFormatsProcEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317814(v=vs.85))

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)