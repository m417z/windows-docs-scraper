# IWDFIoQueue::DrainSynchronously

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **DrainSynchronously** method directs the queue to reject new incoming I/O requests and allows already-queued requests to be delivered to the driver for processing. This method returns after all requests are completed or canceled.

## Remarks

The **DrainSynchronously** method is a synchronous version of the [IWDFIoQueue::Drain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-drain) method. That is, **DrainSynchronously** does not return to the driver until the queue is drained.

## See also

[IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)

[IWDFIoQueue::Drain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-drain)