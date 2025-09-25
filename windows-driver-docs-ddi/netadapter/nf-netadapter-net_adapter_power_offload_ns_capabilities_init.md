# NET_ADAPTER_POWER_OFFLOAD_NS_CAPABILITIES_INIT function

## Description

The **NET_ADAPTER_POWER_OFFLOAD_NS_CAPABILITIES_INIT** function initializes a [**NET_ADAPTER_POWER_OFFLOAD_NS_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_power_offload_ns_capabilities) structure.

## Parameters

### `Capabilities` [_Out_]

A pointer to a client driver-allocated [**NET_ADAPTER_POWER_OFFLOAD_NS_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_power_offload_ns_capabilities) structure.

### `MaximumOffloadCount` [_In_]

The maximum number of NS protocol offloads that the hardware supports.

## Remarks

After calling this function to initialize the **NET_ADAPTER_POWER_OFFLOAD_NS_CAPABILITIES** structure, call [**NetAdapterPowerOffloadSetNsCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterpoweroffloadsetnscapabilities) to set the net adapter's NS protocol offload capabilities. Client drivers typically call **NetAdapterPowerOffloadSetNsCapabilities** when starting a net adapter, but before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_POWER_OFFLOAD_NS_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_power_offload_ns_capabilities)

[**NetAdapterPowerOffloadSetNsCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterpoweroffloadsetnscapabilities)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)