# getprotobyname function

## Description

The
**getprotobyname** function retrieves the protocol information corresponding to a protocol name.

## Parameters

### `name` [in]

Pointer to a null-terminated protocol name.

## Return value

If no error occurs,
**getprotobyname** returns a pointer to the
[protoent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-protoent). Otherwise, it returns a null pointer and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAHOST_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Authoritative answer protocol not found. |
| **[WSATRY_AGAIN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonauthoritative protocol not found, or server failure. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Nonrecoverable errors, the protocols database is not accessible. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Valid name, no data record of requested type. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *name* parameter is not a valid part of the user address space. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Socket 1.1 call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |

## Remarks

The
**getprotobyname** function returns a pointer to the
[protoent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-protoent) structure containing the name(s) and protocol number that correspond to the protocol specified in the *name* parameter. All strings are null-terminated. The
**protoent** structure is allocated by the Windows Sockets library. An application must never attempt to modify this structure or to free any of its components. Furthermore, like
[hostent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-hostent), only one copy of this structure is allocated per thread, so the application should copy any information that it needs before issuing any other Windows Sockets function calls.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSAAsyncGetProtoByName](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncgetprotobyname)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[getprotobynumber](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getprotobynumber)