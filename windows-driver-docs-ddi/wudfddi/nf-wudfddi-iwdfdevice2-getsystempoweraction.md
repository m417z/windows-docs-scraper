# IWDFDevice2::GetSystemPowerAction

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetSystemPowerAction** method returns the [system power action](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-power-actions), if any, that is currently occurring for the computer.

## Return value

**GetSystemPowerAction** returns a [POWER_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-power_action)-typed enumerator value. The value indicates the [system power action](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-power-actions) that is currently occurring for the computer. For more information, see the following Remarks section.

## Remarks

The **GetSystemPowerAction** method enables a driver to determine whether a device's power transition is occurring because the device is idle (or waking up), or because the entire computer is entering (or leaving) a low-power state.

The driver must call **GetSystemPowerAction** only from the event callback functions that the framework calls when the device is [entering a low-power state](https://learn.microsoft.com/windows-hardware/drivers/wdf/a-device-enters-a-low-power-state) or [returning to its working state](https://learn.microsoft.com/windows-hardware/drivers/wdf/a-device-returns-to-its-working-state).

The value that **GetSystemPowerAction** returns depends on the following situations:

* If the computer is entering a low-power state when the driver calls **GetSystemPowerAction**, the method returns the reason that the computer is entering the low-power state. For example, the method returns **PowerActionSleep** if the computer is entering its S1, S2, or S3 low-power state.
* If the computer is returning to its working (S0) state from a low-power state when the driver calls **GetSystemPowerAction**, the method returns the reason that the computer entered the low-power state. For example, the method returns **PowerActionSleep** if the computer is leaving its S1, S2, or S3 low-power state.
* If the computer is powering up (after having been turned off) when the driver calls **GetSystemPowerAction**, the method returns **PowerActionNone**.
* If the device is entering a low-power idle state or returning to its working (D0) state when the driver calls **GetSystemPowerAction**, while the rest of the system remains at its working (S0) state, the method returns **PowerActionNone**.
* If the computer and the device are both in their working states when the driver calls **GetSystemPowerAction**, the method returns **PowerActionNone**.

For more information about low-power states, see [A Device Enters a Low-Power State](https://learn.microsoft.com/windows-hardware/drivers/wdf/a-device-enters-a-low-power-state).

#### Examples

The following code example obtains the [IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2) interface and then calls **GetSystemPowerAction**.

```
   IWDFDevice2 *pDevice2 = NULL;
    HRESULT hrQI = pDevice->QueryInterface(IID_PPV_ARGS(&pDevice2));
    if (SUCCEEDED(hrQI))
    {
        POWER_ACTION powerAction = pDevice2->GetSystemPowerAction();
    }
...
    SAFE_RELEASE(pDevice2);
```

## See also

[IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2)