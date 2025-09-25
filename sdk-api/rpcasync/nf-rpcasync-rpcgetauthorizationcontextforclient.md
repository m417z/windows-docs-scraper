# RpcGetAuthorizationContextForClient function

## Description

The
**RpcGetAuthorizationContextForClient** function returns the Authz context for an RPC client that can be used with Authz functions for high-performance authentication. Supported for **ncalrpc** and **ncacn_*** protocol sequences only.

## Parameters

### `ClientBinding` [in, optional]

Binding handle on the server that represents a binding to a client. The server impersonates the client indicated by this handle. If a value of zero is specified, the server impersonates the client that is being served by this server thread.

### `ImpersonateOnReturn` [in]

Directs the function to impersonate the client on return, and then return an **AUTHZ_CLIENT_CONTEXT_HANDLE** structure. Set this parameter to nonzero to impersonate the client. See Remarks.

### `Reserved1` [in]

Reserved. Must be null.

### `pExpirationTime` [in, optional]

Pointer to the expiration date and time of the token. If no value is passed, the token never expires. Expiration time is not currently enforced.

### `Reserved2` [in]

Reserved. Must be a **LUID** structure with each member set to zero.

### `Reserved3` [in]

Reserved. Must be zero.

### `Reserved4` [in]

Reserved. Must be null.

### `pAuthzClientContext` [out]

Pointer to an **AUTHZ_CLIENT_CONTEXT_HANDLE** structure that can be passed directly to Authz functions. If the function fails, the content of this parameter is undefined.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RERROR_INVALID_PARAMETER** | A reserved parameter is different than its prescribed value. |
| **RPC_S_NO_CONTEXT_AVAILABLE** | The RPC client has not been authenticated successfully. |

Failure returns an RPC_S_* error code, or a Windows error code. Extended error information is available through standard RPC or Windows error code retrieval mechanisms. For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcGetAuthorizationContextForClient** function can be called in the same context as the
**RpcImpersonateClient** function. All functions that impersonate check to determine whether the caller has the SeImpersonatePrivilege privilege. If the caller has the SeImpersonatePrivilege, or if the authenticated identity is the same as the caller, the requested impersonation is allowed. Otherwise, the impersonation succeeds at Identify level only.

**Note** The SeImpersonatePrivilege privilege is not supported until Windows XP with Service Pack 2 (SP2).

The
**RpcGetAuthorizationContextForClient** function is supported for ncalrpc and ncacn_* protocol sequences only, and is not supported on named pipes that only implement transport security.

The
**RpcGetAuthorizationContextForClient** function is thread-safe, and can be called from multiple threads. The context returned in *pAuthzClientContext* is independent of the function call, and can be used subsequent to its completion. The caller is responsible for freeing the context with a call to the
[RpcFreeAuthorizationContext](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcfreeauthorizationcontext) function.

Performance improvement observed by using the
**RpcGetAuthorizationContextForClient** function, when compared to previous methods of impersonation or access check or revert to self, depend on the following factors:

* How many times the function is called for a given client identity.
* Protocol sequence and identity tracking in effect for the function call.

Subsequent calls to the
**RpcGetAuthorizationContextForClient** function for the same client identity have an extremely low cost. This efficiency is achieved by results from previous inquiries being cached, and responses being returned from the cache whenever possible.

Calls over ncalrpc with static identity tracking execute the
**RpcGetAuthorizationContextForClient** function faster than calls over ncalrpc with dynamic identity tracking. Calls over ncacn_* execute with approximately the same speed for a given protocol sequence, regardless of whether identity tracking is static or dynamic.

## See also

[Client/Server Access
Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid)

[RPC Return
Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values)

[RpcFreeAuthorizationContext](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcfreeauthorizationcontext)

[RpcImpersonateClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcimpersonateclient)