# _NET_ADAPTER_LINK_LAYER_CAPABILITIES structure

## Description

Describes the link layer capabilities of the adapter.

## Members

### `Size`

The size of this structure, in bytes.

### `MaxTxLinkSpeed`

The maximum transmit link speed of the adapter in bits per second. For more information, see [OID_GEN_MAX_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-max-link-speed).

### `MaxRxLinkSpeed`

 The maximum receive link speed of the adapter in bits per second. For more information, see [OID_GEN_MAX_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-max-link-speed).

## Remarks

The client driver passes an initialized **NET_ADAPTER_LINK_LAYER_CAPABILITIES** structure as an input parameter value to [NetAdapterSetLinkLayerCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetlinklayercapabilities).

Call [NET_ADAPTER_LINK_LAYER_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_link_layer_capabilities_init) to initialize this structure.

## See also