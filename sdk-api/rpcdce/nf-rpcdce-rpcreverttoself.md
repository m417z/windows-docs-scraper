# RpcRevertToSelf function

## Description

After calling
[RpcImpersonateClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcimpersonateclient) and completing any tasks that require client impersonation, the server calls
**RpcRevertToSelf** to end impersonation and to reestablish its own security identity.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_NO_CALL_ACTIVE** | The server does not have a client to impersonate. |
| **RPC_S_INVALID_BINDING** | The binding handle is invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This is the wrong kind of binding for this operation. |
| **RPC_S_CANNOT_SUPPORT** | The call is not supported for this operating system, this transport, or this security subsystem. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

In a multithreaded application, if the call to
[RpcImpersonateClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcimpersonateclient) is with a handle to another client thread, you must call
[RpcRevertToSelfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcreverttoselfex) with the handle to that thread to end impersonation.

## See also

[Client
Impersonation](https://learn.microsoft.com/windows/desktop/Rpc/client-impersonation)

[RpcImpersonateClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcimpersonateclient)