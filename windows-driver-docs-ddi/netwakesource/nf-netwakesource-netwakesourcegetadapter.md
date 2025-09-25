# NetWakeSourceGetAdapter function

## Description

The **NetWakeSourceGetAdapter** function gets the net adapter for a wake-on-LAN (WoL) source.

## Parameters

### `WakeSource` [_In_]

The NETWAKESOURCE object that represents the source of the wake-up event.

## Return value

Returns the NETADAPTER object that represents the net adapter for this wake source.

## Remarks

Client drivers that have one network adapter per device do not need to call this optional function. Call **NetWakeSourceGetAdapter** if your device has more than one net adapter object per device, such as in a [MBBCx client driver](https://learn.microsoft.com/windows-hardware/drivers/netcx/mobile-broadband-mbb-wdf-class-extension-mbbcx).

The client driver must only call **NetWakeSourceGetAdapter** during a power transition, typically from its *[EVT_WDF_DEVICE_ARM_WAKE_FROM_SX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)*, *[EVT_WDF_DEVICE_ARM_WAKE_FROM_S0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)*, or *[EVT_NET_DEVICE_PREVIEW_WAKE_SOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nc-netdevice-evt_net_device_preview_wake_source)* callback function. Otherwise, the call results in a system bugcheck.

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NetWakeSourceListGetElement**]