# CoQueryClientBlanket function

## Description

Called by the server to find out about the client that invoked the method executing on the current thread. This is a helper function for [IServerSecurity::QueryBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iserversecurity-queryblanket).

## Parameters

### `pAuthnSvc` [out, optional]

A pointer to a variable that receives the current authentication service. This will be a single value taken from the [authentication service constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-service-constants). If the caller specifies **NULL**, the current authentication service is not retrieved.

### `pAuthzSvc` [out, optional]

A pointer to a variable that receives the current authorization service. This will be a single value taken from the [authorization constants](https://learn.microsoft.com/windows/desktop/com/com-authorization-constants). If the caller specifies **NULL**, the current authorization service is not retrieved.

### `pServerPrincName` [out, optional]

The current principal name. The string will be allocated by the callee using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc), and must be freed by the caller using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree). By default, Schannel principal names will be in the msstd form. The fullsic form will be returned if EOAC_MAKE_FULLSIC is specified in the *pCapabilities* parameter. For more information about the msstd and fullsic forms, see [Principal Names](https://learn.microsoft.com/windows/desktop/Rpc/principal-names). If the caller specifies **NULL**, the current principal name is not retrieved.

### `pAuthnLevel` [out, optional]

A pointer to a variable that receives the current authentication level. This will be a single value taken from the [authentication level constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-level-constants). If the caller specifies **NULL**, the current authentication level is not retrieved.

### `pImpLevel` [out, optional]

This parameter must be **NULL**.

### `pPrivs` [out, optional]

A pointer to a handle that receives the privilege information for the client application. The format of the structure that the handle refers to depends on the authentication service. The application should not write or free the memory. The information is valid only for the duration of the current call. For NTLMSSP and Kerberos, this is a string identifying the client principal. For Schannel, this is a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that represents the client's certificate. If the client has no certificate, **NULL** is returned. If the caller specifies **NULL**, the current privilege information is not retrieved. See [RPC_AUTHZ_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-authz-handle).

### `pCapabilities` [in, out, optional]

A pointer to return flags indicating capabilities of the call. To request that the principal name be returned in fullsic form if Schannel is the authentication service, the caller can set the EOAC_MAKE_FULLSIC flag in this parameter. If the caller specifies **NULL**, the current capabilities are not retrieved.

## Return value

This function can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and S_OK.

## Remarks

**CoQueryClientBlanket** is called by the server to get security information about the client that invoked the method executing on the current thread. This function encapsulates the following sequence of common calls (error handling excluded):

``` syntax
    CoGetCallContext(IID_IServerSecurity, (void**)&pss);
    pss->QueryBlanket(pAuthnSvc, pAuthzSvc, pServerPrincName,
                pAuthnLevel, pImpLevel, pPrivs, pCapabilities);
    pss->Release();

```

This sequence calls [CoGetCallContext](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetcallcontext) to get a pointer to [IServerSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iserversecurity) and, with the resulting pointer, calls [IServerSecurity::QueryBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iserversecurity-queryblanket) and then releases the pointer.

## See also

[CoGetCallContext](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetcallcontext)

[CoQueryProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coqueryproxyblanket)

[IServerSecurity::QueryBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iserversecurity-queryblanket)

[Security in COM](https://learn.microsoft.com/windows/desktop/com/security-in-com)