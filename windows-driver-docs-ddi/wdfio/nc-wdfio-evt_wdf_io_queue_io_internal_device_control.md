# EVT_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtIoInternalDeviceControl* event callback function processes an I/O request that contains an internal device I/O control code (IOCTL).

## Parameters

### `Queue` [in]

A handle to the framework queue object that is associated with the I/O request.

### `Request` [in]

A handle to a framework request object.

### `OutputBufferLength` [in]

The length, in bytes, of the request's output buffer, if an output buffer is available.

### `InputBufferLength` [in]

The length, in bytes, of the request's input buffer, if an input buffer is available.

### `IoControlCode` [in]

The driver-defined or system-defined IOCTL that is associated with the request.

## Remarks

A driver registers an *EvtIoInternalDeviceControl* callback function when it calls the [WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate) method. For more information about calling **WdfIoQueueCreate**, see [Creating I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-i-o-queues).

If a driver has registered an *EvtIoInternalDeviceControl* callback function for a device's I/O queue, the callback function receives every internal I/O control request ([IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)) from the queue. For more information, see [Request Handlers](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers).

The *EvtIoInternalDeviceControl* callback function must process each received I/O request in some manner. For more information, see [Processing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/processing-i-o-requests).

Drivers receive internal I/O control requests when another driver creates a request by calling either [WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously) or [WdfIoTargetFormatRequestForInternalIoctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetformatrequestforinternalioctl).

The type of operation to be performed depends on the value of the *IoControlCode* parameter. You must determine the set of *IoControlCode* values that applications and other drivers can send to your driver. For more information about IOCTLs, see [Using I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-i-o-control-codes).

Most internal I/O control operations require an input buffer, an output buffer, or both. For information about how the driver can access a request's buffers, see [Accessing Data Buffers in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

The techniques that your driver can use to access the request's input and output buffers (if they exist) depend on the *TransferType* field of the IOCTL. The value of the IOCTL's *TransferType* field can be METHOD_BUFFERED, METHOD_DIRECT_IN, METHOD_DIRECT_OUT, or METHOD_NEITHER. For more information about the *TransferType* field, see [Defining I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/defining-i-o-control-codes).

The *EvtIoInternalDeviceControl* callback function can be called at IRQL <= DISPATCH_LEVEL, unless the **ExecutionLevel** member of the device or driver's [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure is set to **WdfExecutionLevelPassive**. (If your driver is at the top of its driver stack, the callback function is called at IRQL = PASSIVE_LEVEL.)

If the IRQL is PASSIVE_LEVEL, the framework calls the callback function within a [critical region](https://learn.microsoft.com/windows-hardware/drivers/kernel/critical-regions-and-guarded-regions).

For more information about IRQL levels for request handlers, see [Using Automatic Synchronization](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-automatic-synchronization).

A driver's *EvtIoInternalDeviceControl* callback function should not call the following queue object methods:

[WdfIoQueueDrainSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuedrainsynchronously)

[WdfIoQueuePurgeSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurgesynchronously)

[WdfIoQueueStopSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestopsynchronously)

## See also

[EvtIoDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_device_control)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate)

[WdfIoTargetFormatRequestForInternalIoctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetformatrequestforinternalioctl)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)