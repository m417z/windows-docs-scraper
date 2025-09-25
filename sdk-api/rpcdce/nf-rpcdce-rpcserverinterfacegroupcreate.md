# RpcServerInterfaceGroupCreate function

## Description

The **RpcServerInterfaceGroupCreate** function creates an RPC server interface group for the server application. This interface group fully specifies the interfaces, endpoints, and idle properties of an RPC server application. Once created, an interface group can be activated and deactivated as the application requires.

## Parameters

### `Interfaces` [in]

A pointer to an array of [RPC_INTERFACE_TEMPLATE](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_interface_template) structures that define the interfaces exposed by the interface group.

### `NumIfs` [in]

The number of elements in *Interfaces*.

### `Endpoints` [in]

A pointer to an array of [RPC_ENDPOINT_TEMPLATE](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_endpoint_template) structures that define the endpoints used by the interface group.

### `NumEndpoints` [in]

The number of elements in *Endpoints*.

### `IdlePeriod` [in]

The length of time in seconds after the interface group becomes idle that the RPC runtime should wait before invoking the idle callback. 0 means the callback is invoked immediately. **INFINITE** means the server application does not care about the interface group’s idle state.

### `IdleCallbackFn` [in]

A [RPC_INTERFACE_GROUP_IDLE_CALLBACK_FN](https://learn.microsoft.com/windows/desktop/api/rpcdce/nc-rpcdce-rpc_interface_group_idle_callback_fn) callback that the RPC runtime will invoke once the interface group is idle for the length of time given in *IdlePeriod*. Can be **NULL** only if *IdlePeriod* is **INFINITE**.

### `IdleCallbackContext` [in]

A user-defined pointer to be passed to the idle callback in *IdleCallbackFn*.

### `IfGroup` [out]

If successful, a pointer to an **RPC_INTERFACE_GROUP** buffer that receives the handle to the newly created interface group. If this function fails, *IfGroup* is undefined.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A server application can optionally be notified when an interface group becomes idle. Though any application can take advantage of this functionality, it is targeted towards service developers who would like to enable their service to idle stop.

*IdlePeriod* prevents the RPC runtime from producing a large number of notifications if the idle state rapidly changes, and in the case of triggered services, helps the service avoid needlessly starting and stopping. Developers should consider the cost of service initialization and shutdown, the expected frequency with which new activity will occur, and the cost of keeping the service sitting idle when selecting this value. A low idle period will cause the service to frequently start and stop as new client activity takes place, whereas a high idle period will cause the service to consume resources without performing meaningful work.

Interfaces in an interface group can only be called over endpoints of the same group. Interfaces that are not part of an interface group cannot be called over endpoints that are part of a group.

RPC server activity is not always visible to the server application. In some cases, simply having a client with an open connection to the server may keep it active even if no calls have been dispatched for a long period of time. Server applications must not rely on any correlation between the RPC runtime declaring that the group is idle and the time since the last call was dispatched.

## See also

[RpcServerInterfaceGroupActivate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupactivate)

[RpcServerInterfaceGroupClose](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupclose)

[RpcServerInterfaceGroupDeactivate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupdeactivate)

[RpcServerInterfaceGroupInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupinqbindings)