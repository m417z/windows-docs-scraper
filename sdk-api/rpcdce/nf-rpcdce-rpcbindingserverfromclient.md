# RpcBindingServerFromClient function

## Description

An application calls
**RpcBindingServerFromClient** to convert a client binding handle into a partially-bound server binding handle.

## Parameters

### `ClientBinding`

Client binding handle to convert to a server binding handle. If a value of zero is specified, the server impersonates the client that is being served by this server thread.

**Note** This parameter cannot be **NULL** in Windows NT 4.0.

### `ServerBinding`

Returns a server binding handle.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |
| **RPC_S_CANNOT_SUPPORT** | Cannot determine the client's host. See Remarks for a list of supported protocol sequences. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The following protocol sequences support
**RpcBindingServerFromClient**:

* [ncadg_ip_udp](https://learn.microsoft.com/windows/desktop/Midl/ncadg-ip-udp)
* [ncadg_ipx](https://msdn.microsoft.com/)
* [ncacn_ip_tcp](https://learn.microsoft.com/windows/desktop/Midl/ncacn-ip-tcp)
* [ncacn_spx](https://learn.microsoft.com/windows/desktop/Midl/ncacn-spx).
* [ncacn_np](https://learn.microsoft.com/windows/desktop/Midl/ncacn-np) (effective with Windows 2000)
* [ncacn_http](https://msdn.microsoft.com/)
* ncalrpc

An application gets a client binding handle from the RPC run-time. When the remote procedure call arrives at a server, the run-time creates a client binding handle that contains information about the calling client. The run-time passes this handle to the server manager function as the first argument.

Calling
**RpcBindingServerFromClient** converts this client handle to a server handle that has these properties:

* The server handle is a partially-bound handle. It contains a network address for the calling client, but lacks an endpoint.
* The server handle contains the same object
  [UUID](https://msdn.microsoft.com/) used by the calling client. This can be the nil UUID. For more information on how a client specifies an object UUID for a call, see
  [RpcBindingsetObject](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetobject),
  [RpcNsBindingImportBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportbegina),
  [RpcNsBindingLookupBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupbegina), and
  [RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding).
* The server handle contains no authentication information.

The server application must call
[RpcBindingFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfree) to free the resources used by the server binding handle once it is no longer needed.

**Note** To query a client's address, an application starts by calling the RpcBindingServerFromClient function to obtain a partially bound server binding handle. The server binding handle can be used to obtain a string binding by invoking RpcBindingToStringBinding. The server can then call RpcStringBindingParse to extract the client's network address from the string binding.

## See also

[RpcBindingFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfree)

[RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding)

[RpcBindingSetObject](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetobject)

[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister)

[RpcEpRegisterNoReplace](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregisternoreplace)

[RpcNsBindingImportBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportbegina)

[RpcNsBindingLookupBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupbegina)