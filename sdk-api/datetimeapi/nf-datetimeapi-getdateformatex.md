# GetDateFormatEx function

## Description

Formats a date as a date string for a locale specified by name. The function formats either a specified date or the local system date.

**Note** The application should call this function in preference to [GetDateFormat](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-getdateformata) if designed to run only on Windows Vista and later.

**Note** This function can format data that changes between releases, for example, due to a custom locale. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

## Parameters

### `lpLocaleName` [in, optional]

Pointer to a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names), or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `dwFlags` [in]

Flags specifying various function options that can be set if *lpFormat* is set to **NULL**. The application can specify a combination of the following values and [LOCALE_USE_CP_ACP](https://learn.microsoft.com/windows/desktop/Intl/locale-use-cp-acp) or [LOCALE_NOUSEROVERRIDE](https://learn.microsoft.com/windows/desktop/Intl/locale-nouseroverride).

**Caution** Use of [LOCALE_NOUSEROVERRIDE](https://learn.microsoft.com/windows/desktop/Intl/locale-nouseroverride) is strongly discouraged as it disables user preferences.

| Value | Meaning |
| --- | --- |
| **DATE_AUTOLAYOUT** | **Windows 7 and later:** Detect the need for right-to-left and left-to-right reading layout using the locale and calendar information, and add marks accordingly. This value cannot be used with DATE_LTRREADING or DATE_RTLREADING. DATE_AUTOLAYOUT is preferred over DATE_LTRREADING and DATE_RTLREADING because it uses the locales and calendars to determine the correct addition of marks. |
| **DATE_LONGDATE** | Use the long date format. This value cannot be used with DATE_MONTHDAY, DATE_SHORTDATE, or DATE_YEARMONTH. |
| **DATE_LTRREADING** | Add marks for left-to-right reading layout. This value cannot be used with DATE_RTLREADING. |
| **DATE_RTLREADING** | Add marks for right-to-left reading layout. This value cannot be used with DATE_LTRREADING |
| **DATE_SHORTDATE** | Use the short date format. This is the default. This value cannot be used with DATE_MONTHDAY, DATE_LONGDATE, or DATE_YEARMONTH. |
| **DATE_USE_ALT_CALENDAR** | Use the alternate calendar, if one exists, to format the date string. If this flag is set, the function uses the default format for that alternate calendar, rather than using any user overrides. The user overrides will be used only in the event that there is no default format for the specified alternate calendar. |
| **DATE_YEARMONTH** | **Windows Vista:** Use the year/month format. This value cannot be used with DATE_MONTHDAY, DATE_SHORTDATE, or DATE_LONGDATE. |
| **DATE_MONTHDAY** | **Windows 10:** Use the combination of month and day formats appropriate for the specified locale. This value cannot be used with DATE_YEARMONTH, DATE_SHORTDATE, or DATE_LONGDATE. |

If the application does not specify DATE_YEARMONTH, DATE_MONTHDAY, DATE_SHORTDATE, or DATE_LONGDATE, and *lpFormat* is set to **NULL**, DATE_SHORTDATE is the default.

### `lpDate` [in, optional]

Pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the date information to format. The application can set this parameter to **NULL** if the function is to use the current local system date.

### `lpFormat` [in, optional]

Pointer to a format picture string that is used to form the date. Possible values for the format picture string are defined in [Day, Month, Year, and Era Format Pictures](https://learn.microsoft.com/windows/desktop/Intl/day--month--year--and-era-format-pictures).

For example, to get the date string "Wed, Aug 31 94", the application uses the picture string "ddd',' MMM dd yy".

The function uses the specified locale only for information not specified in the format picture string, for example, the day and month names for the locale. The application can set this parameter to **NULL** to format the string according to the date format for the specified locale.

### `lpDateStr` [out, optional]

Pointer to a buffer in which this function retrieves the formatted date string.

### `cchDate` [in]

Size, in characters, of the *lpDateStr* buffer. The application can set this parameter to 0 to return the buffer size required to hold the formatted date string. In this case, the buffer indicated by *lpDateStr* is not used.

### `lpCalendar` [in, optional]

Reserved; must set to **NULL**.

## Return value

Returns the number of characters written to the *lpDateStr* buffer if successful. If the *cchDate* parameter is set to 0, the function returns the number of characters required to hold the formatted date string, including the terminating null character.

This function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

**Note** This API is being updated to support the May 2019 Japanese era change. If your application supports the Japanese calendar, you should validate that it properly handles the new era. See [Prepare your application for the Japanese era change](https://learn.microsoft.com/windows/uwp/design/globalizing/japanese-era-change) for more information.

The earliest date supported by this function is January 1, 1601.

The day name, abbreviated day name, month name, and abbreviated month name are all localized based on the locale identifier.

The date values in the structure indicated by *lpDate* must be valid. The function checks each of the date values: year, month, day, and day of week. If the day of the week is incorrect, the function uses the correct value, and returns no error. If any of the other date values are outside the correct range, the function fails, and sets the last error to ERROR_INVALID_PARAMETER.

The function ignores the time members of the [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure indicated by *lpDate*. These include **wHour**, **wMinute**, **wSecond**, and **wMilliseconds**.

If the *lpFormat* parameter contains a bad format string, the function returns no errors, but just forms the best possible date string. For example, the only year pictures that are valid are L"yyyy" and L"yy", where the "L" indicates a Unicode (16-bit characters) string. If L"y" is passed in, the function assumes L"yy". If L"yyy" is passed in, the function assumes L"yyyy". If more than four date (L"dddd") or four month (L"MMMM") pictures are passed in, the function defaults to L"dddd" or L"MMMM".

The application should enclose any text that should remain in its exact form in the date string within single quotation marks in the date format picture. The single quotation mark can also be used as an escape character to allow the single quotation mark itself to be displayed in the date string. However, the escape sequence must be enclosed within two single quotation marks. For example, to display the date as "May '93", the format string is: L"MMMM ''''yy". The first and last single quotation marks are the enclosing quotation marks. The second and third single quotation marks are the escape sequence to allow the single quotation mark to be displayed before the century.

When the date picture contains both a numeric form of the day (either d or dd) and the full month name (MMMM), the genitive form of the month name is retrieved in the date string.

To obtain the default short and long date format without performing any actual formatting, the application should use [GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex) with the [LOCALE_SSHORTDATE](https://learn.microsoft.com/windows/desktop/Intl/locale-sshortdate) or [LOCALE_SLONGDATE](https://learn.microsoft.com/windows/desktop/Intl/locale-slongdate) constant. To get the date format for an alternate calendar, the application uses [GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex) with the [LOCALE_IOPTIONALCALENDAR](https://learn.microsoft.com/windows/desktop/Intl/locale-ioptionalcalendar) constant. To get the date format for a particular calendar, the application uses [GetCalendarInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcalendarinfoex), passing the appropriate [Calendar Identifier](https://learn.microsoft.com/windows/desktop/Intl/calendar-identifiers). It can call [EnumCalendarInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumcalendarinfoexa) or [EnumDateFormatsEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexa) to retrieve date formats for a particular calendar.

This function can retrieve data from [custom locales](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

The DATE_LONGDATE format includes two kinds of date patterns: patterns that include the day of the week and patterns that do not include the day of the week. For example, "Tuesday, October 18, 2016" or "October 18, 2016". If your application needs to ensure that dates use one of these kinds of patterns and not the other kind, your application should perform the following actions:

1. Call the [EnumDateFormatsExEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexex) function to get all of the date formats for the DATE_LONGDATE format.
2. Look for the first date format passed to the callback function that you specified for [EnumDateFormatsExEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexex) that matches your requested calendar identifier and has a date format string that matches the requirements of your application. For example, look for the first date format that includes "dddd" if your application requires that the date include the full name of the day of the week, or look for the first date format that includes neither "ddd" nor "dddd" if your application requires that the date includes nether the abbreviated name nor the full name of the day of the week.
3. Call the **GetDateFormatEx** function with the *lpFormat* parameter set to the date format string that you identified as the appropriate format in the callback function.

If the presence or absence of the day of the week in the long date format does not matter to your application, your application can call **GetDateFormatEx** directly without first enumerating all of the long date formats by calling [EnumDateFormatsExEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexex).

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

**Beginning in Windows 8:** **GetDateFormatEx** is declared in Datetimeapi.h. Before Windows 8, it was declared in Winnls.h.

## See also

[Day, Month, Year, and Era Format Pictures](https://learn.microsoft.com/windows/desktop/Intl/day--month--year--and-era-format-pictures)

[EnumDateFormatsExEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumdateformatsexex)

[GetCalendarInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getcalendarinfoex)

[GetDateFormat](https://learn.microsoft.com/windows/desktop/api/datetimeapi/nf-datetimeapi-getdateformata)

[NLS: Name-based APIs Sample](https://learn.microsoft.com/windows/desktop/Intl/nls--name-based-apis-sample)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)