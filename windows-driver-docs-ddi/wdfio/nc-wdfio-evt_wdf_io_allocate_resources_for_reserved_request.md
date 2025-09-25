# EVT_WDF_IO_ALLOCATE_RESOURCES_FOR_RESERVED_REQUEST callback function

## Description

[Applies to KMDF only]

A driver's *EvtIoAllocateResourcesForReservedRequest* callback function allocates request-specific resources that the driver can use to process an I/O request in the future. The framework is pre-allocating the specified request object for future use in low-memory situations.

## Parameters

### `Queue` [in]

A handle to an I/O queue object.

### `Request` [in]

A handle to a request object that the framework has created for use during future low-memory situations.

## Return value

The *EvtIoAllocateResourcesForReservedRequest* callback function must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE** if the function encounters no errors. Otherwise, this function must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

## Remarks

A driver can register an *EvtIoAllocateResourcesForReservedRequest* callback function when it calls [WdfIoQueueAssignForwardProgressPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueassignforwardprogresspolicy).

If your driver registers an *EvtIoAllocateResourcesForReservedRequest* callback function, the framework calls the function immediately after it creates a request object that it reserves for low-memory situations.

The callback function can allocate resources that your driver will require to process a request later, if the framework uses the reserved request because of a low-memory situation.

To allocate memory for request-specific resources, an *EvtIoAllocateResourcesForReservedRequest* callback function might call [WdfObjectAllocateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectallocatecontext), specifying the request object handle that the *Request* parameter specifies.

Alternatively or additionally, your driver might call [WdfDeviceInitSetRequestAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetrequestattributes) before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). As a result, the framework will allocate context space for each reserved request object when it creates the object.

If your driver allocates object context space for reserved request objects, the driver must reinitialize the context space when it completes an I/O request that uses a reserved request object. The framework does not reinitialize the context space of reserved request objects after use.

If your driver calls [WdfDeviceInitSetRequestAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetrequestattributes) and specifies an [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) or [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback function for its request objects, the framework calls these callback functions for its reserved request objects only when it deletes the associated I/O queues.

The driver's [request handlers](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers) can call [WdfRequestIsReserved](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestisreserved) to determine if reserved request objects are being used.

For more information about how to use object context space, see [Framework Object Context Space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).

If the callback function successfully allocates resources, it should return STATUS_SUCCESS.

If a resource allocation error occurs, such as a low memory situation, the callback function must return an error status value. In this case, the framework stops allocating reserved request objects and uses the callback function's return value as the return value for [WdfIoQueueAssignForwardProgressPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueassignforwardprogresspolicy).

For more information about the *EvtIoAllocateResourcesForReservedRequest* callback function, see [Guaranteeing Forward Progress of I/O Operations](https://learn.microsoft.com/windows-hardware/drivers/wdf/guaranteeing-forward-progress-of-i-o-operations).

## See also

[EvtIoAllocateRequestResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_allocate_request_resources)

[WdfIoQueueAssignForwardProgressPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueassignforwardprogresspolicy)

[WdfRequestIsReserved](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestisreserved)