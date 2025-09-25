# NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES structure

## Description

The **NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES** structure describes a network interface card (NIC)'s capabilities for receive segment coalescence (RSC).

## Members

### `Size`

The size of this structure, in bytes.

### `Layer3Flags`

Flags specifying the layer 3 protocols that the NIC can successfully perform RSC on. `NetAdapterOffloadLayer3FlagIPv4NoOptions` and `NetAdapterOffloadLayer3FlagIPv6NoExtensions` are the only valid values.

### `Layer4Flags`

Flags specifying the layer 4 protocols that the NIC can successfully perform RSC on. `NetAdapterOffloadLayer4FlagTcpNoOptions` and `NetAdapterOffloadLayer4FlagUdp` are the only valid values. Layer 3 flags must be set if the `NetAdapterOffloadLayer4FlagTcpNoOptions` flag is set.

### `TcpTimestampOption`

Optional. A flag specifying whether the hardware can perform RSC on packets with a timestamp.

### `EvtAdapterOffloadSetRsc`

A pointer to the client driver's implementation of the [*EVT_NET_ADAPTER_OFFLOAD_SET_RSC*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_rsc) callback function.

## Remarks

Call [**NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-net_adapter_offload_rsc_capabilities_init) to initialize this structure. The client driver passes an initialized **NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES** structure as a parameter to [**NetAdapterOffloadSetRscCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetrsccapabilities).

To see an example of how a client driver might set up its RSC hardware offload capabilities, see [Receive Segment Coalescing offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/rsc-offload).

## See also

[Receive Segment Coalescing offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/rsc-offload)

[**NET_ADAPTER_OFFLOAD_RSC_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-net_adapter_offload_rsc_capabilities_init)

[**NetAdapterOffloadSetRscCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetrsccapabilities)

[*EVT_NET_ADAPTER_OFFLOAD_SET_RSC*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_rsc)