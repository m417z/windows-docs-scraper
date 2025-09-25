# MesInqProcEncodingId function

## Description

The
**MesInqProcEncodingId** function provides the identity of an encoding.

## Parameters

### `Handle`

An encoding or decoding handle.

### `pInterfaceId`

Pointer to the address in which the identity of the interface used to encode the data will be written. The *pInterfaceId* consists of the interface universally unique identifier
[UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) and the version number.

### `pProcNum`

Number of the function used to encode the data.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_ARG** | The argument was not valid. |
| **RPC_S_OUT_OF_MEMORY** | Out of memory. |
| **RPC_S_UNKNOWN_IF** | Unknown interface. |
| **RPC_S_UNSUPPORTED_TRANS_SYN** | Transfer syntax not supported by server. |
| **RPC_X_INVALID_ES_ACTION** | Operation for a given handle was not valid. |
| **RPC_X_WRONG_ES_VERSION** | Incompatible version of the serializing package. |
| **RPC_X_SS_INVALID_BUFFER** | Buffer not valid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**MesInqProcEncodingId** function is used by applications to obtain the identity of the function used to encode the data before calling a function to decode it. When called with an encoding handle, it returns the identity of the last encoding operation. When called with a decoding handle, it returns the identity of the next decoding operation by pre-reading the buffer.

This function can only be used to check the identity of a procedure encoding; it cannot be used to check the identity for a type encoding.

## See also

[MesEncodeDynBufferHandleCreate](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesencodedynbufferhandlecreate)

[MesEncodeFixedBufferHandleCreate](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesencodefixedbufferhandlecreate)

[MesEncodeIncrementalHandleCreate](https://learn.microsoft.com/windows/desktop/api/midles/nf-midles-mesencodeincrementalhandlecreate)