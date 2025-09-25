# NdrSimpleStructUnmarshall function

## Description

The **NdrSimpleStructUnmarshall** function unmarshals the simple structure from the network buffer to memory.

## Parameters

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. The **MIDL_STUB_MESSAGE** structure is for internal use only, and must not be modified.

### `ppMemory` [out]

Address to a pointer to the unmarshalled simple structure. If set to null, or if the *fMustAlloc* parameter is set to **TRUE**, the stub will allocate the memory.

### `pFormat` [in]

Pointer to the format string description.

### `fMustAlloc` [in]

Flag that specifies whether the stub must allocate the memory into which the simple structure is to be marshaled. Specify **TRUE** if RPC must allocate *ppMemory*.

## Return value

Returns null upon success. Raises one of the following exceptions upon failure.

| Error | Description |
| --- | --- |
| RPC_BAD_STUB_DATA or RPC_X_INVALID_BOUND | The network is incorrect. |
| RPC_S_OUT_OF_MEMORY | Out of memory. |
| STATUS_ACCESS_VIOLATION | An access violation occurred. |
| RPC_S_INTERNAL_ERROR | An error occurred in RPC. |

## See also

[MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message)