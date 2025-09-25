# IRequestCallbackRequestCompletion::OnCompletion

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnCompletion** method completes the specified request.

## Parameters

### `pWdfRequest` [in]

A pointer to the [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest) interface that represents the framework request object.

### `pIoTarget` [in]

A pointer to the [IWDFIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotarget) interface for the I/O target object that represents the lower driver in the stack where the request was previously sent.

### `pParams` [in]

A pointer to the [IWDFRequestCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfrequestcompletionparams) interface for the parameters object for the completion request.

### `pContext` [in]

A pointer to a buffer that contains context information that is related to the completion request.

## Remarks

A driver registers the [IRequestCallbackRequestCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-irequestcallbackrequestcompletion) interface when the driver calls the [IWDFIoRequest::SetCompletionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-setcompletioncallback) method.

## See also

[IRequestCallbackRequestCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-irequestcallbackrequestcompletion)

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFIoRequest::SetCompletionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-setcompletioncallback)

[IWDFIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotarget)

[IWDFRequestCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfrequestcompletionparams)