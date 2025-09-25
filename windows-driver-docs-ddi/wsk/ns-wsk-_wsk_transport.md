# _WSK_TRANSPORT structure

## Description

The WSK_TRANSPORT structure specifies an available transport that is supported by the WSK
subsystem.

## Members

### `Version`

The version of the transport. The format of the version number is transport-specific.

### `SocketType`

The type of socket that is supported by the transport. This member can be one of the following:

#### SOCK_STREAM

Supports reliable connection-oriented byte stream communication.

#### SOCK_DGRAM

Supports unreliable connectionless datagram communication.

#### SOCK_RAW

Supports raw access to the transport protocol.

For more information about the socket types that are supported for each supported address family, see
[WSK Address Families](https://learn.microsoft.com/windows-hardware/drivers/network/ws2def-h).

### `Protocol`

The protocol that is supported by the transport. For more information about the protocols that are
supported for each supported address family, see
[WSK Address Families](https://learn.microsoft.com/windows-hardware/drivers/network/ws2def-h).

### `AddressFamily`

The address family that is supported by the transport. For more information about supported
address families, see
[WSK Address Families](https://learn.microsoft.com/windows-hardware/drivers/network/ws2def-h).

### `ProviderId`

The identifier of the transport provider that implements the transport.

## Remarks

A WSK application passes a pointer to an array of WSK_TRANSPORT structures to the
[WskControlClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_client) function when specifying
the
[WSK_TRANSPORT_LIST_QUERY](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-transport-list-query) control
code. The WSK subsystem fills in the array with the list of available transports that can be used for
socket communication. When a WSK application calls the
[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) or
[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect) function to create a new
socket, it can pass the values contained in the
**AddressFamily**,
**SocketType**, and
**Protocol** members of a returned WSK_TRANSPORT structure for the
*AddressFamily*,
*SocketType*, and
*Protocol* parameters.

A single transport provider can support multiple combinations of values for the
**AddressFamily**,
**SocketType**, and
**Protocol** members.

## See also

[WskControlClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_client)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)

[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect)