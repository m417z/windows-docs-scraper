# NdrStubGetBuffer function

## Description

The **NdrStubGetBuffer** function retrieves a buffer from the RPC channel.

## Parameters

### `This` [in]

Pointer to the stub.

### `pRpcChannelBuffer` [in]

Pointer to RPC channel.

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. The **pRpcMsg** member points to a structure whose **Buffer** member points to the newly allocated buffer. Structure is for internal use only; do not modify.

## See also

[IRpcChannelBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcchannelbuffer)

[IRpcStubBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcstubbuffer)