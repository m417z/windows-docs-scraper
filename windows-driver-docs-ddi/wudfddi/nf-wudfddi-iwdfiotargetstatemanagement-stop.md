# IWDFIoTargetStateManagement::Stop

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Stop** method stops sending queued requests to a [local I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets-in-umdf).

## Parameters

### `Action` [in]

A [WDF_IO_TARGET_SENT_IO_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_sent_io_action)-typed value that identifies how to handle sent I/O when the I/O target object is stopped.

## Return value

**Stop** always returns S_OK.

## Remarks

If your driver can detect recoverable device errors, you might want your driver to call **Stop** to temporarily stop sending requests to the local I/O target, then later call [IWDFIoTargetStateManagement::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-start) to resume sending requests.

Additionally, if a driver calls [IWDFUsbTargetPipe2::ConfigureContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe2-configurecontinuousreader) to configure a continuous reader for a USB pipe, the driver's [IPnpCallback::OnD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0exit) callback function must call **Stop** to stop the reader.

If a driver has called **Stop**, it can still send a request to the target by setting the WDF_REQUEST_OPTION_IGNORE_TARGET_STATE flag when it calls [IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send). If a driver sets this flag, the driver can send a request, such as a request to reset a USB pipe (see [IWDFUsbTargetPipe::Reset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe-reset)), to a device after the driver has called **Stop**.

Your driver must call [IWDFIoTargetStateManagement::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-start) and **Stop** synchronously. After the driver calls one of these functions, it must not call either function before the first call returns.

Your driver can call **Stop** multiple times without calling [IWDFIoTargetStateManagement::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-start). For example, your driver might do the following:

1. Call **Stop** and specify an *Action* value of **WdfIoTargetLeaveSentIoPending**.
2. Determine whether the target should resume processing I/O requests.
3. If the target should resume, call [IWDFIoTargetStateManagement::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-start). Otherwise, call **Stop** again with an *Action* value of **WdfIoTargetCancelSentIo**.

For more information about **Stop**, see [Controlling a General I/O Target's State](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets-in-umdf).

#### Examples

The following code example shows how an [IPnpCallback::OnD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0exit) callback function can call **Stop**, if the driver uses a continuous reader for a USB pipe. (To see how to obtain the [IWDFIoTargetStateManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotargetstatemanagement) interface, see the code example at [IWDFIoTargetStateManagement::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-start).)

```
HRESULT
CMyDevice::OnD0Exit(
    __in IWDFDevice*  pWdfDevice,
    __in WDF_POWER_DEVICE_STATE  previousState
    )
{
    HRESULT hr;
    hr = m_pIoTargetInterruptPipeStateMgmt->Stop(WdfIoTargetCancelSentIo);
    return hr;
}
```

## See also

[IWDFIoTargetStateManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotargetstatemanagement)

[IWDFRemoteTarget::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-stop)