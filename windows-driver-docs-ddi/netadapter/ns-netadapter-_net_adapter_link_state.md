# _NET_ADAPTER_LINK_STATE structure

## Description

Describes the link state of the adapter.

## Members

### `Size`

The size of the **NET_ADAPTER_LINK_STATE** structure, in bytes.

### `TxLinkSpeed`

The current transmit link speed of the adapter in bits per second.

### `RxLinkSpeed`

The current receive link speed of the adapter in bits per second.

### `MediaConnectState`

The media connect state for the network adapter.

### `MediaDuplexState`

The media duplex state for the network adapter.

### `SupportedPauseFunctions`

Support for the IEEE 802.3 pause frames specified by a [**NET_ADAPTER_PAUSE_FUNCTION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-_net_adapter_pause_function_type) value.

### `AutoNegotiationFlags`

The auto-negotiation settings for the network adapter. For more info, see [NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniportgeneralattributes/ns-miniportgeneralattributes-ndis_miniport_adapter_general_attributes).

## Remarks

Call [NET_ADAPTER_LINK_STATE_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_link_state_init) or [NET_ADAPTER_LINK_STATE_INIT_DISCONNECTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_link_state_init_disconnected) to initialize this structure.

An initialized **NET_ADAPTER_LINK_STATE** structure is an input parameter value to [NetAdapterSetLinkState](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetlinkstate).

## See also

[NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniportgeneralattributes/ns-miniportgeneralattributes-ndis_miniport_adapter_general_attributes)

[NET_ADAPTER_LINK_STATE_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_link_state_init)

[NET_ADAPTER_LINK_STATE_INIT_DISCONNECTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_link_state_init_disconnected)

[NetAdapterSetLinkState](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetlinkstate)