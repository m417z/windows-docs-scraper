# getsourcefilter function

## Description

The
**getsourcefilter** inline function retrieves the multicast filter state for an IPv4 or IPv6 socket.

## Parameters

### `Socket` [in]

A descriptor that identifies a multicast socket.

### `Interface` [in]

The interface index of the multicast interface.

### `Group` [in]

A pointer to the socket address of the multicast group.

### `GroupLength` [in]

The length, in bytes, of the socket address pointed to by the *Group* parameter.

### `FilterMode` [out]

A pointer to a value to receive the multicast filter mode for the multicast group address when the function returns.

### `SourceCount` [in, out]

On input, a pointer to a value that indicates the maximum number of source addresses that will fit in the buffer pointed to by the *SourceList* parameter.

On output, a pointer to a value that indicates the total number of source addresses associated with the multicast filter.

### `SourceList` [out]

A pointer to a buffer to receive the list of IP addresses associated with the multicast filter.

If *SourceCount* is zero on input, a **NULL** pointer
may be supplied.

## Return value

On success, **getsourcefilter** returns NO_ERROR (0). Any nonzero return value indicates failure and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient buffer space is available. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |

## Remarks

The
**getsourcefilter** inline function is used to retrieve the multicast filter state for an IPv4 or IPv6 socket.

If the app does not know the size of the source list
beforehand, it can make a guess (zero, for example). If upon
completion, the *SourceCount* parameter holds a larger value, the operation can be
repeated with a large enough buffer.

On return, the *SourceCount* parameter is always updated to be the total number
of sources in the filter, while the buffer pointed to by the *SourceList* parameter will hold as many source
addresses as fit, up to the minimum of the array size passed in as
the original *SourceCount* value and the total number of sources in the
filter.

This function is part of socket interface extensions for multicast source filters defined in RFC 3678. An app can use these functions to retrieve and set the multicast source address filters associated with a socket.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[MULTICAST_MODE_TYPE](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ne-ws2ipdef-multicast_mode_type)

[SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85))

[getipv4sourcefilter](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getipv4sourcefilter)

[setipv4sourcefilter](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-setipv4sourcefilter)

[setsourcefilter](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-setsourcefilter)