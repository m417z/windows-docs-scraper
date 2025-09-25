# _WSK_TDI_MAP structure

## Description

The WSK_TDI_MAP structure specifies a mapping between a particular address family, socket type, and
protocol to the device name of a
[TDI](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565094(v=vs.85)) transport.

## Members

### `SocketType`

The socket type. This member can contain any of the SOCK_*XXX* values that are defined in the
Ws2def.h header file.

### `AddressFamily`

The address family. This member can contain any of the AF_*XXX* values that are defined in the
Ws2def.h header file.

### `Protocol`

The transport protocol.

### `TdiDeviceName`

A pointer to a null-terminated wide character string that contains the device name for the
[TDI](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565091(v=vs.85)) transport that supports the combination of
address family, socket type, and protocol specified by the
**AddressFamily**,
**SocketType**, and
**Protocol** members.

## Remarks

The
**Map** member of the
[WSK_TDI_MAP_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_tdi_map_info) structure points to an
array of WSK_TDI_MAP structures, each of which contains a mapping between a particular address family,
socket type, and protocol to the device name of a
[TDI](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565094(v=vs.85)) transport.

For more information about using TDI transports, see
[Using TDI Transports](https://learn.microsoft.com/windows-hardware/drivers/network/using-tdi-transports).

**Note** TDI will not be supported in Microsoft Windows versions after Windows Vista. Use
[Windows Filtering
Platform](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) or
[Winsock Kernel](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) instead.

## See also

[WSK_TDI_MAP_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_tdi_map_info)