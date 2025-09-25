# NdrConformantStringUnmarshall function

## Description

The **NdrConformantStringUnmarshall** function unmarshals the conformant string from the network buffer to memory.

## Parameters

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. This structure is for internal use only and should not be modified.

### `ppMemory` [out]

Address to a pointer to the unmarshalled conformant string. If set to null, or if the *fMustAlloc* is set to **TRUE**, the stub will allocate the memory.

### `pFormat` [in]

Pointer to the format string description.

### `fMustAlloc` [in]

Flag that specifies whether the stub must allocate the memory into which the conformant string is to be marshaled. Specify **TRUE** if RPC must allocate *ppMemory*.

## Return value

Returns null upon success. If an error occurs, the function throws one of the following exception codes.

| Error | Description |
| --- | --- |
| RPC_BAD_STUB_DATA or RPC_X_INVALID_BOUND | The network is incorrect. |
| RPC_S_OUT_OF_MEMORY | Out of memory. |
| STATUS_ACCESS_VIOLATION | An access violation occurred. |
| RPC_S_INTERNAL_ERROR | An error occurred in RPC. |