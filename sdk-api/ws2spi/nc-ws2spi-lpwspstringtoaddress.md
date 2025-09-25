# LPWSPSTRINGTOADDRESS callback function

## Description

The
**WSPStringToAddress** function converts a human-readable numeric string to a socket address structure ([sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)) suitable to passing to Windows Sockets routines that take such a structure. Any missing components of the address are defaulted to a reasonable value, if possible. For example, a missing port number defaults to zero.

## Parameters

### `AddressString` [in]

Pointer to the zero-terminated, human-readable string to convert.

### `AddressFamily` [in]

Address family to which the string belongs, or AF_UNSPEC if it is unknown.

### `lpProtocolInfo` [in]

(required) Provider's
[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure.

### `lpAddress` [out]

Buffer that is filled with a single
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure.

### `lpAddressLength` [in, out]

Length of the Address buffer, in bytes. Returns the size of the resultant [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure. If the supplied buffer is not large enough, the function fails with a specific error of [WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) and this parameter is updated with the required size in bytes.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs,
**WSPStringToAddress** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified address buffer is too small, pass in a larger buffer. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Unable to translate the string into a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2), or the provider was unable to support the indicated address family, or the specified *lpProtocolInfo* did not refer to a [WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure supported by the provider. |

## Remarks

A layered service provider supplies an implementation of this function, but it is also a client of this function if and when it calls
**WSPStringToAddress** of the next layer in the protocol chain. Some special considerations apply to this function's *lpProtocolInfo* parameter as it is propagated down through the layers of the protocol chain.

If the next layer in the protocol chain is another layer, then when the next layer's
**WSPStringToAddress** is called, this layer must pass to the next layer a *lpProtocolInfo* that references the same unmodified
[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure with the same unmodified chain information. However, if the next layer is the base protocol (that is, the last element in the chain), this layer performs a substitution when calling the base provider's
**WSPStringToAddress**. In this case, the base provider's
**WSAPROTOCOL_INFO** structure should be referenced by the *lpProtocolInfo* parameter.

One vital benefit of this policy is that base service providers do not have to be aware of protocol chains.

This same propagation policy applies when propagating a
[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure through a layered sequence of other functions such as
[LPWSPAddressToString](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaddresstostring),
[LPWSPDuplicateSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspduplicatesocket),
[WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup), or
[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket).

## See also

[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa)

[LPWSPDuplicateSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspduplicatesocket)

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)

[WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)