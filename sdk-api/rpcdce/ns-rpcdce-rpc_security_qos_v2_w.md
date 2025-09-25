# RPC_SECURITY_QOS_V2_W structure

## Description

The **RPC_SECURITY_QOS_V2** structure defines version 2 security quality-of-service settings on a binding handle. See Remarks for version availability on Windows editions.

## Members

### `Version`

Version of the [RPC_SECURITY_QOS](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos) structure being used. This topic documents version 2 of the **RPC_SECURITY_QOS** structure. See **RPC_SECURITY_QOS**, [RPC_SECURITY_QOS_V3](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos_v3_a), [RPC_SECURITY_QOS_V4](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos_v4_a), and [RPC_SECURITY_QOS_V5](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos_v5_a) for other versions.

### `Capabilities`

Security services being provided to the application. Capabilities is a set of flags that can be combined using the bitwise **OR** operator.

| Value | Meaning |
| --- | --- |
| **RPC_C_QOS_CAPABILITIES_DEFAULT** | Used when no provider-specific capabilities are needed. |
| **RPC_C_QOS_CAPABILITIES_MUTUAL_AUTH** | Specifying this flag causes the RPC run time to request mutual authentication from the security provider. Some security providers do not support mutual authentication. If the security provider does not support mutual authentication, or the identity of the server cannot be established, a remote procedure call to such server fails with error RPC_S_SEC_PKG_ERROR.<br><br>**Note** RPC relies on the SSP to indicate which security options were successfully negotiated; RPC in turn fails any call for which the SSP reports it could not negotiate an option. However, some security providers are known to report the successful negotiation of an option even when the option was not successfully negotiated. For example, NTLM will report successful negotiation of mutual authentication for backward compatibility reasons, even though it does not support mutual authentication. Check with the particular SSP being used to determine its behavior with respect to security options. |
| **RPC_C_QOS_CAPABILITIES_MAKE_FULLSIC** | Not currently implemented. |
| **RPC_C_QOS_CAPABILITIES_ANY_AUTHORITY** | Accepts the client's credentials even if the certificate authority (CA) is not in the server's list of trusted CAs. This constant is used only by the SCHANNEL SSP. |
| **RPC_C_QOS_CAPABILITIES_IGNORE_DELEGATE_FAILURE** | When specified, this flag directs the RPC runtime on the client to ignore an error to establish a security context that supports delegation. Normally, if the client asks for delegation and the security system cannot establish a security context that supports delegation, error RPC_S_SEC_PKG_ERROR is returned; when this flag is specified, no error is returned.<br><br>**Note** Unsupported on Windows XP and earlier client editions, unsupported on Windows 2000 and earlier server editions. |
| **RPC_C_QOS_CAPABILITIES_LOCAL_MA_HINT** | When specified, this flag specifies to RPC that the server is local to the machine making the RPC call. In this situation RPC instructs the endpoint mapper to pick up only endpoints registered by the principal specified in the **ServerPrincName** or **Sid** members (these members are available in [RPC_SECURITY_QOS_V3](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos_v3_a), [RPC_SECURITY_QOS_V4](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos_v4_a), and [RPC_SECURITY_QOS_V5](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos_v5_a) only). See Remarks for more information.<br><br>**Note** Unsupported on Windows XP and earlier client editions, unsupported on Windows 2000 and earlier server editions. |

### `IdentityTracking`

Sets the context tracking mode. Should be set to one of the values shown in the following table.

| Value | Meaning |
| --- | --- |
| **RPC_C_QOS_IDENTITY_STATIC** | Security context is created only once and is never revised during the entire communication, even if the client side changes it. This is the default behavior if **RPC_SECURITY_QOS_V2** is not specified. |
| **RPC_C_QOS_IDENTITY_DYNAMIC** | Context is revised whenever the ModifiedId in the client's token is changed. All protocols use the ModifiedId (see note).<br><br>**Windows 2000:** All remote protocols (all protocols other than [ncalrpc](https://learn.microsoft.com/windows/desktop/Midl/ncalrpc)) use the AuthenticationID, also known as the LogonId, to track changes in the client's identity. The **ncalrpc** protocol uses ModifiedId. |

### `ImpersonationType`

Level at which the server process can impersonate the client.

| Value | Meaning |
| --- | --- |
| **RPC_C_IMP_LEVEL_DEFAULT** | Uses the default impersonation level. |
| **RPC_C_IMP_LEVEL_ANONYMOUS** | Client does not provide identification information to the server. The server cannot impersonate the client or identify the client. Many servers reject calls with this impersonation type. |
| **RPC_C_IMP_LEVEL_IDENTIFY** | Server can obtain the client's identity, and impersonate the client to perform Access Control List (ACL) checks, but cannot impersonate the client. See [Impersonation Levels](https://learn.microsoft.com/windows/desktop/SecAuthZ/impersonation-levels) for more information.<br><br>**Note** Some security providers may treat this impersonation type as equivalent to RPC_C_IMP_LEVEL_IMPERSONATE. |
| **RPC_C_IMP_LEVEL_IMPERSONATE** | Server can impersonate the client's security context on its local system, but not on remote systems. |
| **RPC_C_IMP_LEVEL_DELEGATE** | The server can impersonate the client's security context while acting on behalf of the client. The server can also make outgoing calls to other servers while acting on behalf of the client. The server may use the client's security context on other machines to access local and remote resources as the client. |

### `AdditionalSecurityInfoType`

Specifies the type of additional credentials present in the **u** union. The following constants are supported:

| Supported Constants | Meaning |
| --- | --- |
| **0** | No additional credentials are passed in the **u** union. |
| **RPC_C_AUTHN_INFO_TYPE_HTTP** | The **HttpCredentials** member of the **u** union points to a [RPC_HTTP_TRANSPORT_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_http_transport_credentials_a) structure. This value can be used only when the protocol sequence is [ncacn_http](https://msdn.microsoft.com/). Any other protocol sequence returns RPC_S_INVALID_ARG. |

### `u`

### `u.HttpCredentials`

Additional set of credentials to pass to RPC, in the form of an [RPC_HTTP_TRANSPORT_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_http_transport_credentials_a) structure. Used when the **AdditionalSecurityInfoType** member is set to RPC_C_AUTHN_INFO_TYPE_HTTP.

## Remarks

The following listing defines the availability of QOS versions on various Windows operating systems:

* Version 1: Windows 2000 and later.
* Version 2: Windows XP with Service Pack 1 (SP1) and later.
* Version 3: Windows Server 2003 and later.
* Version 4: Windows Vista and later.
* Version 5: Windows 8 and later.

Windows editions support downlevel versions as well. For example, Windows Server 2003 supports version 3, but also supports versions 1 and 2.

The client-side security functions
[RpcBindingInqAuthInfoEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqauthinfoexa) and
[RpcBindingSetAuthInfo](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfo) use the
[RPC_SECURITY_QOS](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos) structure to inquire about, or to set, the security quality of service for a binding handle.

RPC supports the RPC_C_QOS_CAPABILITIES_LOCAL_MA_HINT hint (unsupported on Windows XP and earlier client editions, unsupported on Windows 2000 and earlier server editions). This hint is used only when dynamic endpoints and mutual authentication are used. Furthermore, it is not supported for the **ncadg_*** protocol sequences. If this flag is used for a **ncadg_*** protocol sequence, or without using mutual authentication, RPC_S_INVALID_ARG is returned from the [RpcBindingSetAuthInfoEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfoexa) function call.
This flag is designed to prevent a Denial of Service Attack. Using this flag forces the RPC Runtime to ask the endpoint mapper only for endpoints registered by the principal specified in the **ServerPrincName** or **Sid** members. This prevents an attacker on the local machine from trying to trick your RPC client to connect to a spoof endpoint it has registered in the endpoint mapper. Note that since the attack is local only (such as from a terminal server machine with many users), the flag also works only for RPC calls made locally.

**Note** Some security providers, such as Kerberos, support delegation-impersonation type. On Windows editions that support delegation-impersonation type, if the client has asked for delegation but the security provider is unable to provide it, the call fails with PRC_S_SEC_PKG_ERROR unless the RPC_C_QOS_CAPABILITIES_IGNORE_DELEGATE_FAILURE flag is specified.

## See also

[RPC_HTTP_TRANSPORT_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_http_transport_credentials_a)

[RPC_SECURITY_QOS](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos)

[RPC_SECURITY_QOS_V3](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos_v3_a)

[RPC_SECURITY_QOS_V4](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos_v4_a)

[RPC_SECURITY_QOS_V5](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_security_qos_v5_a)

[RpcBindingInqAuthInfoEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindinginqauthinfoexa)

[RpcBindingSetAuthInfoEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingsetauthinfoexa)