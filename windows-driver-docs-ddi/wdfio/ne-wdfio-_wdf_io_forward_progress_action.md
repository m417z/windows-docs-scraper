# _WDF_IO_FORWARD_PROGRESS_ACTION enumeration

## Description

[Applies to KMDF only]

The **WDF_IO_FORWARD_PROGRESS_ACTION** enumeration identifies actions that the framework can take for an I/O request packet (IRP) that your driver examines during a low-memory situation.

## Constants

### `WdfIoForwardProgressActionInvalid:0x0`

For internal use only.

### `WdfIoForwardProgressActionFailRequest`

The framework will complete the current I/O request with an error status value.

### `WdfIoForwardProgressActionUseReservedRequest`

The framework will use a reserved request object, if one is available, for the current I/O request.

## Remarks

The **WDF_IO_FORWARD_PROGRESS_ACTION** enumeration is used as the return value for the [EvtIoWdmIrpForForwardProgress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_wdm_irp_for_forward_progress) callback function.

## See also

[EvtIoWdmIrpForForwardProgress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_wdm_irp_for_forward_progress)