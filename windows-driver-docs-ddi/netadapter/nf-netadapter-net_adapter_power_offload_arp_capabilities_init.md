# NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES_INIT function

## Description

The **NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES_INIT** function initializes a [**NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_power_offload_arp_capabilities) structure.

## Parameters

### `Capabilities` [_Out_]

A pointer to a client driver-allocated [**NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_power_offload_arp_capabilities) structure.

### `MaximumOffloadCount` [_In_]

The maximum number of ARP protocol offloads that the hardware supports.

## Remarks

After calling this function to initialize the **NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES** structure, call [**NetAdapterPowerOffloadSetArpCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterpoweroffloadsetarpcapabilities) to set the net adapter's ARP protocol offload capabilities. Client drivers typically call **NetAdapterPowerOffloadSetArpCapabilities** when starting a net adapter, but before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_power_offload_arp_capabilities)

[**NetAdapterPowerOffloadSetArpCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterpoweroffloadsetarpcapabilities)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)