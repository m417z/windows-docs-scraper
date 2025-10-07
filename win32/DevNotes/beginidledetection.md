# BeginIdleDetection function

\[This function is not supported and may be altered or unavailable in the future. Instead, use the **GetLastInputInfo** function.\]

Begins monitoring inactivity.

## Parameters

*pfnCallback*

The function that is called when the idle state changes. This callback is defined as follows:

``` syntax
typedef void (WINAPI* _IDLECALLBACK) (DWORD dwState);

#define STATE_USER_IDLE_BEGIN       1
#define STATE_USER_IDLE_END         2
```

*dwIdleMin*

The number of minutes of inactivity before the call is made to the callback function.

*dwReserved*

This parameter must be set to zero.

## Return value

Returns 0 if the function succeeds; otherwise, it returns an error code. For example, if *dwReserved* is anything other than 0, **ERROR\_INVALID\_DATA** is returned.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions. This function is not exported by name; specify ordinal 3 when calling **GetProcAddress**.

## Requirements

| Requirement | Value |
|----------------|---------------------------------------------------------------------------------------|
| DLL<br> | Msidle.dll |

## See also

[**GetLastInputInfo**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getlastinputinfo)

