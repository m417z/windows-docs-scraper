# EVT_WDF_IO_QUEUE_IO_READ callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtIoRead* event callback function processes a specified read request.

## Parameters

### `Queue` [in]

A handle to the framework queue object that is associated with the I/O request.

### `Request` [in]

A handle to a framework request object.

### `Length` [in]

The number of bytes to be read.

## Remarks

A driver registers an *EvtIoRead* callback function when it calls [WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate). For more information about calling **WdfIoQueueCreate**, see [Creating I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-i-o-queues).

If a driver has registered an *EvtIoRead* callback function for a device's I/O queue, the callback function receives every read request from the queue. For more information, see [Request Handlers](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers).

The *EvtIoRead* callback function must process each received I/O request in some manner. For more information, see [Processing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/processing-i-o-requests).

Read requests require an output buffer, which receives data that the driver provides. For information about how the driver can access a read request's buffer, see [Accessing Data Buffers in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

This callback function can be called at IRQL <= DISPATCH_LEVEL, unless the **ExecutionLevel** member of the device or driver's [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure is set to **WdfExecutionLevelPassive**.

If the IRQL is PASSIVE_LEVEL, the framework calls the callback function within a [critical region](https://learn.microsoft.com/windows-hardware/drivers/kernel/critical-regions-and-guarded-regions).

For more information about IRQL levels for request handlers, see [Using Automatic Synchronization](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-automatic-synchronization).

A driver's *EvtIoRead* callback function should not call the following queue object methods:

[WdfIoQueueDrainSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuedrainsynchronously)

[WdfIoQueuePurgeSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurgesynchronously)

[WdfIoQueueStopSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestopsynchronously)

## See also

[EvtIoDefault](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_default)

[EvtIoWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_write)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate)