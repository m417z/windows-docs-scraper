# TLSDisconnectFromServer function

Closes an open handle to a Remote Desktop license server.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mstlsapi.dll.

## Parameters

*hHandle* \[in\]

Handle to a Remote Desktop license server that is opened by a call to the [**TLSConnectToLsServer**](https://learn.microsoft.com/windows/win32/termserv/tlsconnecttolsserver) function.

## Return value

This method does not return a value.

## Remarks

Call the **TLSDisconnectFromServer** function as part of your program's clean-up routine to close all the server handles that are opened by calls to the [**TLSConnectToLsServer**](https://learn.microsoft.com/windows/win32/termserv/tlsconnecttolsserver) function.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| DLL<br> | Mstlsapi.dll |

## See also

[**TLS\_HANDLE**](https://learn.microsoft.com/windows/win32/termserv/tls-handle)

[**TLSConnectToLsServer**](https://learn.microsoft.com/windows/win32/termserv/tlsconnecttolsserver)

