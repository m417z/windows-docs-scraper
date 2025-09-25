# _NET_ADAPTER_OFFLOAD_RX_CHECKSUM_CAPABILITIES structure

## Description

The **NET_ADAPTER_OFFLOAD_RX_CHECKSUM_CAPABILITIES** structure describes a network interface card (NIC)'s Rx checksum offload capabilities.

## Members

### `Size`

The size of this structure in bytes.

### `EvtAdapterOffloadSetRxChecksum`

A pointer to the client driver's implementation of the [*EVT_NET_ADAPTER_OFFLOAD_SET_RX_CHECKSUM*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_rx_checksum) callback function.

## Remarks

Call [**NET_ADAPTER_OFFLOAD_RX_CHECKSUM_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-net_adapter_offload_rx_checksum_capabilities_init) to initialize this structure. The client driver passes an initialized **NET_ADAPTER_OFFLOAD_RX_CHECKSUM_CAPABILITIES** structure as a parameter to [**NetAdapterOffloadSetRxChecksumCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetrxchecksumcapabilities).

## See also

[Checksum Offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/checksum-offload)

[*EVT_NET_ADAPTER_OFFLOAD_SET_RX_CHECKSUM*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_rx_checksum)

[**NET_ADAPTER_OFFLOAD_RX_CHECKSUM_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-net_adapter_offload_rx_checksum_capabilities_init)

[**NetAdapterOffloadSetRxChecksumCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetrxchecksumcapabilities)