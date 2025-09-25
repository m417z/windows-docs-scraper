# NdrPointerBufferSize function

## Description

The **NdrPointerBufferSize** function computes the needed buffer size, in bytes, for a top-level pointer to anything.

## Parameters

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. The **BufferLength** member contains the size of the buffer. This structure is for internal use only and should not be modified.

### `pMemory` [in]

Pointer to the data being sized.

### `pFormat` [in]

Pointer to the format string description.

## Return value

This function has no return values. If an error occurs, the function throws one of the following exception codes.

| Error | Description |
| --- | --- |
| STATUS_ACCESS_VIOLATION | An access violation occurred. |
| RPC_S_INTERNAL_ERROR | An error occurred in RPC. |

## Remarks

Pointers embedded in structures, arrays, or unions call
**NdrPointerBufferSize** directly.

Used for FC_RP, FC_UP, FC_FP, FC_OP format strings.