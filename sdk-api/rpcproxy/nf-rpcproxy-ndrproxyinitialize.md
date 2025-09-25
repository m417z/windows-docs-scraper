# NdrProxyInitialize function

## Description

The **NdrProxyInitialize** function initializes the proxy for an object method.

## Parameters

### `This` [in]

Pointer to the interface proxy.

### `pRpcMsg` [in]

Pointer to an [RPC_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcdcep/ns-rpcdcep-rpc_message) structure that contains information about the RPC request.

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. Structure is for internal use only; do not modify.

### `pStubDescriptor` [in]

Pointer to a [MIDL_STUB_DESC](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_desc) structure that contains a descriptor for the RPC stub. Structure is for internal use only; do not modify.

### `ProcNum` [in]

Procedure number for the object method.