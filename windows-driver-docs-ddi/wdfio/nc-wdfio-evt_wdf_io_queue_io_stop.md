# EVT_WDF_IO_QUEUE_IO_STOP callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtIoStop* event callback function completes, requeues, or suspends processing of a specified request because the request's I/O queue is being stopped.

## Parameters

### `Queue` [in]

A handle to the framework queue object that is associated with the I/O request.

### `Request` [in]

A handle to a framework request object.

### `ActionFlags` [in]

A bitwise OR of one or more [WDF_REQUEST_STOP_ACTION_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_stop_action_flags)-typed flags that identify the reason that the callback function is being called and whether the request is cancelable.

## Remarks

A driver registers an *EvtIoStop* callback function when it calls [WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate). For more information about calling **WdfIoQueueCreate**, see [Creating I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-i-o-queues).

If a driver registers an *EvtIoStop* callback function for an I/O queue, the framework calls it when the queue's underlying device is leaving its working (D0) state. The framework calls the *EvtIoStop* callback function for every I/O request that the driver has not [completed](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests), including requests that the driver [owns](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-ownership) and those that it has [forwarded](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests) to an I/O target.

In most cases, the *EvtIoStop* callback function [completes](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests), [cancels](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests), or postpones further processing of the I/O request.

Typically, the driver does one of the following:

* If the driver owns the I/O request, it calls [WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable) (if the request is cancelable) and either calls [WdfRequestStopAcknowledge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequeststopacknowledge) with a *Requeue* value of TRUE, or it calls [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) with a completion status value of STATUS_SUCCESS or STATUS_CANCELLED.

  Before it can call **WdfRequest*Xxx*** methods safely, the driver must make sure that its implementation of *EvtIoStop* has exclusive access to the request.

  In order to do that, the driver must synchronize access to the request to prevent other threads from manipulating the request concurrently. The synchronization method you choose will depend on your driver's design.

  For example, if the request is held in a shared context area, the *EvtIoStop* callback might acquire an internal driver lock, remove the request from the shared context, and then release the lock. At this point, the *EvtIoStop* callback owns the request and can safely complete or requeue the request.

  Alternatively, the driver postpones further processing of the request and calls [WdfRequestStopAcknowledge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequeststopacknowledge) with a *Requeue* value of FALSE.
* If the driver has forwarded the I/O request to an I/O target, it can call [WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest) to attempt to cancel the request.

  Or, if the driver has forwarded the I/O request to a lower-level driver in its own driver stack, and the framework calls the driver's *EvtIoStop* callback with an *ActionFlags* value of **WdfRequestStopActionSuspend**, the driver can call [WdfRequestStopAcknowledge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequeststopacknowledge) with a *Requeue* value of FALSE. Before doing so, the driver should verify that the following conditions are met:
  + The lower driver stops processing all outstanding I/O requests in response to receiving a device set-power IRP (Dx).
  + The driver's [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function can complete requests while the device is in a low-power state.

A driver might choose to take no action in *EvtIoStop* for requests that are guaranteed to complete in a small amount of time.

 In this case, the framework waits until the specified request is complete before moving the device (or system) to a lower power state or removing the device. Potentially, this inaction can prevent a system from entering its hibernation state or another low system power state. In extreme cases, it can cause the system to crash with bugcheck code 9F.

If the [WdfRequestStopRequestCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_stop_action_flags) flag is set in the *ActionFlags* parameter, the driver must call [WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable) before it calls [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) to complete (or cancel) the request or [WdfRequestStopAcknowledge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequeststopacknowledge) to requeue the request.

If the driver forwards an I/O request from one of its [request handlers](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers)
and specifies the **WDF_REQUEST_SEND_OPTION_SEND_AND_FORGET** flag in the request's [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure, the framework does not call the driver's *EvtIoStop* callback function for this request. However, if the driver forwards the same I/O request from another thread, the framework might call *EvtIoStop* for this request.

For more information about the *EvtIoStop* callback function, see [Using Power-Managed I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-power-managed-i-o-queues).

This callback function can be called at IRQL <= DISPATCH_LEVEL, unless the **ExecutionLevel** member of the device or driver's [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure is set to **WdfExecutionLevelPassive**.

## See also

[EvtIoResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_resume)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_REQUEST_STOP_ACTION_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_stop_action_flags)

[WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate)

[WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete)

[WdfRequestStopAcknowledge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequeststopacknowledge)