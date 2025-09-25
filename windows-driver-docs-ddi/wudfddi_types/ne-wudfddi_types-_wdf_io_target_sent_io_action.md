# _WDF_IO_TARGET_SENT_IO_ACTION enumeration (wudfddi_types.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WDF_IO_TARGET_SENT_IO_ACTION** enumeration identifies the actions that the framework can take when a driver calls [IWDFIoTargetStateManagement::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-stop) or [IWDFRemoteTarget::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-stop) to stop an I/O target.

## Constants

### `WdfIoTargetSentIoUndefined`

Reserved for system use.

### `WdfIoTargetCancelSentIo`

Before the framework stops the I/O target, it will attempt to cancel I/O requests that are in the I/O target's queue. The framework cancels all of the target queue's I/O requests before [IWDFIoTargetStateManagement::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-stop) or [IWDFRemoteTarget::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-stop) returns.

### `WdfIoTargetWaitForSentIoToComplete`

Before the framework stops the I/O target, it will wait for I/O requests that are in the I/O target's queue to be completed. The framework completes all of the target queue's I/O requests, and calls each request's [IRequestCallbackRequestCompletion::OnCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackrequestcompletion-oncompletion) callback function, before [IWDFIoTargetStateManagement::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-stop) or [IWDFRemoteTarget::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-stop) returns.

### `WdfIoTargetLeaveSentIoPending`

The framework will leave I/O requests in the I/O target's queue. The requests remain in the target's queue until the driver calls [IWDFIoTargetStateManagement::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-start) or [IWDFRemoteTarget::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-start) or the device is removed.

### `WdfIoTargetSentIoMaximum`

Valid enumeration values were exceeded.

## Remarks

The **WDF_IO_TARGET_SENT_IO_ACTION** enumeration is used as an input parameter to the [IWDFIoTargetStateManagement::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-stop) and [IWDFRemoteTarget::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-stop) methods.

If your driver specifies the **WdfIoTargetWaitForSentIoToComplete** flag, the driver must not call [IWDFIoTargetStateManagement::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotargetstatemanagement-stop) or [IWDFRemoteTarget::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-stop) from a request handler, an [IRequestCallbackRequestCompletion::OnCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackrequestcompletion-oncompletion) callback function, or an [IUsbTargetPipeContinuousReaderCallbackReadersFailed::OnReaderFailure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iusbtargetpipecontinuousreadercallbackreadersfailed-onreaderfailure) callback function.

For the KMDF version of this enumeration, see [WDF_IO_TARGET_SENT_IO_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_sent_io_action).

## See also

[WDF_IO_TARGET_SENT_IO_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_sent_io_action)