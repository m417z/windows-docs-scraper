# NET_POWER_OFFLOAD_NS_PARAMETERS_INIT function

## Description

The **NET_POWER_OFFLOAD_NS_PARAMETERS_INIT** function initializes a [**NET_POWER_OFFLOAD_NS_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/ns-netpoweroffload-_net_power_offload_ns_parameters) structure.

## Parameters

### `Parameters` [_Out_]

A pointer to a client driver-allocated [**NET_POWER_OFFLOAD_NS_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/ns-netpoweroffload-_net_power_offload_ns_parameters) structure.

## Remarks

This function zeroes out the memory of the **NET_POWER_OFFLOAD_NS_PARAMETERS** structure, then fills in the **Size** member. Client drivers must then call [**NetPowerOffloadGetNsParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/nf-netpoweroffload-netpoweroffloadgetnsparameters) to fill in the remaining members of the structure.

The client driver must only call **NET_POWER_OFFLOAD_NS_PARAMETERS_INIT** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_POWER_OFFLOAD_NS_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/ns-netpoweroffload-_net_power_offload_ns_parameters)