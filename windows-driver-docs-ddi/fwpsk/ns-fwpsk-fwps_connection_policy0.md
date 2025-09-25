## Description

The **FWPS_CONNECTION_POLICY0** structure defines the connection policy for outbound network connections.

## Members

### `localAddress`

The local address of the outbound connection. This is an IPV4 or IPV6 address and TCP/UDP port formatted as a [**SOCKADDR_STORAGE**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh) structure.

### `nextHopAddress`

The next hop address for the outbound connection. This is an IPV4 or IPV6 address and TCP/UDP port formatted as a [**SOCKADDR_STORAGE**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh) structure.

### `interfaceLuid`

The locally unique identifier (LUID) for the network interface used for the outbound connection.

## Remarks

## See also

[**SOCKADDR_STORAGE**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh)