## Description

The **NetOffloadIsTcpRscIPv4Enabled** function determines whether a net adapter has RSC offload enabled for IPv4 packets.

## Parameters

### `Offload` [_In_]

A NETOFFLOAD object that represents the net adapter's RSC capabilities.

## Return value

Returns **TRUE** if RSC offload is enabled for IPv4 packets, or **FALSE** if it is not.

## Remarks

Client drivers typically call this function during their [*EvtNetAdapterOffloadSetRsc*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_rsc) callback to test whether an updated set of active RSC capabilities includes RSC offload for IPv4 packets.

## See also

[Receive Segment Coalescing offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/rsc-offload)

[*EvtNetAdapterOffloadSetRsc*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_rsc)