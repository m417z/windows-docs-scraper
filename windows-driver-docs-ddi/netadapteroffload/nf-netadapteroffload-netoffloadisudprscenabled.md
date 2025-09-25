## Description

The **NetOffloadIsUdpRscEnabled** function determines whether a network adapter has [UDP RSC Offload (URO)](https://learn.microsoft.com/windows-hardware/drivers/netcx/rsc-offload#udp-rsc-offload-uro-) enabled.

## Parameters

### `Offload` [_In_]

A NETOFFLOAD object that represents the network adapter's URO capabilities.

## Return value

Returns **TRUE** if URO is enabled. Otherwise, returns **FALSE**.

## Remarks

Client drivers typically call this function during their [*EvtNetAdapterOffloadSetRsc*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_rsc) callback to test whether an updated set of active RSC capabilities includes URO.

## See also

[UDP RSC Offload (URO)](https://learn.microsoft.com/windows-hardware/drivers/netcx/rsc-offload#udp-rsc-offload-uro-)

[*EvtNetAdapterOffloadSetRsc*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapteroffload/nc-netadapteroffload-evt_net_adapter_offload_set_rsc)