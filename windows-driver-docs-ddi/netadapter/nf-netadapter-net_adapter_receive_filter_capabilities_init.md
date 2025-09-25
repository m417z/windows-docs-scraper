## Description

The **NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES_INIT** function initializes a [**NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_receive_filter_capabilities) structure.

## Parameters

### `Capabilities` [_Out_]

A pointer to a driver-allocated [**NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_receive_filter_capabilities) structure.

### `EvtSetReceiveFilter` [_In_]

A pointer to the client driver's implementation of the [*EVT_NET_ADAPTER_SET_RECEIVE_FILTER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_set_receive_filter) callback function.

## Remarks

The client driver calls **NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES_INIT** to initialize a [**NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_receive_filter_capabilities) structure. The driver passes the initialized **NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES** structure as a parameter to the [**NetAdapterSetReceiveFilterCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetreceivefiltercapabilities) function to register it.

## See also

[*EVT_NET_ADAPTER_SET_RECEIVE_FILTER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_set_receive_filter)

[**NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_receive_filter_capabilities)

[**NetAdapterSetReceiveFilterCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetreceivefiltercapabilities)

[**NET_PACKET_FILTER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-net_packet_filter_flags)