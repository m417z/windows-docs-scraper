# WdfDeviceAssignS0IdleSettings function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceAssignS0IdleSettings** method provides driver-supplied information that the framework uses when a device is idle and the system is in its working (S0) state.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Settings` [in]

A pointer to a caller-supplied [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) structure.

## Return value

If the operation succeeds, **WdfDeviceAssignS0IdleSettings** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The calling driver is not the device's power policy owner. |
| **STATUS_INVALID_PARAMETER** | An invalid *Settings* value is detected. |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) structure is incorrect. |
| **STATUS_POWER_STATE_INVALID** | This value is returned if one of the following occurs:<br><br>* The [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) structure contains an invalid device power state.<br>* The **IdleCaps** member of the [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) structure indicates the device can wake itself, but the bus driver indicates the device cannot wake itself.<br>* Starting in KMDF version 1.11 running on Windows 8, the framework checks if the system's firmware can handle a wake signal while the system is in its fully on (S0) power state. If the machine fails this check, [WdfDeviceAssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigns0idlesettings) returns **STATUS_POWER_STATE_INVALID**, and the device remains in its fully on (D0) power state as long as the system remains in S0.<br><br>  In this case, the driver should not return an error status value from [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) or any other runtime callback. At most, the driver might log an error indicating that the device will consume more power than it normally would. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If the driver sets the **IdleTimeoutType** member of [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) to **SystemManagedIdleTimeout** or **SystemManagedIdleTimeoutWithHint**, it must call **WdfDeviceAssignS0IdleSettings** before returning from [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry). Typically, a driver first calls **WdfDeviceAssignS0IdleSettings** from [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add).

 Additional calls to **WdfDeviceAssignS0IdleSettings** can be made at any time. However, after the driver sets the value of the **IdleTimeoutType** member in its first call to **WdfDeviceAssignS0IdleSettings**, it must not change this value in later calls to this method.

If the driver registers for asynchronous notifications in [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) (for example by calling [PoRegisterPowerSettingCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poregisterpowersettingcallback) or [IoRegisterPlugPlayNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterplugplaynotification)), the driver must not subsequently call **WdfDeviceAssignS0IdleSettings** from within the driver callback routine that it registered.

For more information, see [Supporting Idle Power-Down](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-idle-power-down).

#### Examples

The following code example initializes a [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) structure, sets an idle time-out value of 10 seconds, and calls **WdfDeviceAssignS0IdleSettings**.

```cpp
WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS  idleSettings;
NTSTATUS  status = STATUS_SUCCESS;

WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT(
                                           &idleSettings,
                                           IdleCanWakeFromS0
                                           );
idleSettings.IdleTimeout = 10000;

status = WdfDeviceAssignS0IdleSettings(
                                       device,
                                       &idleSettings
                                       );
if (!NT_SUCCESS(status)) {
    return status;
}
```

## See also

[WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings)

[WdfDeviceAssignSxWakeSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassignsxwakesettings)