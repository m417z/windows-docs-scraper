# EVT_NET_ADAPTER_OFFLOAD_SET_GSO callback function

## Description

The client driver implements the *EvtNetAdapterOffloadSetGso* callback function to query changes in active Generic Segmentation Offload (GSO) capabilities and update the hardware settings accordingly.

## Parameters

### `Adapter` [_In_]

A handle to a NETADAPTER object the client driver previously created with a call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `Offload` [_In_]

A handle to a NETOFFLOAD object that describes the adapter's offload capabilities.

## Remarks

Register your implementation of this callback function by setting the appropriate parameter when calling [**NetAdapterOffloadSetGsoCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetgsocapabilities).

For an example implementation of this callback, see [Generic Segmentation Offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/gso-offload).

## See also

[Generic Segmentation Offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/gso-offload)

[**NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_gso_capabilities)

[**NetAdapterOffloadSetGsoCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetgsocapabilities)

[**NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-net_adapter_offload_gso_capabilities_init)