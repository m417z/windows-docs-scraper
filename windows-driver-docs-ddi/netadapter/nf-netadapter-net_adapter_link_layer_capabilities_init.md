# NET_ADAPTER_LINK_LAYER_CAPABILITIES_INIT function

## Description

The **NET_ADAPTER_LINK_LAYER_CAPABILITIES_INIT** function initializes a [NET_ADAPTER_LINK_LAYER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_link_layer_capabilities) structure.

## Parameters

### `LinkLayerCapabilities` [_Out_]

A pointer to the driver-allocated [NET_ADAPTER_LINK_LAYER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_link_layer_capabilities) structure that describes the link layer capabilities of the adapter.

### `MaxTxLinkSpeed` [_In_]

The maximum transmit link speed of the adapter in bits per second. For more information, see [OID_GEN_MAX_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-max-link-speed).

### `MaxRxLinkSpeed` [_In_]

The maximum receive link speed of the adapter in bits per second. For more information, see [OID_GEN_MAX_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-max-link-speed).

## Remarks

**NET_ADAPTER_LINK_LAYER_CAPABILITIES_INIT** zeroes out the [NET_ADAPTER_LINK_LAYER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_link_layer_capabilities) structure and then sets all of its members.

## See also