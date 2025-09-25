# _NET_PACKET_CHECKSUM structure

## Description

A **NET_PACKET_CHECKSUM** structure describes checksum information for a [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet).

## Members

### `Layer2`

A bit field that specifies a flag from either [**NET_PACKET_TX_CHECKSUM_ACTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksumtypes/ne-checksumtypes-_net_packet_tx_checksum_action) or [**NET_PACKET_RX_CHECKSUM_EVALUATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksumtypes/ne-checksumtypes-_net_packet_rx_checksum_evaluation). Targets the checksum field in the packet's layer 2 header.

### `Layer3`

A bit field that specifies a flag from either [**NET_PACKET_TX_CHECKSUM_ACTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksumtypes/ne-checksumtypes-_net_packet_tx_checksum_action) or [**NET_PACKET_RX_CHECKSUM_EVALUATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksumtypes/ne-checksumtypes-_net_packet_rx_checksum_evaluation). Targets the checksum field in the packet's layer 3 header.

### `Layer4`

A bit field that specifies a flag from either [**NET_PACKET_TX_CHECKSUM_ACTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksumtypes/ne-checksumtypes-_net_packet_tx_checksum_action) or [**NET_PACKET_RX_CHECKSUM_EVALUATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksumtypes/ne-checksumtypes-_net_packet_rx_checksum_evaluation). Targets the checksum field in the packet's layer 4 header.

### `Reserved`

Reserved for system use.

## Remarks

Client drivers can obtain this structure for a packet by calling [**NetExtensionGetPacketChecksum**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksum/nf-checksum-netextensiongetpacketchecksum).

For a transmit queue, the client specifies flag values from the [**NET_PACKET_TX_CHECKSUM_ACTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksumtypes/ne-checksumtypes-_net_packet_tx_checksum_action) enumeration. In a transmit queue, the client cross-references the **Checksum** information for a packet with the [**Layout**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet_layout) member of a [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet) in order to determine which hardware transmit checksum offloads need to be enabled.

For a receive queue, the client specifies flag values from the [**NET_PACKET_RX_CHECKSUM_EVALUATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksumtypes/ne-checksumtypes-_net_packet_rx_checksum_evaluation) enumeration. The client should also fill out the [**Layout**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet_layout) member of the [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet) structure.

## See also

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)