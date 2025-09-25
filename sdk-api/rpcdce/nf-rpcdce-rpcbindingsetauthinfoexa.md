# RpcBindingSetAuthInfoExA function

## Description

The
**RpcBindingSetAuthInfoEx** function sets a binding handle's authentication, authorization, and security quality-of-service information.

## Parameters

### `Binding`

Server binding handle into which authentication and authorization information is set.

### `ServerPrincName`

Pointer to the expected principal name of the server referenced by *Binding*. The content of the name and its syntax are defined by the authentication service in use.

**Note** For the set of allowable target names for SSPs, please refer to the comments in the [InitializeSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) documentation.

### `AuthnLevel`

Level of authentication to be performed on remote procedure calls made using *Binding*. For a list of the RPC-supported authentication levels, see
[Authentication-Level Constants](https://learn.microsoft.com/windows/desktop/Rpc/authentication-level-constants).

### `AuthnSvc`

Authentication service to use.

Specify RPC_C_AUTHN_NONE to turn off authentication for remote procedure calls made using *Binding*.

If RPC_C_AUTHN_DEFAULT is specified, the RPC run-time library uses the RPC_C_AUTHN_WINNT authentication service for remote procedure calls made using *Binding*.

### `AuthIdentity`

Handle for the structure that contains the client's authentication and authorization credentials appropriate for the selected authentication and authorization service.

When using the [RPC_C_AUTHN_WINNT](https://learn.microsoft.com/windows/desktop/Rpc/authentication-service-constants) authentication service *AuthIdentity* should be a pointer to a
[SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-sec_winnt_auth_identity_a) structure (defined in Rpcdce.h). Kerberos and Negotiate authentication services also use the
**SEC_WINNT_AUTH_IDENTITY** structure.

Specify a null value to use the security login context for the current address space. Pass the value RPC_C_NO_CREDENTIALS to use an anonymous log-in context. Note that RPC_C_NO_CREDENTIALS is only valid if RPC_C_AUTHN_GSS_SCHANNEL is selected as the authentication service.

### `AuthzSvc`

Authorization service implemented by the server for the interface of interest. The validity and trustworthiness of authorization data, like any application data, depends on the authentication service and authentication level selected. This parameter is ignored when using the RPC_C_AUTHN_WINNT authentication service. See Note.

### `SecurityQos`

Pointer to the
[RPC_SECURITY_QOS](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos) structure, which defines the security quality-of-service.

**Note** For a list of the RPC-supported authentication services, see
[Authentication-Service Constants](https://learn.microsoft.com/windows/desktop/Rpc/authentication-service-constants).

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |
| **RPC_S_UNKNOWN_AUTHN_SERVICE** | Unknown authentication service. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A client application calls the
**RpcBindingSetAuthInfoEx** function to set up a server binding handle for making authenticated remote procedure calls. This function provides the capability to set security quality-of-service information on the binding handle. It is otherwise identical to
[RpcBindingSetAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfo).

Unless a client calls
**RpcBindingSetAuthInfoEx**, all remote procedure calls on *Binding* are unauthenticated. A client is not required to call this function.

The
**RpcBindingSetAuthInfoEx** function takes a snapshot of the credentials. Therefore, the memory dedicated to the *AuthIdentity* parameter can be freed before the binding handle. The exception to this is when your application uses
**RpcBindingSetAuthInfoEx** with RPC_C_QOS_IDENTITY_DYNAMIC and also specifies a non-**NULL** value for *AuthIdentity*.

**Note** The [RpcBindingSetAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfo) function must not be called on a binding handle while an RPC call on the same handle is in progress. Doing so produces undefined results.

Due to the varying requirements of different versions of Microsoft RPC, Microsoft recommends that an application maintain a pointer to the *AuthIdentity* parameter for as long as the binding handle exists. Doing so increases the applications portability.

**Windows Server 2003 with SP1 and Windows XP with SP2:** For Windows XP SP2 and Windows Server 2003 SP1, the pointer to the *AuthIdentity* parameter need not be maintained for the life of the binding handle. This pointer must only be maintained if subsequent calls to [RpcBindingInqAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqauthinfo) or [RpcBindingInqAuthInfoEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqauthinfoexa) are made.

**Note** The **ncalrpc** protocol sequence supports only RPC_C_AUTHN_WINNT, but does support mutual authentication; supply an SPN and request mutual authentication through the *SecurityQOS* parameter to achieve this.

> [!NOTE]
> The rpcdce.h header defines RpcBindingSetAuthInfoEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RPC_SECURITY_QOS](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos)

[RpcBindingInqAuthInfoEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqauthinfoexa)

[RpcServerRegisterAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterauthinfo)