# NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES_INIT function

## Description

The **NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES_INIT** function initializes a [**NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_rsc_capabilities) structure.

## Parameters

### `RscCapabilities` [_Out_]

A pointer to a driver-allocated [**NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_rsc_capabilities) structure.

### `Layer3Flags` [_In_]

Flags specifying the layer 3 protocols that the NIC can successfully perform RSC on.

### `Layer4Flags` [_In_]

Flags specifying the layer 4 protocols that the NIC can successfully perform RSC on.

### `EvtAdapterOffloadSetRsc` [_In_]

A pointer to the client driver's implementation of the [*EVT_NET_ADAPTER_OFFLOAD_SET_RSC*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_rsc) callback function.

## Remarks

The client driver calls **NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES_INIT** to initialize a [**NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_rsc_capabilities) structure. The driver passes the initialized **NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES** structure as a parameter to the [**NetAdapterOffloadSetRscCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetrsccapabilities) function to register it.

To see an example of how a client driver might set up its RSC hardware offload capabilities, see [Receive Segment Coalescing offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/rsc-offload).

## See also

[Receive Segment Coalescing offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/rsc-offload)

[**NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_rsc_capabilities)

[**NetAdapterOffloadSetRscCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetrsccapabilities)