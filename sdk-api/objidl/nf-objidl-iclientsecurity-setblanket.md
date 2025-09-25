# IClientSecurity::SetBlanket

## Description

Sets the authentication information (the security blanket) that will be used to make calls on the specified proxy.

This setting overrides the process default settings for the specified proxy. Calling this method changes the security values for all other users of the specified proxy.

## Parameters

### `pProxy` [in]

A pointer to the proxy.

### `dwAuthnSvc` [in]

The authentication service. This will be a single value taken from the list of [authentication service constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-service-constants). If no authentication is required, use RPC_C_AUTHN_NONE. If RPC_C_AUTHN_DEFAULT is specified, COM will pick an authentication service following its normal security blanket negotiation algorithm.

### `dwAuthzSvc` [in]

The authorization service. This will be a single value taken from the list of [authorization constants](https://learn.microsoft.com/windows/desktop/com/com-authorization-constants). If RPC_C_AUTHZ_DEFAULT is specified, COM will pick an authorization service following its normal security blanket negotiation algorithm. If NTLMSSP, Kerberos, or Schannel is used as the authentication service, RPC_C_AUTHZ_NONE should be used as the authorization service.

### `pServerPrincName` [in]

The server principal name. If COLE_DEFAULT_PRINCIPAL is specified, DCOM will pick a principal name using its security blanket negotiation algorithm. If Kerberos is used as the authentication service, this parameter must be the correct principal name of the server or the call will fail.

If Schannel is used as the authentication service, this value must be one of the msstd or fullsic forms described in [Principal Names](https://learn.microsoft.com/windows/desktop/Rpc/principal-names), or **NULL** if you do not want mutual authentication.

Generally, specifying **NULL** will not reset server principal name on the proxy, rather, the previous setting will be retained. You must exercise care when using **NULL** as *pServerPrincName* when selecting a different authentication service for the proxy, because there is no guarantee that the previously set principal name would be valid for the newly selected authentication service.

### `dwAuthnLevel` [in]

The authentication level. This will be a single value taken from the list of [authentication level constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-level-constants). If RPC_C_AUTHN_LEVEL_DEFAULT is specified, COM will pick an authentication level following its normal security blanket negotiation algorithm. If this value is set to RPC_C_AUTHN_LEVEL_NONE, the authentication service must be RPC_C_AUTHN_NONE. Each authentication service may choose to use a higher security authentication level than the one specified.

### `dwImpLevel` [in]

The impersonation level. This will be a single value taken from the list of [impersonation level constants](https://learn.microsoft.com/windows/desktop/com/com-impersonation-level-constants). If RPC_C_IMP_LEVEL_DEFAULT is specified, COM will pick an impersonation level following its normal security blanket negotiation algorithm. If you are using NTLMSSP remotely, this value must be RPC_C_IMP_LEVEL_IMPERSONATE or RPC_C_IMP_LEVEL_IDENTIFY. When using NTLMSSP on the same computer, RPC_C_IMP_LEVEL_DELEGATE is also supported. For Kerberos, this value can be RPC_C_IMP_LEVEL_IDENTIFY, RPC_C_IMP_LEVEL_IMPERSONATE, or RPC_C_IMP_LEVEL_DELEGATE. For Schannel, this value must be RPC_C_IMP_LEVEL_IMPERSONATE.

### `pAuthInfo` [in]

An RPC_AUTH_IDENTITY_HANDLE value that indicates the identity of the client. This parameter is not used for calls on the same computer. If *pAuthInfo* is **NULL**, COM uses the current proxy identity, which is either the process token, the impersonation token, or the authentication identity from the [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) function. If the handle is not **NULL**, that identity is used. The format of the structure referred to by the handle depends on the provider of the authentication service.

For NTLMSSP or Kerberos, the structure is a [SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a) or [SEC_WINNT_AUTH_IDENTITY_EX](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure. If the client obtains the credentials set on the proxy by calling [CoQueryProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coqueryproxyblanket), it must ensure that the memory remains valid and unchanged until a different identity is set on the proxy or all proxies on the object are released.

If this parameter is **NULL**, COM uses the current proxy identity (which is either the process token or the impersonation token). If the handle refers to a structure, that identity is used.

For Schannel, this parameter must either be a pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the client's X.509 certificate, or **NULL** if the client wishes to make an anonymous connection to the server. If a certificate is specified, the caller must not free it as long as any proxy to the object exists in the current apartment.

For Snego, this member is either **NULL**, points to a [SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a) structure, or points to a [SEC_WINNT_AUTH_IDENTITY_EX](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure. If it is **NULL**, Snego will pick a list of authentication services based on those available on the client computer. If it points to a **SEC_WINNT_AUTH_IDENTITY_EX** structure, the structure's **PackageList** member must point to a string containing a comma-separated list of authentication service names and the **PackageListLength** member must give the number of bytes in the **PackageList** string. If **PackageList** is **NULL**, all calls using Snego will fail.

If COLE_DEFAULT_AUTHINFO is specified, COM will pick the authentication information following its normal security blanket negotiation algorithm.

**SetBlanket** will return an error if both *pAuthInfo* is set and one of the cloaking flags is set in *dwCapabilities*.

### `dwCapabilities` [in]

The capabilities of this proxy. Capability flags are defined in the [EOLE_AUTHENTICATION_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-eole_authentication_capabilities) enumeration. The only flags that can be set through this method are EOAC_MUTUAL_AUTH, EOAC_STATIC_CLOAKING, EOAC_DYNAMIC_CLOAKING, EOAC_ANY_AUTHORITY (this flag is deprecated), EOAC_MAKE_FULLSIC, and EOAC_DEFAULT. Either EOAC_STATIC_CLOAKING or EOAC_DYNAMIC_CLOAKING can be set if *pAuthInfo* is not set and Schannel is not the authentication service. (See [Cloaking](https://learn.microsoft.com/windows/desktop/com/cloaking) for more information.) If any capability flags other than those mentioned here are indicated, **SetBlanket** will return an error.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One or more arguments are not valid. |

## Remarks

**SetBlanket** sets the authentication information that will be used to make calls on the specified interface proxy. The values specified here override the values chosen by automatic security. Calling this method changes the security values for all other users of the specified proxy. If you want the changes to apply only to a particular instance of a proxy, call [IClientSecurity::CopyProxy](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-copyproxy) to make a private copy of the proxy and then call **SetBlanket** on the copy.

Whenever this method is called, DCOM will set the identity on the proxy, and future calls made using this proxy will use this identity. Calls in progress when **SetBlanket** is called will use the authentication information on the proxy at the time the call was started. If *pAuthInfo* is **NULL**, the proxy identity defaults to the current process token (unless an authentication identity was specified on a call to [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity)). See [Cloaking](https://learn.microsoft.com/windows/desktop/com/cloaking) to learn how the cloaking flags affect the proxy when *pAuthInfo* is **NULL**.

By default, COM will choose the first available authentication service and authorization service available on both the client and server computers and the principal name that the server registered for that authentication service. Currently, COM will not try another authentication service if the first fails.

When the default constant for *dwImpLevel* is specified in **SetBlanket**, the parameter defaults to the value specified to [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity). If **CoInitializeSecurity** is not called, it defaults to RPC_C_IMP_LEVEL_IDENTIFY.

The initial value for dwAuthnLevel on a proxy will be the higher of the value set on the client's call to [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) and the server's call to **CoInitializeSecurity**. For any process that did not call **CoInitializeSecurity**, the default authentication level is RPC_C_AUTHN_CONNECT.

The default authentication and impersonation level for processes that do not call [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) can be set with DCOMCNFG.

If EOAC_DEFAULT is specified for *dwCapabilities*, the valid capabilities from [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) will be used. If **CoInitializeSecurity** was not called, EOAC_NONE will be used for the capabilities flag.

If **SetBlanket** is called simultaneously on two threads on the same proxy, only one set of changes will be applied. If **SetBlanket** and **CRpcOptions::Set** are called simultaneously on two threads on the same proxy, both changes may be applied or only one may be applied.

Security information cannot be set on local interfaces such as the [IClientSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iclientsecurity) interface. However, since that interface is only supported locally, there is no need for security. [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) and [IMultiQI](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imultiqi) are special cases. The location implementation makes remote calls to support these interfaces. **SetBlanket** can be used for **IUnknown**. **IMultiQI** will use the security settings on **IUnknown**.

To change one **SetBlanket** parameter without having to deal with the others, one can specify the default constants for the other parameters. Applications can change a parameter (such as the authentication level) and ignore the other parameters, including the authentication service, by setting all other parameters to the default constants.

Note that it is important to set all unused parameters to the default constants because the default value is often not obvious. In particular, if you set the authentication service to the default, you should set the authentication information and principal name to the default. The reasons for this are twofold: First, the type of the authentication information depends on the authentication service DCOM chooses. Second, because DCOM needs to pass some complex authentication information for certain authentication services, if you set the authentication service to default and the authentication information to **NULL**, you might get a security setting that will not work.

## See also

[CoQueryProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coqueryproxyblanket)

[CoSetProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosetproxyblanket)

[IClientSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iclientsecurity)