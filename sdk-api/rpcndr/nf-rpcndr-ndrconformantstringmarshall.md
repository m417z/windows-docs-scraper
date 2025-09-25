# NdrConformantStringMarshall function

## Description

The **NdrConformantStringMarshall** function marshals the conformant string into a network buffer to be sent to the server.

## Parameters

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. This structure is for internal use only and should not be modified.

### `pMemory` [in]

Pointer to the null-terminated conformant string to be marshaled.

### `pFormat` [in]

Pointer to the format string description.

## Return value

Returns null upon success. If an error occurs, the function throws one of the following exception codes.

| Error | Description |
| --- | --- |
| STATUS_ACCESS_VIOLATION | An access violation occurred. |
| RPC_S_INTERNAL_ERROR | An error occurred in RPC. |