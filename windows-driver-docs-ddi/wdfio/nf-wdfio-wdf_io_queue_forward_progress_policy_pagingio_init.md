# WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_PAGINGIO_INIT function

## Description

[Applies to KMDF only]

The **WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_PAGINGIO_INIT** function initializes a driver's [WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_forward_progress_policy) structure.

## Parameters

### `Policy` [out]

A pointer to the driver's [WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_forward_progress_policy) structure.

### `TotalForwardProgressRequests` [in]

The number of request objects that the framework will attempt to reserve for use in low-memory situations. This number must be greater than zero.

## Remarks

The **WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_PAGINGIO_INIT** function zeros the specified [WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_forward_progress_policy) structure and sets its **Size** member. It also sets the **ForwardProgressReservedPolicy** member to **WdfIoForwardProgressReservedPolicyUseExamine**.

#### Examples

The following code example initializes a [WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_forward_progress_policy) structure and then calls [WdfIoQueueAssignForwardProgressPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueassignforwardprogresspolicy). In the example, the driver is specifying that the framework should allocate and reserve 10 request objects for low-memory situations, and that the framework should use one of the reserved requests during low-memory situations only if the I/O request is a paging operation.

```cpp
#define MAX_RESERVED_REQUESTS 10

WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY queueForwardProgressPolicy;
WDFQUEUE readQueue;
NTSTATUS status = STATUS_SUCCESS;

WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_PAGINGIO_INIT(
    &queueForwardProgressPolicy,
    MAX_RESERVED_REQUESTS
    );
status = WdfIoQueueAssignForwardProgressPolicy(
    readQueue,
    &queueForwardProgressPolicy
    );
```

## See also

[WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_DEFAULT_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_forward_progress_policy_default_init)

[WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_EXAMINE_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_forward_progress_policy_examine_init)

[WdfIoQueueAssignForwardProgressPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueassignforwardprogresspolicy)