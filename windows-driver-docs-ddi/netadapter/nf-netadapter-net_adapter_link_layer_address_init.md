# NET_ADAPTER_LINK_LAYER_ADDRESS_INIT function

## Description

The **NET_ADAPTER_LINK_LAYER_ADDRESS_INIT** function initializes a link layer address.

## Parameters

### `LinkLayerAddress` [_Out_]

A pointer to the driver-allocated [NET_ADAPTER_LINK_LAYER_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_link_layer_address) structure to be initialized.

### `Length` [_In_range_(1,32)]

The length of the link layer address, in bytes.

### `AddressBuffer` [_In_reads_bytes_(Length)]

A pointer to the buffer containing the link layer address.

## Remarks

**NET_ADAPTER_LINK_LAYER_ADDRESS_INIT** is used to initialize either a permanent or current link layer address, stored in a **NET_ADAPTER_LINK_LAYER_ADDRESS** allocated by the driver. This **NET_ADAPTER_LINK_LAYER_ADDRESS** is then passed as a parameter to either the [NetAdapterSetPermanentLinkLayerAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetpermanentlinklayeraddress) function or the [NetAdapterSetCurrentLinkLayerAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetcurrentlinklayeraddress) function, depending on the type of address that was initialized and is being set.

## See also

[NET_ADAPTER_LINK_LAYER_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-net_adapter_link_layer_address)