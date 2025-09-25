# GetDurationFormat function

## Description

Formats a duration of time as a time string for a locale specified by identifier.

**Note** For interoperability reasons, the application should prefer the [GetDurationFormatEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getdurationformatex) function to **GetDurationFormat** because Microsoft is migrating toward the use of locale names instead of locale identifiers for new locales. Any application that runs only on Windows Vista and later should use [GetDurationFormatEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getdurationformatex).

## Parameters

### `Locale` [in]

[Locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) that specifies the locale for which this function formats the duration. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

**Windows Vista and later:** The following custom locale identifiers are also supported.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

### `dwFlags` [in]

Flags specifying function options. If *lpFormat* is not set to **NULL**, this parameter must be set to 0. If *lpFormat* is set to **NULL**, your application can specify [LOCALE_NOUSEROVERRIDE](https://learn.microsoft.com/windows/desktop/Intl/locale-nouseroverride) to format the string using the system default duration format for the specified locale.

**Caution** Use of LOCALE_NOUSEROVERRIDE is strongly discouraged as it disables user preferences.

### `lpDuration` [in, optional]

Pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the time duration information to format. If this pointer is **NULL**, the function ignores this parameter and uses *ullDuration*.

### `ullDuration` [in]

64-bit unsigned integer that represents the number of 100-nanosecond intervals in the duration. If both *lpDuration* and *ullDuration* are present, *lpDuration* takes precedence. If *lpDuration* is set to **NULL** and *ullDuration* is set to 0, the duration is zero.

### `lpFormat` [in, optional]

Pointer to the format string. For details, see the *lpFormat* parameter of [GetDurationFormatEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getdurationformatex).

### `lpDurationStr` [out, optional]

Pointer to the buffer in which the function retrieves the duration string.

Alternatively, this parameter can contain **NULL** if *cchDuration* is set to 0. In this case, the function returns the required size for the duration string buffer.

### `cchDuration` [in]

Size, in characters, of the buffer indicated by *lpDurationStr*.

Alternatively, the application can set this parameter to 0. In this case, the function retrieves **NULL** in *lpDurationStr* and returns the required size for the duration string buffer.

## Return value

Returns the number of characters retrieved in the buffer indicated by *lpDurationStr* if successful. If *lpDurationStr* is set to **NULL** and *cchDuration* is set to 0, the function returns the required size for the duration string buffer, including the null terminating character. For example, if 10 characters are written to the buffer, the function returns 11 to include the terminating null character.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

See Remarks for [GetDurationFormatEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getdurationformatex).

## See also

[GetDateFormat](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-getdateformata)

[GetDurationFormatEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getdurationformatex)

[GetLocaleInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoa)

[GetTimeFormat](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-gettimeformata)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)