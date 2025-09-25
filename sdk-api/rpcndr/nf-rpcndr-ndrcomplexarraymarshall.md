# NdrComplexArrayMarshall function

## Description

The **NdrComplexArrayMarshall** function marshals the complex array into a network buffer.

## Parameters

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. The **MIDL_STUB_MESSAGE** structure is for internal use only, and must not be modified.

### `pMemory` [in]

Pointer to the complex array to be marshaled.

### `pFormat` [in]

Pointer to the format string description.

## Return value

Returns null upon success. Raises one of the following exceptions upon failure.

| Error | Description |
| --- | --- |
| STATUS_ACCESS_VIOLATION | An access violation occurred. |
| RPC_S_INTERNAL_ERROR | An error occurred in RPC. |

## See also

[MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message)