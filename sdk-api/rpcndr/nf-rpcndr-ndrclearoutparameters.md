# NdrClearOutParameters function

## Description

The **NdrClearOutParameters** function frees resources of the out parameter and clears its memory if the RPC call to the server fails.

## Parameters

### `pStubMsg` [in]

Pointer to [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. The structure is for internal use only and should not be modified.

### `pFormat` [in]

Pointer to the format string description.

### `ArgAddr` [in, out]

Pointer to the out parameter to be freed.