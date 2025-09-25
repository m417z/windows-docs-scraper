## Description

The **QUERYCLIENTCERT** function is a client-side function that enables the server to request a certificate from the client when establishing a Secure Sockets Layer (SSL) connection.

Also see [Desktop Win32 code samples](https://learn.microsoft.com/windows/win32/desktop-win32-code-samples).

## Parameters

### `Connection` [in]

The session handle.

### `trusted_CAs` [in]

A list of server-trusted Certificate Authorities.

### `ppCertificate` [in, out]

Upon receiving the callback, the user supplies an appropriate client certificate in
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) format and returns a value of **TRUE**. If the client cannot supply an appropriate certificate or wants the server to use anonymous credentials, it should return a value of **FALSE** instead. Any certificate supplied must be freed by the application after the connection is completed.

## Remarks

Implement this function in your client application with the signature previously described. Then call
[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option) (conn, LDAP_OPT_CLIENT_CERTIFICATE, &CertRoutine) where CertRoutine is the address of your callback routine.

When the server demands a client certificate for authorization it will call **QUERYCLIENTCERT**. The LDAP run time passes a structure containing a list of server-trusted Certificate Authorities. The client application must examine this list of CAs the server trusts and supply an appropriate client certificate. The run time subsequently passes these credentials back to the SSL server as part of the handshake. If the client application requires anonymous credentials, it should pass back **FALSE** instead of supplying a certificate.

**Note** The application must perform an external bind subsequent to establishing the connection for the server to use the supplied client credentials.

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option)

[Desktop Win32 code samples](https://learn.microsoft.com/windows/win32/desktop-win32-code-samples)