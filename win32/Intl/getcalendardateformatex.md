# GetCalendarDateFormatEx function

Deprecated. Retrieves a properly formatted date string for the specified locale using the specified date and calendar. The user can specify the short date format, the long date format, the year month format, or a custom format pattern.

> [!Note]
> This function can retrieve data that changes between releases, for example, due to a custom locale. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/win32/intl/using-persistent-locale-data).

## Parameters

*lpszLocale* \[in\]

Pointer to a locale name, or one of the following predefined values.

- [LOCALE\_NAME\_INVARIANT](https://learn.microsoft.com/windows/win32/intl/locale-name-constants)
- [LOCALE\_NAME\_SYSTEM\_DEFAULT](https://learn.microsoft.com/windows/win32/intl/locale-name-constants)
- [LOCALE\_NAME\_USER\_DEFAULT](https://learn.microsoft.com/windows/win32/intl/locale-name-constants)

*dwFlags* \[in\]

Flags specifying date format options. If *lpFormat* is not set to **NULL**, this parameter must be set to 0. If *lpFormat* is set to **NULL**, the application can specify a combination of the following values and [LOCALE\_NOUSEROVERRIDE](https://learn.microsoft.com/windows/win32/intl/locale-nouseroverride).

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------|
| **DATE\_SHORTDATE** | Use the short date format. This is the default. This value cannot be used with DATE\_LONGDATE or DATE\_YEARMONTH. <br> |
| **DATE\_LONGDATE** | Use the long date format. This value cannot be used with DATE\_SHORTDATE or DATE\_YEARMONTH. <br> |
| **DATE\_YEARMONTH** | Use the year/month format. This value cannot be used with DATE\_SHORTDATE or DATE\_LONGDATE.<br> |
| **DATE\_LTRREADING** | Add marks for left-to-right reading layout. This value cannot be used with DATE\_RTLREADING.<br> |
| **DATE\_RTLREADING** | Add marks for right-to-left reading layout. This value cannot be used with DATE\_LTRREADING<br> |

*lpCalDateTime* \[in\]

Pointer to a [**CALDATETIME**](https://learn.microsoft.com/windows/win32/intl/caldatetime) structure that contains the date and calendar information to format.

*lpFormat* \[in\]

Pointer to a format picture string that is used to form the date string. Possible values for the format picture string are defined in [Day, Month, Year, and Era Format Pictures](https://learn.microsoft.com/windows/win32/intl/day--month--year--and-era-format-pictures).

The format picture string must be null-terminated. The function uses the locale only for information not specified in the format picture string, for example, the day and month names for the locale. The application sets this parameter to **NULL** if the function is to use the date format of the specified locale.

*lpDateStr* \[out\]

Pointer to a buffer in which this function receives the formatted date string.

*cchDate* \[in\]

Size, in characters, of the *lpDateStr* buffer. Alternatively, the application can set this parameter to 0. In this case, the function returns the number of characters required to hold the formatted date string, and the *lpDateStr* parameter is not used.

## Return value

Returns the number of characters written to the *lpDateStr* buffer if successful. If the *cchDate* parameter is set to 0, the function returns the number of characters required to hold the formatted date string, including the terminating null character.

This function returns 0 if it does not succeed. To get extended error information, the application can call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

- ERROR\_DATE\_OUT\_OF\_RANGE. The specified date was out of range.
- ERROR\_INSUFFICIENT\_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
- ERROR\_INVALID\_FLAGS. The values supplied for flags were not valid.
- ERROR\_INVALID\_PARAMETER. Any of the parameter values was invalid.

## Remarks

The earliest date supported by this function is January 1, 1601.

This function does not have an associated header file or library file. The application can call [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name (Kernel32.dll) to obtain a module handle. It can then call [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) with that module handle and the name of this function to get the function address.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Kernel32.dll |

## See also

[National Language Support](https://learn.microsoft.com/windows/win32/intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/win32/intl/national-language-support-functions)

[Day, Month, Year, and Era Format Pictures](https://learn.microsoft.com/windows/win32/intl/day--month--year--and-era-format-pictures)

[NLS: Name-based APIs Sample](https://learn.microsoft.com/windows/win32/intl/nls--name-based-apis-sample)

[**EnumDateFormatsExEx**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-enumdateformatsexex)

[**GetDateFormat**](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-getdateformata)

[**GetDateFormatEx**](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-getdateformatex)

[**CALDATETIME**](https://learn.microsoft.com/windows/win32/intl/caldatetime)

