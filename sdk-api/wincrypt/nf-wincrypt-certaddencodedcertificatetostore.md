# CertAddEncodedCertificateToStore function

## Description

The **CertAddEncodedCertificateToStore** function creates a certificate [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) from an encoded certificate and adds it to the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). The context created does not include any extended properties.

The **CertAddEncodedCertificateToStore** function also makes a copy of the encoded certificate before adding the certificate to the store.

## Parameters

### `hCertStore` [in]

A handle to the certificate store.

### `dwCertEncodingType` [in]

Specifies the type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pbCertEncoded` [in]

A pointer to a buffer containing the encoded certificate that is to be added to the certificate store.

### `cbCertEncoded` [in]

The size, in bytes, of the *pbCertEncoded* buffer.

### `dwAddDisposition` [in]

Specifies the action to take if a matching certificate or link to a matching certificate exists in the store. Currently defined disposition values and their uses are as follows.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_ADD_ALWAYS** | The function makes no check for an existing matching certificate or link to a matching certificate. A new certificate is always added to the store. This can lead to duplicates in a store. |
| **CERT_STORE_ADD_NEW** | If a matching certificate or a link to a matching certificate exists in the store, the operation fails. [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the CRYPT_E_EXISTS code. |
| **CERT_STORE_ADD_REPLACE_EXISTING** | If a matching certificate or link to a matching certificate exists in the store, the existing certificate or link is deleted and a new certificate is created and added to the store. If a matching certificate or link to a matching certificate does not exist, a new certificate is created and added to the store. |
| **CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES** | If a matching certificate exists in the store, that existing context is deleted before creating and adding the new context. The new context inherits properties from the existing certificate. |
| **CERT_STORE_ADD_USE_EXISTING** | If a matching certificate or a link to a matching certificate exists, that existing certificate or link is used and properties from the new certificate are added. The function does not fail, but it does not add a new context. If *ppCertContext* is not **NULL**, the existing context is duplicated.<br><br>If a matching certificate or link to a matching certificate does not exist, a new certificate is added. |

### `ppCertContext` [out, optional]

A pointer to a pointer to the decoded [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This is an optional parameter that can be **NULL**, indicating that the calling application does not require a copy of the new or existing certificate. When a copy is made, its context must be freed by using
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext).

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_EXISTS** | This code is returned if CERT_STORE_ADD_NEW is set and the certificate already exists in the store, or if CERT_STORE_ADD_NEWER is set and there is a certificate in the store with a **NotBefore** date greater than or equal to the **NotBefore** date on the certificate to be added. |
| **E_INVALIDARG** | A disposition value that is not valid was specified in the *dwAddDisposition* parameter, or a certificate encoding type that is not valid was specified. Currently, only the X509_ASN_ENCODING type is supported. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[CertAddCertificateContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcertificatecontexttostore)

[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext)

[Certificate Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)