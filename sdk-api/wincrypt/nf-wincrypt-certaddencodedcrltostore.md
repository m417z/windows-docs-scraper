# CertAddEncodedCRLToStore function

## Description

The **CertAddEncodedCRLToStore** function creates a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) context from an encoded CRL and adds it to the certificate store. The function makes a copy of the CRL context before adding it to the store.

## Parameters

### `hCertStore` [in]

Handle of a certificate store.

### `dwCertEncodingType` [in]

Specifies the type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pbCrlEncoded` [in]

A pointer to a buffer containing the encoded CRL to be added to the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `cbCrlEncoded` [in]

The size, in bytes, of the *pbCrlEncoded* buffer.

### `dwAddDisposition` [in]

Specifies the action to take if a matching CRL or a link to a matching CRL already exists in the store. Currently defined disposition values and their uses are as follows.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_ADD_ALWAYS** | Makes no check for an existing matching CRL or link to a matching CRL. A new CRL is always added to the store. This can lead to duplicates in a store. |
| **CERT_STORE_ADD_NEW** | If a matching CRL or a link to a matching CRL exists, the operation fails. [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the CRYPT_E_EXISTS code. |
| **CERT_STORE_ADD_NEWER** | If a matching CRL or a link to a matching CRL exists, the **ThisUpdate** times on the CRLs are compared. If the existing CRL has a **ThisUpdate** time less than the **ThisUpdate** time on the new CRL, the old CRL or link is replaced just as with CERT_STORE_ADD_REPLACE_EXISTING. If the existing CRL has a **ThisUpdate** time greater than or equal to the **ThisUpdate** time on the CRL to be added, the function fails with [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returning the CRYPT_E_EXISTS code.<br><br>If a matching CRL or a link to a matching CRL is not found in the store, a new CRL is added to the store. |
| **CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES** | The action is the same as for CERT_STORE_ADD_NEWER, except that if an older CRL is replaced, the properties of the older CRL are incorporated into the replacement CRL. |
| **CERT_STORE_ADD_REPLACE_EXISTING** | If a matching CRL or a link to a matching CRL exists, that existing CRL or link is deleted and a new CRL is created and added to the store. If a matching CRL or a link to a matching CRL does not exist, one is added. |
| **CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES** | If a matching CRL exists in the store, that existing context is deleted before creating and adding the new context. The new context inherits properties from the existing CRL. |
| **CERT_STORE_ADD_USE_EXISTING** | If a matching CRL or a link to a matching CRL exists, that existing CRL is used and properties from the new CRL are added. The function does not fail, but no new CRL is added. If *ppCertContext* is not **NULL**, the existing context is duplicated. <br><br>If a matching CRL or a link to a matching CRL does not exist, a new CRL is added. |

### `ppCrlContext` [out, optional]

A pointer to a pointer to the decoded
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structure. This is an optional parameter that can be **NULL**, indicating that the calling application does not require a copy of the new or existing CRL. If a copy is made, that context must be freed using
[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext).

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_EXISTS** | CERT_STORE_ADD_NEW is set and the CRL already exists in the store, or CERT_STORE_ADD_NEWER is set and there is a CRL in the store with a **ThisUpdate** time greater than or equal to the **ThisUpdate** time for the CRL to be added. |
| **E_INVALIDARG** | A disposition value that is not valid was specified in the *dwAddDisposition* parameter, or an encoding type that is not valid was specified. Currently, only the encoding type X509_ASN_ENCODING is supported. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[CertAddCRLContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcrlcontexttostore)

[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext)

[Certificate Revocation List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)