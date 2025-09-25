# RpcFreeAuthorizationContext function

## Description

The
**RpcFreeAuthorizationContext** function frees an Authz context obtained by a previous call to the
[RpcGetAuthorizationContextForClient](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcgetauthorizationcontextforclient) function.

## Parameters

### `pAuthzClientContext` [in]

Pointer to the previously obtained Authz client context to be freed.

## Return value

Successful completion returns RPC_S_OK. This function does not fail unless an invalid parameter is provided.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The *pAuthzClientContext* parameter is a pointer to the Authz context, not the context itself. To prevent accidental reuse of the Authz context freed by this function call, RPC run-time zeros out the context upon return.

## See also

[Extended Error
Information](https://learn.microsoft.com/windows/desktop/SecAuthN/extended-error-information)

[RpcGetAuthorizationContextForClient](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcgetauthorizationcontextforclient)