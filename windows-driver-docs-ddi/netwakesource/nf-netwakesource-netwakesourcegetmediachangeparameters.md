# NetWakeSourceGetMediaChangeParameters function

## Description

The **NetWakeSourceGetMediaChangeParameters** function gets parameters for a media change wake source.

## Parameters

### `WakeSource` [_In_]

A NETWAKESOURCE object that represents this media change wake source.

### `Parameters` [_Inout_]

A pointer to a driver-allocated and initialized [**NET_WAKE_SOURCE_MEDIA_CHANGE_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/ns-netwakesource-_net_wake_source_media_change_parameters) structure that receives the media change parameters.

## Remarks

Call [**NET_WAKE_SOURCE_MEDIA_CHANGE_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/nf-netwakesource-net_wake_source_media_change_parameters_init) to initialize the [**NET_WAKE_SOURCE_MEDIA_CHANGE_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/ns-netwakesource-_net_wake_source_media_change_parameters) structure before calling this function.

The client driver must only call **NetWakeSourceGetMediaChangeParameters** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_WAKE_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_wake_source)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_WAKE_SOURCE_MEDIA_CHANGE_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/ns-netwakesource-_net_wake_source_media_change_parameters)

[**NET_WAKE_SOURCE_MEDIA_CHANGE_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netwakesource/nf-netwakesource-net_wake_source_media_change_parameters_init)