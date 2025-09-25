## Description

The **LPWSPSelect** function determines the status of one or more sockets.

## Parameters

### `nfds` [in]

Ignored and included only for the sake of compatibility.

### `readfds` [in, out]

Optional pointer to a set of sockets to be checked for readability.

### `writefds` [in, out]

Optional pointer to a set of sockets to be checked for writability.

### `exceptfds` [in, out]

Optional pointer to a set of sockets to be checked for errors.

### `timeout` [in]

Maximum time for **LPWSPSelect** to wait, or **null** for a blocking operation, in the form of a [**timeval**](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-timeval) structure.

### `lpErrno` [out]

Pointer to the error code.

## Return value

The **LPWSPSelect** function returns the total number of descriptors that are ready and contained in the [fd_set](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-fd_set) structures, or SOCKET_ERROR if an error occurred. If the return value is SOCKET_ERROR, a specific error code is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| [WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEFAULT) | Windows Sockets service provider was unable to allocated needed resources for its internal operations, or the *readfds*, *writefds*, *exceptfds* or *timeval* parameters are not part of the user address space. |
| [WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN) | The network subsystem has failed. |
| [WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL) | The *timeout* value is not valid, or all three descriptor parameters were **NULL**. |
| [WSAEINTR](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINTR) | (Blocking) call was canceled through **[LPWSPCancelBlockingCall](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspcancelblockingcall)**. |
| [WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS) | Blocking Windows Sockets call is in progress, or the service provider is still processing a callback function. |
| [WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK) | One of the descriptor sets contains an entry that is not a socket. |

## Remarks

This function is used to determine the status of one or more sockets. For each socket, the caller can request information on read, write, or error status. The set of sockets for which a given status is requested is indicated by an [fd_set](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-fd_set) structure. All entries in an **fd_set** correspond to sockets created by the service provider (that is, the **[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa)** structures describing their protocols have the same *providerId* value). Upon return, the structures are updated to reflect the subset of these sockets that meet the specified condition, and **LPWSPSelect** returns the total number of sockets meeting the conditions. A set of macros is provided for manipulating an **fd_set**. These macros are compatible with those used in the Berkeley software, but the underlying representation is completely different.

The parameter *readfds* identifies those sockets that are to be checked for readability. If the socket is currently listening through **[LPWSPListen](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsplisten)**, it will be marked as readable if an incoming connection request has been received, so that a [LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept) is guaranteed to complete without blocking. For other sockets, readability means that queued data is available for reading so that a **[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)** or [LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom) is guaranteed not to block.

For connection-oriented sockets, readability can also indicate that a close request has been received from the peer. If the virtual circuit was closed gracefully, then a **[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)** will return immediately with zero bytes read. If the virtual circuit was reset, then a **LPWSPRecv** will complete immediately with an error code, such as WSAECONNRESET. The presence of OOB data will be checked if the socket option SO_OOBINLINE has been enabled (see **[LPWSPSetSockOpt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsetsockopt)**).

The parameter *writefds* identifies those sockets that are to be checked for writability:

- If a socket is connecting through **[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)**, writability means that the connection establishment successfully completed.
- If the socket is not in the process of listening through **[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)**, writability means that a **[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend)** or **[LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto)** are guaranteed to succeed.

However, they can block on a blocking socket if the **len** exceeds the amount of outgoing system buffer space available. It is not specified how long these guarantees can be assumed to be valid, particularly in a multithreaded environment.

The parameter *exceptfds* identifies those sockets that are to be checked for the presence of OOB data or any exceptional error conditions. Note that OOB data will only be reported in this way if the option SO_OOBINLINE is **FALSE**. If a socket is making a **[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)** (nonblocking) connection, failure of the connect attempt is indicated in *exceptfds*. This specification does not define which other errors will be included.

Any two of *readfds*, *writefds*, or *exceptfds* can be given as **null** if no descriptors are to be checked for the condition of interest. At least one must be non-**null**, and any non-**null** descriptor set must contain at least one socket descriptor.

Summary: A socket will be identified in a particular set when **LPWSPSelect** returns according to the following.

| Parameter | Description |
|---|---|
| *readfds*: | If **[LPWSPListen](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsplisten)** is called, a connection is pending, **[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)** will succeed.Data is available for reading (includes OOB data if SO_OOBINLINE is enabled).The connection has been closed/reset/terminated. |
| *writefds*: | If **[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)** (nonblocking), connection has succeeded.Data can be sent.|
| *exceptfds*: | If **[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)** (nonblocking), connection attempt failed.OOB data is available for reading (only if SO_OOBINLINE is disabled). |

Three macros and one upcall function are defined in the header file Ws2spi.h for manipulating and checking the descriptor sets. The variable FD_SETSIZE determines the maximum number of descriptors in a set. (The default value of FD_SETSIZE is 64, which can be modified by \#defining FD_SETSIZE to another value before \#including Ws2spi.h.) Internally, socket handles in a [fd_set](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-fd_set) are not represented as bit flags as in Berkeley UNIX. Their data representation is opaque. Use of these macros will maintain software portability between different socket environments.

The macros to manipulate and check [fd_set](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-fd_set) contents are:

**FD_CLR(*s*, \**set*)**

Removes the descriptor *s* from *set*.

**FD_SET(*s*, \**set*)**

Adds descriptor *s* to *set*.

**FD_ZERO(\**set*)**

Initializes the *set* to the **null** set.

The upcall function used to check the membership is:

**intWPUFDIsSet** (**SOCKET***s*, **FD_SET FAR** \**set*);

which will return nonzero if *s* is a member of the *set* or otherwise zero.

The parameter *timeout* controls how long the **LPWSPSelect** can take to complete. If *timeout* is a **null** pointer, **LPWSPSelect** will block indefinitely until at least one descriptor meets the specified criteria. Otherwise, *timeout* points to a [**timeval**](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-timeval) structure that specifies the maximum time that **LPWSPSelect** should wait before returning. When **LPWSPSelect** returns, the contents of the **timeval** structure are not altered. If **timeval** is initialized to {0, 0}, **LPWSPSelect** will return immediately; this is used to poll the state of the selected sockets. If this is the case, then the **LPWSPSelect** call is considered nonblocking and the standard assumptions for nonblocking calls apply. For example, the blocking hook will not be called, and the Windows Sockets provider will not yield.

> [!Note]
> The **LPWSPSelect** function has no effect on the persistence of socket events registered with **[LPWSPAsyncSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspasyncselect)** or **[LPWSPEventSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspeventselect)**.

## See also

**[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)**

**[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)**

**[LPWSPEventSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspeventselect)**

**[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)**

**[LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom)**

**[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend)**

**[LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto)**