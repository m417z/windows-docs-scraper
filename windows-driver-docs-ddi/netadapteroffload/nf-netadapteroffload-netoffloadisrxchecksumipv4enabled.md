# NetOffloadIsRxChecksumIPv4Enabled function

## Description

The **NetOffloadIsRxChecksumIPv4Enabled** function determines whether a net adapter has Rx IPv4 checksum offload enabled.

## Parameters

### `Offload` [_In_]

A NETOFFLOAD object that represents the net adapter's Rx checksum capabilities.

## Return value

Returns **TRUE** if Rx IPv4 checksum offload is enabled. Otherwise, returns **FALSE**.

## Remarks

Client drivers typically call this function during their [*EvtNetAdapterOffloadSetRxChecksum*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_rx_checksum) callback to test whether an updated set of active Rx checksum capabilities includes Rx IPv4 checksum offload.

## See also

[Checksum Offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/checksum-offload)

[*EVT_NET_ADAPTER_OFFLOAD_SET_RX_CHECKSUM*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_rx_checksum)