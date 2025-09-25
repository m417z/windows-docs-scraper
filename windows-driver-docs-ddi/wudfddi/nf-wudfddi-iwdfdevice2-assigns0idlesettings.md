# IWDFDevice2::AssignS0IdleSettings

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **AssignS0IdleSettings** method provides driver-supplied information that the framework uses when a device is idle and the system is in its working (S0) state.

## Parameters

### `IdleCaps` [in]

A [WDF_POWER_POLICY_S0_IDLE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_policy_s0_idle_capabilities)-typed enumerator that identifies the device's ability to wake itself after it is set to a low-power state, while the system remains in its working (S0) state.

### `DxState` [in]

A [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state)-typed enumerator that identifies the low [device power state](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states) that the device will enter after the idle timeout period ends. DEVICE_POWER_STATE values are defined in wdm.h.

### `IdleTimeout` [in]

The amount of time, in milliseconds, that the device will remain idle before the framework places it in the *DxState*-supplied low-power state. To use the framework's default idle timeout value, specify **IdleTimeoutDefaultValue** For more information, see the Remarks section.

### `UserControlOfIdleSettings` [in]

A [WDF_POWER_POLICY_S0_IDLE_USER_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_policy_s0_idle_user_control)-typed enumerator that indicates whether users have the ability to modify the device's idle settings.

### `Enabled` [in]

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed enumerator that indicates whether the device will be powered down if it remains idle and while the system power is at S0. This member can have one of the following values:

**WdfTrue** - Powering down is enabled.

**WdfFalse** - Powering down is disabled.

**WdfUseDefault** - Powering down is initially enabled by default; but if the *UserControlOfIdleSettings* parameter is set to **IdleAllowUserControl**, the [user's setting or driver's INF file](https://learn.microsoft.com/windows-hardware/drivers/wdf/user-control-of-device-idle-and-wake-behavior) overrides the initial value.

If powering down is enabled, the device has a wake-up capability, and the idle timeout value expires, the framework calls the driver's [IPowerPolicyCallbackWakeFromS0::OnArmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefroms0-onarmwakefroms0) callback function before the device enters a low-power state.

## Return value

**AssignS0IdleSettings** returns S_OK if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The caller specified an invalid value for an input parameter. |
| **HRESULT_FROM_NT(STATUS_INVALID_DEVICE_REQUEST)** | The calling driver is not the device's [power policy owner](https://learn.microsoft.com/windows-hardware/drivers/wdf/power-policy-ownership-in-umdf). |
| **HRESULT_FROM_NT(STATUS_POWER_STATE_INVALID)** | The *DxState* parameter specifies an invalid device power state, or the *IdleCaps* parameter indicates the device can wake itself, but the bus driver indicates the device cannot wake itself. |

This method might return one of the other values that Winerror.h contains.

## Remarks

The first time a driver calls **AssignS0IdleSettings**, the following actions occur:

* The framework stores the values of all parameters.
* If the *UserControlOfIdleSettings* parameter is set to **IdleAllowUserControl** and if the *Enabled* parameter is set to **WdfUseDefault**, the framework reads the registry to find out if the user has enabled powering down the device when it is idle.

During subsequent calls to **AssignS0IdleSettings**, the framework only stores the values of the *DxState*, *IdleTimeout*, and *Enabled* parameters. Also, the framework stores the value of the *IdleCaps* parameter subject to the following rules:

* If the driver has ever specified **IdleCanWakeFromS0** for the *IdleCaps* parameter's value in a previous call to **AssignS0IdleSettings**, it cannot subsequently change that value to **IdleUsbSelectiveSuspend**.
* If the driver has ever specified **IdleUsbSelectiveSuspend** for the *IdleCaps* parameter's value in a previous call to **AssignS0IdleSettings**, it cannot subsequently change that value to **IdleCanWakeFromS0**.

The following rules apply to the value that you specify for the *DxState* parameter:

* The value cannot be **PowerDeviceD0**.
* For USB devices, the value cannot be **PowerDeviceD0** or **PowerDeviceD3**.
* If you specify **DevicePowerMaximum**, the framework uses the value that the kernel-mode driver for the device's bus supplied in the **DeviceWake** member of its [WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities) structure.
* If the value of the *IdleCaps* parameter is **IdleCanWakeFromS0** or **IdleUsbSelectiveSuspend**, you cannot specify a device power state that is lower than the device power state in the **DeviceWake** member of the kernel-mode bus driver's [WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities) structure. (In other words, if the bus driver's **DeviceWake** value is **PowerDeviceD2**, your function driver's *DxState* value cannot be **PowerDeviceD3**.)

If you specify **IdleTimeoutDefaultValue** for the *IdleTimeout* parameter, the timeout defaults to five seconds. You can examine the output from the [!wudfext.wudfdevice](https://learn.microsoft.com/windows-hardware/drivers/debugger/-wudfext-wudfdevice) and [!wudfext.umdevstacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/-wudfext-umdevstacks) debugger extensions to see the effective settings and power references.

For information about registry entries that control a device's idle capabilities, see [User Control of Device Idle and Wake Behavior in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/user-control-of-device-idle-and-wake-behavior-in-umdf).

For more information about supporting a device's idle capabilities, see [Supporting Idle Power-Down in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-idle-power-down-in-umdf-drivers).

#### Examples

The following code example is based on the UMDF version of the toaster sample. The example obtains the [IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2) interface and then calls **AssignS0IdleSettings**.

```
    IWDFDevice2 *pIWDFDevice2 = NULL;
    HRESULT hr;

    //
    // Get a pointer to the IWDFDevice2 interface.
    //
    hr = pIWDFDevice->QueryInterface(__uuidof(IWDFDevice2),
                                     (void**) &pIWDFDevice2);
    if (SUCCEEDED(hr))
    {
    //
    // The toaster device is virtual, so we tell the framework that the
    // device cannot wake if it sleeps while the system is in S0. The device
    // can return to D0 only when the driver stack receives an I/O request.
    //
    hr = pIWDFDevice2->AssignS0IdleSettings(IdleCannotWakeFromS0,
                                            PowerDeviceD3,
                                            IDLEWAKE_TIMEOUT_MSEC,
                                            IdleAllowUserControl,
                                            WdfTrue);
    }
...
    SAFE_RELEASE(pIWDFDevice2);
```

## See also

[IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2)

[IWDFDevice2::AssignSxWakeSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-assignsxwakesettings)

[IWDFDevice3::AssignS0IdleSettingsEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-assigns0idlesettingsex)