# NdrUserMarshalBufferSize function

## Description

The **NdrUserMarshalBufferSize** function calculates the size of the buffer, in bytes, needed to marshal the user marshal object.

## Parameters

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. The **BufferLength** member contains the size of the buffer. Structure is for internal use only; do not modify.

### `pMemory` [in]

Pointer to the user marshal object to be calculated.

### `pFormat` [in]

Pointer to the format string description.