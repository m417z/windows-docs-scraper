# NET_ADAPTER_LINK_STATE_INIT function

## Description

Initializes a [NET_ADAPTER_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_link_state) structure.

## Parameters

### `LinkState` [_Out_]

A pointer to a driver-allocated [NET_ADAPTER_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_link_state) structure.

### `LinkSpeed` [_In_]

The link speed of the adapter in bits per second.

### `MediaConnectState` [_In_]

The media connect state for the network adapter.

### `MediaDuplexState` [_In_]

The media duplex state for the network adapter.

### `SupportedPauseFunctions` [_In_]

Support for the IEEE 802.3 pause frames specified by a [**NET_ADAPTER_PAUSE_FUNCTION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-_net_adapter_pause_function_type) value.

### `AutoNegotiationFlags` [_In_]

The auto-negotiation settings for the network adapter. For more info, see [NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniportgeneralattributes/ns-miniportgeneralattributes-ndis_miniport_adapter_general_attributes).

## Remarks

Call **NET_ADAPTER_LINK_STATE_INIT** or [NET_ADAPTER_LINK_STATE_INIT_DISCONNECTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_link_state_init_disconnected) to initialize a [NET_ADAPTER_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_link_state) structure.

An initialized **NET_ADAPTER_LINK_STATE** structure is an input parameter value to [NetAdapterSetLinkState](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetlinkstate).

## See also

[NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniportgeneralattributes/ns-miniportgeneralattributes-ndis_miniport_adapter_general_attributes)

[NetAdapterSetLinkState](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetlinkstate)

[NET_ADAPTER_LINK_STATE_INIT_DISCONNECTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_link_state_init_disconnected)

[NET_ADAPTER_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_link_state)