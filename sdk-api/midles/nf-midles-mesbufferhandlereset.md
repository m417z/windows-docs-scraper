# MesBufferHandleReset function

## Description

The
**MesBufferHandleReset** function re-initializes the handle for buffer serialization.

## Parameters

### `Handle`

Handle to be initialized.

### `HandleStyle`

Style of *Handle*. Valid styles are **MES_FIXED_BUFFER_HANDLE** or **MES_DYNAMIC_BUFFER_HANDLE**.

### `Operation`

Operation code. Valid codes are **MES_ENCODE**, **MES_ENCODE_NDR64**, or **MES_DECODE**.

### `pBuffer`

For **MES_DECODE**, pointer to a pointer to the buffer containing the data to be decoded.

For **MES_ENCODE**, pointer to a pointer to the buffer for
[fixed buffer style](https://learn.microsoft.com/windows/desktop/Rpc/fixed-buffer-serialization), and pointer to a pointer to return the buffer address for
[dynamic buffer style of serialization](https://learn.microsoft.com/windows/desktop/Rpc/dynamic-buffer-serialization).

For **MES_ENCODE_NDR64**, pointer to a pointer to the buffer for fixed buffer style, and pointer to a pointer to return the buffer address for dynamic buffer style of serialization, but explicitly uses NDR64 to encode the buffer. The user-provided buffer must be aligned to 16.

### `BufferSize`

Bytes of data to be decoded in the buffer. Note that this is used only for the fixed buffer style of serialization.

### `pEncodedSize`

Pointer to the size of the completed encoding. Note that this is used only when the operation is **MES_ENCODE** or **MES_ENCODE_NDR64**.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_ARG** | The argument was invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**MesBufferHandleReset** routine is used by applications to re-initialize a buffer style handle and save memory allocations.

## See also

[MesEncodeDynBufferHandleCreate](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesencodedynbufferhandlecreate)

[MesEncodeFixedBufferHandleCreate](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesencodefixedbufferhandlecreate)

[MesHandleFree](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-meshandlefree)