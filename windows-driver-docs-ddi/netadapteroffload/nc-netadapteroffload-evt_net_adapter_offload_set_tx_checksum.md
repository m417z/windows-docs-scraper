# EVT_NET_ADAPTER_OFFLOAD_SET_TX_CHECKSUM callback function

## Description

The client driver implements the *EvtNetAdapterOffloadSetTxChecksum* callback function to query changes in active Tx checksum offload capabilities and update the hardware settings accordingly.

## Parameters

### `Adapter` [_In_]

A handle to a NETADAPTER object the client driver previously created with a call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `Offload` [_In_]

A handle to a NETOFFLOAD object that describes the adapter's offload capabilities.

## Remarks

Register your implementation of this callback function by setting the appropriate parameter when calling [**NetAdapterOffloadSetTxChecksumCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsettxchecksumcapabilities).

For an example implementation of this callback, see [Checksum Offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/checksum-offload).

## See also

[Checksum Offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/checksum-offload)

[**NET_ADAPTER_OFFLOAD_TX_CHECKSUM_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/ns-netadapteroffload-_net_adapter_offload_tx_checksum_capabilities)

[**NetAdapterOffloadSetTxChecksumCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nf-netadapteroffload-netadapteroffloadsettxchecksumcapabilities)