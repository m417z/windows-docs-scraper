# EVT_WDF_IO_QUEUE_IO_RESUME callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtIoResume* event callback function resumes processing a specified I/O request after the underlying device returns to its working (D0) power state.

## Parameters

### `Queue` [in]

A handle to the framework queue object that is associated with the I/O request.

### `Request` [in]

A handle to a framework request object.

## Remarks

A driver registers an *EvtIoResume* callback function when it calls the [WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate) method. For more information about calling **WdfIoQueueCreate**, see [Creating I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-i-o-queues).

A driver registers *EvtIoResume* only for use with a power-managed queue.

The framework calls the driver's *EvtIoResume* callback function only if the driver's [EvtIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_stop) callback function previously called [WdfRequestStopAcknowledge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequeststopacknowledge) with the *Requeue* parameter set to **FALSE**.

For more information about the *EvtIoResume* callback function, see [Using Power-Managed I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-power-managed-i-o-queues).

This callback function can be called at IRQL <= DISPATCH_LEVEL, unless the **ExecutionLevel** member of the device or driver's [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure is set to **WdfExecutionLevelPassive**. You should not make this callback function [pageable](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-pageable-code-in-a-kmdf-driver).

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfIoQueueCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuecreate)