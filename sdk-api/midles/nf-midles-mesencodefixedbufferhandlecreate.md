# MesEncodeFixedBufferHandleCreate function

## Description

The
**MesEncodeFixedBufferHandleCreate** function creates an encoding handle and then initializes it for a fixed buffer style of serialization.

## Parameters

### `pBuffer`

Pointer to the user-supplied buffer.

### `BufferSize`

Size of the user-supplied buffer, in bytes.

### `pEncodedSize`

Pointer to the size of the completed encoding. The size will be written to the pointee by the subsequent encoding operation(s).

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
**MesEncodeFixedBufferHandleCreate** routine is used by applications to create and initialize the handle for the fixed buffer style of encoding. When using the fixed buffer style of encoding, the user supplies a single buffer into which all the encoded data is placed. This buffer must have an address which is aligned at 8, and must be a multiple of 8 bytes in size. Further, it must be large enough to hold an encoding of all the data, along with an encoding header for each routine being encoded.

When the handle is used for multiple encoding operations, the encoded size is cumulative.

When a stub is compiled using **-protocol all** or **-protocol ndr64** and the buffer is to be encoded using the NDR64 transfer syntax, the
[MesBufferHandleReset](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesbufferhandlereset) function must be called with its *OpCode* parameter set to MES_ENCODE_NDR64.

## See also

[MesBufferhandleReset](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesbufferhandlereset)

[MesDecodeBufferHandleCreate](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesdecodebufferhandlecreate)

[MesHandleFree](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-meshandlefree)