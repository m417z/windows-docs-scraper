# GetTimeFormatEx function

## Description

Formats time as a time string for a locale specified by name. The function formats either a specified time or the local system time.

**Note** The application should call this function in preference to [GetTimeFormat](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-gettimeformata) if designed to run only on Windows Vista and later.

**Note** This function can format data that changes between releases, for example, due to a custom locale. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

## Parameters

### `lpLocaleName` [in, optional]

Pointer to a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names), or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `dwFlags` [in]

Flags specifying time format options. The application can specify a combination of the following values and [LOCALE_USE_CP_ACP](https://learn.microsoft.com/windows/desktop/Intl/locale-use-cp-acp) or [LOCALE_NOUSEROVERRIDE](https://learn.microsoft.com/windows/desktop/Intl/locale-nouseroverride).

**Caution** Use of [LOCALE_NOUSEROVERRIDE](https://learn.microsoft.com/windows/desktop/Intl/locale-nouseroverride) is strongly discouraged as it disables user preferences.

| Value | Meaning |
| --- | --- |
| **TIME_NOMINUTESORSECONDS** | Do not use minutes or seconds. |
| **TIME_NOSECONDS** | Do not use seconds. |
| **TIME_NOTIMEMARKER** | Do not use a time marker. |
| **TIME_FORCE24HOURFORMAT** | Always use a 24-hour time format. |

### `lpTime` [in, optional]

Pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the time information to format. The application can set this parameter to **NULL** if the function is to use the current local system time.

### `lpFormat` [in, optional]

Pointer to a format picture to use to format the time string. If the application sets this parameter to **NULL**, the function formats the string according to the time format of the specified locale. If the application does not set the parameter to **NULL**, the function uses the locale only for information not specified in the format picture string, for example, the locale-specific time markers. For information about the format picture string, see the Remarks section.

### `lpTimeStr` [out, optional]

Pointer to a buffer in which this function retrieves the formatted time string.

### `cchTime` [in]

Size, in characters, for the time string buffer indicated by *lpTimeStr*. Alternatively, the application can set this parameter to 0. In this case, the function returns the required size for the time string buffer, and does not use the *lpTimeStr* parameter.

## Return value

Returns the number of characters retrieved in the buffer indicated by *lpTimeStr*. If the *cchTime* parameter is set to 0, the function returns the size of the buffer required to hold the formatted time string, including a terminating null character.

This function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.
* ERROR_OUTOFMEMORY. Not enough storage was available to complete this operation.

## Remarks

If a time marker exists and the TIME_NOTIMEMARKER flag is not set, the function localizes the time marker based on the specified locale identifier. Examples of time markers are "AM" and "PM" for English (United States).

The time values in the structure indicated by *lpTime* must be valid. The function checks each of the time values to determine that it is within the appropriate range of values. If any of the time values are outside the correct range, the function fails, and sets the last error to ERROR_INVALID_PARAMETER.

The function ignores the date members of the [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure. These include: **wYear**, **wMonth**, **wDayOfWeek**, and **wDay**.

If TIME_NOMINUTESORSECONDS or TIME_NOSECONDS is specified, the function removes the separators following the minutes and/or seconds members.

If TIME_NOTIMEMARKER is specified, the function removes the separators preceding and following the time marker.

If TIME_FORCE24HOURFORMAT is specified, the function displays any existing time marker, unless the TIME_NOTIMEMARKER flag is also set.

The function does not include milliseconds as part of the formatted time string.

The function returns no errors for a bad format string, but just forms the best possible time string. If more than two hour, minute, second, or time marker format pictures are passed in, the function defaults to two. For example, the only time marker pictures that are valid are "t" and "tt". If "ttt" is passed in, the function assumes "tt".

To obtain the time format without performing any actual formatting, the application should use the [GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex) function, specifying [LOCALE_STIMEFORMAT](https://learn.microsoft.com/windows/desktop/Intl/locale-stime-constants).

The application can use the following elements to construct a format picture string. If spaces are used to separate the elements in the format string, these spaces appear in the same location in the output string. The letters must be in uppercase or lowercase as shown, for example, "ss", not "SS". Characters in the format string that are enclosed in single quotation marks appear in the same location and unchanged in the output string.

| Picture | Meaning |
| --- | --- |
| h | Hours with no leading zero for single-digit hours; 12-hour clock |
| hh | Hours with leading zero for single-digit hours; 12-hour clock |
| H | Hours with no leading zero for single-digit hours; 24-hour clock |
| HH | Hours with leading zero for single-digit hours; 24-hour clock |
| m | Minutes with no leading zero for single-digit minutes |
| mm | Minutes with leading zero for single-digit minutes |
| s | Seconds with no leading zero for single-digit seconds |
| ss | Seconds with leading zero for single-digit seconds |
| t | One character time marker string, such as A or P |
| tt | Multi-character time marker string, such as AM or PM |

For example, to get the time string

``` syntax
"11:29:40 PM"
```

the application should use the picture string

``` syntax
"hh':'mm':'ss tt"
```

This function can retrieve data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

**Beginning in Windows 8:** **GetTimeFormatEx** is declared in Datetimeapi.h. Before Windows 8, it was declared in Winnls.h.

## See also

[GetDateFormatEx](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-getdateformatex)

[GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex)

[GetTimeFormat](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-gettimeformata)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)