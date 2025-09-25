# SOLE_AUTHENTICATION_SERVICE structure

## Description

Identifies an authentication service that a server is willing to use to communicate to a client.

## Members

### `dwAuthnSvc`

The authentication service. This member can be a single value from the [Authentication Service Constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-service-constants).

### `dwAuthzSvc`

The authorization service. This member can be a single value from the [Authorization Constants](https://learn.microsoft.com/windows/desktop/com/com-authorization-constants).

### `pPrincipalName`

The principal name to be used with the authentication service. If the principal name is **NULL**, the current user identifier is assumed. A **NULL** principal name is allowed for NTLMSSP, Kerberos, and Snego authentication services but may not work for other authentication services. For Schannel, this member must point to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the server's certificate; if it **NULL** and if a certificate for the current user does not exist, RPC_E_NO_GOOD_SECURITY_PACKAGES is returned.

### `hr`

When used in [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity), set on return to indicate the status of the call to register the authentication services.

## See also

[CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity)

[CoQueryAuthenticationServices](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coqueryauthenticationservices)