# _WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY structure

## Description

[Applies to KMDF only]

The **WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY** structure contains driver-supplied information that the framework uses to enable [guaranteed forward progress](https://learn.microsoft.com/windows-hardware/drivers/wdf/guaranteeing-forward-progress-of-i-o-operations) for an I/O queue.

## Members

### `Size`

The length, in bytes, of this structure.

### `TotalForwardProgressRequests`

The number of request objects that the framework will attempt to reserve for use in low-memory situations. This number must be greater than zero.

### `ForwardProgressReservedPolicy`

A [WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_forward_progress_reserved_policy)-typed value that specifies how the framework will allocate request objects during low-memory situations.

### `ForwardProgressReservePolicySettings`

A [WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_forward_progress_reserved_policy_settings) structure that contains additional values that are specific to the policy that the **ForwardProgressReservedPolicy** member specifies. This member should be **NULL** unless the driver provides an [EvtIoWdmIrpForForwardProgress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_wdm_irp_for_forward_progress) callback function.

### `EvtIoAllocateResourcesForReservedRequest`

A pointer to the driver's queue-specific [EvtIoAllocateResourcesForReservedRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_allocate_resources_for_reserved_request) callback function, or **NULL**.

### `EvtIoAllocateRequestResources`

A pointer to the driver's queue-specific [EvtIoAllocateRequestResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_allocate_request_resources) callback function, or **NULL**.

## Remarks

The **WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY** structure is used as input to the [WdfIoQueueAssignForwardProgressPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueassignforwardprogresspolicy) method.

Drivers must initialize the **WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY** structure by calling [WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_DEFAULT_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_forward_progress_policy_default_init), [WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_EXAMINE_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_forward_progress_policy_examine_init), or [WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_PAGINGIO_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_forward_progress_policy_pagingio_init) before they call [WdfIoQueueAssignForwardProgressPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueueassignforwardprogresspolicy).