# getservbyport function

## Description

The
**getservbyport** function retrieves service information corresponding to a port and protocol.

## Parameters

### `port` [in]

Port for a service, in network byte order.

### `proto` [in]

Optional pointer to a protocol name. If this is null,
**getservbyport** returns the first service entry for which the *port* matches the **s_port** of the
[servent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-servent) structure. Otherwise,
**getservbyport** matches both the *port* and the *proto* parameters.

## Return value

If no error occurs,
**getservbyport** returns a pointer to the
[servent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-servent) structure. Otherwise, it returns a null pointer and a specific error number can be retrieved by calling
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
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *proto* parameter is not a valid part of the user address space. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Socket 1.1 call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |

## Remarks

The
**getservbyport** function returns a pointer to a
[servent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-servent) structure as it does in the
[getservbyname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getservbyname) function.

The
**servent** structure is allocated by Windows Sockets. The application must never attempt to modify this structure or to free any of its components. Furthermore, only one copy of this structure is allocated per thread, so the application should copy any information it needs before issuing any other Windows Sockets function calls.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSAAsyncGetServByPort](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncgetservbyport)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[getservbyname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getservbyname)