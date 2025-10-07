# GetTimeFormatWrapW function

\[**GetTimeFormatWrapW** is available for use in Windows XP. It may not be available in subsequent versions. You should use [**GetTimeFormatW**](https://learn.microsoft.com/windows/win32/api/datetimeapi/nf-datetimeapi-gettimeformata) in its place.\]

Formats time as a time string for a specified locale. The function formats either a specified time or the local system time.

> [!Note]
> **GetTimeFormatWrapW** is a wrapper for the **GetTimeFormatW** function. See the [**GetTimeFormat**](https://learn.microsoft.com/windows/win32/api/datetimeapi/nf-datetimeapi-gettimeformata) page for further usage notes.

## Parameters

*Locale* \[in\]

Type: **LCID**

Specifies the locale for which the time string is to be formatted. If *pwzFormat* is **NULL**, the function formats the string according to the time format for this locale. If *pwzFormat* is not **NULL**, the function uses the locale only for information not specified in the format picture string (for example, the locale's time markers).

This parameter can be a locale identifier created by the [**MAKELCID**](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-makelcid) macro, or one of the following predefined values.

**LOCALE\_SYSTEM\_DEFAULT**

Default system locale.

**LOCALE\_USER\_DEFAULT**

Default user locale.

*dwFlags* \[in\]

Type: **DWORD**

Specifies various function options. You can specify a combination of the following values.

**LOCALE\_NOUSEROVERRIDE**

If set, the function formats the string using the system default time format for the specified locale. If not set, the function formats the string using any user overrides to the locale's default time format. This flag can only be set if *pwzFormat* is **NULL**.

**LOCALE\_USE\_CP\_ACP**

Uses the system ANSI code page for string translation instead of the locale code page.

**TIME\_NOMINUTESORSECONDS**

Does not use minutes or seconds.

**TIME\_NOSECONDS**

Does not use seconds.

**TIME\_NOTIMEMARKER**

Does not use a time marker.

**TIME\_FORCE24HOURFORMAT**

Always uses a 24-hour time format.

*lpTime* \[in\]

Type: **const [**SYSTEMTIME**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-systemtime)\***

A pointer to a [**SYSTEMTIME**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-systemtime) structure that contains the time information to be formatted. If this pointer is **NULL**, the function uses the current local system time.

*pwzFormat* \[in\]

Type: **LPCWSTR**

A pointer to a format to use to form the time string. If *pwzFormat* is **NULL**, the function uses the time format of the specified locale. See [**GetTimeFormat**](https://learn.microsoft.com/windows/win32/api/datetimeapi/nf-datetimeapi-gettimeformata) for more details.

*pwzTimeStr* \[out\]

Type: **LPWSTR**

A pointer to a buffer that receives the formatted time string.

*cchTime* \[in\]

Type: **int**

The size, in characters, of the *pwzTimeStr* buffer. If *cchTime* is zero, the function returns the number of characters required to hold the formatted time string, and the buffer pointed to by *pwzTimeStr* is not used.

## Return value

Type: **int**

If the function succeeds, the return value is the number of characters written to the buffer pointed to by *pwzTimeStr*. If the *cchTime* parameter is zero, the return value is the number of characters required to hold the formatted time string. The count includes the terminating null character.

If the function fails, the return value is zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** may return one of the following error codes.

**ERROR\_INSUFFICIENT\_BUFFER**

**ERROR\_INVALID\_FLAGS**

**ERROR\_INVALID\_PARAMETER**

## Remarks

**GetTimeFormatWrapW** provides the ability to use Unicode strings in operating systems earlier than Windows XP. The preferred method is to use [**GetTimeFormatW**](https://learn.microsoft.com/windows/win32/api/datetimeapi/nf-datetimeapi-gettimeformata) in conjunction with the Microsoft Layer for Unicode (MSLU).

**GetTimeFormatWrapW** must be called directly from Shlwapi.dll, using ordinal 310.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional, Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Shlwapi.dll (version 5.0 or later) |

## See also

[**GetTimeFormat**](https://learn.microsoft.com/windows/win32/api/datetimeapi/nf-datetimeapi-gettimeformata)

