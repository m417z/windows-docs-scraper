# IWDFIoRequest::SetCompletionCallback

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **SetCompletionCallback** method registers the interface for the [OnCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackrequestcompletion-oncompletion) method that the framework should call when an I/O request completes.

## Parameters

### `pCompletionCallback` [in]

A pointer to the [IRequestCallbackRequestCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-irequestcallbackrequestcompletion) interface whose [OnCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackrequestcompletion-oncompletion) method the framework calls after the I/O request completes. Beginning with version 1.9 of UMDF, the driver can specify **NULL** to deregister a previously registered **OnCompletion** method.

### `pContext` [in, optional]

A pointer to a buffer that contains context information that is related to the request completion. The framework passes this context information in a call to the [IRequestCallbackRequestCompletion::OnCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackrequestcompletion-oncompletion) method. This parameter is optional and can be **NULL**.

## Remarks

If a driver that forwards an I/O request requires notification when the lower-level driver completes the request, the driver can provide a completion routine and call **SetCompletionCallback** to register the [IRequestCallbackRequestCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-irequestcallbackrequestcompletion) interface for the completion routine. The framework calls the completion routine after the lower-level driver completes the I/O request.

#### Examples

For a code example of how to use the **SetCompletionCallback** method, see [IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send).

## See also

[IRequestCallbackRequestCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-irequestcallbackrequestcompletion)

[IRequestCallbackRequestCompletion::OnCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackrequestcompletion-oncompletion)

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send)