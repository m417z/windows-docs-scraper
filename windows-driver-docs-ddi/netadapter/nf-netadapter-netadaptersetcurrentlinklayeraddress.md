# NetAdapterSetCurrentLinkLayerAddress function

## Description

The **NetAdapterSetCurrentLinkLayerAddress** function sets the current link layer address for the network adapter.

## Parameters

### `Adapter` [_In_]

The network adapter object that the driver created in a prior call to [NetAdapterCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `LinkLayerAddress` [_In_]

A pointer to a [NET_ADAPTER_LINK_LAYER_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_link_layer_address) structure that the driver initialized in a prior call to [NET_ADAPTER_LINK_LAYER_ADDRESS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_link_layer_address_init).

## Remarks

## See also

[NET_ADAPTER_LINK_LAYER_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_link_layer_address)