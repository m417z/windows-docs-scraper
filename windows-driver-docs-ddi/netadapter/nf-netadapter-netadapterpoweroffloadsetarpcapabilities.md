# NetAdapterPowerOffloadSetArpCapabilities function

## Description

The **NetAdapterPowerOffloadSetArpCapabilities** function sets a net adapter's capabilities for IPv4 ARP low power protocol offload.

## Parameters

### `Adapter` [_In_]

A handle to a NETADAPTER object that the client driver obtained from a previous call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `Capabilities` [_In_]

A pointer to a client driver-allocated and initialized [**NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_power_offload_arp_capabilities) structure.

## Remarks

Client drivers typically call this function from within their [*EvtDevicePrepareHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback, but **must** call this function before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_power_offload_arp_capabilities)

[**NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_power_offload_arp_capabilities_init)

[**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate)

[*EvtDevicePrepareHardware*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)

[**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart)