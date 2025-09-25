# IWDFIoRequest::Complete

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Complete** method completes an I/O request.

## Parameters

### `CompletionStatus` [in]

A status value to complete the request with.

## Remarks

Instead of calling **Complete**, the driver can call the [IWDFIoRequest::CompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-completewithinformation) method.

For more information about completing an I/O request, see [Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

#### Examples

The following code example completes a request with the failure that occurred when a memory object could not be retrieved.

```
    IWDFIoRequest* FxRequest;
    HRESULT hr = S_OK;
    IWDFMemory* FxInputMemory = NULL;

    FxRequest->GetInputMemory(&FxInputMemory);
    if (S_OK != hr) {
        FxRequest->Complete(hr);
    }
```

## See also

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFIoRequest::CompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-completewithinformation)