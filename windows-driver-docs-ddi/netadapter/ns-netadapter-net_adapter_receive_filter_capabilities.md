## Description

The **NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES** structure specifies a network adapter's receive filtering capabilities.

## Members

### `Size`

The size of this structure in bytes.

### `SupportedPacketFilters`

A [**NET_PACKET_FILTER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-net_packet_filter_flags) enumeration. These flags describe the receive packet filters that the network adapter supports.

### `MaximumMulticastAddresses`

The maximum number of addresses that the multicast address list can contain.

### `EvtSetReceiveFilter`

A pointer to the client driver's implementation of the [*EVT_NET_ADAPTER_SET_RECEIVE_FILTER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_set_receive_filter) callback function.

## Remarks

Call [**NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_receive_filter_capabilities_init) to initialize this structure. The driver passes the initialized **NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES** structure as a parameter to [**NetAdapterSetReceiveFilterCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetreceivefiltercapabilities) to register it.

## See also

[*EVT_NET_ADAPTER_SET_RECEIVE_FILTER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_set_receive_filter)

[**NetAdapterSetReceiveFilterCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetreceivefiltercapabilities)

[**NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_receive_filter_capabilities_init)

[**NET_PACKET_FILTER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-net_packet_filter_flags)