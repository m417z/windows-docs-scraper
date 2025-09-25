# VERIFYSERVERCERT callback function

## Description

**VERIFYSERVERCERT** is a callback function that allows a client to evaluate the certificate chain of the server to which it is connected.

## Parameters

### `Connection`

The session handle.

### `pServerCert`

#### - ppServerCert

A pointer to a pointer to a session handle, represented by [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context).

## Return value

If the function succeeds (the client approves the server certificate), the return value is **TRUE**.

If the function fails; the return value is **FALSE** and the secure connection is torn down.

## Remarks

The **VERIFYSERVERCERT** callback function allows the client to verify the certificate of the server. The client registers a callback which is invoked after the secure connection is set up. The server certificate context is presented to the callback function, where it can be verified as acceptable or not. To register this callback, call
[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option) where CertRoutine is the address of your callback function.

```cpp
conn, LDAP_OPT_SERVER_CERTIFICATE, &CertRoutine
```

The server calls **VERIFYSERVERCERT** after the secure connection has been established. The server's certificate context is supplied for examination by the client.

An application should use the *ppServerCert* parameter as: `PCCERT_CONTEXT* ppServerCert = (PCCERT_CONTEXT*)pServerCert;`

Even though **VERIFYSERVERCERT** is declared as receiving a [PCCERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context), it in fact receives a **PCCERT_CONTEXT***. The *ppServerCert* can be used to verify the certificate. [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) should be called before this function returns. The call to this function should be made as follows:

```cpp
CertFreeCertificateContext(*ppServerCert);
```

Or, alternatively, as:

```cpp
CertFreeCertificateContext(*((PCCERT_CONTEXT*)pServerCert));
```

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option)