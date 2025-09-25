## Description

The **LPWSPEnumNetworkEvents** function reports occurrences of network events for the indicated socket.

## Parameters

### `s` [in]

Descriptor identifying the socket.

### `hEventObject` [in]

Optional handle identifying an associated event object to be reset.

### `lpNetworkEvents` [out]

Pointer to a [WSANETWORKEVENTS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsanetworkevents) structure that is filled with a record of occurred network events and any associated error codes. The **WSANETWORKEVENTS** structure is defined in the following text.

### `lpErrno` [out]

Pointer to the error code.

## Return value

The return value is zero if the operation was successful. Otherwise, the value SOCKET_ERROR is returned, and a specific error number is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN)** | The network subsystem has failed. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL)** | Indicates that one of the specified parameters was invalid. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS)** | A blocking Windows Sockets call is in progress, or the service provider is still processing a callback function. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK)** | The descriptor is not a socket. |

## Remarks

This function is used to report which network events have occurred for the indicated socket since the last invocation of this function. It is intended for use in conjunction with [LPWSPEventSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspeventselect) and [LPWSPAsyncSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspasyncselect), which associate an event object with one or more network events. Recording of network events commences when **LPWSPEventSelect** or **LPWSPAsyncSelect** is called with a nonzero *lNetworkEvents* argument, and remains in effect until another corresponding call is made to **LPWSPEventSelect** or **LPWSPAsyncSelect** with the *lNetworkEvents* argument set to zero.

**LPWSPEnumNetworkEvents** only reports network activity and errors nominated through **[LPWSPEventSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspeventselect)**. See the descriptions of **[LPWSPSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspselect)** and **[LPWSPAsyncSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspasyncselect)** to find out how those functions report network activity and errors.

The socket's internal record of network events is copied to the structure referenced by *lpNetworkEvents*, whereafter the internal network events record is cleared. If *hEventObject* is non-null, the indicated event object is also reset. The Windows Sockets provider guarantees that the operations of copying the network event record, clearing it, and resetting any associated event object are atomic, such that the next occurrence of a nominated network event will cause the event object to become set. In the case of this function returning SOCKET_ERROR, the associated event object is not reset and the record of network events is not cleared.

The [WSANETWORKEVENTS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsanetworkevents) structure is defined on the [WSANETWORKEVENTS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsanetworkevents) reference page.

The **lNetworkEvents** member of the [WSANETWORKEVENTS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsanetworkevents) structure indicates which of the FD_XXX network events have occurred. The *iErrorCode* array is used to contain any associated error codes, with array index corresponding to the position of event bits in **lNetworkEvents**. The identifiers such as FD_READ_BIT and FD_WRITE_BIT can be used to index the *iErrorCode* array.

Note that only those elements of the *iErrorCode* array are set that correspond to the bits set in the **lNetworkEvents** member. Other members are not modified (this is important for backward compatibility with the Windows Socket 2 SPI clients that are not aware of new FD_ROUTING_INTERFACE_CHANGE and FD_ADDRESS_LIST_CHANGE events).

The following error codes can be returned along with the respective network event.

### Event: FD_CONNECT

| Error Code | Meaning |
| --- | --- |
| [WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEAFNOSUPPORT) | Addresses in the specified family cannot be used with this socket. |
| [WSAECONNREFUSED](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAECONNREFUSED) | An attempt to connect was forcefully rejected. |
| [WSAENETUNREACH](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETUNREACH) | The network cannot be reached from this host at this time. |
| [WSAENOBUFS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOBUFS) | No buffer space is available. The socket cannot be connected. |
| [WSAETIMEDOUT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAETIMEDOUT) | An attempt to connect timed out without establishing a connection. |

### Event: FD_CLOSE

| Error Code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN) | The network subsystem has failed. |
| [WSAECONNRESET](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAECONNRESET) | The connection was reset by the remote side. |
| [WSAECONNABORTED](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAECONNABORTED) | The connection was terminated due to a time-out or other failure. |

### Event: FD_READ, FD_WRITE, FD_OOB, FD_ACCEPT, FD_QOS, FD_GROUP_QOS, FD_ADDRESS_LIST_CHANGE

| Error Code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN) | The network subsystem has failed. |

### Event: FD_ROUTING_INTERFACE_CHANGE

| Error Code | Meaning |
| --- | --- |
| [WSAENETUNREACH](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETUNREACH) | The specified destination is no longer reachable. |
| [WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN) | The network subsystem has failed. |

## See also

[LPWSPEventSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspeventselect)