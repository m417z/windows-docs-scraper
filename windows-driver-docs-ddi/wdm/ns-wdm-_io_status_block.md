# _IO_STATUS_BLOCK structure

## Description

A driver sets an IRP's I/O status block to indicate the final status of an I/O request, before calling [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest) for the IRP.

## Members

### `Status`

This is the completion status, either STATUS_SUCCESS if the requested operation was completed successfully or an informational, warning, or error STATUS_*XXX* value. For more information, see [Using NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

### `Pointer`

Reserved. For internal use only.

### `Information`

This is set to a request-dependent value. For example, on successful completion of a transfer request, this is set to the number of bytes transferred. If a transfer request is completed with another STATUS_*XXX*, this member is set to zero.

## Remarks

Unless a driver's dispatch routine completes an IRP with an error status value, the lowest-level driver in the chain frequently sets the IRP's I/O status block to the values that will be returned to the original requester of the I/O operation.

The [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routines of higher-level drivers usually check the I/O status block in IRPs completed by lower drivers. By design, the I/O status block in an IRP is the only information passed back from the underlying device driver to all higher-level drivers' *IoCompletion* routines.

The operating system implements [support routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/) that write **IO_STATUS_BLOCK** values to caller-supplied output buffers. For example, see [ZwOpenFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile) or [NtOpenFile](https://learn.microsoft.com/windows/win32/api/winternl/nf-winternl-ntopenfile). These routines return status codes that might not match the status codes in the **IO_STATUS_BLOCK** structures. If one of these routines returns STATUS_PENDING, the caller should wait for the I/O operation to complete, and then check the status code in the **IO_STATUS_BLOCK** structure to determine the final status of the operation. If the routine returns a status code other than STATUS_PENDING, the caller should rely on this status code instead of the status code in the **IO_STATUS_BLOCK** structure.

For more information, see [I/O Status Blocks](https://learn.microsoft.com/windows-hardware/drivers/kernel/i-o-status-blocks).

## See also

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)

[IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine)