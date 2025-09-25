## Description

The **NET_PACKET_FILTER_FLAGS** enumeration describes a network adapter's receive packet filters.

## Constants

### `NetPacketFilterFlagDirected:0x00000001`

The network adapter can filter directed packets. Directed packets contain a destination address equal to the MAC address of the NIC.

### `NetPacketFilterFlagMulticast:0x00000002`

The network adapter can filter multicast packets whose destination MAC address matches an address in the multicast address list.

### `NetPacketFilterFlagAllMulticast:0x00000004`

The network adapter can filter all multicast address packets, not just the ones enumerated in the multicast address list.

### `NetPacketFilterFlagBroadcast:0x00000008`

The network adapter can filter broadcast packets.

### `NetPacketFilterFlagPromiscuous:0x00000020`

The network adapter can filter all packets regardless of whether VLAN filtering is enabled or not and whether the VLAN identifier matches or not.

## Remarks

The driver uses the **NET_PACKET_FILTER_FLAGS** enumeration to specify the net adapter's receive packet filters in the [**NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_receive_filter_capabilities) structure.

An initialized [**NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_receive_filter_capabilities) structure is an input to [**NetAdapterSetReceiveFilterCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetreceivefiltercapabilities).

> [!IMPORTANT]
> If the driver doesn't report support for all of the packet filters expected by an upper layer, NetAdapterCx will fail the **OID_GEN_CURRENT_PACKET_FILTER** request, which causes the upper layer to fail to bind to your driver. For reliable binding, your driver must report support for all packet filter types.

## See also

[**NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_receive_filter_capabilities)

[*EVT_NET_ADAPTER_SET_RECEIVE_FILTER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_set_receive_filter)

[**NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_receive_filter_capabilities_init)

[**NetAdapterSetReceiveFilterCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetreceivefiltercapabilities)

[**NetReceiveFilterGetPacketFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netreceivefiltergetpacketfilter)