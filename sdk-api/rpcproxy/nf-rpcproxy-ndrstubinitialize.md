# NdrStubInitialize function

## Description

The **NdrStubInitialize** function is called by the server stub before unmarshalling.
It sets up some stub message fields.

## Parameters

### `pRpcMsg` [in]

Pointer to the [RPC_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcdcep/ns-rpcdcep-rpc_message) structure which contains the RPC message.

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. Structure is for internal use only; do not modify.

### `pStubDescriptor` [in]

Pointer to a [MIDL_STUB_DESC](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_desc) structure that contains a descriptor for the RPC stub. Structure is for internal use only; do not modify.

### `pRpcChannelBuffer` [in]

Pointer to RPC channel buffer.

## See also

[IRpcChannelBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcchannelbuffer)