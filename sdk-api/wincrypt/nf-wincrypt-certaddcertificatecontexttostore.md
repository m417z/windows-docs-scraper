# CertAddCertificateContextToStore function

## Description

The **CertAddCertificateContextToStore** function adds a certificate [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Parameters

### `hCertStore` [in]

Handle of a certificate store.

### `pCertContext` [in]

A pointer to the
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure to be added to the store.

### `dwAddDisposition` [in]

Specifies the action to take if a matching certificate or a link to a matching certificate already exists in the store. Currently defined disposition values and their uses are as follows.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_ADD_ALWAYS** | The function makes no check for an existing matching certificate or link to a matching certificate. A new certificate is always added to the store. This can lead to duplicates in a store. |
| **CERT_STORE_ADD_NEW** | If a matching certificate or a link to a matching certificate exists, the operation fails. [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the CRYPT_E_EXISTS code. |
| **CERT_STORE_ADD_NEWER** | If a matching certificate or a link to a matching certificate exists and the NotBefore time of the existing context is equal to or greater than the NotBefore time of the new context being added, the operation fails and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the CRYPT_E_EXISTS code. <br><br>If the NotBefore time of the existing context is less than the NotBefore time of the new context being added, the existing certificate or link is deleted and a new certificate is created and added to the store. If a matching certificate or a link to a matching certificate does not exist, a new link is added. <br><br>If [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs) or [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTLs) are being compared, the ThisUpdate time is used. |
| **CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES** | If a matching certificate or a link to a matching certificate exists and the NotBefore time of the existing context is equal to or greater than the NotBefore time of the new context being added, the operation fails and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the CRYPT_E_EXISTS code. <br><br>If the NotBefore time of the existing context is less than the NotBefore time of the new context being added, the existing context is deleted before creating and adding the new context. The new added context inherits properties from the existing certificate.<br><br>If CRLs or CTLs are being compared, the ThisUpdate time is used. |
| **CERT_STORE_ADD_REPLACE_EXISTING** | If a link to a matching certificate exists, that existing certificate or link is deleted and a new certificate is created and added to the store. If a matching certificate or a link to a matching certificate does not exist, a new link is added. |
| **CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES** | If a matching certificate exists in the store, the existing context is not replaced. The existing context inherits properties from the new certificate. |
| **CERT_STORE_ADD_USE_EXISTING** | If a matching certificate or a link to a matching certificate exists, that existing certificate or link is used and properties from the new certificate are added. The function does not fail, but it does not add a new context. If *pCertContext* is not **NULL**, the existing context is duplicated. <br><br>If a matching certificate or a link to a matching certificate does not exist, a new certificate is added. |

### `ppStoreContext` [out, optional]

A pointer to a pointer to the copy to be made of the certificate that was added to the store.

The *ppStoreContext* parameter can be **NULL**, indicating that the calling application does not require a copy of the added certificate. If a copy is made, it must be freed by using
[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext).

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_EXISTS** | This value is returned if CERT_STORE_ADD_NEW is set and the certificate already exists in the store, or if CERT_STORE_ADD_NEWER is set and a certificate exists in the store with a **NotBefore** date greater than or equal to the **NotBefore** date on the certificate to be added. |
| **E_INVALIDARG** | A disposition value that is not valid was specified in the *dwAddDisposition* parameter. |

Errors from the called functions,
[CertAddEncodedCertificateToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedcertificatetostore) and
[CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty), can be propagated to this function.

## Remarks

The certificate [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) is not duplicated using [CertDuplicateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecertificatecontext). Instead, the function creates a new copy of the context and adds it to the [store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

In addition to the encoded certificate, [CertDuplicateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecertificatecontext) also copies the context's properties, with the exception of the CERT_KEY_PROV_HANDLE_PROP_ID and CERT_KEY_CONTEXT_PROP_ID properties.

To remove the certificate context from the certificate store, use the [CertDeleteCertificateFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletecertificatefromstore) function.

**Note** The order of the certificate context may not be preserved within the store.
To access a specific certificate you must iterate across the certificates in the store.

## See also

[CertAddEncodedCertificateToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedcertificatetostore)

[CertSetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcertificatecontextproperty)

[Certificate Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)