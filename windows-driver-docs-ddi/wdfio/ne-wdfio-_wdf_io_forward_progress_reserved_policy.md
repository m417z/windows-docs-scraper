# _WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY enumeration

## Description

[Applies to KMDF only]

The **WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY** enumeration identifies actions that the framework can take when it receives an I/O request for your driver, if a low-memory situation exists.

## Constants

### `WdfIoForwardProgressInvalidPolicy:0x0`

### `WdfIoForwardProgressReservedPolicyAlwaysUseReservedRequest`

In a low-memory situation, the framework always uses a reserved request object, if one is available.

### `WdfIoForwardProgressReservedPolicyUseExamine`

In a low-memory situation, the framework calls the driver's [EvtIoWdmIrpForForwardProgress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_wdm_irp_for_forward_progress) callback function.

### `WdfIoForwardProgressReservedPolicyPagingIO`

In a low-memory situation, if the **Flags** member of the I/O request's [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure indicates a paging operation, the framework uses a reserved request object, if one is available. If the I/O request is not a paging operation, the framework completes the I/O request with an error status value.

## Remarks

The **WDF_IO_FORWARD_PROGRESS_RESERVED_POLICY** enumeration is used as a member type in the [WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_forward_progress_policy) structure.