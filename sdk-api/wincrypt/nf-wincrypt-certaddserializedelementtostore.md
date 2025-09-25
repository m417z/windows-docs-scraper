# CertAddSerializedElementToStore function

## Description

The **CertAddSerializedElementToStore** function adds a serialized [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL), or [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) element to the store. The serialized element contains the encoded certificate, CRL, or CTL and its extended properties. Extended properties are associated with a certificate and are not part of a certificate as issued by a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). Extended properties are not available on a certificate when it is used on a non-Microsoft platform.

## Parameters

### `hCertStore` [in]

The handle of a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) where the created certificate will be stored. If *hCertStore* is **NULL**, the function creates a copy of a certificate, CRL, or CTL context with its extended properties, but the certificate, CRL, or CTL is not persisted in any store.

### `pbElement` [in]

A pointer to a buffer that contains the certificate, CRL, or CTL information to be serialized and added to the certificate store.

### `cbElement` [in]

The size, in bytes, of the *pbElement* buffer.

### `dwAddDisposition` [in]

Specifies the action to take if the certificate, CRL, or CTL already exists in the store. Currently defined disposition values are shown in the following table.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_ADD_NEW** | If the certificate, CRL, or CTL is new, it is created and persisted to the store. The operation fails if an identical certificate, CRL, or CTL already exists in the store. The last error code is set to CRYPT_E_EXISTS. |
| **CERT_STORE_ADD_USE_EXISTING** | If the certificate, CRL, or CTL is new, it is added to the store. If an identical certificate, CRL, or CTL already exists, the existing element is used. If *ppvContext* is not **NULL**, the existing context is duplicated. The function only adds properties that do not already exist. The SHA-1 and MD5 hash properties are not copied. |
| **CERT_STORE_ADD_REPLACE_EXISTING** | If an identical certificate, CRL, or CTL already exists in the store, the existing certificate, CRL, or CTL context is deleted before creating and adding the new context. |
| **CERT_STORE_ADD_ALWAYS** | No check is made to determine whether an identical certificate, CRL, or CTL already exists. A new element is always created. This can lead to duplicates in the store. To determine whether the element already exists in the store, call [CertGetCRLFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcrlfromstore) or [CertGetSubjectCertificateFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetsubjectcertificatefromstore). |
| **CERT_STORE_ADD_NEWER** | If a matching CRL or CTL or a link to a matching CRL or CTL exists, the function compares the **NotBefore** times on the CRL or CTL. If the existing CRL or CTL has a **NotBefore** time less than the **NotBefore** time on the new element, the old element or link is replaced just as with CERT_STORE_ADD_REPLACE_EXISTING. If the existing element has a **NotBefore** time greater than or equal to the **NotBefore** time on the element to be added, the function fails with [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returning the CRYPT_E_EXISTS code.<br><br>If a matching CRL or CTL or a link to a matching CRL or CTL is not found in the store, a new element is added to the store. |
| **CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES** | The action is the same as for CERT_STORE_ADD_NEWER. However, if an older CRL or CTL is replaced, the properties of the older element are incorporated into the replacement. |
| **CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES** | If a matching certificate exists in the store, the existing context is deleted before creating and adding the new context. The new added context inherits properties from the existing certificate. |

### `dwFlags` [in]

Reserved for future use and must be zero.

### `dwContextTypeFlags` [in]

Specifics the contexts that can be added. For example, to add either a certificate, CRL, or CTL, set *dwContextTypeFlags* to **CERT_STORE_CERTIFICATE_CONTEXT_FLAG** or **CERT_STORE_CRL_CONTEXT_FLAG**.

Currently defined context type flags are shown in the following table.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_ALL_CONTEXT_FLAG** | Adds any context. |
| **CERT_STORE_CERTIFICATE_CONTEXT_FLAG** | Adds only a certificate context. |
| **CERT_STORE_CRL_CONTEXT_FLAG** | Adds only a CRL context. |
| **CERT_STORE_CTL_CONTEXT_FLAG** | Adds only a CTL context. |

### `pdwContextType` [out]

A pointer to the context type of the added serialized element. This is an optional parameter and can be **NULL**, which indicates that the calling application does not require the [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) type.

Currently defined context types are shown in the following table.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_CERTIFICATE_CONTEXT** | Certificates |
| **CERT_STORE_CRL_CONTEXT** | CRLs |
| **CERT_STORE_CTL_CONTEXT** | CTLs |

### `ppvContext` [out]

A pointer to a pointer to the decoded certificate, CRL, or CTL context. This is an optional parameter and can be **NULL**, which indicates that the calling application does not require the context of the added or existing certificate, CRL, or CTL.

If *ppvContext* is not **NULL**, it must be the address of a pointer to a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context),
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context), or
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context). When the application is finished with the context, the context must be freed by using
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) for a certificate,
[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext) for a CRL, or
[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext) for a CTL.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_EXISTS** | If the *dwAddDisposition* parameter is set to CERT_STORE_ADD_NEW, the certificate, CRL, or CTL already exists in the store. |
| **E_INVALIDARG** | A disposition value that is not valid was specified in the *dwAddDisposition* parameter. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[CertSerializeCRLStoreElement](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certserializecrlstoreelement)

[CertSerializeCertificateStoreElement](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certserializecertificatestoreelement)

[Certificate and Certificate Store Maintenance Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)