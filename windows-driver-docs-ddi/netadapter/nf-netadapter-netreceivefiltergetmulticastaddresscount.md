## Description

The **NetReceiveFilterGetMulticastAddressCount** function retrieves the number of addresses in a network adapter's multicast address list.

## Parameters

### `ReceiveFilter` [_In_]

A handle to a NETRECEIVEFILTER object.

## Return value

Returns the number of addresses in the multicast address list.

## Remarks

Client drivers typically call this function during their [*EvtNetAdapterSetReceiveFilter*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_set_receive_filter) callback to get an updated count of multicast addresses.

## See also

[**NetReceiveFilterGetMulticastAddressList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netreceivefiltergetmulticastaddresslist)

[**NetReceiveFilterGetPacketFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netreceivefiltergetpacketfilter)

[*EVT_NET_ADAPTER_SET_RECEIVE_FILTER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_set_receive_filter)