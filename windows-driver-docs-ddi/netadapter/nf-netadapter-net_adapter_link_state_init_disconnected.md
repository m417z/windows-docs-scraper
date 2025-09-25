# NET_ADAPTER_LINK_STATE_INIT_DISCONNECTED function

## Description

Initializes a [NET_ADAPTER_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_link_state) structure for an adapter that is disconnected from the network.

## Parameters

### `LinkState` [_Out_]

A pointer to a driver-allocated [NET_ADAPTER_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_link_state) structure.

## Remarks

Call [NET_ADAPTER_LINK_STATE_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_link_state_init) or **NET_ADAPTER_LINK_STATE_INIT_DISCONNECTED** to initialize a [NET_ADAPTER_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_link_state) structure.

An initialized **NET_ADAPTER_LINK_STATE** structure is an input parameter value to [NetAdapterSetLinkState](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetlinkstate).

## See also

[NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_attributes)

[NET_ADAPTER_LINK_STATE_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_link_state_init)

[NET_ADAPTER_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_link_state)

[NetAdapterSetLinkState](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetlinkstate)