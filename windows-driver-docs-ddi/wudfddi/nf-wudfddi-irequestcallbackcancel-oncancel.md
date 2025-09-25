# IRequestCallbackCancel::OnCancel

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnCancel** method is called when an application cancels an I/O operation through the Microsoft Win32 **CancelIo**, **CancelIoEx**, or **CancelSynchronousIo** function.

## Parameters

### `pWdfRequest` [in]

A pointer to the [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest) interface that represents the framework request object to cancel.

## Remarks

The framework calls the **OnCancel** method to cancel the I/O request that the *pWdfRequest* parameter identifies. The driver should first determine whether it can cancel the I/O request. If the request can be canceled, the driver should cancel it. For more information about how to cancel a request, see [Canceling I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests).

If the driver cancels the request, the driver must also complete the request by calling the [IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete) method with the *CompletionStatus* parameter set to HRESULT_FROM_WIN32(ERROR_OPERATION_ABORTED).

The framework does not call **OnCancel** to cancel a request unless the driver previously called the [IWDFIoRequest::MarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-markcancelable) method to enable cancellation of the request and to register the [IRequestCallbackCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-irequestcallbackcancel) interface.

The User-Mode Driver Framework (UMDF) allows only one **OnCancel** method per queue. Therefore, when a driver calls [IWDFIoRequest::MarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-markcancelable) for requests that are associated with a particular queue to enable the framework to cancel those requests, the driver must pass a pointer to the [IRequestCallbackCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-irequestcallbackcancel) interface for the same request-callback object. Later, to cancel each request, the framework passes a pointer to the [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest) interface for the request in a call to this request-callback object's **OnCancel** method.

## See also

[IRequestCallbackCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-irequestcallbackcancel)

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete)

[IWDFIoRequest::MarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-markcancelable)