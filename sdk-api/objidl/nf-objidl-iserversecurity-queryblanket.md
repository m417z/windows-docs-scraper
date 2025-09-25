# IServerSecurity::QueryBlanket

## Description

Retrieves information about the client that invoked one of the server's methods.

## Parameters

### `pAuthnSvc` [out]

A pointer to the current authentication service. This will be a single value taken from the list of [authentication service constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-service-constants). If the caller specifies **NULL**, the current authentication service is not retrieved.

### `pAuthzSvc` [out]

A pointer to a variable that receives the current authorization service. This will be a single value from the list of [authorization constants](https://learn.microsoft.com/windows/desktop/com/com-authorization-constants). If the caller specifies **NULL**, the current authorization service is not retrieved.

### `pServerPrincName` [out]

The current principal name. The string will be allocated by the callee using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc), and must be freed by the caller using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree). By default, Schannel principal names will be in the msstd form. The fullsic form will be returned if EOAC_MAKE_FULLSIC is specified in the *pCapabilities* parameter. For more information on the msstd and fullsic forms, see [Principal Names](https://learn.microsoft.com/windows/desktop/Rpc/principal-names). If the caller specifies **NULL**, the current principal name is not retrieved.

### `pAuthnLevel` [out]

A pointer to a variable that receives the current authentication level. This will be a single value taken from the list of [authentication level constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-level-constants). If the caller specifies **NULL**, the current authentication level is not retrieved.

### `pImpLevel` [out]

This parameter must be **NULL**.

### `pPrivs` [out]

The privilege information for the client application. The format of the structure that the handle refers to depends on the authentication service. The application should not write or free the memory. The information is only valid for the duration of the current call. For NTLMSSP, and Kerberos, this is a [SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a) or [SEC_WINNT_AUTH_IDENTITY_EX](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure. For Schannel, this is a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that represents the client's certificate. If the client has no certificate, **NULL** is returned. If the caller specifies **NULL**, the current privilege information is not retrieved.

### `pCapabilities` [in, out]

The capabilities of the call. To request that the principal name be returned in fullsic form if Schannel is the authentication service, the caller can set the EOAC_MAKE_FULLSIC flag in this parameter. If the caller specifies **NULL**, the current capabilities are not retrieved.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and S_OK.

## Remarks

**QueryBlanket** is used by the server to find out about the client that invoked one of its methods. To get a pointer to [IServerSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iserversecurity) for the current call on the current thread, call [CoGetCallContext](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetcallcontext), specifying IID_IServerSecurity. This interface pointer may only be used in the same apartment as the call for the duration of the call.

## See also

[CoQueryClientBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coqueryclientblanket)

[CoQueryProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coqueryproxyblanket)

[IServerSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iserversecurity)