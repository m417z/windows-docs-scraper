# RpcServerUnregisterIfEx function

## Description

The
**RpcServerUnregisterIfEx** function removes an interface from the RPC run-time library registry. This function extends the functionality of the
[RpcServerUnregisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterif) function.

## Parameters

### `IfSpec` [in]

Interface to remove from the registry.

Specify a null value to remove all interfaces previously registered with the type UUID value specified in the *MgrTypeUuid* parameter.

### `MgrTypeUuid` [in]

Pointer to the type UUID of the manager entry-point vector (EPV) to remove from the registry. The value of *MgrTypeUuid* should be the same value as was provided in a call to the
[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif) function, [RpcServerRegisterIf2](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif2) function, or the
[RpcServerRegisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterifex) function.

Specify a null value to remove the interface specified in the *IfSpec* parameter for all previously registered type UUIDs from the registry.

Specify a nil UUID to remove the MIDL-generated default manager EPV from the registry. In this case, all manager EPVs registered with a non-nil type UUID remain registered.

### `RundownContextHandles` [in]

Specifies whether rundown is called for active context handles. If non-zero, the rundown is called once all calls on the interface have completed. If set to zero, the RPC run time assumes the server has already destroyed its portion of the context handle and it will not call the rundown routines.

## Return value

Returns RPC status.
**RpcServerUnregisterIfEx** does not fail unless supplied with invalid values.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcServerUnregisterIfEx** function waits for all calls on a given interface to complete before unregistering the context handles.

The
**RpcServerUnregisterIfEx** function supplies all the functionality provided in the
[RpcServerUnregisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterif) function. In addition, the
**RpcServerUnregisterIfEx** function unregisters all context handles registered by the given interface. The interface must use the **strict_context_handle** attribute, otherwise the results are undefined.

**RpcServerUnregisterIfEx** is the only function that provides safe unloading of a DLL with active context handles outside of process shutdown. It is available on Windows XP and later versions of Windows only.

## See also

[RPC_MGR_EPV](https://learn.microsoft.com/windows/desktop/Rpc/rpc-mgr-epv)

[Registering Interfaces](https://learn.microsoft.com/windows/desktop/Rpc/registering-interfaces)

[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif)

[RpcServerRegisterIf2](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif2)

[RpcServerRegisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterifex)

[RpcServerUnregisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterif)

[Using Context
Handles](https://learn.microsoft.com/windows/desktop/Rpc/using-context-handles)