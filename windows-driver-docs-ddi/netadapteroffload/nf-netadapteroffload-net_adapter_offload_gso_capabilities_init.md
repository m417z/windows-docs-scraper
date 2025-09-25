# NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES_INIT function

## Description

The **NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES_INIT** function initializes a [**NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_gso_capabilities) structure.

## Parameters

### `GsoCapabilities` [_Out_]

A pointer to a driver-allocated [**NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_gso_capabilities) structure.

### `Layer3Flags` [_In_]

Flags specifying the layer 3 protocols and variations contained in packets that the NIC can successfully segment.

### `Layer4Flags` [_In_]

Flags specifying the layer 4 protocols and variations contained in packets that the NIC can successfully segment.

### `MaximumOffloadSize` [_In_]

The maximum bytes of user data that the transport can pass to the NIC driver in a single packet.

### `MinimumSegmentCount` [_In_]

The minimum number of segments by which a large TCP packet must be divisible before the transport can offload it to the hardware for segmentation.

### `EvtAdapterOffloadSetGso` [_In_]

A pointer to the client driver's implementation of the [*EVT_NET_ADAPTER_OFFLOAD_SET_GSO*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_gso) callback function.

## Remarks

The client driver calls **NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES_INIT** to initialize a [**NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_gso_capabilities) structure. The driver passes the initialized **NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES** structure as a parameter to the [**NetAdapterOffloadSetGsoCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetgsocapabilities) function to register it.

## See also

[Generic Segmentation Offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/gso-offload)

[*EVT_NET_ADAPTER_OFFLOAD_SET_GSO*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_gso)

[**NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_gso_capabilities)

[**NetAdapterOffloadSetGsoCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetgsocapabilities)