## Description

The **NetReceiveFilterGetMulticastAddressList** function retrieves a network adapter's multicast address list.

## Parameters

### `ReceiveFilter` [_In_]

A handle to a NETRECEIVEFILTER object.

## Return value

Returns a pointer to the first **NET_ADAPTER_LINK_LAYER_ADDRESS** structure in the network adapter's multicast address list.

## Remarks

Client drivers typically call this function during their [*EvtNetAdapterSetReceiveFilter*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_set_receive_filter) callback to get an updated multicast address list that the NIC must enable.

## See also

[**NetReceiveFilterGetMulticastAddressCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netreceivefiltergetmulticastaddresscount)

[**NetReceiveFilterGetPacketFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netreceivefiltergetpacketfilter)

[*EVT_NET_ADAPTER_SET_RECEIVE_FILTER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_set_receive_filter)