# GetDateFormatWrapW function

\[**GetDateFormatWrapW** is available for use in Windows XP. It will not be available in subsequent versions. You should use [**GetDateFormatW**](https://learn.microsoft.com/windows/win32/api/datetimeapi/nf-datetimeapi-getdateformata) in its place.\]

Formats a date as a date string for a specified locale. The function formats either a specified date or the local system date.

> [!Note]
> **GetDateFormatWrapW** is a wrapper for the **GetDateFormatW** function. See the [**GetDateFormat**](https://learn.microsoft.com/windows/win32/api/datetimeapi/nf-datetimeapi-getdateformata) page for further usage notes.

## Parameters

*Locale* \[in\]

Type: **LCID**

The locale for which the date string is to be formatted. If *pwzFormat* is **NULL**, the function formats the string according to the date format for this locale. If *pwzFormat* is not **NULL**, the function uses the locale only for information not specified in the format picture string (for example, the locale's day and month names).

This parameter can be a locale identifier created by the [**MAKELCID**](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-makelcid) macro, or one of the following predefined values.

**LOCALE\_SYSTEM\_DEFAULT**

Default system locale.

**LOCALE\_USER\_DEFAULT**

Default user locale.

*dwFlags* \[in\]

Type: **DWORD**

Specifies various function options. If *pwzFormat* is not **NULL**, this parameter must be zero. If *pwzFormat* is **NULL**, you can specify a combination of the following values. If you do not specify either DATE\_YEARMONTH, DATE\_SHORTDATE, or DATE\_LONGDATE, and *pwzFormat* is **NULL**, then DATE\_SHORTDATE is used as the default.

**LOCALE\_NOUSEROVERRIDE**

If set, the function formats the string using the system default date format for the specified locale. If not set, the function formats the string using any user overrides to the locale's default date format.

**LOCALE\_USE\_CP\_ACP**

Uses the system ANSI code page for string translation instead of the locale's code page.

**DATE\_SHORTDATE**

Uses the short date format. This value cannot be used with DATE\_LONGDATE or DATE\_YEARMONTH.

**DATE\_LONGDATE**

Uses the long date format. This value cannot be used with DATE\_SHORTDATE or DATE\_YEARMONTH.

**DATE\_YEARMONTH**

Uses the year/month format. This value cannot be used with DATE\_SHORTDATE or DATE\_LONGDATE.

**DATE\_USE\_ALT\_CALENDAR**

Uses the alternate calendar, if one exists, to format the date string. If this flag is set, the function uses the default format for that alternate calendar, rather than using any user overrides. The user overrides will be used only in the event that there is no default format for the specified alternate calendar.

**DATE\_LTRREADING**

Adds marks for left-to-right reading layout. This value cannot be used with DATE\_RTLREADING.

**DATE\_RTLREADING**

Adds marks for right-to-left reading layout. This value cannot be used with DATE\_LTRREADING.

*lpDate* \[in\]

Type: **const [**SYSTEMTIME**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-systemtime)\***

A pointer to a [**SYSTEMTIME**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-systemtime) structure that contains the date information to be formatted. If this pointer is **NULL**, the function uses the current local system date.

*pwzFormat* \[in\]

Type: **LPCWSTR**

A pointer to a format picture to use to form the date string. If *pwzFormat* is **NULL**, the function uses the date format of the specified locale. See [**GetDateFormat**](https://learn.microsoft.com/windows/win32/api/datetimeapi/nf-datetimeapi-getdateformata) for more details.

*pwzDateStr* \[out\]

Type: **LPWSTR**

A pointer to a buffer that receives the formatted date string.

*cchDate* \[in\]

Type: **int**

Specifies the size, in characters, of the *pwzDateStr* buffer. If *cchDate* is zero, the function returns the number of characters required to hold the formatted date string, and the buffer pointed to by *pwzDateStr* is not used.

## Return value

Type: **int**

If the function succeeds, the return value is the number of characters written to the buffer pointed to by *pwzDateStr*. If the *cchDate* parameter is zero, the return value is the number of characters required to hold the formatted date string. The count includes the terminating null character.

If the function fails, the return value is zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** may return one of the following error codes.

**ERROR\_INSUFFICIENT\_BUFFER**

**ERROR\_INVALID\_FLAGS**

**ERROR\_INVALID\_PARAMETER**

## Remarks

**GetDateFormatWrapW** provides the ability to use Unicode strings in operating systems earlier than Windows XP. The preferred method is to use [**GetDateFormatW**](https://learn.microsoft.com/windows/win32/api/datetimeapi/nf-datetimeapi-getdateformata) in conjunction with the Microsoft Layer for Unicode (MSLU).

**GetDateFormatWrapW** must be called directly from Shlwapi.dll, using ordinal 311.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional, Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Shlwapi.dll (version 5.0 or later) |

## See also

[**GetDateFormat**](https://learn.microsoft.com/windows/win32/api/datetimeapi/nf-datetimeapi-getdateformata)

