# WinHttpCheckPlatform function

## Description

The **WinHttpCheckPlatform** function determines whether the current platform is supported by this version of Microsoft Windows HTTP Services (WinHTTP).

## Return value

The return value is **TRUE** if the platform is supported by Microsoft Windows HTTP Services (WinHTTP), or **FALSE** otherwise.

## Remarks

This function is useful if your application uses Microsoft Windows HTTP Services (WinHTTP), but also supports platforms that WinHTTP does not.

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function operates synchronously. The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

 WinHTTP version 5.1 is an operating-system component of Windows 2000 with Service Pack 3 (SP3) and later (except Datacenter Server), Windows XP with Service Pack 1 (SP1) and later, and Windows Server 2003. In Windows Server 2003, WinHTTP is a system side-by-side assembly.

For more information, see [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

#### Examples

The following example shows how to determine whether the current platform is supported.

```cpp
    if (WinHttpCheckPlatform( ))
        printf("This platform is supported by WinHTTP.\n");
    else
        printf("This platform is NOT supported by WinHTTP.\n");

```

## See also

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)