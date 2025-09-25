# NdrSimpleTypeUnmarshall function

## Description

The **NdrSimpleTypeUnmarshall** function unmarshalls a simple type.

## Parameters

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. Structure is for internal use only; do not modify.

### `pMemory` [in]

Pointer to memory to unmarshall.

### `FormatChar` [in]

Format string of the simple type.

## Return value

 If an error occurs, the function throws one of the following exception codes.

| Error | Description |
| --- | --- |
| STATUS_ACCESS_VIOLATION | An access violation occurred. |
| RPC_S_INTERNAL_ERROR | An error occurred in RPC. |