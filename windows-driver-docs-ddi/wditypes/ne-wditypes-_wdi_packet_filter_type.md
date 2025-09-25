# _WDI_PACKET_FILTER_TYPE enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_PACKET_FILTER_TYPE enumeration defines the packet filter types.

## Constants

### `WDI_PACKET_FILTER_NONE`

None.

### `WDI_PACKET_FILTER_DIRECTED`

Directed packets. Directed packets contain a destination address equal to the station address of the NIC.

### `WDI_PACKET_FILTER_MULTICAST`

Multicast address packets sent to addresses in the multicast address list.

### `WDI_PACKET_FILTER_ALL_MULTICAST`

All multicast address packets, not just the ones enumerated in the multicast address list.

### `WDI_PACKET_FILTER_BROADCAST`

Broadcast packets.

### `WDI_PACKET_FILTER_PROMISCUOUS`

Specifies all packets regardless of whether VLAN filtering is enabled or not and whether the VLAN identifier matches or not.

### `WDI_PACKET_FILTER_802_11_RAW_DATA`

An 802.11 media access control (MAC) protocol data unit (MPDU) frame, which contains all of the data in the format received by the 802.11 station. When this filter is set, the driver must indicate every unmodified MPDU fragment before it indicates the MAC service data unit (MSDU) packet reassembled from the MPDU fragments.

If an MPDU fragment is encrypted, it must not decrypt the fragment before it is indicated. However, the miniport driver must decrypt each MPDU fragment before reassembling and indicating the MSDU packet.

If enabled, this filter type only affects other standard packet filters, such as WDI_PACKET_FILTER_DIRECTED or WDI_PACKET_FILTER_BROADCAST.

### `WDI_PACKET_FILTER_802_11_DIRECTED_MGMT`

Directed 802.11 management packets. Directed packets contain a destination address equal to the station address of the NIC.

### `WDI_PACKET_FILTER_802_11_BROADCAST_MGMT`

Broadcast 802.11 management packets received by the 802.11 station.

### `WDI_PACKET_FILTER_802_11_MULTICAST_MGMT`

Multicast 802.11 management packets sent to addresses in the multicast address list.

### `WDI_PACKET_FILTER_802_11_ALL_MULTICAST_MGMT`

All multicast 802.11 management packets received by the 802.11 station, regardless of whether the destination address in the 802.11 MAC header is in the multicast address list.

### `WDI_PACKET_FILTER_802_11_PROMISCUOUS_MGMT`

All 802.11 management packets received by the 802.11 station.

### `WDI_PACKET_FILTER_802_11_RAW_MGMT`

An 802.11 MPDU management frame, which contains all of the data in the format received by the 802.11 station. When this filter is set, the driver must indicate every unmodified MPDU fragment before it indicates the MAC management protocol data unit (MMPDU) packet reassembled from the MPDU fragments.

If enabled, this filter type only affects other 802.11 management packet filters, such as WDI_PACKET_FILTER_802_11_DIRECTED_MGMT or WDI_PACKET_FILTER_802_11_MULTICAST_MGMT.

### `WDI_PACKET_FILTER_802_11_DIRECTED_CTRL`

Directed 802.11 control packets. Directed packets contain a destination address equal to the station address of the NIC.

### `WDI_PACKET_FILTER_802_11_BROADCAST_CTRL`

Broadcast 802.11 control packets received by the 802.11 station.

### `WDI_PACKET_FILTER_802_11_PROMISCUOUS_CTRL`

All 802.11 control packets received by the 802.11 station.

### `WDI_PACKET_FILTER_ALL`

All packet types.