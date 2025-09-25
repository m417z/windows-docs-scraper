# RtlLocalTimeToSystemTime function

## Description

[**RtlLocalTimeToSystemTime** is available for use in Windows 2000 and Windows XP. It may be unavailable or modified in subsequent releases. Applications should use the [LocalFileTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-localfiletimetofiletime) function.]

Converts the specified local time to system time.

## Parameters

### `LocalTime` [in]

A pointer to a [LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1) structure that specifies the local time.

### `SystemTime` [out]

A pointer to a [LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1) structure that receives the returned system time.

## Return value

If the function succeeds, it returns STATUS_SUCCESS. If it fails, it will return the appropriate status code.

## Remarks

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Ntdll.dll.

## See also

[LocalFileTimeToFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-localfiletimetofiletime)

[Time Functions](https://learn.microsoft.com/windows/desktop/SysInfo/time-functions)