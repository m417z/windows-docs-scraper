# NetPowerOffloadGetNSParameters function

## Description

The **NetPowerOffloadGetNSParameters** function gets parameters for an IPv6 Neighbor Solicitation (NS) low power protocol offload to a net adapter.

## Parameters

### `PowerOffload` [_In_]

The NETPOWEROFFLOAD object that represents this NS protocol offload.

### `Parameters` [_Inout_]

A pointer to a driver-allocated [**NET_POWER_OFFLOAD_NS_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/ns-netpoweroffload-_net_power_offload_ns_parameters) structure that receives the NS parameter information.

## Remarks

Call [**NET_POWER_OFFLOAD_NS_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/nf-netpoweroffload-net_power_offload_ns_parameters_init) to initialize the [**NET_POWER_OFFLOAD_NS_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/ns-netpoweroffload-_net_power_offload_ns_parameters) structure before calling this function.

The client driver must only call **NetPowerOffloadGetNSParameters** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_POWER_OFFLOAD_NS_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/ns-netpoweroffload-_net_power_offload_ns_parameters)

[**NET_POWER_OFFLOAD_NS_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/nf-netpoweroffload-net_power_offload_ns_parameters_init)