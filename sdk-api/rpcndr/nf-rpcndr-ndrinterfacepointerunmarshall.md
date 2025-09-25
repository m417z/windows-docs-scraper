# NdrInterfacePointerUnmarshall function

## Description

The **NdrInterfacePointerUnmarshall** function unmarshalls the data referenced by the interface pointer from the network buffer to memory.

## Parameters

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. Structure is for internal use only; do not modify.

### `ppMemory` [out]

Pointer to a pointer to the unmarshalled interface pointer.

### `pFormat` [in]

Pointer to the format string description.

### `fMustAlloc` [in]

Unused.

## Return value

Returns NULL upon success. If an error occurs, the function throws one of the following exception codes. In addition, the function can throw exception codes from [CoUnmarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-counmarshalinterface).

| Error | Description |
| --- | --- |
| RPC_BAD_STUB_DATA | The network buffer is incorrect. |
| RPC_S_OUT_OF_MEMORY | The system is out of memory. |
| STATUS_ACCESS_VIOLATION | An access violation occurred. |
| RPC_S_INTERNAL_ERROR | An error occurred in RPC. |