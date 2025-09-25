# EVT_WDF_IO_WDM_IRP_FOR_FORWARD_PROGRESS callback function

## Description

[Applies to KMDF only]

A driver's *EvtIoWdmIrpForForwardProgress* callback function examines an I/O request packet (IRP) and determines whether to use a reserved request object to process the I/O request or to fail the I/O request.

## Parameters

### `Queue` [in]

A handle to an I/O queue object.

### `Irp` [in]

A pointer to an IRP structure.

## Return value

The *EvtIoWdmIrpForForwardProgress* callback function must return a [WDF_IO_FORWARD_PROGRESS_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_forward_progress_action)-typed value.

## Remarks

A driver can register an *EvtIoWdmIrpForForwardProgress* callback function when it calls [WdfIoQueueAssignForwardProgressPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueassignforwardprogresspolicy).

If your driver registers an *EvtIoWdmIrpForForwardProgress* callback function, the framework calls the function if all of the following conditions exist:

* The framework has received an I/O request packet ([IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)) that the I/O manager is sending to the driver.
* The framework has attempted to create a request object for the IRP, but the attempt failed.
* The driver has enabled guaranteed forward progress for the I/O queue that should receive the request object, with the [policy type](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_forward_progress_reserved_policy) set to **WdfIoForwardProgressReservedPolicyUseExamine**.

The framework passes the IRP to the *EvtIoWdmIrpForForwardProgress* callback function. The callback function must examine the IRP and determine whether the framework should use one of its reserved request objects for the IRP or (if the IRP is not important when the computer's available memory is low) fail the I/O request without delivering it to the driver. The callback function's return value specifies the action that the framework should take.

For more information about the *EvtIoWdmIrpForForwardProgress* callback function, see [Guaranteeing Forward Progress of I/O Operations](https://learn.microsoft.com/windows-hardware/drivers/wdf/guaranteeing-forward-progress-of-i-o-operations).

This callback function can be called at IRQL <= DISPATCH_LEVEL. If the IRQL is PASSIVE_LEVEL, the framework calls the callback function within a [critical region](https://learn.microsoft.com/windows-hardware/drivers/kernel/critical-regions-and-guarded-regions).

## See also

[EvtIoAllocateRequestResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_allocate_request_resources)

[EvtIoAllocateResourcesForReservedRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_allocate_resources_for_reserved_request)