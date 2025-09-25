# _NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES structure

## Description

The **NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES** structure describes a network interface card (NIC)'s capabilities for [Generic Segmentation Offload (GSO)](https://learn.microsoft.com/windows-hardware/drivers/netcx/gso-offload).

## Members

### `Size`

The size of this structure, in bytes.

### `Layer3Flags`

Flags specifying the layer 3 protocol variations that the NIC can successfully perform GSO on.

The flags should be a combination of:

| Flag | Description |
| --- | --- |
| NetAdapterOffloadLayer3FlagIPv4NoOptions | Set if the NIC is capable of performing GSO on IPv4 packets without options |
| NetAdapterOffloadLayer3FlagIPv4WithOptions | Set if the NIC is capable of performing GSO on IPv4 packets with options |
| NetAdapterOffloadLayer3FlagIPv6NoExtensions | Set if the NIC is capable of performing GSO on IPv6 packets without extensions |
| NetAdapterOffloadLayer3FlagIPv6WithExtensions | Set if the NIC is capable of performing GSO on IPv6 packets with extensions |

### `Layer4Flags`

Flags specifying the layer 4 protocol variations that the NIC can successfully perform GSO on. The `NetAdapterOffloadLayer4FlagTcpNoOptions` flag must be set if the NIC supports LSO. The `NetAdapterOffloadLayer4FlagUdp` flag must be set if the NIC supports USO.

The flags should be a combination of:

| Flag | Description |
| --- | --- |
| NetAdapterOffloadLayer4FlagTcpNoOptions | Set if the NIC is capable of performing LSO on TCP packets without options |
| NetAdapterOffloadLayer4FlagTcpWithOptions | Set if the NIC is capable of performing LSO on TCP packets with options |
| NetAdapterOffloadLayer4FlagUdp | Set if the NIC is capable of performing USO on UDP packets |

### `Layer4HeaderOffsetLimit`

The maximum layer 4 header offset that the NIC supports in bytes. This field is optional.

### `MaximumOffloadSize`

The maximum bytes of user data that the transport can pass to the NIC driver in a single packet.

### `MinimumSegmentCount`

The minimum number of segments by which a large TCP/UDP packet must be divisible before the transport can offload it to the hardware for segmentation.

### `EvtAdapterOffloadSetGso`

A pointer to the client driver's implementation of the [*EVT_NET_ADAPTER_OFFLOAD_SET_GSO*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_gso) callback function.

## Remarks

Call [**NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-net_adapter_offload_gso_capabilities_init) to initialize this structure. The client driver passes an initialized **NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES** structure as a parameter to [**NetAdapterOffloadSetGsoCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetgsocapabilities).

## See also

[Generic Segmentation Offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/gso-offload)

[**NET_ADAPTER_OFFLOAD_GSO_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-net_adapter_offload_gso_capabilities_init)

[**NetAdapterOffloadSetGsoCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetgsocapabilities)

[*EVT_NET_ADAPTER_OFFLOAD_SET_GSO*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_gso)