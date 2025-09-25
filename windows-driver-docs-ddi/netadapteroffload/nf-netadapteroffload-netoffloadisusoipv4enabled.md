# NetOffloadIsUsoIPv4Enabled function

## Description

The **NetOffloadIsUsoIPv4Enabled** function determines whether a net adapter has UDP send offload (USO) enabled for IPv4 packets.

## Parameters

### `Offload` [_In_]

A NETOFFLOAD object that represents the net adapter's generic send offload (GSO) capabilities.

## Return value

Returns **TRUE** if USO is enabled for IPv4 packets, or **FALSE** if it is not.

## Remarks

Client drivers typically call this function during their [*EVT_NET_ADAPTER_OFFLOAD_SET_GSO*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_gso) callback to test whether an updated set of active GSO capabilities includes USO for IPv4 packets.

## See also

[Generic Segmentation Offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/gso-offload)

[*EVT_NET_ADAPTER_OFFLOAD_SET_GSO*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_gso)