# WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_EXAMINE_INIT function

## Description

[Applies to KMDF only]

The **WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_EXAMINE_INIT** function initializes a driver's [WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_forward_progress_policy) structure.

## Parameters

### `Policy` [out]

A pointer to the driver's [WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_forward_progress_policy) structure.

### `TotalForwardProgressRequests` [in]

The number of request objects that the framework will attempt to reserve for use in low-memory situations. This number must be greater than zero.

### `EvtIoWdmIrpForForwardProgress` [in]

A pointer to the driver's [EvtIoWdmIrpForForwardProgress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_wdm_irp_for_forward_progress) callback function.

## Remarks

The **WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_EXAMINE_INIT** function zeros the specified [WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_forward_progress_policy) structure and sets its **Size** member. It also sets the structure's **TotalForwardProgressRequests** and**ForwardProgressReservePolicySettings.Policy.ExaminePolicy.EvtIoWdmIrpForForwardProgress** members to the specified values, and it sets the **ForwardProgressReservedPolicy** member to **WdfIoForwardProgressReservedPolicyUseExamine**.

#### Examples

The following code example initializes a [WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_forward_progress_policy) structure and then calls [WdfIoQueueAssignForwardProgressPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueassignforwardprogresspolicy). In the example, the driver is specifying that the framework should allocate and reserve 10 request objects for low-memory situations, and that the framework should call the driver's **MyIoForwardExamineIrpForForwardProgress** callback function before using one of the reserved request objects.

```cpp
#define MAX_RESERVED_REQUESTS 10

WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY queueForwardProgressPolicy;
WDFQUEUE readQueue;
NTSTATUS status = STATUS_SUCCESS;

WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_EXAMINE_INIT(
    &queueForwardProgressPolicy,
    MAX_RESERVED_REQUESTS,
    MyIoForwardExamineIrpForForwardProgress
    );
status = WdfIoQueueAssignForwardProgressPolicy(
    readQueue,
    &queueForwardProgressPolicy
    );
```

## See also

[WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_DEFAULT_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_forward_progress_policy_default_init)

[WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_PAGINGIO_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_forward_progress_policy_pagingio_init)

[WdfIoQueueAssignForwardProgressPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueassignforwardprogresspolicy)