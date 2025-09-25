# IWDFIoQueue::StopSynchronously

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **StopSynchronously** method prevents an I/O queue from delivering I/O requests, but the queue receives and stores new requests. The method returns after all delivered requests have been canceled or completed.

## Remarks

The **StopSynchronously** method is the synchronous version of the [IWDFIoQueue::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-stop) method. That is, **StopSynchronously** does not return to the driver until the queue stops.

The **StopSynchronously** method enables the queue to receive new requests, even if the queue was not receiving new requests before the driver called **StopSynchronously**. For example, a driver might call [IWDFIoQueue::Drain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-drain), which causes the framework to stop adding new I/O requests to the queue. The driver's subsequent call of **StopSynchronously** causes the framework to resume adding requests to the queue.

## See also

[IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)

[IWDFIoQueue::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-stop)