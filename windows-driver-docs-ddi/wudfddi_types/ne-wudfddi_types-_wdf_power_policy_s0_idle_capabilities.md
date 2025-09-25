# _WDF_POWER_POLICY_S0_IDLE_CAPABILITIES enumeration (wudfddi_types.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_POWER_POLICY_S0_IDLE_CAPABILITIES** enumeration identifies the capabilities that a device can support when it enters a low-power state while it is idling.

## Constants

### `IdleCapsInvalid`

For internal use only.

### `IdleCannotWakeFromS0`

The device cannot wake itself from a low-power state while the system is in its working (S0) state.

### `IdleCanWakeFromS0`

The device can wake itself from a low-power state while the system is in its working (S0) state.

### `IdleUsbSelectiveSuspend`

The device is connected to a USB bus and supports [USB selective suspend](https://learn.microsoft.com/windows-hardware/drivers/ddi/). Use this value if your USB-connected device supports both idling and waking itself while the computer is in its working state. If your USB device supports only idling, use **IdleCannotWakeFromS0**. (Drivers for USB devices must not specify **IdleCanWakeFromS0**.) See the code examples in the following Examples section.

For Windows XP, the framework supports USB selective suspend only if the device's [USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor) structure shows that the device supports [remote wakeup](https://learn.microsoft.com/windows-hardware/drivers/ddi/). For Windows Vista and later versions of Windows, the framework supports USB selective suspend whether or not the device supports remote wakeup.

## Remarks

The **WDF_POWER_POLICY_S0_IDLE_CAPABILITIES** enumeration is used in the [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) structure.

#### Examples

The following code examples show how to enable idle support for a USB device. In each case, the STATUS_POWER_STATE_INVALID return value means the bus driver has reported that the device cannot wake itself.

**KMDF Example**

```
WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT(&idleSettings,
                                           IdleUsbSelectSuspend);
status = WdfDeviceAssignS0IdleSettings(device,
                                       &idleSettings);
if (status == STATUS_POWER_STATE_INVALID){
    //
    // The device probably does not support wake.
    // It might support idle without wake.
    //
    idleSettings.IdleCaps = IdleCannotWakeFromS0;
    status = WdfDeviceAssignS0IdleSettings(device,
                                           &IdleSettings);
    if (!NT_SUCCESS(status) {...}
 }
else {...}
```

**UMDF Example**

```
hr = pIWDFDevice2->AssignS0IdleSettings(IdleUsbSelectSuspend,
                                        PowerDeviceD3,
                                        IDLEWAKE_TIMEOUT_MSEC,
                                        IdleAllowUserControl,
                                        WdfTrue);
if (hr == HRESULT_FROM_NT(STATUS_POWER_STATE_INVALID)){
    //
    // The device probably does not support wake.
    // It might support idle without wake.
    //
    hr = pIWDFDevice2->AssignS0IdleSettings(IdleCannotWakeFromS0,
                                         PowerDeviceD3,
                                         IDLEWAKE_TIMEOUT_MSEC,
                                         IdleAllowUserControl,
                                         WdfTrue);
    if (!SUCCEEDED(hr)) {...}
}
else {...}
```

## See also

[WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings)