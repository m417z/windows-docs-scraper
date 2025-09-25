# RpcServerInterfaceGroupInqBindings function

## Description

The **RpcServerInterfaceGroupInqBindings** function returns the binding handles over which remote procedure calls can be received for the given interface group.

## Parameters

### `IfGroup` [in]

A **RPC_INTERFACE_GROUP** from [RpcServerInterfaceGroupCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupcreate) that defines the interface group for which the bindings should be queried.

### `BindingVector` [out]

Returns a pointer to a pointer to a vector of server binding handles.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_NO_BINDINGS** | There are no bindings. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A server application calls **RpcServerInterfaceGroupInqBindings** to obtain a vector of server binding handles for the given interface group. The RPC run-time library creates binding handles for an interface group when a server application calls the [RpcServerInterfaceGroupActivate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupactivate) function.

The returned binding vector can contain binding handles with dynamic endpoints or binding handles with well-known endpoints, depending on the interface group’s endpoint specification.

A server uses the vector of binding handles for exporting to the name service or for conversion to string bindings. If there are no binding handles (no registered protocol sequences), **RpcServerInterfaceGroupInqBindings** returns **RPC_S_NO_BINDINGS** and *BindingVector* is **NULL**. The server is responsible for calling [RpcBindingVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingvectorfree) to release the vector's memory.

## See also

[RpcServerInterfaceGroupActivate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupactivate)

[RpcServerInterfaceGroupClose](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupclose)

[RpcServerInterfaceGroupCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupcreate)

[RpcServerInterfaceGroupDeactivate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupdeactivate)