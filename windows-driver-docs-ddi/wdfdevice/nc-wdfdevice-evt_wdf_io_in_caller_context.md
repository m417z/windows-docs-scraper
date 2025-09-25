# EVT_WDF_IO_IN_CALLER_CONTEXT callback function

## Description

[Applies to KMDF only]

A driver's *EvtIoInCallerContext* event callback function preprocesses an I/O request before the framework places it into an I/O queue.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Request` [in]

A handle to a framework request object.

## Remarks

The framework calls a driver's *EvtIoInCallerContext* callback function so that the driver can examine each I/O request, and possibly perform preliminary processing on the request, before the framework places it in an I/O queue. To register an *EvtIoInCallerContext* callback function for a device, the driver calls [WdfDeviceInitSetIoInCallerContextCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetioincallercontextcallback).

If a driver registers an *EvtIoInCallerContext* callback function for a device, the framework calls the callback function each time it receives an I/O request for the device. The callback function is called in the thread context of the process that sent the I/O request to the driver. This process is either the next-higher level driver or, if the driver is at the top of the driver stack, a user-mode application.

This callback function's primary purpose is to enable framework-based drivers to support the buffer-access method that is called [neither buffered nor direct I/O](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers). For this buffer-access method, the driver must access received buffers in the originator's process context.

After the callback function has obtained a request's buffers, it can store buffer addresses or handles in the request object's context storage. (The driver sets the size of the request object's context storage area by calling [WdfDeviceInitSetRequestAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetrequestattributes).)

Because the request does not yet belong to an I/O queue, the framework does not lock or synchronize the request. The driver is responsible for any synchronization that might be necessary. For more information about synchronization, see [Synchronization Techniques for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronization-techniques-for-wdf-drivers).

After the callback function has finished preprocessing the request, it must either queue it by calling [WdfDeviceEnqueueRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceenqueuerequest) or complete it by calling [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) (if an error is detected).

For more information about the *EvtIoInCallerContext* callback function, see [Intercepting an I/O Request before it is Queued](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues) and [Accessing Data Buffers in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

If a driver has configured an I/O queue to support [guaranteed forward progress](https://learn.microsoft.com/windows-hardware/drivers/wdf/guaranteeing-forward-progress-of-i-o-operations), the framework might not call the driver's *EvtIoInCallerContext* callback function during low-memory situations. If all of the framework's reserved request objects are in use, the framework postpones processing the I/O request until a reserved request object is available. In this situation, the framework cannot call the *EvtIoInCallerContext* callback function for the postponed I/O request because, when a reserved request object becomes available, the framework will no longer be running in the thread context of the process that sent the I/O request to the driver.

The *EvtIoInCallerContext* callback function is called at the IRQL of the calling thread. If the calling thread is from a user-mode application, the callback function is called at IRQL = PASSIVE_LEVEL. If the calling thread is from a higher-level kernel-mode driver, your driver's *EvtIoInCallerContext* callback function can be called at IRQL <= DISPATCH_LEVEL if both the callback function and the higher-level driver are designed to pass the request at IRQL <= DISPATCH_LEVEL.

## See also

[EvtDeviceWdmIrpPreprocess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdfdevice_wdm_irp_preprocess)