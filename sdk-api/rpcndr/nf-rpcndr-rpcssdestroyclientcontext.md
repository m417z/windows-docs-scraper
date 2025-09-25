# RpcSsDestroyClientContext function

## Description

The
**RpcSsDestroyClientContext** function destroys a context handle no longer needed by the client, without contacting the server.

## Parameters

### `ContextHandle`

Context handle to be destroyed. The handle is set to **NULL** before
**RpcSsDestroyClientContext** returns.

## Return value

**RpcSsDestroyClientContext** has no return value.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

**RpcSsDestroyClientContext** is used by the client application to reclaim the memory resources used to maintain a context handle on the client. This function is used when *ContextHandle* is no longer valid, such as when a communication failure has occurred and the server is no longer available. The context handle is set to **NULL**. The
**RpcSsDestroyClientContext** function provides the same functionality as the
[RpcSmDestroyClientContext](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmdestroyclientcontext) function. This function does not invoke the server's context handle run-down process.

Do not use
**RpcSsDestroyClientContext** to replace a server function that closes the context handle.

The
**RpcSsDestroyClientContext** function can throw an RPC_X_SS_CONTEXT_MISMATCH exception if the context handle passed to it is invalid. Applications should never pass an invalid context handle to this function. If an exception is thrown, it indicates an error in the calling code, and should therefore be investigated and fixed.

## See also

[RpcBindingReset](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingreset)

[RpcSmDestroyClientContext](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcsmdestroyclientcontext)