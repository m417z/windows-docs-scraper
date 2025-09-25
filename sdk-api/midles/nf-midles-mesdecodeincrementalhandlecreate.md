# MesDecodeIncrementalHandleCreate function

## Description

The
**MesDecodeIncrementalHandleCreate** function creates a decoding handle for the incremental style of serialization.

## Parameters

### `UserState`

Pointer to the user-supplied state object that coordinates the user-supplied **Alloc**, **Write**, and **Read** functions.

### `ReadFn`

Pointer to the **Read** function.

### `pHandle`

Pointer to the newly created handle.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_ARG** | The argument was invalid. |
| **RPC_S_OUT_OF_MEMORY** | Out of memory. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**MesDecodeIncrementalHandleCreate** function is used by applications to create the handle and initialize it for the incremental style of decoding. When using the incremental style of decoding, the user supplies a **Read** function to provide a buffer containing the next part of the data to be decoded. The buffer must be aligned at 8, and the size of the buffer must be a multiple of 8. For additional information on the user-supplied **Alloc**, **Write**, and **Read** functions, see
[Serialization Services](https://learn.microsoft.com/windows/desktop/Rpc/serialization-services).

## See also

[Alloc](https://learn.microsoft.com/windows/desktop/Rpc/incremental-serialization)

[MesHandleFree](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-meshandlefree)

[MesIncrementalHandleReset](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesincrementalhandlereset)