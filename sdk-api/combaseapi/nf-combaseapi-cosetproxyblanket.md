# CoSetProxyBlanket function

## Description

Sets the authentication information that will be used to make calls on the specified proxy. This is a helper function for [IClientSecurity::SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket).

## Parameters

### `pProxy` [in]

The proxy to be set.

### `dwAuthnSvc` [in]

The authentication service to be used. For a list of possible values, see [Authentication Service Constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-service-constants). Use RPC_C_AUTHN_NONE if no authentication is required. If RPC_C_AUTHN_DEFAULT is specified, DCOM will pick an authentication service following its normal security blanket negotiation algorithm.

### `dwAuthzSvc` [in]

The authorization service to be used. For a list of possible values, see [Authorization Constants](https://learn.microsoft.com/windows/desktop/com/com-authorization-constants). If RPC_C_AUTHZ_DEFAULT is specified, DCOM will pick an authorization service following its normal security blanket negotiation algorithm. RPC_C_AUTHZ_NONE should be used as the authorization service if NTLMSSP, Kerberos, or Schannel is used as the authentication service.

### `pServerPrincName` [in, optional]

The server principal name to be used with the authentication service. If COLE_DEFAULT_PRINCIPAL is specified, DCOM will pick a principal name using its security blanket negotiation algorithm. If Kerberos is used as the authentication service, this value must not be **NULL**. It must be the correct principal name of the server or the call will fail.

If Schannel is used as the authentication service, this value must be one of the msstd or fullsic forms described in [Principal Names](https://learn.microsoft.com/windows/desktop/Rpc/principal-names), or **NULL** if you do not want mutual authentication.

Generally, specifying **NULL** will not reset the server principal name on the proxy; rather, the previous setting will be retained. You must be careful when using **NULL** as *pServerPrincName* when selecting a different authentication service for the proxy, because there is no guarantee that the previously set principal name would be valid for the newly selected authentication service.

### `dwAuthnLevel` [in]

The authentication level to be used. For a list of possible values, see [Authentication Level Constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-level-constants). If RPC_C_AUTHN_LEVEL_DEFAULT is specified, DCOM will pick an authentication level following its normal security blanket negotiation algorithm. If this value is none, the authentication service must also be none.

### `dwImpLevel` [in]

The impersonation level to be used. For a list of possible values, see [Impersonation Level Constants](https://learn.microsoft.com/windows/desktop/com/com-impersonation-level-constants). If RPC_C_IMP_LEVEL_DEFAULT is specified, DCOM will pick an impersonation level following its normal security blanket negotiation algorithm. If NTLMSSP is the authentication service, this value must be RPC_C_IMP_LEVEL_IMPERSONATE or RPC_C_IMP_LEVEL_IDENTIFY. NTLMSSP also supports delegate-level impersonation (RPC_C_IMP_LEVEL_DELEGATE) on the same computer. If Schannel is the authentication service, this parameter must be RPC_C_IMP_LEVEL_IMPERSONATE.

### `pAuthInfo` [in, optional]

A pointer to an **RPC_AUTH_IDENTITY_HANDLE** value that establishes the identity of the client. The format of the structure referred to by the handle depends on the provider of the authentication service.

For calls on the same computer, RPC logs on the user with the supplied credentials and uses the resulting token for the method call.

For NTLMSSP or Kerberos, the structure is a [SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a) or [SEC_WINNT_AUTH_IDENTITY_EX](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure. The client can discard *pAuthInfo* after calling the API. RPC does not keep a copy of the *pAuthInfo* pointer, and the client cannot retrieve it later in the [CoQueryProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coqueryproxyblanket) method.

If this parameter is **NULL**, DCOM uses the current proxy identity (which is either the process token or the impersonation token). If the handle refers to a structure, that identity is used.

For Schannel, this parameter must be either a pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the client's X.509 certificate or is **NULL** if the client wishes to make an anonymous connection to the server. If a certificate is specified, the caller must not free it as long as any proxy to the object exists in the current apartment.

For Snego, this member is either **NULL**, points to a [SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a) structure, or points to a [SEC_WINNT_AUTH_IDENTITY_EX](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure. If it is **NULL**, Snego will pick a list of authentication services based on those available on the client computer. If it points to a **SEC_WINNT_AUTH_IDENTITY_EX** structure, the structure's **PackageList** member must point to a string containing a comma-separated list of authentication service names and the **PackageListLength** member must give the number of bytes in the **PackageList** string. If **PackageList** is **NULL**, all calls using Snego will fail.

If COLE_DEFAULT_AUTHINFO is specified for this parameter, DCOM will pick the authentication information following its normal security blanket negotiation algorithm.

**CoSetProxyBlanket** will fail if *pAuthInfo* is set and one of the cloaking flags is set in the *dwCapabilities* parameter.

### `dwCapabilities` [in]

The capabilities of this proxy. For a list of possible values, see the [EOLE_AUTHENTICATION_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-eole_authentication_capabilities) enumeration. The only flags that can be set through this function are EOAC_MUTUAL_AUTH, EOAC_STATIC_CLOAKING, EOAC_DYNAMIC_CLOAKING, EOAC_ANY_AUTHORITY (this flag is deprecated), EOAC_MAKE_FULLSIC, and EOAC_DEFAULT. Either EOAC_STATIC_CLOAKING or EOAC_DYNAMIC_CLOAKING can be set if *pAuthInfo* is not set and Schannel is not the authentication service. (See [Cloaking](https://learn.microsoft.com/windows/desktop/com/cloaking) for more information.) If any capability flags other than those mentioned here are set, **CoSetProxyBlanket** will fail.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The function was successful. |
| **E_INVALIDARG** | One or more arguments is invalid. |

## Remarks

**CoSetProxyBlanket** sets the authentication information that will be used to make calls on the specified proxy. This function encapsulates the following sequence of common calls (error handling excluded).

```C++
    pProxy->QueryInterface(IID_IClientSecurity, (void**)&pcs);
    pcs->SetBlanket(pProxy, dwAuthnSvc, dwAuthzSvc, pServerPrincName,
        dwAuthnLevel, dwImpLevel, pAuthInfo, dwCapabilities);
    pcs->Release();

```

This sequence calls [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the proxy to get a pointer to [IClientSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iclientsecurity), and with the resulting pointer, calls [IClientSecurity::SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket) and then releases the pointer.

## See also

[CoQueryProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coqueryproxyblanket)

[IClientSecurity::SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket)

[Security in COM](https://learn.microsoft.com/windows/desktop/com/security-in-com)

[Setting Security at the Interface Proxy Level](https://learn.microsoft.com/windows/desktop/com/setting-security-at-the-interface-proxy-level)