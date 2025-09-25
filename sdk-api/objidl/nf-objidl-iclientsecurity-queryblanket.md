# IClientSecurity::QueryBlanket

## Description

Retrieves authentication information the client uses to make calls on the specified proxy.

## Parameters

### `pProxy` [in]

A pointer to the proxy. This parameter cannot be **NULL**. For more information, see the Remarks section.

### `pAuthnSvc` [out]

The current authentication service. This will be a single value taken from the list of [authentication service constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-service-constants). This parameter cannot be **NULL**.

### `pAuthzSvc` [out]

The current authorization service. This will be a single value taken from the list of [authorization constants](https://learn.microsoft.com/windows/desktop/com/com-authorization-constants). This parameter cannot be **NULL**.

### `pServerPrincName` [out]

The current principal name. The string will be allocated by the callee using the [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) function and must be freed by the caller using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function. Note that the actual principal name is returned. The EOAC_MAKE_FULLSIC flag is not accepted to convert the prinicpal name. If the caller specifies **NULL**, the current principal name is not retrieved.

### `pAuthnLevel` [out]

The current authentication level. This will be a single value taken from the list of [authentication level constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-level-constants). If this parameter is **NULL**, the current authentication level is not retrieved.

### `pImpLevel` [out]

The current impersonation level. This will be a single value taken from the list of [impersonation level constants](https://learn.microsoft.com/windows/desktop/com/com-impersonation-level-constants). If this parameter is **NULL**, the current impersonation level is not retrieved.

### `pAuthInfo` [out]

A pointer to a handle indicating the identity of the client that was passed to the last [IClientSecurity::SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket) call (or the default value). Default values are only valid until the proxy is released. If the caller specifies **NULL**, the client identity is not retrieved.

The format of the structure that the returned handle refers to depends on the authentication service. For NTLMSSP and Kerberos, if the client specified a structure in the *pAuthInfo* parameter to [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity), that value is returned. For Schannel, if a certificate for the client could be retrieved from the certificate manager, that value is returned here. Otherwise, **NULL** is returned. Because this points to the value itself and is not a copy, it should not be manipulated or freed.

### `pCapabilites` [out]

The capabilities of the proxy. These flags are defined in the [EOLE_AUTHENTICATION_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-eole_authentication_capabilities) enumeration. If this parameter is **NULL**, the current capability flags are not retrieved.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **E_OUTOFMEMORY** | There is insufficient memory to create the *pServerPrincName* buffer. |

## Remarks

**QueryBlanket** is called by the client to retrieve the authentication information COM will use on calls made from the specified interface proxy. With a pointer to an interface on the proxy, the client would first call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for a pointer to [IClientSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iclientsecurity); then, with this pointer, the client would call **QueryBlanket**, followed by releasing the pointer. This sequence of calls is encapsulated in the helper function [CoQueryProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coqueryproxyblanket).

In *pProxy*, you pass an interface pointer. However, you cannot pass a pointer to an interface that does not use a proxy. Thus you cannot pass a pointer to an interface that has the local keyword in its interface definition since no proxy is created for such an interface. [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) is the exception to this rule.

## See also

[CoQueryProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coqueryproxyblanket)

[CoSetProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosetproxyblanket)

[IClientSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iclientsecurity)