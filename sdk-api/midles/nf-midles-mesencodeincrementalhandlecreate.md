# MesEncodeIncrementalHandleCreate function

## Description

The
**MesEncodeIncrementalHandleCreate** function creates an encoding and then initializes it for the incremental style of serialization.

## Parameters

### `UserState`

Pointer to the user-supplied state object that coordinates the user-supplied **Alloc**, **Write**, and **Read** functions.

### `AllocFn`

Pointer to the user-supplied **Alloc** function.

### `WriteFn`

Pointer to the user-supplied **Write** function.

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
**MesEncodeIncrementalHandleCreate** function is used by applications to create and initialize the handle for the incremental style of encoding or decoding. When using the incremental style of encoding, the user supplies an **Alloc** function to provide an empty buffer into which the encoded data is placed, and a **Write** function to call when the buffer is full or the encoding is complete. For additional information on the user-supplied **Alloc**, **Write**, and **Read** functions, see
[Serialization Services](https://learn.microsoft.com/windows/desktop/Rpc/serialization-services).

When a stub is compiled using **-protocol all** or **-protocol ndr64** and the buffer is to be encoded using the NDR64 transfer syntax, the
[MesIncrementalHandleReset](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesbufferhandlereset) function must be called with its *OpCode* parameter set to MES_ENCODE_NDR64.

## See also

[Alloc](https://learn.microsoft.com/windows/desktop/Rpc/incremental-serialization)

[MesBufferHandleReset](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesbufferhandlereset)

[MesHandleFree](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-meshandlefree)

[MesIncrementalHandleReset](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesincrementalhandlereset)