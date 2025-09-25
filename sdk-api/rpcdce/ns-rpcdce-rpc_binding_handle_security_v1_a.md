# RPC_BINDING_HANDLE_SECURITY_V1_A structure

## Description

The **RPC_BINDING_HANDLE_SECURITY_V1** structure contains the basic security options with which to create an RPC binding handle.

## Members

### `Version`

The version of this structure. For **RPC_BINDING_HANDLE_SECURITY_V1** this must be set to 1.

### `ServerPrincName`

Pointer to a string that contains the server principal name referenced by the binding handle. The content of the name and its syntax are defined by the authentication service in use.

### `AuthnLevel`

Level of authentication to be performed on remote procedure calls made using this binding handle. For a list of the RPC-supported authentication levels, see
[Authentication-Level Constants](https://learn.microsoft.com/windows/desktop/Rpc/authentication-level-constants).

If *AuthnSvc* is set to RPC_C_AUTHN_NONE, this member must likewise be set to RPC_C_AUTHN_NONE.

### `AuthnSvc`

Authentication service to use when binding.

Specify RPC_C_AUTHN_NONE to turn off authentication for remote procedure calls made using the binding handle.

If RPC_C_AUTHN_DEFAULT is specified, the RPC run-time library uses the RPC_C_AUTHN_WINNT authentication service for remote procedure calls made using the binding handle.

If *AuthnLevel* is set to RPC_C_AUTHN_NONE, this member must likewise be set to RPC_C_AUTHN_NONE.

### `AuthIdentity`

[SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-sec_winnt_auth_identity_a) structure that contains the client's authentication and authorization credentials appropriate for the selected authentication and authorization service.

### `SecurityQos`

[RPC_SECURITY_QOS](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos) structure that contains the security quality-of-service settings for the binding handle.

**Note** For a list of the RPC-supported authentication services, see
[Authentication-Service Constants](https://learn.microsoft.com/windows/desktop/Rpc/authentication-service-constants).

## Remarks

If this structure is not passed to [RpcBindingCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingcreatea) -- that is, if the *Security* parameter of **RpcBindingCreate** is set to **NULL** -- then the following default security behaviors are assumed:

* For the protocol sequence ncalrpc (local RPC), RPC will use transport-level security. This means that RPC will use the security mechanisms offered by the Windows kernel to provide security, and RPC will not authenticate the server since it connects using the current thread identity. In this case, the identity tracking is static, the impersonation type is set to "Impersonate", and the authentication level is set to "Privacy".
* For the protocol sequence ncacn_np, RPC will also use transport-level security. If the call is remote, RPC uses the security mechanisms provided by the Windows file system redirector and there is no mutual authentication. In this case, the identity is the current thread identity, the identity tracking state is static, the impersonation type is set to "Impersonate", and the authentication level is determined by the policies of the remote machine.

  If the call is local, RPC uses the security mechanisms provided by the Named Pipe File System (NPFS), and there is also no mutual authentication. In this case, the identity is the current thread identity or any identity established through the "net use" command for the server. The identity tracking state is dynamic, the impersonation type is set to "Impersonate", and the authentication level is set to "Privacy".
* For the protocol sequences ncacn_ip_tcp, ncacn_ip_udp and ncacn_http, no security is used when *Security* is set to **NULL**. The server will not perform impersonation, and all data will be sent as clear text. To provide maximum protection for data, the application must always provide security data.

The following table summarizes the default security settings for the different protocol sequences if the *Security* parameter of [RpcBindingCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingcreatea) is set to **NULL**.

| Default Security Settings | ncalrpc | local ncacn_np | remote ncacn_np | ncacn_ip_tcp, ncacn_ip_udp, and ncacn_http |
| --- | --- | --- | --- | --- |
| Security Mechanism | Windows Kernel | NPFS | File system redirector | None |
| Authentication Level | Privacy | Privacy | Server policy dependent | None |
| Mutual Authentication? | No | No | No | No |
| Impersonation Type | Impersonate | Impersonate | Impersonate | N/A |
| Identity Tracking Type | Static | Dynamic | Static | N/A |
| Effective Only? | Yes | No | N/A | N/A |
| Call Identity | Current thread | Current thread | Current thread or "net use" settings | N/A |

**Note** If you create your binding handle by calling the [RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding) API, the default identity tracking for ncalrpc in the absence of specific security settings is dynamic.

If you create a fast binding handle by calling the [RpcBindingCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingcreatea) API, the default identity tracking for ncalrpc in the absence of specific security settings is static.

You should be aware of the differences in these two APIs if you are switching between them in your application.

After the binding handle is created, the [RpcBindingSetAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfo) and [RpcBindingSetAuthInfoEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfoexa) APIs can be used to change the settings of the binding handle set with this structure.

## See also

[RPC_BINDING_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-binding-handle)

[RpcBindingBind](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcbindingbind)

[RpcBindingCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingcreatea)