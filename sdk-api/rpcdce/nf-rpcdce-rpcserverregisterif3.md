# RpcServerRegisterIf3 function

## Description

The
**RpcServerRegisterIf3** function registers an interface with the RPC run-time library.

## Parameters

### `IfSpec` [in]

MIDL-generated structure indicating the interface to register.

### `MgrTypeUuid` [in, optional]

Pointer to a type **UUID** to associate with the *MgrEpv* parameter. Specifying a **null** parameter value (or a nil **UUID**) registers *IfSpec* with a nil-type **UUID**.

### `MgrEpv` [in, optional]

Manager routines' entry-point vector (EPV). To use the MIDL-generated default EPV, specify a **null** value. For more information, please see [RPC_MGR_EPV](https://learn.microsoft.com/windows/desktop/Rpc/rpc-mgr-epv).

### `Flags` [in]

Flags. For a list of flag values, see
[Interface Registration Flags](https://learn.microsoft.com/windows/desktop/Rpc/interface-registration-flags).

### `MaxCalls` [in]

Maximum number of concurrent remote procedure call requests the server can accept on an **auto-listen** interface. The *MaxCalls* parameter is only applicable on an **auto-listen** interface, and is ignored on interfaces that are not **auto-listen**. The RPC run-time library makes its best effort to ensure the server does not allow more concurrent call requests than the number of calls specified in *MaxCalls*. The actual number can be greater and can vary for each protocol sequence.

Calls on other interfaces are governed by the value of the process-wide *MaxCalls* parameter specified in the
[RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten) function call.

If the number of concurrent calls is not a concern, you can achieve slightly better server-side performance by specifying the default value using RPC_C_LISTEN_MAX_CALLS_DEFAULT. Doing so relieves the RPC run-time environment from enforcing an unnecessary restriction.

### `MaxRpcSize` [in]

Maximum size of incoming data blocks, in bytes. This parameter may be used to help prevent malicious denial-of-service attacks. If the data block of a remote procedure call is larger than *MaxRpcSize*, the RPC run-time library rejects the call and sends an RPC_S_ACCESS_DENIED error to the client. Specifying a value of (unsigned int) –1 for this parameter removes the limit on the size of incoming data blocks. This parameter has no effect on calls made over the [ncalrpc](https://learn.microsoft.com/windows/desktop/Midl/ncalrpc) protocol.

### `IfCallback` [in, optional]

Security-callback function, or **NULL** for no callback. Each registered interface can have a different callback function. See the Remarks on [RpcServerRegisterIf2](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif2).

### `SecurityDescriptor` [in, optional]

Security descriptor for accessing the RPC interface. Each registered interface can have a different security descriptor.

## Return value

Returns RPC_S_OK upon success.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The parameters and effects of the
**RpcServerRegisterIf3** function extend those of the
[RpcServerRegisterIf2](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif2) function. The difference is the ability to specify a security descriptor for controlling access to the registered RPC interface.

If both *SecurityDescriptor* and *IfCallbackFn* are specified, the security descriptor in *SecurityDescriptor* will be checked first and the callback in *IfCallbackFn* will be called after the access check against the security descriptor passes.

When calling **RpcServerRegisterIf3** with *SecurityDescriptor* set to **NULL**, or calling [RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif), [RpcServerRegisterIf2](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif2), or [RpcServerRegisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterifex) to register an interface, a default security descriptor will be used. The default security descriptor will not allow access from any AppContainer process to the interface if the RPC server is not an AppContainer process. The default security descriptor will not allow access from any process in other AppContainer processes to the interface if the RPC server is an AppContainer process. The default security descriptor will allow access from normal processes including Low integrity processes.

## See also

[Registering Interfaces](https://learn.microsoft.com/windows/desktop/Rpc/registering-interfaces)

[RpcGetAuthorizationContextForClient](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcgetauthorizationcontextforclient)

[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif)

[RpcServerRegisterIf2](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif2)

[RpcServerRegisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterifex)

[RpcServerUnregisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterif)

[RpcServerUnregisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterifex)