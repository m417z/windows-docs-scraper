# NdrInterfacePointerBufferSize function

## Description

The **NdrInterfacePointerBufferSize** function calculates the size of the buffer, in bytes, needed to marshal the interface pointer.

## Parameters

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. The **BufferLength** member contains the size of the buffer. This structure is for internal use only and should not be modified.

### `pMemory` [in]

Pointer to the interface pointer to be calculated.

### `pFormat` [in]

Pointer to the format string description.

## Return value

This function has no return values. If an error occurs, the function throws one of the following exception codes. In addition, the function can throw exception codes from [CoGetMarshalSizeMax](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetmarshalsizemax).

| Error | Description |
| --- | --- |
| STATUS_ACCESS_VIOLATION | An access violation occurred. |
| RPC_S_INTERNAL_ERROR | An error occurred in RPC. |