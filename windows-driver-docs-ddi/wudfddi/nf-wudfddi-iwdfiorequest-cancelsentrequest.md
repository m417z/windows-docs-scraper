# IWDFIoRequest::CancelSentRequest

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CancelSentRequest** method attempts to cancel the I/O request that the driver previously submitted to an I/O target.

## Return value

**CancelSentRequest** returns a BOOL value that indicates whether the cancel request was successfully delivered to the request's owner. **TRUE** indicates the request was successfully delivered. **FALSE** indicates the request was not successfully delivered.

## Remarks

A driver can call **CancelSentRequest** to attempt to cancel the I/O request that it previously sent to an I/O target by calling the [IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send) method.

If the request is in the I/O target's queue, the framework cancels the request. If the framework already delivered the request to the I/O target's driver, and if that driver previously called [IWDFIoRequest::MarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-markcancelable) to enabling canceling, the framework calls that driver's [IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel) method. If the target's driver did not call **IWDFIoRequest::MarkCancelable**, the request is not canceled unless the request subsequently becomes cancelable.

If the driver previously registered the [IRequestCallbackRequestCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-irequestcallbackrequestcompletion) interface for the request's completion routine, the framework calls the completion routine after the request is canceled.

## See also

[IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel)

[IRequestCallbackRequestCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-irequestcallbackrequestcompletion)

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFIoRequest::MarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-markcancelable)

[IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send)