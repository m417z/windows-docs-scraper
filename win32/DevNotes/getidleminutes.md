# GetIdleMinutes function

\[This function is not supported and may be altered or unavailable in the future. Instead, use the **GetLastInputInfo** function.\]

Gets the length of time, in minutes, since the user's last activity.

## Parameters

*dwReserved*

This parameter must be set to zero.

## Return value

Returns the number of minutes since the user's last activity.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions. This function is not exported by name; specify ordinal 8 when calling **GetProcAddress**.

## Requirements

| Requirement | Value |
|----------------|---------------------------------------------------------------------------------------|
| DLL<br> | Msidle.dll |

## See also

[**GetLastInputInfo**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getlastinputinfo)

