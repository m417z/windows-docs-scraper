# NdrProxyFreeBuffer function

## Description

The **NdrProxyFreeBuffer** function frees an RPC buffer.

## Parameters

### `This` [in]

Pointer to the interface proxy.

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. The **pRpcMsg** member points to a structure whose **Buffer** member is to be freed. Structure is for internal use only; do not modify.

## Remarks

The **NdrProxyFreeBuffer** function calls the [IRpcChannelBuffer::FreeBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irpcchannelbuffer-freebuffer) method to free the RPC buffer and release [IRpcChannelBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcchannelbuffer).