# WSAGetQOSByName function

## Description

The
**WSAGetQOSByName** function initializes a
[QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos) structure based on a named template, or it supplies a buffer to retrieve an enumeration of the available template names.

## Parameters

### `s` [in]

A descriptor identifying a socket.

### `lpQOSName` [in, out]

A pointer to a specific quality of service template.

### `lpQOS` [out]

A pointer to the
[QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos) structure to be filled.

## Return value

If
**WSAGetQOSByName** succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**. To get extended error information, call
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpQOSName* or *lpQOS* parameter are not a valid part of the user address space, or the buffer length for *lpQOS* is too small. |

## Remarks

The
**WSAGetQOSByName** function is used by applications to initialize a
[QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos) structure to a set of known values appropriate for a particular service class or media type. These values are stored in a template that is referenced by a well-known name. The client may retrieve these values by setting the *buf* parameter of the
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structure indicated by *lpQOSName*, which points to a string of nonzero length specifying a template name. In this case, the usage of *lpQOSName* is IN only, and results are returned through *lpQOS*.

Alternatively, the client may use this function to retrieve an enumeration of available template names. The client may do this by setting the *buf* parameter of the
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) indicated by *lpQOSName* to a zero-length null-terminated string. In this case the buffer indicated by *buf* is overwritten with a sequence of as many available, null-terminated template names up to the number of bytes available in *buf* as indicated by the *len* parameter of the
**WSABUF** indicated by *lpQOSName*. The list of names itself is terminated by a zero-length name. When the
**WSAGetQOSByName** function is used to retrieve template names, the *lpQOS* parameter is ignored.

## See also

[QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos)

[WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept)

[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)