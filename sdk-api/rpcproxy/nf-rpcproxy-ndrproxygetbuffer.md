# NdrProxyGetBuffer function

## Description

The **NdrProxyGetBuffer** function obtains a network buffer from COM through the use of an [IRpcChannelBuffer::GetBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irpcchannelbuffer-getbuffer) method call.

## Parameters

### `This` [in]

Pointer to the interface proxy.

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. The **pRpcMsg** member points to a structure whose **Buffer** member points to the newly allocated buffer. Structure is for internal use only; do not modify.