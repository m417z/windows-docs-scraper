# WSALookupServiceEnd function

## Description

The
**WSALookupServiceEnd** function is called to free the handle after previous calls to
[WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina) and
[WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicenexta).

If you call
**WSALookupServiceEnd** from another thread while an existing
[WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicenexta) is blocked, the end call will have the same effect as a cancel and will cause the
**WSALookupServiceNext** call to return immediately.

## Parameters

### `hLookup` [in]

Handle previously obtained by calling
[WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina).

## Return value

The return value is zero if the operation was successful. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_INVALID_HANDLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The handle is not valid. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The WS2_32.DLL has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) before calling any Windows Sockets functions. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |

## Remarks

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[Bluetooth and WSALookupServiceEnd](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-wsalookupserviceend)

[WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina)

[WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicenexta)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)