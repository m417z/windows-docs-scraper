# SOCKADDR_IN structure

## Description

The SOCKADDR_IN structure specifies a transport address and port for the
[AF_INET](https://learn.microsoft.com/windows-hardware/drivers/network/af-inet) address family.

## Members

### `sin_family`

The address family for the transport address. This member should always be set to AF_INET.

### `sin_port`

A transport protocol port number.

### `sin_addr`

An
[IN_ADDR](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff556972(v=vs.85)) structure that contains an IPv4 transport
address.

### `sin_zero`

Reserved for system use. A WSK application should set the contents of this array to zero.

## Remarks

All of the data in the SOCKADDR_IN structure, except for the address family, must be specified in
network-byte-order (big-endian).

## See also

[AF_INET](https://learn.microsoft.com/windows-hardware/drivers/network/af-inet)

[IN_ADDR](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff556972(v=vs.85))

[SOCKADDR](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-sockaddr)

[SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh)