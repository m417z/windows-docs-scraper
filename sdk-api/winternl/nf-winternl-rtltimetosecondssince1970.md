# RtlTimeToSecondsSince1970 function

## Description

[**RtlTimeToSecondsSince1970** is available for use in Windows 2000 and Windows XP. It may be unavailable or modified in subsequent releases.]

Converts the specified 64-bit system time to the
number of seconds since the beginning of January 1, 1970.

## Parameters

### `Time` [in]

A pointer to a [LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1) structure that specifies the system time. The valid years for this value are 1970 to 2105 inclusive.

### `ElapsedSeconds` [out]

A pointer to a variable that receives the number of seconds.

## Return value

If the function succeeds, it returns **TRUE**. If it fails, it returns **FALSE**. Typically, this function will fail if the specified value of the *Time* parameter is not within the valid timeframe specified in the parameter description.

## Remarks

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Ntdll.dll.

There is no single equivalent public function. To perform this task using public functions, use the following steps:

1. Call [SystemTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-systemtimetofiletime) to copy the system time to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure. Call [GetSystemTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtime) to get the current system time to pass to **SystemTimeToFileTime**.
2. Copy the contents of the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure to a [ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer-r1) structure.
3. Initialize a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure with the date and time of the first second of January 1, 1970.
4. Call [SystemTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-systemtimetofiletime), passing the [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure initialized in Step 3 to the call.
5. Copy the contents of the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure returned by [SystemTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-systemtimetofiletime) in Step 4 to a second [ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer-r1).
   The copied value should be less than or equal to the value copied in Step 2.
6. Subtract the 64-bit value in the [ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer-r1) structure initialized in Step 5 (January 1, 1970) from the 64-bit value of the **ULARGE_INTEGER** structure initialized in Step 2 (the current system time). This produces a value in 100-nanosecond intervals since January 1, 1970. To convert this value to seconds, divide by 10,000,000.

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)

[SystemTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-systemtimetofiletime)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)

[ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer-r1)