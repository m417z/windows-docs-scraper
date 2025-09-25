# NdrUserMarshalFree function

## Description

The **NdrUserMarshalFree** function frees the user marshal object.

## Parameters

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. Structure is for internal use only; do not modify.

### `pMemory` [in]

Pointer to be freed.

### `pFormat` [in]

Pointer's format string description.

## Remarks

You should never free the top level object, it is freed by the system.