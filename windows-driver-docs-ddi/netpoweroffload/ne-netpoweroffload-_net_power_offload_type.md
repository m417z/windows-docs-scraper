# NET_POWER_OFFLOAD_TYPE enumeration

## Description

The **NET_POWER_OFFLOAD_TYPE** enumeration specifies the type for a low power offload protocol offload to a net adapter.

## Constants

### `NetPowerOffloadTypeArp:1`

The power offload is the IPv4 ARP protocol.

### `NetPowerOffloadTypeNS:2`

The power offload is the IPv6 Neighbor Solicitation (NS) protocol.

## Remarks

Call [**NetPowerOffloadGetType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/nf-netpoweroffload-netpoweroffloadgettype) to get the type for a low power protocol offload.

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)