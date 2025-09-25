# NdrSimpleStructBufferSize function

## Description

The **NdrSimpleStructBufferSize** function calculates the required buffer size, in bytes, to marshal the simple structure.

## Parameters

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. The **BufferLength** member contains the size of the buffer. The **MIDL_STUB_MESSAGE** structure is for internal use only, and must not be modified.

### `pMemory` [in]

Pointer to the simple structure to be calculated.

### `pFormat` [in]

Pointer to the format string description.

## See also

[MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message)