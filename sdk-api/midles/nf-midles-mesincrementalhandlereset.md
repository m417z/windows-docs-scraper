# MesIncrementalHandleReset function

## Description

The
**MesIncrementalHandleReset** function re-initializes the handle for incremental serialization.

## Parameters

### `Handle`

Handle to be re-initialized.

### `UserState`

Depending on the function, pointer to the user-supplied block that coordinates successive calls to the user-supplied **Alloc**, **Write**, and **Read** functions.

### `AllocFn`

Pointer to the user-supplied **Alloc** function. This parameter can be **NULL** if the operation does not require it, or if the handle was previously initiated with the pointer.

### `WriteFn`

Pointer to the user-supplied **Write** function. This parameter can be **NULL** if the operation does not require it, or if the handle was previously initiated with the pointer.

### `ReadFn`

Pointer to the user-supplied **Read** function. This parameter can be **NULL** if the operation does not require it, or if the handle was previously initiated with the pointer.

### `Operation`

Specifies the operation. Valid operations are **MES_ENCODE**, **MES_ENCODE_NDR64**, or **MES_DECODE**.

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
**MesIncrementalHandleReset** routine is used by applications to re-initialize the handle for the incremental style of encoding or decoding. For additional information on the user-supplied **Alloc**, **Write**, and **Read** functions, see
[Serialization Services](https://learn.microsoft.com/windows/desktop/Rpc/serialization-services).

## See also

[Alloc](https://learn.microsoft.com/windows/desktop/Rpc/incremental-serialization)

[MesBufferhandleReset](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesbufferhandlereset)

[MesEncodeIncrementalHandleCreate](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesencodeincrementalhandlecreate)

[MesHandleFree](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-meshandlefree)