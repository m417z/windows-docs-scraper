# RpcServerInterfaceGroupClose function

## Description

The **RpcServerInterfaceGroupClose** function is used to free an interface group.

## Parameters

### `IfGroup` [in]

A **RPC_INTERFACE_GROUP** from [RpcServerInterfaceGroupCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupcreate) that defines the interface group to close.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_ARG** | *IfGroup* is invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

If the given interface group is still active, **RpcServerInterfaceGroupClose** performs a forced deactivation before closing the group.

This function must not be called from an interface group’s idle callback or deadlock can occur.

## See also

[RpcServerInterfaceGroupActivate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupactivate)

[RpcServerInterfaceGroupCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupcreate)

[RpcServerInterfaceGroupDeactivate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupdeactivate)

[RpcServerInterfaceGroupInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupinqbindings)