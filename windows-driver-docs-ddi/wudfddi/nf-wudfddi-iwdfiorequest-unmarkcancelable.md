# IWDFIoRequest::UnmarkCancelable

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **UnmarkCancelable** method disables the canceling of an I/O request.

## Return value

**UnmarkCancelable** returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | [UnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-unmarkcancelable) disabled use of the [IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel) method that was previously registered through a call to the [IWDFIoRequest::MarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-markcancelable) method. |
| **HRESULT_FROM_WIN32 (ERROR_OPERATION_ABORTED)** | The request is currently being canceled. |

## Remarks

A driver can call **IWDFIoRequest::UnmarkCancelable** to disable cancellation of an I/O request, if the driver previously called [IWDFIoRequest::MarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-markcancelable) to enable cancellation of the request.

If the driver previously called [MarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-markcancelable), the driver must call **UnmarkCancelable** before calling [IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete) outside of a call to its [IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel) callback method.

However, the driver must not call **UnmarkCancelable** after [OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel) calls [Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterextensionrequest-complete).

If **UnmarkCancelable** returns HRESULT_FROM_WIN32(ERROR_OPERATION_ABORTED), and then [OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel) completes the request, the driver must not subsequently use the request object.

If **UnmarkCancelable** returns HRESULT_FROM_WIN32(ERROR_OPERATION_ABORTED), the driver must not complete the request before the framework calls [OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel). Otherwise, the framework might call the driver's **OnCancel** with an invalid request.

#### Examples

The following code example demonstrates how a driver might call **IWDFIoRequest::UnmarkCancelable** before calling [IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete), outside of a call to its [IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel) method.

The example also shows how you can use [OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel) to expedite the completion of a request. In this case, the **OnCancel** callback does not always complete/cancel the specified request.

```
//
// The driver calls CompletePendingRequest when it is ready to complete the request with error/success.
// You must previously initialize m_CompleteCancelledRequest to zero.
//
VOID
CompletePendingRequest(
    HRESULT hr,
    DWORD   information
    )
{
    LONG shouldComplete = 1;

    if (m_PendingRequest) {
        HRESULT hrUnmark = m_PendingRequest->UnmarkCancelable();
        if (HRESULT_FROM_WIN32(ERROR_OPERATION_ABORTED) == hrUnmark) {
            //
            // We are racing with OnCancel.  We cannot complete m_PendingRequest until after
            // both IWDFIoRequest::Complete and OnCancel have finished with it. To
            // guarantee this, the last to run (either OnCancel or CompletePendingRequest) will
            // be the one to complete the request.
            //
            shouldComplete = InterlockedExchange(&m_CompleteCancelledRequest, 1);
        }

        //
        // If we were first to set m_CompleteCancelledRequest to 1, then drop out here
        // and rely on OnCancel to complete the request.
        //

        if (1 == shouldComplete) {
            IWDFIoRequest *FxRequest = (IWDFIoRequest*)InterlockedExchangePointer((PVOID *)&m_PendingRequest, NULL);
            InterlockedExchange(&m_CompleteCancelledRequest, 0);
            FxRequest->SetInformation(information);
            FxRequest->Complete(hr);
        }
   }
}

//
// The framework calls OnCancel when an application cancels a pending I/O request.
//
VOID
STDMETHODCALLTYPE
OnCancel(
    _In_ IWDFIoRequest *pWdfRequest
    )
{
    if (m_PendingRequest != pWdfRequest) {
        TraceEvents(TRACE_LEVEL_ERROR,
                    YOURDEVICE_TRACE_DEVICE,
                    "%!FUNC! Cancelled request does not match pending request.");
    }

    //
    // Add your code to speed up the completion of the request.  Maybe you need to reset the hardware or
    // do some other domain-specific task.
    //

    //
    // Since we only complete the request if we were the last to run (see comment in
    // CompletePendingRequest), if we are *not* the last to run we rely on CompletePendingRequest
    // to complete this request.
    //

    LONG shouldComplete = InterlockedExchange(&m_CompleteCancelledRequest, 1);
    if (1 == shouldComplete) {
        //
        // Enter this block only if we are the last to run.
        // Otherwise, rely on CompletePendingRequest to complete this request.
        //
        (void*) InterlockedExchangePointer((PVOID *)&m_PendingRequest, NULL);
        InterlockedExchange(&m_CompleteCancelledRequest, 0);
        pWdfRequest->Complete(HRESULT_FROM_WIN32(ERROR_CANCELLED));
     }

}

```

In the next code example, the driver stores I/O requests in a driver-implemented queue object called **MyQueue**. The driver’s **MyQueue** interface implements some basic methods to manipulate the queue, such as **IsEmpty**, **RemoveHead**, **Cleanup**, **GetFirstNodePosition**, **GetAt**, and **RemoveAt**.

The driver also defines a **CommandInformation** structure that holds a single I/O request from **MyQueue**.

 The **MyQueue::DeQueue** method removes an I/O request from the queue, calls **UnmarkCancelable** to disable canceling of the request, and then returns the request for processing.

```

void MyQueue::DeQueue(__out CommandInformation* CommandInfo)
{
    CComCritSecLock<CComAutoCriticalSection> scopeLock(m_CriticalSection);

    if (NULL != CommandInfo)
    {
        for (;;)
        {
            if (TRUE == IsEmpty())
            {
                ZeroMemory(CommandInfo, sizeof(CommandInformation));
                break;
            }
            //
            // If queue is not empty, retrieve the first element from the list.
            //
            *CommandInfo = RemoveHead();
            if (HRESULT_FROM_WIN32(ERROR_OPERATION_ABORTED) != (CommandInfo->Request)->UnmarkCancelable())
            {
                //
                // UnmarkCancelable was successful.
                // Ownership of this request has been transferred back to this driver.
                //
                break;
            }
            else
            {
                //
                // If UMDF returns HRESULT_FROM_WIN32(ERROR_OPERATION_ABORTED) for UnmarkCancelable,
                // that means UMDF is planning on cancelling the request. However, since this call
                // popped the request off our internal queue, let’s cleanup the generic command object
                // and let OnCancel complete the request.
                //
                CommandInfo->Cleanup();
            }
        }
    }
}

//
// The framework calls OnCancel when an application cancels a dispatched I/O request.
//
void MyQueue::OnCancel(__in IWDFIoRequest* Request)
{
    {
        CComCritSecLock<CComAutoCriticalSection> scopeLock(m_CriticalSection);

        POSITION pos = GetFirstNodePosition();

        while (NULL != pos)
        {
            //
            // Find the request and remove it from our driver-implemented queue.
            //
            CommandInformation commandInfo = GetAt(pos);
            if (Request == commandInfo.Request)
            {
                RemoveAt(pos);
                commandInfo.Cleanup();
                break;
            }

            GetNext(pos);
        }
    }

    //
    // Cancel/Complete the request.
    //
    // The request might not be in the queue when the framework calls OnCancel.
    // This occurs if DeQueue receives HRESULT_FROM_WIN32(ERROR_OPERATION_ABORTED)
    // when it calls UnmarkCancelable for the request. In this case, as soon as
    // DeQueue releases the scopeLock, the framework calls OnCancel to cancel the request.
    //
    Request->Complete(HRESULT_FROM_WIN32(ERROR_CANCELLED));
}

```

Also see the code example on [WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable). While written for a KMDF driver, this example demonstrates how you can use the framework's [automatic synchronization](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-automatic-synchronization) to manage synchronization between the cancel callback and another thread that calls the *Unmark* routine.

## See also

[IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel)

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete)

[IWDFIoRequest::MarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-markcancelable)