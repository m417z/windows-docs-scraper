# RpcServerRegisterIfEx function

## Description

The
**RpcServerRegisterIfEx** function registers an interface with the RPC run-time library.

## Parameters

### `IfSpec`

MIDL-generated structure indicating the interface to register.

### `MgrTypeUuid`

Pointer to a type UUID to associate with the *MgrEpv* parameter. Specifying a **null** parameter value (or a nil UUID) registers *IfSpec* with a nil-type UUID.

### `MgrEpv`

Manager routines' entry-point vector (EPV). To use the MIDL-generated default EPV, specify a **null** value. For more information, please see [RPC_MGR_EPV](https://learn.microsoft.com/windows/desktop/Rpc/rpc-mgr-epv).

### `Flags`

Flags. For a list of flag values, see
[Interface Registration Flags](https://learn.microsoft.com/windows/desktop/Rpc/interface-registration-flags).

### `MaxCalls`

Maximum number of concurrent remote procedure call requests the server can accept on an auto-listen interface. The *MaxCalls* parameters is only applicable on an auto-listen interface, and is ignored on interfaces that are not auto-listen. The RPC run-time library makes its best effort to ensure the server does not allow more concurrent call requests than the number of calls specified in *MaxCalls*. The actual number can be greater and can vary for each protocol sequence.

Calls on other interfaces are governed by the value of the process-wide *MaxCalls* parameter specified in the
[RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten) function call.

If the number of concurrent calls is not a concern, you can achieve slightly better server-side performance by specifying the default value using RPC_C_LISTEN_MAX_CALLS_DEFAULT. Doing so relieves the RPC run-time environment from enforcing an unnecessary restriction.

### `IfCallback`

Security-callback function, or **NULL** for no callback. Each registered interface can have a different callback function. See Remarks for more details.

## Return value

Returns RPC_S_OK upon success.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The parameters and effects of
**RpcServerRegisterIfEx** subsume those of
[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif). The difference is the ability to register an auto-listen interface and to specify a security-callback function.

The server application code calls
**RpcServerRegisterIfEx** to register an interface. To register an interface, the server provides the following information:

* Interface specification

  The interface specification is a data structure that the MIDL compiler generates.
* Manager type UUID and manager EPV

  The manager type UUID and the manager EPV determine which manager routine executes when a server receives a remote procedure call request from a client. For each implementation of an interface offered by a server, it must register a separate manager EPV.

  Note that when specifying a non-nil, manager type UUID, the server must also call
  [RpcObjectSetType](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectsettype) to register objects of this non-nil type.

Specifying the RPC_IF_AUTOLISTEN flags marks the interface as an auto-listen interface. The run time begins listening for calls as soon as the interface is registered, and stops listening when the interface is unregistered. A call to
[RpcServerUnregisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterif) for this interface will wait for the completion of all pending calls on this interface. Calls to
[RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten) and
[RpcMgmtStopServerListening](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtstopserverlistening) will not affect the interface, nor will a call to
[RpcServerUnregisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterif) with *IfSpec* == **NULL**. This allows a DLL to register RPC interfaces or remove them from the registry without changing the main application's RPC state.

Specifying a security-callback function allows the server application to restrict access to its interfaces on a per-client basis. Remember that, by default, security is optional; the server run time will dispatch unsecured calls even if the server has called
[RpcServerRegisterAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterauthinfo). If the server wants to accept only authenticated clients, an interface callback function must call the
[RpcBindingInqAuthClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqauthclient) or
[RpcGetAuthorizationContextForClient](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcgetauthorizationcontextforclient) function to retrieve the security level, or attempt to impersonate the client with
[RpcImpersonateClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcimpersonateclient). It can also specify the RPC_IF_ALLOW_SECURE_ONLY flag in the interface flags.

When a server application specifies a security-callback function for its interface(s), the RPC run time automatically rejects unauthenticated calls to that interface. In addition, the run-time records the interfaces that each client has used. When a client makes an RPC to an interface that it has not used during the current communication session, the RPC run-time library will call the interface's security-callback function. Specifying RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH flag will prevent the automatic rejection of unauthenticated clients.

For the signature for the callback function, see
[RPC_IF_CALLBACK_FN](https://learn.microsoft.com/windows/desktop/api/rpcdce/nc-rpcdce-rpc_if_callback_fn).

The callback function should return RPC_S_OK if the client is allowed to call methods in this interface. Any other return code will cause the client to receive the exception RPC_S_ACCESS_DENIED.

In some cases, the RPC run time may call the security-callback function more than once per client–per interface. Be sure your callback function can handle this possibility.

## See also

[Registering Interfaces](https://learn.microsoft.com/windows/desktop/Rpc/registering-interfaces)

[RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding)

[RpcBindingSetObject](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetobject)

[RpcGetAuthorizationContextForClient](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcgetauthorizationcontextforclient)

[RpcNsBindingExport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexporta)

[RpcNsBindingImportBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingimportbegina)

[RpcNsBindingLookupBegin](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindinglookupbegina)

[RpcObjectSetType](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectsettype)

[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif)

[RpcServerRegisterIf2](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif2)

[RpcServerRegisterIf3](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif3)

[RpcServerUnregisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterif)

[RpcServerUnregisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterifex)