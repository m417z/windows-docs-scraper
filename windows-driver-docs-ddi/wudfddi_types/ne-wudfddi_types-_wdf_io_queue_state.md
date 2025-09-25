# _WDF_IO_QUEUE_STATE enumeration (wudfddi_types.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The [WDF_IO_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_io_queue_state) enumeration contains values that identify the state of an I/O queue.

## Constants

### `WdfIoQueueAcceptRequests`

If this value is set to 1, the queue accepts requests by automatically forwarding them through the setting of the [IWDFIoQueue::ConfigureRequestDispatching](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-configurerequestdispatching) method or by manually forwarding each request through a call to the [IWDFIoRequest::ForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-forwardtoioqueue) method.

If this value is set to 0, the queue completes any automatically forwarded requests with "status canceled" or fails [IWDFIoRequest::ForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-forwardtoioqueue) with "status busy".

### `WdfIoQueueDispatchRequests`

If this value is set to 1, the queue automatically presents requests to the driver, unless the queue is a **WdfIoQueueDispatchManual** type (see [WDF_IO_QUEUE_DISPATCH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_queue_dispatch_type)).

If this value is set to 0, the queue does not automatically dispatch requests to the driver. The setting of this status does not prevent the driver from calling the [IWDFIoQueue::RetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-retrievenextrequest) method to manually retrieve a request from the queue.

### `WdfIoQueueNoRequests`

If this value is set to 1, no requests are in the queue, even requests that can be presented to the driver and that can be returned from [IWDFIoQueue::RetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-retrievenextrequest).

### `WdfIoQueueDriverNoRequests`

If this value is set to 1, there are no requests that the driver currently operates on that it received from the queue.

### `WdfIoQueuePnpHeld`

If this value is set to 1, an event from the Plug and Play (PnP) subsystem suspended the queue from processing requests.

## See also

[IWDFIoQueue::ConfigureRequestDispatching](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-configurerequestdispatching)

[IWDFIoQueue::RetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-retrievenextrequest)

[IWDFIoRequest::ForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-forwardtoioqueue)

[WDF_IO_QUEUE_DISPATCH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_queue_dispatch_type)