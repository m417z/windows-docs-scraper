# getipv4sourcefilter function

## Description

The
**getipv4sourcefilter** inline function retrieves the multicast filter state for an IPv4 socket.

## Parameters

### `Socket` [in]

A descriptor that identifies a multicast socket.

### `Interface` [in]

The local IPv4 address of the interface or the interface index on which the multicast group should be joined or dropped.

This value is in network byte order. If this member specifies an IPv4 address of 0.0.0.0, the default IPv4 multicast interface is used.

Any IP address in the 0.x.x.x block (first octet of 0) except IPv4 address 0.0.0.0 is treated as an interface index. An interface index is a 24-bit number, and the 0.0.0.0/8 IPv4 address block is not used (this range is reserved).

To use an interface index of 1 would be the same as an IP address of 0.0.0.1.

### `Group` [in]

The IPv4 address of the multicast group.

### `FilterMode` [out]

A pointer to a value to receive the multicast filter mode for multicast group address when the function returns.

### `SourceCount` [in, out]

On input, a pointer to a value that indicates the maximum number of source addresses that will fit in the buffer pointed to by the *SourceList* parameter.

On output, a pointer to a value that indicates the total number of source addresses associated with the multicast filter.

### `SourceList` [out]

A pointer to a buffer to receive the list of IP addresses associated with the multicast filter.

If *SourceCount* is zero on input, a **NULL** pointer
may be supplied.

## Return value

On success, **getipv4sourcefilter** returns NO_ERROR (0). Any nonzero return value indicates failure and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Insufficient buffer space is available. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |

## Remarks

The
**getipv4sourcefilter** inline function is used to retrieve the multicast filter state for an IPv4 socket.

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

[getsourcefilter](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getsourcefilter)

[in_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr)

[setipv4sourcefilter](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-setipv4sourcefilter)

[setsourcefilter](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-setsourcefilter)