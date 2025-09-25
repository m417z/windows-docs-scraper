# NdrInterfacePointerFree function

## Description

The **NdrInterfacePointerFree** function releases the interface pointer.

## Parameters

### `pStubMsg`

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. This structure is for internal use only and should not be modified.

### `pMemory` [in]

Pointer to the interface pointer to be released.

### `pFormat` [in]

Pointer to the format string description.