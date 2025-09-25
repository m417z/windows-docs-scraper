# GetDurationFormatEx function

## Description

Formats a duration of time as a time string for a locale specified by name.

**Note** The application should call this function in preference to [GetDurationFormat](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getdurationformat) if designed to run only on Windows Vista and later.

**Note** This function can format data that changes between releases, for example, due to a custom locale. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

## Parameters

### `lpLocaleName` [in, optional]

Pointer to a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names), or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `dwFlags` [in]

Flags specifying function options. If *lpFormat* is not set to **NULL**, this parameter must be set to 0. If *lpFormat* is set to **NULL**, your application can specify [LOCALE_NOUSEROVERRIDE](https://learn.microsoft.com/windows/desktop/Intl/locale-nouseroverride) to format the string using the system default duration format for the specified locale.

**Caution** Use of **LOCALE_NOUSEROVERRIDE** is strongly discouraged as it disables user preferences.

### `lpDuration` [in, optional]

Pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the time duration information to format. The application sets this parameter to **NULL** if the function is to ignore it and use *ullDuration*.

### `ullDuration` [in]

64-bit unsigned integer that represents the number of 100-nanosecond intervals in the duration. If both *lpDuration* and *ullDuration* are set, the *lpDuration* parameter takes precedence. If *lpDuration* is set to **NULL** and *ullDuration* is set to 0, the duration is 0.

### `lpFormat` [in, optional]

Pointer to the format string with characters as shown below. The application can set this parameter to **NULL** if the function is to format the string according to the duration format for the specified locale. If *lpFormat* is not set to **NULL**, the function uses the locale only for information not specified in the format picture string.

| Value | Meaning |
| --- | --- |
| **d** | days |
| **h or H** | hours |
| **hh or HH** | hours; if less than ten, prepend a leading zero |
| **m** | minutes |
| **mm** | minutes; if less than ten, prepend a leading zero |
| **s** | seconds |
| **ss** | seconds; if less than ten, prepend a leading zero |
| **f** | fractions of a second<br><br>**Note** The character "f" can occur up to nine consecutive times (fffffffff), although support for frequency timers is limited to 100 nanoseconds. Thus, if nine characters are present, the last two digits are always 0. |

### `lpDurationStr` [out, optional]

Pointer to the buffer in which the function retrieves the duration string.

Alternatively, this parameter retrieves **NULL** if *cchDuration* is set to 0. In this case, the function returns the required size for the duration string buffer.

### `cchDuration` [in]

Size, in characters, of the buffer indicated by *lpDurationStr*.

Alternatively, the application can set this parameter to 0. In this case, the function retrieves **NULL** in *lpDurationStr* and returns the required size for the duration string buffer.

## Return value

Returns the number of characters retrieved in the buffer indicated by *lpDurationStr* if successful. If *lpDurationStr* is set to **NULL** and *cchDuration* is set to 0, the function returns the required size for the duration string buffer, including the terminating null character. For example, if 10 characters are written to the buffer, the function returns 11 to include the terminating null character.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* **ERROR_INSUFFICIENT_BUFFER**. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* **ERROR_INVALID_PARAMETER**. Any of the parameter values was invalid.

## Remarks

This function can be used with multimedia applications that display file time and sporting event applications that display finish times.

The function ignores the first three members of the [SYSTEMTIME](https://learn.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-systemtime) structure: **wYear**, **wMonth**, and **wDayOfWeek**.

This function can retrieve data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

The following are characteristics of duration format strings:

* Formatting characters are lowercase.

  **Note** An exception is made for (H) to be consistent with [GetTimeFormatEx](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-gettimeformatex).
* Two-digit format strings for hours, minutes, and seconds prepend a leading zero if the value is less than 10.
* The first output field is not subject to any bounds testing (hours<24, minutes<60, seconds<60, milliseconds<1000). Days are not subject to bounds testing.
* The function assumes that all format strings are in decreasing field size, for example, hours, minutes, seconds, milliseconds.
* The first field to be displayed is normalized, as defined by the format string. For example, if the application specifies 310 seconds and the format string is m:ss, the output is 5:10. However, if the format string specifies minutes and seconds but the application specifies hours, the minutes field is adjusted accordingly.
* If fractions are not the first field, the number of "f" characters in the format string indicates the number of decimals to show (limit of 9). If fractions are the first field, the number of "f" characters indicates the number of significant digits below one second.
* Round-off occurs by truncation, not by the rule of five rounds up and four rounds down.
* Single quotes are used to escape characters.

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

**Examples**

Following are examples of duration formats and corresponding outputs for specified time durations.

**SYSTEMTIME = 14 days, 2 hours, 45 minutes, 12 seconds, and 247 milliseconds**

| Format | Output |
| --- | --- |
| d:hh:mm:ss | 14:02:45:12 |
| hh:mm:ss:ff | 338:45:12:24 |
| hh:mm:ss:fff | 338:45:12:247 |
| h' h 'mm' m 'ss' s' | 338 h 45 m 12 s |

**SYSTEMTIME = 345 seconds**

| Format | Output |
| --- | --- |
| hh:mm:ss | 00:05:45 |
| h:mm:ss | 0:05:45 |
| mm:ss | 05:45 |
| m:ss | 5:45 |
| mm' m 'ss' s' | 05 m 45 s |
| ss | 345 |
| ss' seconds' | 345 seconds |

**uulDuration = 51234567 (5.1234567 seconds)**

| Format | Output |
| --- | --- |
| s.fff | 5.123 |
| s.ffffff | 5.123456 |
| s.fffffffff | 5.123456700 (add trailing zeros) |
| fff 'ms' | 5123 ms |
| ffffff 'microseconds' | 5123456 microseconds |
| fffffffff 'ns' | 5123456700 ns |

## See also

[GetDateFormatEx](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-getdateformatex)

[GetDurationFormat](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getdurationformat)

[GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex)

[GetTimeFormatEx](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-gettimeformatex)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)