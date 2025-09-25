# select function

## Description

The
**select** function determines the status of one or more sockets, waiting if necessary, to perform synchronous I/O.

## Parameters

### `nfds` [in]

Ignored. The *nfds* parameter is included only for compatibility with Berkeley sockets.

### `readfds` [in, out]

An optional pointer to a set of sockets to be checked for readability.

### `writefds` [in, out]

An optional pointer to a set of sockets to be checked for writability.

### `exceptfds` [in, out]

An optional pointer to a set of sockets to be checked for errors.

### `timeout` [in]

The maximum time for
**select** to wait, provided in the form of a
[TIMEVAL](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-timeval) structure. Set the *timeout* parameter to **null** for blocking operations.

## Return value

The
**select** function returns the total number of socket handles that are ready and contained in the
[fd_set](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-fd_set) structures, zero if the time limit expired, or SOCKET_ERROR if an error occurred. If the return value is SOCKET_ERROR,
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) can be used to retrieve a specific error code.

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The Windows Sockets implementation was unable to allocate needed resources for its internal operations, or the *readfds*, *writefds*, *exceptfds*, or *timeval* parameters are not part of the user address space. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *time-out* value is not valid, or all three descriptor parameters were **null**. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Socket 1.1 call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One of the descriptor sets contains an entry that is not a socket. |

## Remarks

The
**select** function is used to determine the status of one or more sockets. For each socket, the caller can request information on read, write, or error status. The set of sockets for which a given status is requested is indicated by an
[fd_set](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-fd_set) structure. The sockets contained within the
**fd_set** structures must be associated with a single service provider. For the purpose of this restriction, sockets are considered to be from the same service provider if the
[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structures describing their protocols have the same *providerId* value. Upon return, the structures are updated to reflect the subset of these sockets that meet the specified condition. The
**select** function returns the number of sockets meeting the conditions. A set of macros is provided for manipulating an
**fd_set** structure. These macros are compatible with those used in the Berkeley software, but the underlying representation is completely different.

The parameter *readfds* identifies the sockets that are to be checked for readability. If the socket is currently in the
[listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen) state, it will be marked as readable if an incoming connection request has been received such that an
[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) is guaranteed to complete without blocking. For other sockets, readability means that queued data is available for reading such that a call to
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv),
[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv),
[WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom), or
[recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom) is guaranteed not to block.

For connection-oriented sockets, readability can also indicate that a request to close the socket has been received from the peer. If the virtual circuit was closed gracefully, and all data was received, then a
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) will return immediately with zero bytes read. If the virtual circuit was reset, then a
**recv** will complete immediately with an error code such as
[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). The presence of OOB data will be checked if the socket option SO_OOBINLINE has been enabled (see
[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt)).

The parameter *writefds* identifies the sockets that are to be checked for writability. If a socket is processing a
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) call (nonblocking), a socket is writable if the connection establishment successfully completes. If the socket is not processing a
**connect** call, writability means a
[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send),
[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto), or
[WSASendto](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto) are guaranteed to succeed. However, they can block on a blocking socket if the *len* parameter exceeds the amount of outgoing system buffer space available. It is not specified how long these guarantees can be assumed to be valid, particularly in a multithreaded environment.

The parameter *exceptfds* identifies the sockets that are to be checked for the presence of OOB data or any exceptional error conditions.

**Note** Out-of-band data will only be reported in this way if the option SO_OOBINLINE is **FALSE**. If a socket is processing a
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) call (nonblocking), failure of the connect attempt is indicated in *exceptfds* (application must then call
[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) SO_ERROR to determine the error value to describe why the failure occurred). This document does not define which other errors will be included.

Any two of the parameters, *readfds*, *writefds*, or *exceptfds*, can be given as **null**. At least one must be non-**null**, and any non-**null** descriptor set must contain at least one handle to a socket.

In summary, a socket will be identified in a particular set when
**select** returns if:

*readfds*:

* If
  [listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen) has been called and a connection is pending,
  [accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) will succeed.
* Data is available for reading (includes OOB data if SO_OOBINLINE is enabled).
* Connection has been closed/reset/terminated.

*writefds*:

* If processing a
  [connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) call (nonblocking), connection has succeeded.
* Data can be sent.

*exceptfds*:

* If processing a
  **connect** call (nonblocking), connection attempt failed.
* OOB data is available for reading (only if SO_OOBINLINE is disabled).

Four macros are defined in the header file Winsock2.h for manipulating and checking the descriptor sets. The variable FD_SETSIZE determines the maximum number of descriptors in a set. (The default value of FD_SETSIZE is 64, which can be modified by defining FD_SETSIZE to another value before including Winsock2.h.) Internally, socket handles in an
[fd_set](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-fd_set) structure are not represented as bit flags as in Berkeley Unix. Their data representation is opaque. Use of these macros will maintain software portability between different socket environments. The macros to manipulate and check
**fd_set** contents are:

* *FD_ZERO(*set)* - Initializes set to the empty set. A set should always be cleared before using.
* *FD_CLR(s, *set)* - Removes socket s from set.
* *FD_ISSET(s, *set)* - Checks to see if s is a member of set and returns TRUE if so.
* *FD_SET(s, *set)* - Adds socket s to set.

The parameter *time-out* controls how long the
**select** can take to complete. If *time-out* is a **null** pointer,
**select** will block indefinitely until at least one descriptor meets the specified criteria. Otherwise, *time-out* points to a
[TIMEVAL](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-timeval) structure that specifies the maximum time that
**select** should wait before returning. When
**select** returns, the contents of the **TIMEVAL** structure are not altered. If **TIMEVAL** is initialized to {0, 0},
**select** will return immediately; this is used to poll the state of the selected sockets. If
**select** returns immediately, then the
**select** call is considered nonblocking and the standard assumptions for nonblocking calls apply. For example, the blocking hook will not be called, and Windows Sockets will not yield.

**Note** The
**select** function has no effect on the persistence of socket events registered with
[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect) or
[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect).

**Note** When issuing a blocking Winsock call such as **select** with the *timeout* parameter set to **NULL**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[TIMEVAL](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-timeval)

[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect)

[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)

[recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom)

[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)