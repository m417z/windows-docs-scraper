# KsAllocateExtraData function

## Description

The **KsAllocateExtraData** function is used with streaming IRPs to allocate a buffer to contain additional header data. A pointer to the allocated buffer is returned, and the buffer must eventually be freed by the caller.

## Parameters

### `Irp` [in, out]

Specifies the IRP containing the stream headers. The IRP must have been previously passed to **KsProbeStreamIrp** to buffer the headers.

### `ExtraSize` [in]

Specifies the size, in bytes, of additional memory to allocate between each stream header. This value *must* be alignable on an eight-byte boundary. A copy of the headers is placed in the returned buffer, with the extra data size inserted between each header. This must be freed by the caller.

### `ExtraBuffer` [out]

Points to a caller-allocated pointer that, on successful completion, points to a system-allocated buffer containing the stream headers and the requested padding between them. This must be freed by the caller.

## Return value

The **KsAllocateExtraData** function returns STATUS_SUCCESS if successful, or it returns a resource or access error.

## Remarks

When **KsAllocateExtraData** completes successfully, a pointer to a block of memory is returned that contains both the stream data headers from the IRP, specified at *Irp*, and padding between each header of size specified in *ExtraSize*. An example of such a resultant buffer is shown below:

![Diagram illustrating a resultant buffer.](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/images/ksexdata.png)

When the extra buffer is no longer needed, the memory should be freed using **ExFreePool**.