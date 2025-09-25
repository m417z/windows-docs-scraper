# IWDFIoQueue::PurgeSynchronously

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **PurgeSynchronously** method directs the framework to reject new incoming I/O requests and to cancel all outstanding requests. The method returns after all outstanding requests are canceled.

## Remarks

The framework cancels unprocessed requests in the queue. For requests that are delivered to the driver and marked cancelable, the framework calls [IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel).

The **PurgeSynchronously** method is a synchronous version of the [IWDFIoQueue::Purge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-purge) method. That is, **PurgeSynchronously** does not return to the driver until all outstanding requests are canceled.

## See also

[IRequestCallbackCancel::OnCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-irequestcallbackcancel-oncancel)

[IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)

[IWDFIoQueue::Purge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-purge)