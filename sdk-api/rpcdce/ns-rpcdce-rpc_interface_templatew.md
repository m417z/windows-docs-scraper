# RPC_INTERFACE_TEMPLATEW structure

## Description

The **RPC_INTERFACE_TEMPLATE** structure defines an RPC interface group server interface.

## Members

### `Version`

This field is reserved and must be set to 0.

### `IfSpec`

MIDL-generated structure that defines the interface to register.

### `MgrTypeUuid`

Pointer to a [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) to associate with *MgrEpv*. **NULL** or a nil **UUID** registers *IfSpec* with a nil **UUID**.

### `MgrEpv`

Pointer to a [RPC_MGR_EPV](https://learn.microsoft.com/windows/desktop/Rpc/rpc-mgr-epv) structure that contains the manager routines' entry-point vector (EPV). If **NULL**,the MIDL-generated default EPV is used.

### `Flags`

Flags. For a list of flag values, see [Interface Registration Flags](https://learn.microsoft.com/windows/desktop/Rpc/interface-registration-flags). Interface group interfaces are always treated as **auto-listen**.

### `MaxCalls`

Maximum number of concurrent remote procedure call requests the server can accept on this interface. The RPC run-time library makes its best effort to ensure the server does not allow more concurrent call requests than the number of calls specified in *MaxCalls*. However, the actual number can be greater than *MaxCalls* and can vary for each protocol sequence.

Calls on other interfaces are governed by the value of the process-wide *MaxCalls* parameter specified in [RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten).

If the number of concurrent calls is not a concern, slightly better server-side performance can be achieved by specifying the default value using **RPC_C_LISTEN_MAX_CALLS_DEFAULT**. Doing so relieves the RPC run-time environment from enforcing an unnecessary restriction.

### `MaxRpcSize`

Maximum size, in bytes, of incoming data blocks. *MaxRpcSize* may be used to help prevent malicious denial-of-service attacks. If the data block of a remote procedure call is larger than *MaxRpcSize*, the RPC run-time library rejects the call and sends an **RPC_S_ACCESS_DENIED** error to the client. Specifying a value of (unsigned int) –1 in *MaxRpcSize* removes the limit on the size of incoming data blocks. This parameter has no effect on calls made over the [ncalrpc](https://learn.microsoft.com/windows/desktop/Rpc/protocol-sequence-constants) protocol.

### `IfCallback`

A pointer to a [RPC_INTERFACE_GROUP_IDLE_CALLBACK_FN](https://learn.microsoft.com/windows/desktop/api/rpcdce/nc-rpcdce-rpc_interface_group_idle_callback_fn) security-callback function, or **NULL** for no callback. Each registered interface can have a different callback function.

### `UuidVector`

Pointer to a vector of object [UUIDs](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) offered by the server to be registered with the RPC endpoint mapper. The server application constructs this vector. **NULL** indicates there are no object **UUIDs** to register.

### `Annotation`

Pointer to the character-string comment applied to each cross-product element added to the local endpoint-map database. The string can be up to 64 characters long, including the null terminating character. Specify a null value or a null-terminated string ("\0") if there is no annotation string.

The annotation string is used by applications for information only. RPC does not use this string to determine which server instance a client communicates with or for enumerating elements in the endpoint-map database.

### `SecurityDescriptor`

Optional security descriptor describing which clients have the right to access the interface.

## Remarks

To register an interface, the server provides the following information:

* Interface specification The interface specification is a data structure that the MIDL compiler generates.
* Manager type [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) and manager EPV The manager type [UUID](https://learn.microsoft.com/windows/win32/rpc/rpcdce/ns-rpcdce-uuid) and the manager EPV determine which manager routine executes when a server receives a remote procedure call request from a client. For each implementation of an interface offered by a server, it must register a separate manager EPV.
  Note that when specifying a non-nil, manager type **UUID**, the server must also call [RpcObjectSetType](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcobjectsettype) to register objects of this non-nil type.

All interface group interfaces are treated as **auto-listen**. The runtime begins listening for calls as soon as the interface group is activated. Calls to [RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten) and [RpcMgmtStopServerListening](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcmgmtstopserverlistening) do not affect the interface, nor does a call to [RpcServerUnregisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverunregisterif) with *IfSpec* set to **NULL**.

Specifying a security-callback function in *IfCallback* allows the server application to restrict access to its interfaces on an individual client basis. That is, by default, security is optional; the server run-time will dispatch unsecured calls even if the server has called [RpcServerRegisterAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterauthinfo). If the server wants to accept only authenticated clients, an interface callback function must call [RpcBindingInqAuthClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqauthclient), [RpcGetAuthorizationContextForClient](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcgetauthorizationcontextforclient), or [RpcServerInqCallAttributes](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcserverinqcallattributesa) to retrieve the security level, or attempt to impersonate the client with [RpcImpersonateClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcimpersonateclient). It can also specify the [RPC_IF_ALLOW_SECURE_ONLY](https://learn.microsoft.com/windows/desktop/Rpc/interface-registration-flags) flag in *Flags* to reject unauthenticated calls.

When a server application specifies a security-callback function for its interface(s) in *IfCallback*, the RPC run time automatically rejects calls without authentication information to that interface. In addition, the run-time records the interfaces each client has used. When a client makes an RPC to an interface that it has not used during the current communication session, the RPC run-time library calls the interface's security-callback function. Specifying [RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH](https://learn.microsoft.com/windows/desktop/Rpc/interface-registration-flags) in *Flags* will prevent the automatic rejection of unauthenticated clients. Note that calls on the **NULL** security session can have authentication information, even though they come from anonymous clients. Thus, the existence of a callback alone is not sufficient to prevent anonymous clients from connecting; either the security callback function must check for that, or the RPC_IF_ALLOW_SECURE_ONLY flag must be used. RPC_IF_ALLOW_SECURE_ONLY rejects null session calls only on Windows XP and later versions of Windows.

For the signature for the callback function, see [RPC_IF_CALLBACK_FN](https://learn.microsoft.com/windows/desktop/api/rpcdce/nc-rpcdce-rpc_if_callback_fn).

The callback function in *IfCallback* should return **RPC_S_OK** if the client is allowed to call methods in this interface. Any other return code will cause the client to receive the exception **RPC_S_ACCESS_DENIED**.

In some cases, the RPC run time may call the security-callback function more than once per client, per interface. The callback function must be able to handle this possibility.

> [!NOTE]
> The rpcdce.h header defines RPC_INTERFACE_TEMPLATE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RPC_INTERFACE_GROUP_IDLE_CALLBACK_FN](https://learn.microsoft.com/windows/desktop/api/rpcdce/nc-rpcdce-rpc_interface_group_idle_callback_fn)

[RpcServerInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupinqbindings)

[RpcServerInterfaceGroupActivate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupactivate)

[RpcServerInterfaceGroupClose](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupclose)

[RpcServerInterfaceGroupCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupcreate)

[RpcServerInterfaceGroupDeactivate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupdeactivate)