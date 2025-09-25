# _WSK_TDI_MAP_INFO structure

## Description

The WSK_TDI_MAP_INFO structure specifies a list that contains mappings of a combination of an address
family, a socket type, and a protocol to the device name of a
[TDI](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565094(v=vs.85)) transport.

## Members

### `ElementCount`

The number of structures contained in the array pointed to by the
**Map** member.

### `Map`

A pointer to an array of
[WSK_TDI_MAP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_tdi_map) structures. Each WSK_TDI_MAP
structure in the array contains a mapping of a particular address family, socket type, and protocol to
the device name of a
[TDI](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565094(v=vs.85)) transport.

## Remarks

A WSK application passes a pointer to a WSK_TDI_MAP_INFO structure to the
[WskControlClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_client) function when specifying
[WSK_TDI_DEVICENAME_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-tdi-devicename-mapping) for
the control code.

If a WSK application uses the WSK_TDI_DEVICENAME_MAPPING client control operation to map combinations
of address family, socket type, and protocol to device names of
[TDI](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565094(v=vs.85)) transports, it must do so before it creates any
sockets.

For more information about using TDI transports, see
[Using TDI Transports](https://learn.microsoft.com/windows-hardware/drivers/network/using-tdi-transports).

**Note** TDI will not be supported in Microsoft Windows versions after Windows Vista. Use
[Windows Filtering
Platform](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) or
[Winsock Kernel](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) instead.

## See also

[WSK_TDI_MAP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_tdi_map)

[WskControlClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_client)