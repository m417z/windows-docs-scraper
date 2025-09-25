# _NAMED_PIPE_CREATE_PARAMETERS structure

## Description

 The NAMED_PIPE_CREATE_PARAMETERS structure is used by the Windows subsystem to create a named pipe.

## Members

### `NamedPipeType`

Type of named pipe to create.

### `ReadMode`

Mode in which to read the pipe.

### `CompletionMode`

Specifies how the operation is to be completed.

### `MaximumInstances`

Maximum number of simultaneous instances of the named pipe.

### `InboundQuota`

Pool quota that is reserved for writes to the inbound side of the named pipe.

### `OutboundQuota`

Pool quota that is reserved for writes to the outbound side of the named pipe.

### `DefaultTimeout`

Pointer to a timeout value to use if a timeout value is not specified when waiting for an instance of a named pipe. This member is optional and can be set to **NULL**.

### `TimeoutSpecified`

Boolean value that specifies whether a pointer to a timeout period was provided in the *DefaultTimeout* member.

## Remarks

For an [IRP_MJ_CREATE_NAMED_PIPE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create-named-pipe) operation, [FLT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_parameters) is a *CreatePipe* structure, and *CreatePipe.Parameters* points to a NAMED_PIPE_CREATE_PARAMETERS structure that describes the named pipe to create or open.

## See also

[FLT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_parameters)