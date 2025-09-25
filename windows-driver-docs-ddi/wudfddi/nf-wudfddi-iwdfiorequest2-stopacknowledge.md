# IWDFIoRequest2::StopAcknowledge

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **StopAcknowledge** method informs the framework that the driver has stopped processing a specified I/O request.

## Parameters

### `Requeue` [in]

A Boolean value that, if **TRUE**, causes the framework to requeue the request into the queue so that the framework will deliver it to the driver again. If **FALSE**, the framework does not requeue the request. For more information, see the following Remarks section.

## Remarks

If a driver registers an [IQueueCallbackIoStop::OnIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackiostop-oniostop) callback function for an I/O queue, the framework calls it when the queue's underlying device is leaving its working (D0) state. The framework calls this callback function for every I/O request that the driver owns at the time when the queue is being stopped. The driver must complete, cancel, or postpone processing of each request by doing one of the following:

* If the driver owns the request, it can call [IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete) to complete or cancel the request.
* If the driver has forwarded the request to an I/O target, it can call [IWDFIoRequest::CancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-cancelsentrequest) to attempt to cancel the request.
* If the driver postpones processing the request, it must call **StopAcknowledge**.

If your driver calls **StopAcknowledge**, it must call this method from within its [IQueueCallbackIoStop::OnIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackiostop-oniostop) callback function.

If the driver does not call [IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete) or **StopAcknowledge** for every request that an [IQueueCallbackIoStop::OnIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackiostop-oniostop) callback function receives, the framework does not allow the device to leave its working (D0) state. Potentially, this inaction can prevent a system from entering its hibernation state or another low system power state.

When a driver's [IQueueCallbackIoStop::OnIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackiostop-oniostop) callback function calls **StopAcknowledge**, it can set the *Requeue* parameter to **TRUE** or **FALSE**:

* Setting *Requeue* to **TRUE** causes the framework to place the request back into its I/O queue.

  When the underlying device returns to its working (D0) state, the framework will redeliver the request to the driver.
* Setting *Requeue* to **FALSE** causes ownership of the request to remain with the driver. The driver must stop doing any I/O processing that requires hardware access.

  When the underlying device returns to its working (D0) state, the framework will call the driver's [IQueueCallbackIoResume::OnIoResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackioresume-onioresume) callback function, so that the driver can continue processing the request.

If the driver had previously called [IWDFIoRequest::MarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-markcancelable), it must call [IWDFIoRequest::UnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-unmarkcancelable) before calling **StopAcknowledge** with *Requeue* set to **TRUE**.

Before calling **StopAcknowledge**, the driver's [IQueueCallbackIoStop::OnIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackiostop-oniostop) callback function must stop all processing of the I/O request that requires accessing the underlying device, because the device is about to enter a low-power state.

#### Examples

The following code example is an [IQueueCallbackIoStop::OnIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackiostop-oniostop) callback function that checks to see if a received request is cancelable and, if it is, calls [IWDFIoRequest::UnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-unmarkcancelable). If **IWDFIoRequest::UnmarkCancelable** returns HRESULT_FROM_WIN32(ERROR_OPERATION_ABORTED), the example just returns because the driver's [IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel) callback function will handle the request. Otherwise, the example calls **StopAcknowledge** and specifies **FALSE** so that the framework will eventually call the driver's [IQueueCallbackIoResume::OnIoResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackioresume-onioresume) callback function.

```
void
CMyReadWriteQueue::OnIoStop(
    __in IWDFIoQueue*  pWdfQueue,
    __in IWDFIoRequest*  pWdfRequest,
    __in ULONG  ActionFlags
    )
{ HRESULT status;

    if (ActionFlags & WdfRequestStopRequestCancelable) {
        status = pWdfRequest->UnmarkCancelable();
        if (status == HRESULT_FROM_WIN32(ERROR_OPERATION_ABORTED)) {
        return;
        }
    }
    //
    // Declare an IWDFIoRequest2 interface pointer and obtain the
    // IWDFIoRequest2 interface from the IWDFIoRequest interface.
    //
    CComQIPtr<IWDFIoRequest2> r2 = pWdfRequest;

    r2->StopAcknowledge(FALSE);
}
```

## See also

[IQueueCallbackIoResume::OnIoResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackioresume-onioresume)

[IQueueCallbackIoStop::OnIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackiostop-oniostop)

[IWDFIoRequest2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest2)