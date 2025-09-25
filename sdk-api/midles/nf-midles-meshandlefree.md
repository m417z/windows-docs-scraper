# MesHandleFree function

## Description

The
**MesHandleFree** function frees the memory allocated by the serialization handle.

## Parameters

### `Handle`

Handle to be freed.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**MesHandleFree** routine is used by applications to free the resources of the handle after encoding or decoding data.

## See also

[MesDecodeBufferHandleCreate](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesdecodebufferhandlecreate)

[MesEncodeDynBufferHandleCreate](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesencodedynbufferhandlecreate)

[MesEncodeFixedBufferHandleCreate](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesencodefixedbufferhandlecreate)

[MesEncodeIncrementalHandleCreate](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesencodeincrementalhandlecreate)