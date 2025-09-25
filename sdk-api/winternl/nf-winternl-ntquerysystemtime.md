# NtQuerySystemTime function

## Description

[**NtQuerySystemTime** may be altered or unavailable in future versions of Windows. Applications should use the [GetSystemTimeAsFileTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtimeasfiletime) function.]

Retrieves the current system time.

## Parameters

### `SystemTime` [out]

A pointer to a [LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1) structure that receives the system time. This is a 64-bit value representing the number of 100-nanosecond intervals since January 1, 1601 (UTC).

## Return value

If the function succeeds, it returns STATUS_SUCCESS. If it fails, it will return the appropriate status code, which will typically be STATUS_ACCESS_VIOLATION.

## Remarks

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Ntdll.dll.

## See also

[GetSystemTimeAsFileTime](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemtimeasfiletime)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)