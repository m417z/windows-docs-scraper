# IWDFDevice2::StopIdle

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **StopIdle** method informs the framework that the device must be placed in its working (D0) power state.

## Parameters

### `WaitForD0` [in]

A Boolean value that indicates when **StopIdle** will return. If **TRUE**, it returns only after the specified device enters the D0 device power state. If **FALSE**, the method returns immediately.

## Return value

**StopIdle** returns S_OK if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_NT(STATUS_INVALID_DEVICE_REQUEST)** | The calling driver is not the device's [power policy owner](https://learn.microsoft.com/windows-hardware/drivers/wdf/power-policy-ownership-in-umdf). |
| **HRESULT_FROM_NT(STATUS_PENDING)** | The device was already returning to its working state. |
| **HRESULT_FROM_NT(STATUS_POWER_STATE_INVALID)** | A device failure occurred and the device cannot enter its D0 power state. |

This method might return one of the other values that Winerror.h contains.

## Remarks

If your device can enter a low-power state when it becomes idle, your driver might have to occasionally call **StopIdle** to bring the device back to its working (D0) state or to prevent it from entering a low-power state.

Your driver does not have to call **StopIdle** when a device is idle and the framework places an I/O request in the device's power-managed I/O queue. Additionally, your driver does not have to call **StopIdle** when a device is idle and it detects a wake signal. In both of these cases, the framework requests the bus driver to restore the device's power state to D0.

Although drivers typically do not need to call **StopIdle** when handling I/O requests that they obtain from a power-managed I/O queue, the call is allowed. However, drivers must not set the *WaitForD0* parameter to **TRUE** when handling I/O requests from a power-managed I/O queue.

Your driver does have to call **StopIdle** if it must access the device because of a request that the driver has received outside of a power-managed I/O queue. For example, your driver might support a driver-defined interface or a WMI request that requires accessing the device. In this case, you must ensure that the device is in its working state before the driver accesses the device, and that the device remains in its working state until the driver has finished accessing the device.

Calling **StopIdle** forces the device into its working (D0) state, if the system is in its working (S0) state. The device remains in its working state until the driver calls [IWDFDevice2::ResumeIdle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-resumeidle), at which point the framework can place the device in a low-power state if it remains idle.

Do not call **StopIdle** before the framework has called the driver's [IPnpCallback::OnD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0entry) callback method for the first time.

A call to **StopIdle** can restore an idle device to its working state only if the system is in its working (S0) state. If the system is entering a low-power state when a driver calls **StopIdle** with the *WaitForD0* parameter set to **TRUE**, the function does not return until the system returns to its S0 state.

Every call to **StopIdle** must eventually be followed by a call to [ResumeIdle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-resumeidle), or else the device will never return to a low-power state if it again becomes idle. Calls to **StopIdle** can be nested, so the number of calls to **ResumeIdle** must be equal to the number of calls to **StopIdle**.

For more information about **StopIdle** and [ResumeIdle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-resumeidle), see [Supporting Idle Power-Down in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-idle-power-down-in-umdf-drivers).

#### Examples

The following code example obtains the [IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2) interface and then calls **StopIdle**. **StopIdle** will return after the device enters the D0 device power state.

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
        hr = pIWDFDevice2->StopIdle(TRUE);
    }
...
   SAFE_RELEASE(pIWDFDevice2);
```

## See also

[IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2)

[IWDFDevice2::ResumeIdle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-resumeidle)