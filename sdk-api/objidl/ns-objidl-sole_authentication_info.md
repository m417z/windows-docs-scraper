# SOLE_AUTHENTICATION_INFO structure

## Description

Identifies an authentication service, authorization service, and the authentication information for the specified authentication service.

## Members

### `dwAuthnSvc`

The authentication service. This member can be a single value from the [Authentication Service Constants](https://learn.microsoft.com/windows/desktop/com/com-authentication-service-constants).

### `dwAuthzSvc`

The authorization service. This member can be a single value from the [Authorization Constants](https://learn.microsoft.com/windows/desktop/com/com-authorization-constants).

### `pAuthInfo`

A pointer to the authentication information, whose type is specific to the authentication service identified by **dwAuthnSvc**.

For Schannel ([RPC_C_AUTHN_GSS_SCHANNEL](https://learn.microsoft.com/windows/desktop/com/com-authentication-service-constants)), this member either points to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the client's X.509 certificate or is **NULL** if the client has no certificate or wishes to remain anonymous to the server.

For NTLMSSP ([RPC_C_AUTHN_WINNT](https://learn.microsoft.com/windows/desktop/com/com-authentication-service-constants)) and Kerberos (RPC_C_AUTHN_GSS_KERBEROS), this member points to a [SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a) or [SEC_WINNT_AUTH_IDENTITY_EX](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure that contains the user name and password.

For Snego ([RPC_C_AUTHN_GSS_NEGOTIATE](https://learn.microsoft.com/windows/desktop/com/com-authentication-service-constants)), this member is either **NULL**, points to a [SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a) structure, or points to a [SEC_WINNT_AUTH_IDENTITY_EX](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure. If it is **NULL**, Snego will pick a list of authentication services based on those available on the client computer. If it points to a **SEC_WINNT_AUTH_IDENTITY_EX** structure, the structure's **PackageList** member must point to a string containing a comma-separated list of authentication service names and the **PackageListLength** member must give the number of bytes in the **PackageList** string. If **PackageList** is **NULL**, all calls using Snego will fail.

For authentication services not registered with DCOM, **pAuthInfo** must be set to **NULL** and DCOM will use the process identity to represent the client. For more information, see [COM and Security Packages](https://learn.microsoft.com/windows/desktop/com/com-and-security-packages).

## See also

[CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity)

[CoSetProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosetproxyblanket)

[SOLE_AUTHENTICATION_LIST](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-sole_authentication_list)