# EVT_WDF_IO_ALLOCATE_REQUEST_RESOURCES callback function

## Description

[Applies to KMDF only]

A driver's *EvtIoAllocateRequestResources* callback function allocates request-specific resources that the driver requires to process the specified request.

## Parameters

### `Queue` [in]

A handle to an I/O queue object.

### `Request` [in]

A handle to a request object that the framework has created. The framework has not yet added the request object to the I/O queue that the *Queue* parameter's handle specifies.

## Return value

The *EvtIoAllocateRequestResources* callback function must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE** if the function encounters no errors. Otherwise, this function must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

## Remarks

A driver can register an *EvtIoAllocateRequestResources* callback function when it calls [WdfIoQueueAssignForwardProgressPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueassignforwardprogresspolicy).

If your driver registers an *EvtIoAllocateRequestResources* callback function, the framework calls the function immediately after it creates a request object for an I/O request packet (IRP) that the I/O manager has sent to your driver.

The callback function can allocate resources that your driver will require to process the request later, after the driver has obtained the request object from the I/O queue that the *Queue* parameter's handle specifies.

If the callback function successfully allocates resources and returns STATUS_SUCCESS, the framework will eventually deliver the request object to the driver.

If a resource allocation error occurs, such as a low memory situation, the callback function must return an error status value. In this case, the framework follows the driver's forward progress policy, which the driver previously specified with a [WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_forward_progress_reserved_policy) value when it called [WdfIoQueueAssignForwardProgressPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueassignforwardprogresspolicy).

For more information about the *EvtIoAllocateRequestResources* callback function, see [Guaranteeing Forward Progress of I/O Operations](https://learn.microsoft.com/windows-hardware/drivers/wdf/guaranteeing-forward-progress-of-i-o-operations).

This callback function can be called at IRQL <= DISPATCH_LEVEL. If the IRQL is PASSIVE_LEVEL, the framework calls the callback function within a [critical region](https://learn.microsoft.com/windows-hardware/drivers/kernel/critical-regions-and-guarded-regions).

## See also

[EvtIoAllocateResourcesForReservedRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_allocate_resources_for_reserved_request)

[WdfIoQueueAssignForwardProgressPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueassignforwardprogresspolicy)