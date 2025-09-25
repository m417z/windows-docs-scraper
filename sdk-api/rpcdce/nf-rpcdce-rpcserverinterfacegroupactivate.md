# RpcServerInterfaceGroupActivate function

## Description

The **RpcServerInterfaceGroupActivate** function tells the RPC server runtime to register the interface group’s interfaces and endpoints and begin listening for calls.

## Parameters

### `IfGroup` [in]

A **RPC_INTERFACE_GROUP** from [RpcServerInterfaceGroupCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupcreate) that defines the interface group to activate.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_PROTSEQ_NOT_SUPPORTED** | The protocol sequence is not supported on this host. |
| **RPC_S_INVALID_RPC_PROTSEQ** | The protocol sequence is invalid. |
| **RPC_S_INVALID_ENDPOINT_FORMAT** | The endpoint format is invalid. |
| **RPC_S_OUT_OF_MEMORY** | The system is out of memory. |
| **RPC_S_INVALID_SECURITY_DESC** | The security descriptor for an endpoint or interface is invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

**RpcServerInterfaceGroupActivate** does the bulk of the initialization work that the RPC server applications need to do. It performs the following operations:

* Instructs the RPC runtime to begin listening for calls.
* Registers the endpoints with the server runtime.
* Registers the interfaces with the server runtime.
* Registers the endpoints and interfaces with the RPC endpoint mapper.

**RpcServerInterfaceGroupActivate** is atomic. If at any point the operation fails, any items that were previously registered are undone.

Calls may be dispatched to the server application before this function returns.

## See also

[RpcServerInterfaceGroupClose](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupclose)

[RpcServerInterfaceGroupCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupcreate)

[RpcServerInterfaceGroupDeactivate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupdeactivate)

[RpcServerInterfaceGroupInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupinqbindings)