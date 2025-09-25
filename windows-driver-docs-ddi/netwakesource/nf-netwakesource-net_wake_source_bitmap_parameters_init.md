# NET_WAKE_SOURCE_BITMAP_PARAMETERS_INIT function

## Description

The **NET_WAKE_SOURCE_BITMAP_PARAMETERS_INIT** function initializes a [**NET_WAKE_SOURCE_BITMAP_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/ns-netwakesource-_net_wake_source_bitmap_parameters) structure.

## Parameters

### `Parameters` [_Out_]

A pointer to a driver-allocated [**NET_WAKE_SOURCE_BITMAP_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/ns-netwakesource-_net_wake_source_bitmap_parameters) structure.

## Remarks

This function zeroes out the memory of the **NET_WAKE_SOURCE_BITMAP_PARAMETERS** structure, then fills in the **Size** member. Client drivers must then call [**NetWakeSourceGetBitmapParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/nf-netwakesource-netwakesourcegetbitmapparameters) to fill n the other members of the structure.

The client driver must only call **NET_WAKE_SOURCE_BITMAP_PARAMETERS_INIT** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_WAKE_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_wake_source)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_WAKE_SOURCE_BITMAP_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/ns-netwakesource-_net_wake_source_bitmap_parameters)