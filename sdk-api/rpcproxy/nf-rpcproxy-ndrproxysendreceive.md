# NdrProxySendReceive function

## Description

The **NdrProxySendReceive** function sends a message to the server then waits for a reply.

## Parameters

### `This` [in]

Pointer to the interface proxy.

### `pStubMsg` [in, out]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. Structure is for internal use only; do not modify.