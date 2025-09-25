## Description

The **NET_PACKET_IEEE8021Q** structure describes the IEEE 802.1Q information for a [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet).

## Members

### `PriorityCodePoint`

Specifies the quality-of-service prioritization scheme that is used to establish packet priority on an IEEE 802.3 Ethernet network. This 3-bit field refers to the IEEE 802.1p class of service that can be used to prioritize different classes of traffic.

### `VlanIdentifier`

Identifies the virtual LAN (VLAN) that a packet belongs to. Portions of the network which are VLAN-aware can include this 12-bit VLAN tag.

### `TxTagging`

Specifies the actions defined in the [**NET_PACKET_TX_IEEE8021Q_ACTION_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ieee8021qtypes/ne-ieee8021qtypes-net_packet_tx_ieee8021q_action_flags) enum. If only IEEE 802.1 priority tagging is enabled, **TxTagging** is set to 1. If only VLAN tagging is enabled, **TxTagging** is set to 2. If both are enabled, **TxTagging** is set to 3.

## Remarks

Client drivers can obtain this structure for a packet by calling [**NetExtensionGetPacketIeee8021Q**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ieee8021q/nf-ieee8021q-netextensiongetpacketieee8021q).

## See also

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)

[**NetExtensionGetPacketIeee8021Q**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ieee8021q/nf-ieee8021q-netextensiongetpacketieee8021q)