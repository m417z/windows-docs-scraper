# TLSConnectToLsServer function

Opens a handle to the specified Remote Desktop license server.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mstlsapi.dll.

## Parameters

*pszLsServer* \[in\]

Pointer to a **null**-terminated string that specifies the NetBIOS name of the Remote Desktop license server. If the value of this parameter is **NULL**, the specified server is the local computer.

## Return value

If the function succeeds, the return value is a handle to the specified server.

If the function fails, the return value is **NULL**. To get extended error information, call the [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

When you have finished using the handle that is returned by the **TLSConnectToLsServer** function, release it by calling the [**TLSDisconnectFromServer**](https://learn.microsoft.com/windows/win32/termserv/tlsdisconnectfromserver) function.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| DLL<br> | Mstlsapi.dll |

## See also

[**TLS\_HANDLE**](https://learn.microsoft.com/windows/win32/termserv/tls-handle)

[**TLSDisconnectFromServer**](https://learn.microsoft.com/windows/win32/termserv/tlsdisconnectfromserver)

