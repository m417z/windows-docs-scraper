# NetPowerOffloadGetType function

## Description

The **NetPowerOffloadGetType** function gets the power offload type for a low power protocol offload to a net adapter.

## Parameters

### `PowerOffload` [_In_]

The NETPOWEROFFLOAD object that represents this low power protocol offload.

## Return value

Returns a [**NET_POWER_OFFLOAD_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/ne-netpoweroffload-_net_power_offload_type) value that specifies the offload type.

## Remarks

The client driver must only call **NetPowerOffloadGetType** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_POWER_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_power_offload)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_POWER_OFFLOAD_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffload/ne-netpoweroffload-_net_power_offload_type)

[**NET_POWER_OFFLOAD_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpoweroffloadlist/ns-netpoweroffloadlist-_net_power_offload_list)