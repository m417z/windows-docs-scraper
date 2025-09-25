# NET_ADAPTER_POWER_OFFLOAD_NS_CAPABILITIES structure

## Description

The **NET_ADAPTER_POWER_OFFLOAD_NS_CAPABILITIES** structure describes a net adapter's capabilities for IPv6 Neighbor Solicitation (NS) low power protocol offload.

## Members

### `Size`

The size of this structure, in bytes.

### `NSOffload`

A boolean value that specifies if this net adapter supports IPv6 NS protocol offload.

### `MaximumOffloadCount`

The maximum number of NS protocol offloads that the hardware supports.

## Remarks

Call [**NET_ADAPTER_POWER_OFFLOAD_NS_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_power_offload_ns_capabilities_init) to initialize this structure, then call [**NetAdapterPowerOffloadSetNsCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterpoweroffloadsetnscapabilities) to set the net adapter's NS protocol offload capabilities. Client drivers typically call **NetAdapterPowerOffloadSetNsCapabilities** when starting a net adapter, but before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_POWER_OFFLOAD_NS_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_power_offload_ns_capabilities_init)

[**NetAdapterPowerOffloadSetNsCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterpoweroffloadsetnscapabilities)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)