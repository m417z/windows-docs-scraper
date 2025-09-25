# CoQueryAuthenticationServices function

## Description

Retrieves a list of the authentication services registered when the process called [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity).

## Parameters

### `pcAuthSvc` [out]

A pointer to a variable that receives the number of entries returned in the *asAuthSvc* array.

### `asAuthSvc` [out]

A pointer to an array of [SOLE_AUTHENTICATION_SERVICE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-sole_authentication_service) structures. The list is allocated through a call to the [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) function. The caller must free the list when finished with it by calling the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

This function can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and S_OK.

## Remarks

**CoQueryAuthenticationServices** retrieves a list of the authentication services currently registered. If the process calls [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity), these are the services registered through that call. If the application does not call it, **CoInitializeSecurity** is called automatically by COM, registering the default security package, the first time an interface is marshaled or unmarshaled.

This function returns only the authentication services registered with [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity). It does not return all of the authentication services installed on the computer, but [EnumerateSecurityPackages](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-enumeratesecuritypackagesa) does. **CoQueryAuthenticationServices** is primarily useful for custom marshalers, to determine which principal names an application can use.

Different authentication services support different levels of security. For example, NTLMSSP does not support delegation or mutual authentication while Kerberos does. The application is responsible only for registering authentication services that provide the features the application needs. This function provides a way to find out which services have been registered with [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity).

## See also

[CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity)

[SOLE_AUTHENTICATION_SERVICE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-sole_authentication_service)

[Security in COM](https://learn.microsoft.com/windows/desktop/com/security-in-com)