# NdrConformantStringBufferSize function

## Description

The **NdrConformantStringBufferSize** function calculates the size of the buffer, in bytes, needed to marshal the conformant string.

## Parameters

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. The **BufferLength** member contains the size of the buffer. Structure is for internal use only; do not modify.

### `pMemory` [in]

Pointer to the null-terminated conformant string to be calculated.

### `pFormat` [in]

Pointer to the format string description.

## Return value

This function has no return values. If an error occurs, the function throws one of the following exception codes.

| Error | Description |
| --- | --- |
| STATUS_ACCESS_VIOLATION | An access violation occurred. |
| RPC_S_INTERNAL_ERROR | An error occurred in RPC. |