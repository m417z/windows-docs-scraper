# IWDFIoRequest::CompleteWithInformation

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CompleteWithInformation** method completes a request with the supplied information.

## Parameters

### `CompletionStatus` [in]

A status value to complete the request with.

### `Information` [in]

Additional driver-supplied information that is related to the I/O operation.

For read, write, and device I/O control operations, the driver should supply the number of bytes that are transferred.

## Remarks

For more information about completing an I/O request, see [Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For a code example of how to use the **CompleteWithInformation** method, see [IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send).

## See also

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete)

[IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send)