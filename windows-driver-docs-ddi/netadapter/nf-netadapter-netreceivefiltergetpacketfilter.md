## Description

The **NetReceiveFilterGetPacketFilter** function retrieves the **NET_PACKET_FILTER_FLAGS**. These flags describe the packet filters that the network adapter supports.

## Parameters

### `ReceiveFilter` [_In_]

A handle to a NETRECEIVEFILTER object.

## Return value

Returns a [**NET_PACKET_FILTER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-net_packet_filter_flags) enumeration.

## Remarks

Client drivers typically call **NetReceiveFilterGetPacketFilter** during their [*EvtNetAdapterSetReceiveFilter*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_set_receive_filter) callback to get an updated set of [**NET_PACKET_FILTER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-net_packet_filter_flags) that the NIC must filter.

## See also

[*EVT_NET_ADAPTER_SET_RECEIVE_FILTER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_set_receive_filter)

[**NET_PACKET_FILTER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-net_packet_filter_flags)

[**NetReceiveFilterGetMulticastAddressCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netreceivefiltergetmulticastaddresscount)

[**NetReceiveFilterGetMulticastAddressList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netreceivefiltergetmulticastaddresslist)