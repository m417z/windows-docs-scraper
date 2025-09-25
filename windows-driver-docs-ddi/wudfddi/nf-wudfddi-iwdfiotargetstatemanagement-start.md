# IWDFIoTargetStateManagement::Start

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Start** method starts sending queued requests to a [local I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets-in-umdf).

## Return value

**Start** returns S_OK if the operation succeeds. Otherwise, this method might return one of the error codes:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_NT (STATUS_INVALID_DEVICE_STATE)** | The device has been removed. |

This method might return one of the other error codes that Winerror.h defines.

## Remarks

If your driver can detect recoverable device errors, you might want your driver to call [IWDFIoTargetStateManagement::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-stop) to temporarily stop sending requests to the local I/O target, then later call **Start** to resume sending requests.

Additionally, if a driver calls [IWDFUsbTargetPipe2::ConfigureContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe2-configurecontinuousreader) to configure a continuous reader for a USB pipe, the driver's [IPnpCallback::OnD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0entry) callback function must call **Start** to start the reader.

Your driver must call **Start** and [IWDFIoTargetStateManagement::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-stop) synchronously. After the driver calls one of these functions, it must not call the other function before the first one returns.

For more information about **Start**, see [Controlling a General I/O Target's State in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state-in-umdf).

For more information about I/O targets, see [Using I/O Targets in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets-in-umdf).

#### Examples

The following code example first shows how a driver can obtain the [IWDFIoTargetStateManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotargetstatemanagement) interface for a USB pipe object. The code example then shows how an [IPnpCallback::OnD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0entry) callback function can call **Start**, if the driver uses a continuous reader for the USB pipe.

```

    IWDFIoTargetStateManagement * m_pIoTargetInterruptPipeStateMgmt = NULL;

    IWDFUsbTargetFactory *  pIUsbTargetFactory = NULL;
    IWDFUsbTargetDevice *   pIUsbTargetDevice = NULL;
    IWDFUsbInterface *      pIUsbInterface = NULL;
    IWDFUsbTargetPipe *     pIUsbPipe = NULL;

    hr = m_FxDevice->QueryInterface(IID_PPV_ARGS(&pIUsbTargetFactory));
    if (FAILED(hr))
    {...}
    hr = pIUsbTargetFactory->CreateUsbTargetDevice(&pIUsbTargetDevice);
    if (FAILED(hr))
    {...}
    hr = pIUsbTargetDevice->RetrieveUsbInterface(0, &pIUsbInterface);
    if (FAILED(hr))
    {...}
    NumEndPoints = pIUsbInterface->GetNumEndPoints();
    for (UCHAR PipeIndex = 0; PipeIndex < NumEndPoints; PipeIndex++)
    {
        hr = pIUsbInterface->RetrieveUsbPipeObject(PipeIndex, &pIUsbPipe);
        if (FAILED(hr))
        {...}
        else
        {
            if (pIUsbPipe->IsInEndPoint())
            {
                if (UsbdPipeTypeInterrupt == pIUsbPipe->GetType())
                {
                    m_pIUsbInterruptPipe = pIUsbPipe;
                    hr = m_pIUsbInterruptPipe->QueryInterface(IID_PPV_ARGS(&m_pIoTargetInterruptPipeStateMgmt));
                    if (FAILED(hr))
                    {...}
                }
            }
        }
    }

HRESULT
CMyDevice::OnD0Entry(
    __in IWDFDevice*  pWdfDevice,
    __in WDF_POWER_DEVICE_STATE  previousState
    )
{
...
    m_pIoTargetInterruptPipeStateMgmt->Start();
...
    return S_OK;
}
```

## See also

[IWDFIoTargetStateManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotargetstatemanagement)

[IWDFRemoteTarget::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-stop)