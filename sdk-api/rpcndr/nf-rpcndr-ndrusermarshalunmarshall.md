# NdrUserMarshalUnmarshall function

## Description

The **NdrUserMarshalUnmarshall** function calls a user-defined unmarshal routine to unmarshal data with the attribute.

## Parameters

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. The **MIDL_STUB_MESSAGE** structure is for internal use only, and must not be modified.

### `ppMemory` [in]

Pointer to user data object to be unmarshalled.

### `pFormat` [in]

Format string description of the pointer.

### `fMustAlloc` [in]

Flag that specifies whether the stub must allocate the memory into which the user data object is to be unmarshalled. Specify **TRUE** if RPC must allocate *ppMemory*.

## Return value

Returns **NULL** upon success. Returns one of the following exception codes upon error.

| Error | Description |
| --- | --- |
| STATUS_ACCESS_VIOLATION | An access violation occurred. |
| RPC_S_INTERNAL_ERROR | An error occurred in RPC. |

## See also

[MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message)

[wire_marshal](https://msdn.microsoft.com/)