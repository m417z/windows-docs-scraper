# NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES structure

## Description

The **NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES** structure describes a net adapter's capabilities for IPv4 ARP low power protocol offload.

## Members

### `Size`

The size of this structure, in bytes.

### `ArpOffload`

A boolean value that specifies if this net adapter supports IPv4 ARP protocol offload.

### `MaximumOffloadCount`

The maximum number of ARP protocol offloads that the hardware supports.

## Remarks

Call [**NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_power_offload_arp_capabilities_init) to initialize this structure, then call [**NetAdapterPowerOffloadSetArpCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterpoweroffloadsetarpcapabilities) to set the net adapter's ARP protocol offload capabilities. Client drivers typically call **NetAdapterPowerOffloadSetArpCapabilities** when starting a net adapter, but before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_power_offload_arp_capabilities_init)

[**NetAdapterPowerOffloadSetArpCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterpoweroffloadsetarpcapabilities)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)