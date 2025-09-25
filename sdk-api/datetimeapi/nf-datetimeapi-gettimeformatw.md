# GetTimeFormatW function

## Description

Formats time as a time string for a locale specified by identifier. The function formats either a specified time or the local system time.

**Note** For interoperability reasons, the application should prefer the [GetTimeFormatEx](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-gettimeformatex) function to **GetTimeFormat** because Microsoft is migrating toward the use of locale names instead of locale identifiers for new locales. Any application that will be run only on Windows Vista and later should use [GetTimeFormatEx](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-gettimeformatex).

## Parameters

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

### `dwFlags` [in]

Flags specifying time format options. For detailed definitions see the *dwFlags* parameter of [GetTimeFormatEx](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-gettimeformatex).

### `lpTime` [in, optional]

Pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the time information to format. The application can set this parameter to **NULL** if the function is to use the current local system time.

### `lpFormat` [in, optional]

Pointer to a format picture to use to format the time string. If the application sets this parameter to **NULL**, the function formats the string according to the time format of the specified locale. If the application does not set the parameter to **NULL**, the function uses the locale only for information not specified in the format picture string, for example, the locale-specific time markers. For information about the format picture string, see the Remarks section.

### `lpTimeStr` [out, optional]

Pointer to a buffer in which this function retrieves the formatted time string.

### `cchTime` [in]

Size, in TCHAR values, for the time string buffer indicated by *lpTimeStr*. Alternatively, the application can set this parameter to 0. In this case, the function returns the required size for the time string buffer, and does not use the *lpTimeStr* parameter.

## Return value

Returns the number of TCHAR values retrieved in the buffer indicated by *lpTimeStr*. If the *cchTime* parameter is set to 0, the function returns the size of the buffer required to hold the formatted time string, including a terminating null character.

This function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.
* ERROR_OUTOFMEMORY. Not enough storage was available to complete this operation.

## Remarks

See Remarks for [GetTimeFormatEx](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-gettimeformatex).

When the ANSI version of this function is used with a Unicode-only locale identifier, the function can succeed because the operating system uses the system code page. However, characters that are undefined in the system code page appear in the string as a question mark (?).

**Starting with Windows 8:** **GetTimeFormat** is declared in Datetimeapi.h. Before Windows 8, it was declared in Winnls.h.

> [!NOTE]
> The datetimeapi.h header defines GetTimeFormat as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetDateFormat](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-getdateformata)

[GetLocaleInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoa)

[GetTimeFormatEx](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-gettimeformatex)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)