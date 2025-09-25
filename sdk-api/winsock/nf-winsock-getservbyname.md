# getservbyname function

## Description

The
**getservbyname** function retrieves service information corresponding to a service name and protocol.

## Parameters

### `name` [in]

A pointer to a **null**-terminated service name.

### `proto` [in]

A pointer to a **null**-terminated protocol name. If this pointer is **NULL**,
the **getservbyname** function returns the first service entry where *name* matches the **s_name** member of the
[servent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-servent) structure or the **s_aliases** member of the
**servent** structure. Otherwise,
**getservbyname** matches both the *name* and the *proto*.

## Return value

If no error occurs,
**getservbyname** returns a pointer to the
[servent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-servent) structure. Otherwise, it returns a **null** pointer and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAHOST_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Authoritative Answer Service not found. |
| **[WSATRY_AGAIN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonauthoritative Service not found, or server failure. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Nonrecoverable errors, the services database is not accessible. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Valid name, no data record of requested type. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Socket 1.1 call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |

## Remarks

The
**getservbyname** function returns a pointer to the
[servent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-servent) structure containing the name(s) and service number that match the string in the *name* parameter. All strings are **null**-terminated.

The pointer that is returned points to the
**servent** structure allocated by the Windows Sockets library. The application must never attempt to modify this structure or to free any of its components. Furthermore, only one copy of this structure is allocated per thread, so the application should copy any information it needs before issuing any other Windows Sockets function calls.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSAAsyncGetServByName](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncgetservbyname)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[getservbyport](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getservbyport)