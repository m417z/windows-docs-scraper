## Description

The **NetExtensionGetPacketIeee8021Q** function retrieves the IEEE 802.1Q information for a [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet).

## Parameters

### `Extension`

A pointer to a [**NET_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/ns-extension-_net_extension) structure that describes the 802.1Q extension information for this packet queue.

### `Index`

The index in the packet ring for the target [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet).

## Return value

Returns a pointer to a [**NET_PACKET_IEEE8021Q**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ieee8021qtypes/ns-ieee8021qtypes-net_packet_ieee8021q) structure that holds the 802.1Q information for this packet.

## Remarks

## See also

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)

[**NET_PACKET_IEEE8021Q**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ieee8021qtypes/ns-ieee8021qtypes-net_packet_ieee8021q)