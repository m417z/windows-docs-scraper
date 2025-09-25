# IWDFDevice2::AssignSxWakeSettings

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **AssignSxWakeSettings** method provides driver-supplied information about a device's ability to trigger a wake signal while both the device and the system are in a low-power state.

## Parameters

### `DxState` [in]

A [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state)-typed enumerator that identifies the low [device power state](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states) that the device will enter when the system power state drops to a wakeable low-power state. The value of *DxState* cannot be **PowerDeviceD0**. DEVICE_POWER_STATE values are defined in wdm.h.

### `UserControlOfWakeSettings` [in]

A [WDF_POWER_POLICY_SX_WAKE_USER_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_policy_sx_wake_user_control)-typed enumerator that indicates whether users have the ability to modify the device's wake settings.

### `Enabled` [in]

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed enumerator that indicates whether the device can wake the system (that is, restore the system to S0) when the system is in a low-power state. This member can have one of the following values:

**WdfTrue** - Waking the system is enabled.

**WdfFalse** - Waking the system is disabled.

**WdfUseDefault** - Waking the system is initially enabled by default; but if the **UserControlOfWakeSettings** member is set to **WakeAllowUserControl**, the [user's setting or driver's INF file](https://learn.microsoft.com/windows-hardware/drivers/wdf/user-control-of-device-idle-and-wake-behavior) overrides the initial value.

If waking the system is enabled and the system is about to enter a low-power state, the framework calls the driver's [IPowerPolicyCallbackWakeFromSx::OnArmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefromsx-onarmwakefromsx) callback function before the device enters a low-power state.

## Return value

**AssignSxWakeSettings** returns S_OK if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The caller specified an invalid value for an input parameter. |
| **HRESULT_FROM_NT(STATUS_INVALID_DEVICE_REQUEST)** | The calling driver is not the device's [power policy owner](https://learn.microsoft.com/windows-hardware/drivers/wdf/power-policy-ownership-in-umdf). |
| **HRESULT_FROM_NT(STATUS_POWER_STATE_INVALID)** | The *DxState* parameter specifies an invalid device power state, or the bus driver indicates that the device cannot trigger a wake signal, |

This method might return one of the other values that Winerror.h contains.

## Remarks

The first time a driver calls **AssignSxWakeSettings**, the following actions occur:

* The framework stores the parameter values.
* If the *UserControlOfWakeSettings* parameter is set to **WakeAllowUserControl** and if the *Enabled* parameter is set to **WdfUseDefault**, the framework reads the registry to find out if the user has enabled waking the system.

During subsequent calls to **AssignSxWakeSettings**, the framework does not store the value of the *UserControlOfWakeSettings* parameter. In other words, the framework performs the following steps the first time the driver calls **AssignSxWakeSettings** but not during later calls:

* Stores the value of the *UserControlOfWakeSettings* parameter.
* Looks for a user setting in the registry, if the value of the *Enabled* parameter is **WdfUseDefault**.

The following rules apply to the value that you specify for the *DxState* parameter:

* The value cannot be **PowerDeviceD0**.
* If you specify **DevicePowerMaximum**, the framework uses the value that the kernel-mode driver for the device's bus supplied in the **DeviceWake** member of its [WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities) structure.
* You cannot specify a device power state that is lower than the device power state in the **DeviceWake** member of the kernel-mode bus driver's [WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities) structure. (In other words, if the bus driver's **DeviceWake** value is **PowerDeviceD2**, your function driver's *DxState* value cannot be **PowerDeviceD3**.)

For information about registry entries that control a device's wake capabilities, see [User Control of Device Idle and Wake Behavior in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/user-control-of-device-idle-and-wake-behavior-in-umdf).

For more information about supporting a device's wake capabilities, see [Supporting System Wake-Up in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-wake-up-in-umdf-drivers).

The following code example obtains the [IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2) interface and then calls **AssignSxWakeSettings**.

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
        hr = pIWDFDevice2->AssignSxWakeSettings(PowerDeviceMaximum,
                                                WakeAllowUserControl,
                                                WdfUseDefault);
    }
...
    SAFE_RELEASE(pIWDFDevice2);
```

## See also

[IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2)

[IWDFDevice2::AssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-assigns0idlesettings)