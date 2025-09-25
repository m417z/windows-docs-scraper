# PFLT_GET_OPERATION_STATUS_CALLBACK callback function

## Description

A minifilter driver can register a routine of type *PFLT_GET_OPERATION_STATUS_CALLBACK* as the minifilter driver's OperationStatusCallback routine.

## Parameters

### `FltObjects` [in]

A pointer to an [FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) structure that contains opaque pointers for the objects related to the current operation.

### `IopbSnapshot` [in]

A pointer to the data structure containing parameters from the IO Request Packet for the operation.

### `OperationStatus` [in]

The NTSTATUS value of the I/O operation generating the callback.

### `RequesterContext` [in, optional]

An optional pointer to a minifilter driver-provided context information of the requester passed from [FltRequestOperationStatusCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestoperationstatuscallback).

## Remarks

A minifilter driver can register a routine of type *PFLT_GET_OPERATION_STATUS_CALLBACK* as the minifilter driver's OperationStatusCallback routine.

Most minifilter drivers never need to register a routine of type *PFLT_GET_OPERATION_STATUS_CALLBACK*. Normally, a minifilter driver only calls this routine to determine whether a requested opportunistic lock was granted.

## See also

[FLT_IO_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_io_parameter_block)

[FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects)

[FltRequestOperationStatusCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrequestoperationstatuscallback)