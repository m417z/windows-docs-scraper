# IWDFDevice3::AssignS0IdleSettingsEx

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The
**AssignS0IdleSettingsEx** method provides driver-supplied information that the framework uses when a device is idle and the system is in its working (S0) state.

## Parameters

### `IdleSettings` [in]

A pointer to a [WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wudf_device_power_policy_idle_settings) structure that was initialized by a call to the [WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfdevice/nf-wudfdevice-wudf_device_power_policy_idle_settings_init) macro.

## Return value

The method returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

A driver can call **AssignS0IdleSettingsEx** at any point after the driver calls [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice). Before calling **IWDFDriver::CreateDevice**, the driver must call [IWDFDeviceInitialize::SetPowerPolicyOwnership](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-setpowerpolicyownership) with the *fTrue* parameter set to **TRUE**. For an example of this call sequence, see [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice).

If your driver calls **AssignS0IdleSettingsEx** more than once, follow the rules described in the Remarks section of [AssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-assigns0idlesettings).

For more information about idle power-down, see [Supporting Idle Power-Down in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-idle-power-down-in-umdf-drivers).

#### Examples

The following code example initializes a [WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wudf_device_power_policy_idle_settings) structure and sets an idle time-out value of 10 seconds. The example then obtains the [IWDFDevice3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice3) interface and calls **AssignS0IdleSettingsEx**.

```
IWDFDevice3 *pIWDFDevice3 = NULL;
HRESULT hr;

WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS  idleSettings;

WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT(
                                           &idleSettings,
                                           IdleCanWakeFromS0
                                           );
idleSettings.IdleTimeout = 10000;

//
// Get a pointer to the IWDFDevice3 interface.
//

hr = pIWDFDevice->QueryInterface(__uuidof(IWDFDevice3),
                                 (void**) &pIWDFDevice3);
if (SUCCEEDED(hr))
   {

   hr = pIWDFDevice3->AssignS0IdleSettingsEx(&idleSettings
                                            );
   }
...

SAFE_RELEASE(pIWDFDevice3);

```

## See also

[IWDFDevice2::AssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-assigns0idlesettings)

[IWDFDevice3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice3)

[WdfDeviceAssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigns0idlesettings)