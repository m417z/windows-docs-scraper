# NdrPointerUnmarshall function

## Description

The **NdrPointerUnmarshall** function unmarshalls a top level pointer to anything. Pointers embedded in
structures, arrays, or unions call **NdrPointerUnmarshall** directly.

## Parameters

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. Structure is for internal use only; do not modify.

### `ppMemory` [in]

Pointer to memory where pointer will be unmarshalled. Please see MCCP Buffer Protection for information on buffer overrun protections in RPC: [http://msdn.microsoft.com/en-us/library/ff621497(VS.85).aspx](https://learn.microsoft.com/windows/desktop/Rpc/mccp-buffer-protection)

### `pFormat` [in]

Pointer to the format string description.

### `fMustAlloc` [in]

Unused.

## Return value

Returns **NULL** upon success. If an error occurs, the function throws one of the following exception codes.

| Error | Description |
| --- | --- |
| RPC_BAD_STUB_DATA or RPC_X_INVALID_BOUND | The network buffer is incorrect. |
| RPC_S_OUT_OF_MEMORY | The system is out of memory. |
| STATUS_ACCESS_VIOLATION | An access violation occurred. |
| RPC_S_INTERNAL_ERROR | An error occurred in RPC. |

## Remarks

This function is used for FC_RP, FC_UP, FC_FP, FC_OP format strings.