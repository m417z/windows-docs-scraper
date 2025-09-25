# NET_ADAPTER_OFFLOAD_RX_CHECKSUM_CAPABILITIES_INIT function

## Description

The **NET_ADAPTER_OFFLOAD_RX_CHECKSUM_CAPABILITIES_INIT** function initializes a [**NET_ADAPTER_OFFLOAD_RX_CHECKSUM_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_rx_checksum_capabilities) structure.

## Parameters

### `Capabilities` [_Out_]

A pointer to a driver-allocated [**NET_ADAPTER_OFFLOAD_RX_CHECKSUM_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_rx_checksum_capabilities) structure.

### `EvtAdapterOffloadSetRxChecksum` [_In_]

A pointer to the client driver's implementation of the [*EVT_NET_ADAPTER_OFFLOAD_SET_RX_CHECKSUM*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_rx_checksum) callback function.

## Remarks

The client driver calls **NET_ADAPTER_OFFLOAD_RX_CHECKSUM_CAPABILITIES_INIT** to initialize a [**NET_ADAPTER_OFFLOAD_RX_CHECKSUM_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_rx_checksum_capabilities) structure. The driver passes the initialized **NET_ADAPTER_OFFLOAD_RX_CHECKSUM_CAPABILITIES** structure as a parameter to the [**NetAdapterOffloadSetRxChecksumCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetrxchecksumcapabilities) function to register it.

## See also

[Checksum Offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/checksum-offload)

[*EVT_NET_ADAPTER_OFFLOAD_SET_RX_CHECKSUM*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_rx_checksum)

[**NET_ADAPTER_OFFLOAD_RX_CHECKSUM_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_rx_checksum_capabilities)

[**NetAdapterOffloadSetRxChecksumCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsetrxchecksumcapabilities)