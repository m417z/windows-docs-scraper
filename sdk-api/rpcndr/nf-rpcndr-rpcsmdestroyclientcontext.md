# RpcSmDestroyClientContext function

## Description

The
**RpcSmDestroyClientContext** function reclaims the client memory resources for a context handle and makes the context handle **NULL**.

## Parameters

### `ContextHandle`

Context handle that can no longer be used. The handle is set to **NULL** before **RpcSMDestroyClientContext** returns.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_X_SS_CONTEXT_MISMATCH** | The handle is invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

Client applications use
**RpcSmDestroyClientContext** to reclaim resources from an inactive context handle. Applications can call
**RpcSmDestroyClientContext** after a communications error makes the context handle unusable. The
**RpcSmDestroyClientContext** function provides the same functionality as the
[RpcSsDestroyClientContext](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssdestroyclientcontext) function.

This function does not invoke the server's context handle run-down process.

When
**RpcSmDestroyClientContext** reclaims the memory resources, it also makes the context handle **NULL**. For more information, see
[Using Context Handles](https://learn.microsoft.com/windows/desktop/Rpc/using-context-handles).

## See also

[RpcSsDestroyClientContext](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-rpcssdestroyclientcontext)