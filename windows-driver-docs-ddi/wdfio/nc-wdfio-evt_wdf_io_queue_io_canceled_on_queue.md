# EVT_WDF_IO_QUEUE_IO_CANCELED_ON_QUEUE callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtIoCanceledOnQueue* event callback function informs the driver that it must complete an I/O request that the framework has removed from an I/O queue.

## Parameters

### `Queue` [in]

A handle to an I/O queue object.

### `Request` [in]

A handle to a request object.

## Remarks

A driver registers an *EvtIoCanceledOnQueue* callback function when it calls the [WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate) method. For more information about calling **WdfIoQueueCreate**, see [Creating I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-i-o-queues).

If a driver registers an *EvtIoCanceledOnQueue* callback function for an I/O queue, the framework calls the callback function in the following situations:

* A [request handler](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers) receives an I/O request from an I/O queue, the driver calls [WdfRequestForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoioqueue), [WdfRequestForwardToParentDeviceIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoparentdeviceioqueue), or [WdfRequestRequeue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestrequeue) to requeue the request to the I/O queue for which the *EvtIoCanceledOnQueue* callback function is registered, and the associated I/O operation is subsequently canceled.
* The driver's [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) callback function receives an I/O request, the driver calls [WdfDeviceEnqueueRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceenqueuerequest) to pass the request back to the framework, the framework then places the request in the I/O queue for which the *EvtIoCanceledOnQueue* callback function is registered, and the associated I/O operation is subsequently canceled.

After the framework calls the *EvtIoCanceledOnQueue* callback function, the driver [owns](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-ownership) the request object and must [complete](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests) the request with an appropriate status code, either in *EvtIoCanceledOnQueue* or later. When the framework calls *EvtIoCanceledOnQueue*, the request is still associated with the I/O queue, but the driver cannot requeue the request. The ownership of the request stays with the driver even if the driver does not complete the request in *EvtIoCanceledOnQueue*. If the driver completes the request after *EvtIoCanceledOnQueue* returns, it cannot call [WdfIoQueueFindRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuefindrequest) and [WdfIoQueueRetrieveFoundRequest](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfioqueueretrievefoundrequest) to reacquire ownership of the request because the driver already has ownership of the request.

Typically, in *EvtIoCanceledOnQueue*, the driver [completes the I/O request](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests) with a completion status of STATUS_CANCELLED.

In some cases, the driver might have previously requeued an I/O request to a manual queue, perhaps to wait for information. For example, in one of its [request handlers](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers), a driver might place an I/O request that is associated with a pending DMA transaction in a manual queue. In this case, the driver attempts to [cancel the DMA transaction](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-dma-transactions) in its *EvtIoCanceledOnQueue* callback. Depending on the results of the cancel operation, the driver completes the request with an appropriate status, either in *EvtIoCanceledOnQueue* or later.

The framework does not call the driver's *EvtIoCanceledOnQueue* callback function for I/O requests that the framework has never delivered to the driver.

The framework calls an *EvtIoCanceledOnQueue* callback function as soon as it determines that an I/O request has been canceled, regardless of the [dispatching method](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-methods-for-i-o-requests) that the driver has set for the I/O queue. Therefore, the framework can call an *EvtIoCanceledOnQueue* callback function for:

* A request in a queue that uses [sequential dispatching](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-methods-for-i-o-requests), even if the driver currently owns another request from the queue.
* A request in a queue for which the driver has set [NumberOfPresentedRequests](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_config), even if the driver currently owns the maximum number of requests.

For more information about the *EvtIoCanceledOnQueue* callback function, see [Canceling I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests).

The *EvtIoCanceledOnQueue* callback function can be called at IRQL <= DISPATCH_LEVEL, unless the **ExecutionLevel** member of the device or driver's [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure is set to **WdfExecutionLevelPassive**.

If the IRQL is PASSIVE_LEVEL, the framework calls the callback function within a [critical region](https://learn.microsoft.com/windows-hardware/drivers/kernel/critical-regions-and-guarded-regions).

#### Examples

To define an *EvtIoCanceledOnQueue* callback function, you must first provide a function declaration that identifies the type of callback function you’re defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it’s a requirement for writing drivers for the Windows operating system.

To define an *EvtIoCanceledOnQueue* callback function, you must first provide a function declaration that SDV and other verification tools require. The following example is taken from the [PCMCIA Smart Card Driver](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples) sample.

```
EVT_WDF_IO_QUEUE_IO_CANCELED_ON_QUEUE PscrEvtIoCanceledOnQueue;
```

In the [PCMCIA Smart Card Driver](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples) sample, the driver uses a manual queue to store pending smart card notification requests. The driver provides an *EvtIoCanceledOnQueue* callback function in which the driver clears the notification field and completes the request.

```
_Use_decl_annotations_
VOID
PscrEvtIoCanceledOnQueue(
    WDFQUEUE  Queue,
    WDFREQUEST  Request
    )

{
    PDEVICE_EXTENSION DeviceExtension;
    PSMARTCARD_EXTENSION smartcardExtension;

    DeviceExtension = GetDeviceExtension(WdfIoQueueGetDevice(Queue));
    smartcardExtension = (PSMARTCARD_EXTENSION) &DeviceExtension->SmartcardExtension;

    //KdPrint(("Cancelled on queue 0x%x\n", WdfRequestWdmGetIrp(Request)));

    InterlockedExchangePointer(
                             &(smartcardExtension->OsData->NotificationIrp),
                             NULL
                             );

    WdfRequestComplete(Request, STATUS_CANCELLED);
}
```

The **EVT_WDF_IO_QUEUE_IO_CANCELED_ON_QUEUE** function type is defined in the Wdfio.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_WDF_IO_QUEUE_IO_CANCELED_ON_QUEUE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers).
For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/cpp/code-quality/annotating-function-behavior).

## See also

[WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate)

[WdfRequestForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoioqueue)