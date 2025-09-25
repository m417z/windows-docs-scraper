# MesDecodeBufferHandleCreate function

## Description

The
**MesDecodeBufferHandleCreate** function creates a decoding handle and initializes it for a (fixed) buffer style of serialization.

## Parameters

### `Buffer`

Pointer to the buffer containing the data to decode.

### `BufferSize`

Bytes of data to decode in the buffer.

### `pHandle`

Pointer to the address to which the handle will be written.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_ARG** | The argument was not valid. |
| **RPC_S_OUT_OF_MEMORY** | Out of memory. |
| **RPC_X_INVALID_BUFFER** | The buffer was not valid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**MesDecodeBufferHandleCreate** routine is used by applications to create a serialization handle and initialize the handle for the (fixed) buffer style of decoding. When using the fixed buffer style of decoding, the user supplies a single buffer containing all the encoded data. This buffer must have an address which is aligned at 8, and must be a multiple of 8 bytes in size. Further, it must be large enough to hold all of the data to decode.

## See also

[MesEncodeFixedBufferHandleCreate](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesencodefixedbufferhandlecreate)

[MesHandleFree](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-meshandlefree)