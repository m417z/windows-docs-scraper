# RpcBindingReset function

## Description

The
**RpcBindingReset** function resets a binding handle so that the host is specified but the server on that host is unspecified.

## Parameters

### `Binding`

Server binding handle to reset.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A client calls the
**RpcBindingReset** function to disassociate a particular server instance from the server binding handle specified in the *Binding* parameter. The
**RpcBindingReset** function dissociates a server instance by removing the endpoint portion of the server address in the binding handle. The host remains unchanged in the binding handle. The result is a partially-bound server binding handle.

**RpcBindingReset** does not affect the *Binding* parameter's authentication information, if there is any.

If a client is willing to be serviced by any compatible server instance on the host specified in the binding handle, the client calls the
**RpcBindingReset** function before making a remote procedure call using the *Binding* binding handle. Clients must not call the
**RpcBindingReset** function for binding handles on which calls are being executed.

When the client makes the next remote procedure call using the reset (partially-bound) binding, the client's RPC run-time library uses a well-known endpoint from the client's interface specification, if any. Otherwise, the client's run-time library automatically communicates with the endpoint-mapping service on the specified remote host to obtain the endpoint of a compatible server from the endpoint-map database. If a compatible server is located, the RPC run-time library updates the binding with a new endpoint. If a compatible server is not found, the remote procedure call fails. For calls using a connection protocol (ncacn), the EPT_S_NOT_REGISTERED status code is returned to the client. For calls using a datagram protocol (ncadg), the RPC_S_COMM_FAILURE status code is returned to the client.

Server applications should register all binding handles by calling
[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister) and
[RpcEpRegisterNoReplace](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregisternoreplace) if the server wants to be available to clients that make a remote procedure call on a reset binding handle.

## See also

[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister)

[RpcEpRegisterNoReplace](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregisternoreplace)