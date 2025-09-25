# RpcImpersonateClient function

## Description

A server thread that is processing client remote procedure calls can call the
**RpcImpersonateClient** function to impersonate the active client.

## Parameters

### `BindingHandle`

Binding handle on the server that represents a binding to a client. The server impersonates the client indicated by this handle. If a value of zero is specified, the server impersonates the client that is being served by this server thread.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_NO_CALL_ACTIVE** | No client is active on this server thread. |
| **RPC_S_CANNOT_SUPPORT** | The function is not supported for either the operating system, the transport, or this security subsystem. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |
| **RPC_S_NO_CONTEXT_AVAILABLE** | The server does not have permission to impersonate the client. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

In a multithreaded application, if the call to
**RpcImpersonateClient** is with a handle to another client thread, you must call
[RpcRevertToSelfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcreverttoselfex) with the handle to that thread to end impersonation.

All functions that impersonate check to determine whether the caller of this function (the RPC Server) has the SeImpersonatePrivilege privilege. If the caller has the SeImpersonatePrivilege, or if the authenticated identity is the same as the identity of the caller of this function, the requested impersonation is allowed. Otherwise, the impersonation succeeds at Identify level only.

**Windows XP/2000/NT:** The SeImpersonatePrivilege privilege is not supported until Windows XP with Service Pack 2 (SP2).

### Security Remarks

If the call to
**RpcImpersonateClient** fails for any reason, the client connection is not impersonated and the client request is made in the security context of the process. If the process is running as a highly privileged account, such as LocalSystem, or as a member of an administrative group, the user may be able to perform actions they would otherwise be disallowed. Therefore it is important to always check the return value of the call, and if it fails, raise an error; do not continue execution of the client request.

## See also

[Client
Impersonation](https://learn.microsoft.com/windows/desktop/Rpc/client-impersonation)

[RpcRevertToSelf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcreverttoself)