# RpcRevertToSelfEx function

## Description

The
**RpcRevertToSelfEx** function allows a server to impersonate a client and then revert in a multithreaded operation where the call to impersonate a client can come from a thread other than the thread originally dispatched from the RPC.

## Parameters

### `BindingHandle`

Binding handle on the server that represents a binding to the client that the server impersonated. A value of zero specifies the client handle of the current thread; in this case, the functionality of
**RpcRevertToSelfEx** is identical to that of the
[RpcRevertToSelf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcreverttoself) function.

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

After calling
[RpcImpersonateClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcimpersonateclient) and completing any tasks that require client impersonation, the server calls
**RpcRevertToSelfEx** to end impersonation and to reestablish its own security identity. For example, consider a primary thread, called thread1, which is dispatched from a remote client and wakes up a worker thread, called thread2. If thread2 requires that the server impersonate the client, the server calls
**RpcImpersonateClient**(THREAD1_CALL_HANDLE), performs the required task, calls
**RpcRevertToSelfEx**(THREAD1_CALL_HANDLE) to end the impersonation, and then wakes up thread1.

## See also

[Client
Impersonation](https://learn.microsoft.com/windows/desktop/Rpc/client-impersonation)

[RpcImpersonateClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcimpersonateclient)

[RpcRevertToSelf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcreverttoself)