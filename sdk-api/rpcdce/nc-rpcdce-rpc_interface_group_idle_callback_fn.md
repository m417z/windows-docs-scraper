# RPC_INTERFACE_GROUP_IDLE_CALLBACK_FN callback function

## Description

The **RPC_INTERFACE_GROUP_IDLE_CALLBACK_FN** is a user-defined callback that can be implemented for each defined interface group. This callback is invoked by the RPC runtime when it detects that the idle state of an interface group has changed.

## Parameters

### `IfGroup` [in]

A **RPC_INTERFACE_GROUP** from [RpcServerInterfaceGroupCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupcreate) that defines the interface group for which the idle state has changed.

### `IdleCallbackContext` [in]

A user-defined context provided at interface group creation.

### `IsGroupIdle` [in]

**TRUE** if the interface group has just become idle. **FALSE** if the interface group was previously idle but has since received new activity.

## Remarks

When a server registers an interface group, it provides a pointer to an idle callback function through which RPC will notify the application when the interface group’s idle state has changed. The server application can use this callback to attempt to deactivate the interface group when it becomes idle.

[RpcServerInterfaceGroupClose](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupclose) must not be called from this callback or deadlock can occur.

Note that RPC server activity is not always visible to the server application. In some cases, simply having a client with an open connection to the server may keep it active even if no calls have been dispatched for a long period of time. Server applications must not rely on any correlation between the RPC runtime declaring that the group is idle and the time since the last call was dispatched.

## See also

[RpcServerInterfaceGroupActivate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupactivate)

[RpcServerInterfaceGroupClose](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupclose)

[RpcServerInterfaceGroupCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupcreate)

[RpcServerInterfaceGroupDeactivate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupdeactivate)

[RpcServerInterfaceGroupInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupinqbindings)