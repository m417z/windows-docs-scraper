# WdfDeviceAssignSxWakeSettings function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceAssignSxWakeSettings** method provides driver-supplied information about a device's ability to trigger a wake signal while both the device and the system are in a low-power state.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Settings` [in]

A pointer to a caller-supplied [WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_wake_settings) structure.

## Return value

If the operation succeeds, **WdfDeviceAssignSxWakeSettings** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The calling driver is not the device's power policy owner. |
| **STATUS_INVALID_PARAMETER** | An invalid *Settings* value is detected. |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the [WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_wake_settings) structure is incorrect. |
| **STATUS_POWER_STATE_INVALID** | The bus driver indicates the device cannot trigger a wake signal, or the [WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_wake_settings) structure contains an invalid device power state. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information, see [Supporting System Wake-Up](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-wake-up).

#### Examples

The following code example initializes a WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS structure and then calls **WdfDeviceAssignSxWakeSettings**. The example uses the default settings that [WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_power_policy_wake_settings_init) sets.

```cpp
WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS  wakeSettings;
NTSTATUS  status = STATUS_SUCCESS;

WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS_INIT(&wakeSettings);

status = WdfDeviceAssignSxWakeSettings(
                                       device,
                                       &wakeSettings
                                       );
if (!NT_SUCCESS(status)) {
    return status;
}
```

## See also

[WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_wake_settings)

[WdfDeviceAssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigns0idlesettings)