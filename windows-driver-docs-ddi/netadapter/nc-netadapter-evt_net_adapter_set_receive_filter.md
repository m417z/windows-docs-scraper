## Description

The client driver implements the *EvtNetAdapterSetReceiveFilter* callback function to set changes in a network adapter's active receive filtering capabilities.

## Parameters

### `Adapter` [_In_]

A handle to a NETADAPTER object the client driver previously created with a call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `unnamedParam2` [_In_]

A handle to a NETRECEIVEFILTER object.

## Remarks

Register your implementation of this callback function by setting the appropriate parameter when calling [**NetAdapterSetReceiveFilterCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetreceivefiltercapabilities).

## See also

[**NetAdapterSetReceiveFilterCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetreceivefiltercapabilities)

[**NetReceiveFilterGetPacketFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netreceivefiltergetpacketfilter)

[**NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_receive_filter_capabilities_init)

[**NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_receive_filter_capabilities)

[**NET_PACKET_FILTER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-net_packet_filter_flags)

[**NetReceiveFilterGetMulticastAddressList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netreceivefiltergetmulticastaddresslist)

[**NetReceiveFilterGetMulticastAddressCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netreceivefiltergetmulticastaddresscount)