# MesEncodeDynBufferHandleCreate function

## Description

The
**MesEncodeDynBufferHandleCreate** function creates an encoding handle and then initializes it for a dynamic buffer style of serialization.

## Parameters

### `pBuffer`

Pointer to a pointer to the stub-supplied buffer containing the encoding after serialization is complete.

### `pEncodedSize`

Pointer to the size of the completed encoding. The size will be written to the memory location pointed to by *pEncodedSize* by subsequent encoding operations.

### `pHandle`

Pointer to the address to which the handle will be written.

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
**MesEncodeDynBufferHandleCreate** routine is used by applications to allocate the memory and initialize the handle for the dynamic buffer style of encoding. When using the dynamic buffer style of encoding, the buffer into which all the encoded data will be placed is supplied by the stub. This buffer will be allocated by the current client memory-management mechanism.

There can be performance implications when using this style for multiple encodings with the same handle. A single buffer is returned from an encoding and data is copied from intermediate buffers. The buffers are released when necessary.

When a stub is compiled using -protocol all or -protocol ndr64 and the buffer is to be encoded using the NDR64 transfer syntax, the
MesBufferHandleReset function must be called with its *OpCode* parameter set to MES_ENCODE_NDR64.

## See also

[MesBufferhandleReset](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesbufferhandlereset)

[MesHandleFree](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-meshandlefree)