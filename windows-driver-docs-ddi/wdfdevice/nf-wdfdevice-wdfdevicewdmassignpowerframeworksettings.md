# WdfDeviceWdmAssignPowerFrameworkSettings function

## Description

[Applies to KMDF and UMDF]

 The **WdfDeviceWdmAssignPowerFrameworkSettings** method registers power management framework (PoFx) settings for single-component devices.

## Parameters

### `Device` [in]

A handle to the framework device object for which PoFx settings are being specified.

### `PowerFrameworkSettings` [in]

A pointer to a [WDF_POWER_FRAMEWORK_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_power_framework_settings) structure that describes the client driver’s PoFx settings.

## Return value

The **WdfDeviceWdmAssignPowerFrameworkSettings** method returns an NTSTATUS value that indicates success or failure of the operation.

| Return code | Description |
| --- | --- |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the [WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_wake_settings) structure is incorrect. |
| **STATUS_INVALID_DEVICE_REQUEST** | The calling driver is not the device's power policy owner. |
| **STATUS_INVALID_PARAMETER** | An invalid *Settings* value is detected. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **WdfDeviceWdmAssignPowerFrameworkSettings** method applies only to single-component devices.

Before calling this method, the client driver must first successfully call [WdfDeviceAssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigns0idlesettings) and set the **IdleTimeoutType** field of the [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) structure to **SystemManagedIdleTimeout** or **SystemManagedIdleTimeoutWithHint**.

A driver must call **WdfDeviceWdmAssignPowerFrameworkSettings** before or during the first time a device starts. Because a device can start more than once, for example if resource rebalancing occurs, a driver might call this method from within [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) or [EvtDeviceSelfManagedIoInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_init). The framework calls these functions only once, even if the device is started more than once.

Alternatively, the driver could keep track of whether it has already called **WdfDeviceWdmAssignPowerFrameworkSettings**, and call it from one of the following callback functions: [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware), [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry), [EvtDeviceD0EntryPostInterruptsEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry_post_interrupts_enabled), or [EvtDeviceSelfManagedIoRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_restart).

If your driver calls **WdfDeviceWdmAssignPowerFrameworkSettings** more than once, the framework generates a verifier error.

The power management framework (PoFx) is available only on Windows 8 and later. When running on an operating system that does not support PoFx, **WdfDeviceWdmAssignPowerFrameworkSettings** takes no action and returns STATUS_SUCCESS.

For more information, see [Supporting Functional Power States](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-functional-power-states) and [Overview of the Power Management Framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework).

#### Examples

In the following code example, the driver initializes a [WDF_POWER_FRAMEWORK_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_power_framework_settings) structure by calling the [WDF_POWER_FRAMEWORK_SETTINGS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_power_framework_settings_init) function. The driver then manually sets some of the members of the structure, and then calls **WdfDeviceWdmAssignPowerFrameworkSettings**.

```cpp
NTSTATUS status;
WDF_POWER_FRAMEWORK_SETTINGS poFxSettings;

WDF_POWER_FRAMEWORK_SETTINGS_INIT(&poFxSettings);

poFxSettings.EvtDeviceWdmPostPoFxRegisterDevice =
                        SingleCompWdmEvtDeviceWdmPostPoFxRegisterDevice;
poFxSettings.EvtDeviceWdmPrePoFxUnregisterDevice =
                        SingleCompWdmEvtDeviceWdmPrePoFxUnregisterDevice;

poFxSettings.Component = &component;
poFxSettings.ComponentIdleStateCallback =
                        SingleCompWdmIdleStateCallback;
poFxSettings.PoFxDeviceContext = (PVOID) Device;

status = WdfDeviceWdmAssignPowerFrameworkSettings(Device, &poFxSettings);
```

## See also

[EvtDeviceWdmPostPoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_post_po_fx_register_device)

[EvtDeviceWdmPrePoFxUnregisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_pre_po_fx_unregister_device)

[WDF_POWER_FRAMEWORK_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_power_framework_settings)

[WDF_POWER_FRAMEWORK_SETTINGS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_power_framework_settings_init)