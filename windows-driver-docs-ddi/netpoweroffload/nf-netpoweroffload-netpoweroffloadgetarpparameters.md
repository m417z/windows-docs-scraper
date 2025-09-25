# NetPowerOffloadGetArpParameters function

## Description

The **NetPowerOffloadGetArpParameters** function gets parameters for an IPv4 ARP low power protocol offload to a net adapter.

## Parameters

### `PowerOffload` [_In_]

The NETPOWEROFFLOAD object that represents this ARP protocol offload.

### `Parameters` [_Inout_]

A pointer to a driver-allocated and initialized [**NET_POWER_OFFLOAD_ARP_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/ns-netpoweroffload-_net_power_offload_arp_parameters) structure that receives the ARP parameter information.

## Remarks

Call [**NET_POWER_OFFLOAD_ARP_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/nf-netpoweroffload-net_power_offload_arp_parameters_init) to initialize the [**NET_POWER_OFFLOAD_ARP_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/ns-netpoweroffload-_net_power_offload_arp_parameters) structure before calling this function.

The client driver must only call **NetPowerOffloadGetArpParameters** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_POWER_OFFLOAD_ARP_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/ns-netpoweroffload-_net_power_offload_arp_parameters)

[**NET_POWER_OFFLOAD_ARP_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/nf-netpoweroffload-net_power_offload_arp_parameters_init)