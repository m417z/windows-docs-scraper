# NetOffloadIsLsoIPv6Enabled function

## Description

The **NetOffloadIsLsoIPv6Enabled** function determines whether a net adapter has large send offload (LSO) enabled for IPv6 packets.

## Parameters

### `Offload` [_In_]

A NETOFFLOAD object that represents the net adapter's generic send offload (GSO) capabilities.

## Return value

Returns **TRUE** if LSO is enabled for IPv6 packets, or **FALSE** if it is not.

## Remarks

Client drivers typically call this function during their [*EVT_NET_ADAPTER_OFFLOAD_SET_GSO*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_gso) callback to test whether an updated set of active GSO capabilities includes LSO for IPv6 packets.

## See also

[Generic Segmentation Offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/gso-offload)

[*EVT_NET_ADAPTER_OFFLOAD_SET_GSO*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_gso)