# IWDFIoRequest2::IsCanceled

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **IsCanceled** method determines whether the I/O manager has attempted to cancel an I/O request.

## Return value

**IsCanceled** returns **TRUE** if the I/O manager has attempted to cancel the I/O request. This method returns **FALSE** for any of the following reasons:

* The I/O manager has not attempted to cancel the request.
* The calling driver does not own the request.
* The calling driver has called the [IWDFIoRequest::MarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-markcancelable) method.

## Remarks

If your driver has not called [IWDFIoRequest::MarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-markcancelable) to register an [IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel) callback function, but if you want your driver to determine if the I/O manager has attempted to cancel an I/O request, the driver can call **IsCanceled**.

A driver can call **IsCanceled** for a request only if the driver owns the I/O request. If the driver has called [IWDFIoRequest::MarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-markcancelable), it must call [IWDFIoRequest::UnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-unmarkcancelable) before calling **IsCanceled**.

If **IsCanceled** returns **TRUE**, your driver should cancel the request by calling [IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete) with the *CompletionStatus* parameter set to HRESULT_FROM_WIN32(ERROR_OPERATION_ABORTED).

For more information about **IsCanceled**, see [Canceling I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests).

#### Examples

In the following code example, if **IsCanceled** returns **TRUE**, the driver completes the I/O request by calling [IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete) with a completion status of HRESULT_FROM_WIN32(ERROR_OPERATION_ABORTED).

```
if (fxRequest2->IsCanceled())
{
    fxRequest2->Complete(HRESULT_FROM_WIN32(ERROR_OPERATION_ABORTED));
}
...
```

## See also

[IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel)

[IWDFIoRequest2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest2)

[IWDFIoRequest::MarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-markcancelable)

[IWDFIoRequest::UnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-unmarkcancelable)