# NdrPointerMarshall function

## Description

The **NdrPointerMarshall** function marshalls a top level pointer to anything. Pointers embedded in
structures, arrays, or unions call **NdrPointerMarshall** directly.

## Parameters

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. Structure is for internal use only; do not modify.

### `pMemory` [in]

Pointer to the pointer to be marshalled.

### `pFormat` [in]

Pointer to the format string description.

## Return value

Returns **NULL** upon success. If an error occurs, the function throws one of the following exception codes.

| Error | Description |
| --- | --- |
| STATUS_ACCESS_VIOLATION | An access violation occurred. |
| RPC_S_INTERNAL_ERROR | An error occurred in RPC. |

## Remarks

This function is used for FC_RP, FC_UP, FC_FP, FC_OP format strings.