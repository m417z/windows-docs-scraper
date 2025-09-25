## Description

The **NetAdapterSetReceiveFilterCapabilities** function sets the receive filtering capabilities of a network adapter.

## Parameters

### `Adapter` [_In_]

A handle to a NETADAPTER object the client driver previously created with a call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `Capabilities` [_In_]

A pointer to a driver-allocated and initialized [**NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_receive_filter_capabilities) structure that describes the network adapter's receive filtering capabilities.

## Remarks

Client drivers typically call this function from within their [*EvtDevicePrepareHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback, but **must** call this function before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[**NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_receive_filter_capabilities)

[*EVT_NET_ADAPTER_SET_RECEIVE_FILTER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_set_receive_filter)

[**NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_receive_filter_capabilities_init)

[**NET_PACKET_FILTER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-net_packet_filter_flags)

[**NetReceiveFilterGetMulticastAddressList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netreceivefiltergetmulticastaddresslist)

[**NetReceiveFilterGetMulticastAddressCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netreceivefiltergetmulticastaddresscount)