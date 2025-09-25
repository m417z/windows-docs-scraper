# NetAdapterSetLinkState function

## Description

Sets the link state of the of the network adapter.

## Parameters

### `Adapter` [_In_]

The network adapter object that the client created in a prior call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `State` [_In_]

A pointer to an allocated and initialized [**NET_ADAPTER_LINK_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_link_state) structure that describes the link state of the adapter.

## Remarks

The client driver calls **NetAdapterSetLinkState** when starting a net adapter, before it calls [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart). It can also call this function later when it needs to change the current link state.

## See also

[**NET_ADAPTER_LINK_STATE_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_link_state_init)

[**NET_ADAPTER_LINK_STATE_INIT_DISCONNECTED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_link_state_init_disconnected)