# IWDFDevice2::ResumeIdle

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **ResumeIdle** method informs the framework that the device is not in use and can be placed in a device low-power state if it remains idle.

## Remarks

Every call to [IWDFDevice2::StopIdle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-stopidle) must eventually be followed by a call to **ResumeIdle**, or else the device will never return to a low-power state if it again becomes idle.

For more information about [StopIdle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-stopidle) and **ResumeIdle**, see [Supporting Idle Power-Down in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-idle-power-down-in-umdf-drivers).

#### Examples

The following code example obtains the [IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2) interface and then calls **ResumeIdle**.

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
    pIWDFDevice2->ResumeIdle();
    }
...
    SAFE_RELEASE(pIWDFDevice2);
```

## See also

[IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2)

[IWDFDevice2::StopIdle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-stopidle)