# RpcServerInterfaceGroupDeactivate function

## Description

The **RpcServerInterfaceGroupDeactivate** function tells the RPC runtime to attempt to close the given interface group, optionally aborting the operation if there is outstanding client activity.

## Parameters

### `IfGroup` [in]

A **RPC_INTERFACE_GROUP** from [RpcServerInterfaceGroupCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupcreate) that defines the interface group to deactivate

### `ForceDeactivation` [in]

If **TRUE**, the RPC runtime should ignore client activity and unconditionally deactivate the interface group. If **FALSE**, the operation should be aborted if new activity takes place.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_SERVER_TOO_BUSY** | *ForceDeactivation* is **FALSE** and there is outstanding client activity. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

**RpcServerInterfaceGroupDeactivate** is used by server applications to unregister the interfaces and endpoints in an interface group. It does the bulk of the shutdown work that RPC server applications need to do. It performs the following operations:

* Unregisters the endpoints and interfaces from the RPC endpoint mapper.
* Unregisters the endpoints from the server runtime.
* Unregisters the interfaces from the server runtime.
* Tells the runtime to stop listening for calls if no other interfaces are present.

If *ForceDeactivation* is **FALSE**, **RpcServerInterfaceGroupDeactivate** will only deactivate the interface group if there is no outstanding client activity. If new activity arrives during the deactivation process, **RPC_S_SERVER_TOO_BUSY** is returned. In this case, the operation is rolled back and the interface group will continue to receive and dispatch calls.

If *ForceDeactivation* is **TRUE**, **RpcServerInterfaceGroupDeactivate** does not fail.

Service applications can call **RpcServerInterfaceGroupDeactivate** with *ForceDeactivation* set to **FALSE** from their idle callback function [RpcServerInterfaceGroupCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupcreate). When used in conjunction with RPC service start triggers, this enables them to safely idle stop without missing calls from potential clients.

## See also

[RpcServerInterfaceGroupActivate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupactivate)

[RpcServerInterfaceGroupClose](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupclose)

[RpcServerInterfaceGroupCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupcreate)

[RpcServerInterfaceGroupInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupinqbindings)