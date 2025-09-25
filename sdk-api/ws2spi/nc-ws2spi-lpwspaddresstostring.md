# LPWSPADDRESSTOSTRING callback function

## Description

The
**LPWSPAddressToString** function converts all components of a
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure into a human-readable numeric string representation of the address. This is used mainly for display purposes.

## Parameters

### `lpsaAddress` [in]

Pointer to a
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure to translate into a string.

### `dwAddressLength` [in]

Length of the address of [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2), in bytes.

### `lpProtocolInfo` [in]

(required)
[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure associated with the provider that will do the translation.

### `lpszAddressString` [out]

Buffer that receives the human-readable address string..

### `lpdwAddressStringLength` [in, out]

Length of the *AddressString* buffer, in bytes. Returns the length of the string actually copied into the buffer. If the supplied buffer is not large enough, the function fails with a specific error of
[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) and this parameter is updated with the required size, in bytes.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs,
**LPWSPAddressToString** returns zero. Otherwise, it returns SOCKET_ERROR, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified AddressString buffer is too small. Pass in a larger buffer. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified address is not a valid socket address, or its address family is not supported by the provider, or the specified *lpProtocolInfo* did not refer to a [WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure supported by the provider. |

## Remarks

A layered service provider supplies an implementation of this function, but it is also a client of this function if and when it calls
**LPWSPAddressToString** of the next layer in the protocol chain. Some special considerations apply to the *lpProtocolInfo* parameter as it is propagated down through the layers of the protocol chain.

If the next layer in the protocol chain is another layer, then, when the next layer's
**LPWSPAddressToString** is called, this layer must pass to the next layer a *lpProtocolInfo* parameter that references the same unmodified
[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure with the same unmodified chain information. However, if the next layer is the base protocol (that is, the last element in the chain), this layer performs a substitution when calling the base provider's
**LPWSPAddressToString**. In this case, the base provider's
**WSAPROTOCOL_INFO** structure should be referenced by the *lpProtocolInfo* parameter. One vital benefit of this policy is that base service providers do not have to be aware of protocol chains.

This same propagation policy applies when propagating a
[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure through a layered sequence of other functions such as
[LPWSPDuplicateSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspduplicatesocket),
[WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup),
[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket), or
[LPWSPStringToAddress](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspstringtoaddress).

## See also

[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa)

[WSPDucplicateSocket](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566282(v=vs.85))

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)

[WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)