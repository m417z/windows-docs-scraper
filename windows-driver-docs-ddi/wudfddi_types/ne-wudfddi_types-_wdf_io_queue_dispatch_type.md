# _WDF_IO_QUEUE_DISPATCH_TYPE enumeration (wudfddi_types.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The [WDF_IO_QUEUE_DISPATCH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_queue_dispatch_type) enumeration contains values that identify how a driver must receive requests from an I/O queue.

## Constants

### `WdfIoQueueDispatchSequential`

The I/O queue's requests are presented to the driver's I/O queue callback functions one at a time. The framework delivers the next request after the driver calls the [IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete) method to complete the current request.

### `WdfIoQueueDispatchParallel`

The framework presents requests to the driver's I/O queue callback functions as soon as the requests are available.

### `WdfIoQueueDispatchManual`

The framework places requests into the queue but does not deliver them to the driver. The driver must call the [IWDFIoQueue::RetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-retrievenextrequest) method to retrieve a request from the queue.

### `WdfIoQueueDispatchMaximum`

Valid enumeration values were exceeded.

## See also

[IWDFIoQueue::RetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-retrievenextrequest)

[IWDFIoRequest::Complete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-complete)