# RpcServerUnregisterIf function

## Description

The
**RpcServerUnregisterIf** function removes an interface from the RPC run-time library registry.

## Parameters

### `IfSpec`

Interface to remove from the registry.

Specify a **null** value to remove all interfaces previously registered with the type UUID value specified in the *MgrTypeUuid* parameter.

### `MgrTypeUuid`

Pointer to the type UUID of the manager entry-point vector (EPV) to remove from the registry. The value of *MgrTypeUuid* should be the same value as was provided in a call to the
[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif) function, [RpcServerRegisterIf2](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif2) function, or the
[RpcServerRegisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterifex) function.

Specify a **null** value to remove the interface specified in the *IfSpec* parameter for all previously registered type UUIDs from the registry.

Specify a nil UUID to remove the MIDL-generated default manager EPV from the registry. In this case, all manager EPVs registered with a non-nil type UUID remain registered.

### `WaitForCallsToComplete`

Flag that indicates whether to remove the interface from the registry immediately or to wait until all current calls are complete.

Specify a value of zero to disregard calls in progress and remove the interface from the registry immediately. Specify any nonzero value to wait until all active calls complete.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_UNKNOWN_MGR_TYPE** | The manager type is unknown. |
| **RPC_S_UNKNOWN_IF** | The interface is unknown. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A server calls
**RpcServerUnregisterIf** to remove the association between an interface and a manager EPV. To specify the manager EPV to remove in the *MgrTypeUuid* parameter, provide the type UUID value that was specified in a call to
[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif). After it is removed from the registry, an interface is no longer available to client applications.

When an interface is removed from the registry, the RPC run-time library stops accepting new calls for that interface. Calls that are currently executing on the interface are allowed to complete, including callbacks.

The following table summarizes the behavior of
**RpcServerUnregisterIf**.

| IfSpec | MgrTypeUuid | Behavior |
| --- | --- | --- |
| Non-**null** | Non-**null** | Removes from the registry the manager EPV associated with the specified parameters. |
| Non-**null** | **NULL** | Removes all manager EPVs associated with the *IfSpec* parameter. |
| **NULL** | Non-**null** | Removes all manager EPVs associated with the *MgrTypeUuid* parameter. |
| **NULL** | **NULL** | Removes all manager EPVs. This call has the effect of preventing the server from receiving any new remote procedure calls because all the manager EPVs for all interfaces have been unregistered. |

**Note** If the value of *IfSpec* is **NULL**, this function will leave *auto-listen* interfaces registered. *Auto-listen* interfaces must be removed from the registry individually. See
[RpcServerRegisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterifex) for more details.

## See also

[RPC_MGR_EPV](https://learn.microsoft.com/windows/desktop/Rpc/rpc-mgr-epv)

[Registering Interfaces](https://learn.microsoft.com/windows/desktop/Rpc/registering-interfaces)

[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif)

[RpcServerRegisterIf2](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif2)

[RpcServerRegisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterifex)

[RpcServerUnregisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterifex)