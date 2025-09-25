# CoQueryProxyBlanket function

## Description

Retrieves the authentication information the client uses to make calls on the specified proxy. This is a helper function for [IClientSecurity::QueryBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-queryblanket).

## Parameters

### `pProxy` [in]

A pointer indicating the proxy to query. This parameter cannot be **NULL**. For more information, see the Remarks section.

### `pwAuthnSvc` [out, optional]

A pointer to a variable that receives the current authentication service. This will be a single value taken from the [authentication service constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-service-constants). This parameter cannot be **NULL**.

### `pAuthzSvc` [out, optional]

A pointer to a variable that receives the current authorization service. This will be a single value taken from the [authorization constants](https://learn.microsoft.com/windows/desktop/com/com-authorization-constants). If the caller specifies **NULL**, the current authorization service is not retrieved.

### `pServerPrincName` [out, optional]

The current principal name. The string will be allocated by the callee using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc), and must be freed by the caller using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree). The EOAC_MAKE_FULLSIC flag is not accepted in the *pCapabilities* parameter. For more information about the msstd and fullsic forms, see [Principal Names](https://learn.microsoft.com/windows/desktop/Rpc/principal-names). If the caller specifies **NULL**, the current principal name is not retrieved.

### `pAuthnLevel` [out, optional]

A pointer to a variable that receives the current authentication level. This will be a single value taken from the [authentication level constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-level-constants). If the caller specifies **NULL**, the current authentication level is not retrieved.

### `pImpLevel` [out, optional]

A pointer to a variable that receives the current impersonation level. This will be a single value taken from the [impersonation level constants](https://learn.microsoft.com/windows/desktop/com/com-impersonation-level-constants). If the caller specifies **NULL**, the current impersonation level is not retrieved.

### `pAuthInfo` [out, optional]

A pointer to a handle that receives the identity of the client that was passed to the last [IClientSecurity::SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket) call (or the default value). Default values are only valid until the proxy is released. If the caller specifies **NULL**, the client identity is not retrieved. The format of the structure that the handle refers to depends on the authentication service. The application should not write or free the memory. For NTLMSSP and Kerberos, if the client specified a structure in the *pAuthInfo* parameter to [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity), that value is returned. For Schannel, if a certificate for the client could be retrieved from the certificate manager, that value is returned here. Otherwise, **NULL** is returned. See [RPC_AUTH_IDENTITY_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-auth-identity-handle).

### `pCapabilites` [out, optional]

A pointer to a variable that receives the capabilities of the proxy. If the caller specifies **NULL**, the current capability flags are not retrieved.

## Return value

This function can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and S_OK.

## Remarks

**CoQueryProxyBlanket** is called by the client to retrieve the authentication information COM will use on calls made from the specified proxy. This function encapsulates the following sequence of common calls (error handling excluded):

``` syntax
pProxy->QueryInterface(IID_IClientSecurity, (void**)&pcs);
pcs->QueryBlanket(
    pProxy, pAuthnSvc, pAuthzSvc, pServerPrincName, pAuthnLevel, pImpLevel, ppAuthInfo, pCapabilities
  );
pcs->Release();

```

This sequence calls [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the proxy to get a pointer to [IClientSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iclientsecurity), and with the resulting pointer, calls [IClientSecurity::QueryBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-queryblanket) and then releases the pointer.

In *pProxy*, you can pass any proxy, such as a proxy you get through a call to [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) or [CoUnmarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-counmarshalinterface), or you can pass an interface pointer. It can be any interface. You cannot pass a pointer to something that is not a proxy. Therefore, you can't pass a pointer to an interface that has the local keyword in its interface definition because no proxy is created for such an interface. [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) is the exception to this rule.

## See also

[CoQueryClientBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coqueryclientblanket)

[CoSetProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosetproxyblanket)

[IClientSecurity::QueryBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-queryblanket)

[Security in COM](https://learn.microsoft.com/windows/desktop/com/security-in-com)