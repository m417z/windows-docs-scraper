# RpcServerRegisterIf2 function

## Description

The
**RpcServerRegisterIf2** function registers an interface with the RPC run-time library.

## Parameters

### `IfSpec`

MIDL-generated structure indicating the interface to register.

### `MgrTypeUuid`

Pointer to a type **UUID** to associate with the *MgrEpv* parameter. Specifying a **null** parameter value (or a nil **UUID**) registers *IfSpec* with a nil-type **UUID**.

### `MgrEpv`

Manager routines' entry-point vector (EPV). To use the MIDL-generated default EPV, specify a **null** value. For more information, please see [RPC_MGR_EPV](https://learn.microsoft.com/windows/desktop/Rpc/rpc-mgr-epv).

### `Flags`

Flags. For a list of flag values, see
[Interface Registration Flags](https://learn.microsoft.com/windows/desktop/Rpc/interface-registration-flags).

### `MaxCalls`

Maximum number of concurrent remote procedure call requests the server can accept on an **auto-listen** interface. The *MaxCalls* parameter is only applicable on an **auto-listen** interface, and is ignored on interfaces that are not **auto-listen**. The RPC run-time library makes its best effort to ensure the server does not allow more concurrent call requests than the number of calls specified in *MaxCalls*. The actual number can be greater and can vary for each protocol sequence.

Calls on other interfaces are governed by the value of the process-wide *MaxCalls* parameter specified in the
[RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten) function call.

If the number of concurrent calls is not a concern, you can achieve slightly better server-side performance by specifying the default value using RPC_C_LISTEN_MAX_CALLS_DEFAULT. Doing so relieves the RPC run-time environment from enforcing an unnecessary restriction.

### `MaxRpcSize`

Maximum size of incoming data blocks, in bytes. This parameter may be used to help prevent malicious denial-of-service attacks. If the data block of a remote procedure call is larger than *MaxRpcSize*, the RPC run-time library rejects the call and sends an RPC_S_ACCESS_DENIED error to the client. Specifying a value of (unsigned int) –1 for this parameter removes the limit on the size of incoming data blocks. This parameter has no effect on calls made over the [ncalrpc](https://learn.microsoft.com/windows/desktop/Midl/ncalrpc) protocol.

### `IfCallbackFn`

Security-callback function, or **NULL** for no callback. Each registered interface can have a different callback function. See Remarks.

## Return value

Returns RPC_S_OK upon success.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The parameters and effects of the
**RpcServerRegisterIf2** function extend those of the
[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif) function. The difference is the ability to register an **auto-listen** interface and to specify a security-callback function.

The server application code calls
**RpcServerRegisterIf2** to register an interface. To register an interface, the server provides the following information:

* Interface specification

  The interface specification is a data structure that the MIDL compiler generates.
* Manager type **UUID** and manager EPV

  The manager type **UUID** and the manager EPV determine which manager routine executes when a server receives a remote procedure call request from a client. For each implementation of an interface offered by a server, it must register a separate manager EPV.

  Note that when specifying a non-nil, manager type **UUID**, the server must also call
  [RpcObjectSetType](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectsettype) to register objects of this non-nil type.

Specifying the RPC_IF_AUTOLISTEN flags marks the interface as an **auto-listen** interface. The run time begins listening for calls as soon as the interface is registered, and stops listening when the interface is unregistered. A call to
[RpcServerUnregisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterif) for this interface waits for the completion of all pending calls on this interface. Calls to the
[RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten) and the
[RpcMgmtStopServerListening](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtstopserverlistening) functions do not affect the interface, nor does a call to the
**RpcServerUnregisterIf** function with *IfSpec* set to the value **NULL**. This allows a DLL to register RPC interfaces or remove them from the registry without changing the main application's RPC state.

Specifying a security-callback function allows the server application to restrict access to its interfaces on an individual client basis. That is, by default, security is optional; the server run-time will dispatch unsecured calls even if the server has called the
[RpcServerRegisterAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterauthinfo) function. If the server wants to accept only authenticated clients, an interface callback function must call the
[RpcBindingInqAuthClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqauthclient), [RpcGetAuthorizationContextForClient](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcgetauthorizationcontextforclient), or [RpcServerInqCallAttributes](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverinqcallattributesa) function to retrieve the security level, or attempt to impersonate the client with the
[RpcImpersonateClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcimpersonateclient) function. It can also specify the RPC_IF_ALLOW_SECURE_ONLY flag in the interface flags to reject unauthenticated calls.

When a server application specifies a security-callback function for its interface(s), the RPC run time automatically rejects calls without authentication information to that interface. In addition, the run-time records the interfaces each client has used. When a client makes an RPC to an interface that it has not used during the current communication session, the RPC run-time library calls the interface's security-callback function. Specifying RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH flag will prevent the automatic rejection of unauthenticated clients. Note that calls on the so-called **NULL** security session can have authentication information, even though they come from anonymous clients. Thus the existence of a callback alone is not sufficient to prevent anonymous clients from connecting. Either the security callback function must check for that, or the RPC_IF_ALLOW_SECURE_ONLY flag must be used. RPC_IF_ALLOW_SECURE_ONLY rejects **null** session calls only on Windows XP and later versions of Windows.

For the signature for the callback function, see
[RPC_IF_CALLBACK_FN](https://learn.microsoft.com/windows/desktop/api/rpcdce/nc-rpcdce-rpc_if_callback_fn).

The callback function should return RPC_S_OK, if the client is allowed to call methods in this interface. Any other return code will cause the client to receive the exception RPC_S_ACCESS_DENIED.

In some cases, the RPC run time may call the security-callback function more than once per client, per interface. Be sure your callback function can handle this possibility.

## See also

[Registering Interfaces](https://learn.microsoft.com/windows/desktop/Rpc/registering-interfaces)

[RpcGetAuthorizationContextForClient](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcgetauthorizationcontextforclient)

[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif)

[RpcServerRegisterIf3](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif3)

[RpcServerRegisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterifex)

[RpcServerUnregisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterif)

[RpcServerUnregisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterifex)