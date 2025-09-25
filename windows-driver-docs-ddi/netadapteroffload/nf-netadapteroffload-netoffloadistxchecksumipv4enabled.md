# NetOffloadIsTxChecksumIPv4Enabled function

## Description

The **NetOffloadIsTxChecksumIPv4Enabled** function determines whether a net adapter has Tx IPv4 checksum offload enabled.

## Parameters

### `Offload` [_In_]

A NETOFFLOAD object that represents the net adapter's Tx checksum capabilities.

## Return value

Returns **TRUE** if Tx IPv4 checksum offload is enabled. Otherwise, returns **FALSE**.

## Remarks

Client drivers typically call this function during their [*EvtNetAdapterOffloadSetTxChecksum*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_tx_checksum) callback to test whether an updated set of active Tx checksum capabilities includes Tx IPv4 checksum offload.

## See also

[Checksum Offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/checksum-offload)

[*EVT_NET_ADAPTER_OFFLOAD_SET_TX_CHECKSUM*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_tx_checksum)