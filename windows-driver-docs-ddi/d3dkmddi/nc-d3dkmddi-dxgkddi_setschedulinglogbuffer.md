# DXGKDDI_SETSCHEDULINGLOGBUFFER callback function

## Description

Instruct the GPU to use the passed buffer as a scheduling log for a particular GPU node.

## Parameters

### `hAdapter`

Identifies the logical adapter.

### `pSetSchedulingLogBuffer`

Pointer to a [DXGKARG_SETSCHEDULINGLOGBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setschedulinglogbuffer) structure that contains information to set scheduling log buffer.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code.

## Prototype

```cpp
//Declaration

DXGKDDI_SETSCHEDULINGLOGBUFFER DxgkddiSetschedulinglogbuffer;

// Definition

NTSTATUS DxgkddiSetschedulinglogbuffer
(
	IN_CONST_HANDLE hAdapter
	IN_CONST_PDXGKARG_SETSCHEDULINGLOGBUFFER pSetSchedulingLogBuffer
)
{...}

DXGKDDI_SETSCHEDULINGLOGBUFFER *PDXGKDDI_SETSCHEDULINGLOGBUFFER

```

## Remarks

Register your implementation of this callback function by setting the appropriate member of DXGKARG_SETSCHEDULINGLOGBUFFER and then calling DxgkddiSetSchedulingLogBuffer.

DxgkDdiSetSchedulingLogBuffer is a synchronous call. Upon the return from DxgkDdiSetSchedulingLogBuffer, the GPU is not allowed to write any more entries to the previous log. All new entries will be written to the log buffer passed by the latest DxgkDdiSetSchedulingLogBuffer call.

The log buffer passed by the OS has FirstFreeEntryIndex and WraparondCount set to zero, and NumberOfEntries set to the number of allocated log entries. The rest of the buffer is uninitialized. In particular, the GPU cannot assume the individual entries in the log entry buffer are zero initialized.

## See also