# CertAddCertificateLinkToStore function

## Description

The **CertAddCertificateLinkToStore** function adds a link in a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to a [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) in a different store. Instead of creating and adding a duplicate of the certificate context, this function adds a link to the original certificate.

## Parameters

### `hCertStore` [in]

A handle to the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) where the link is to be added.

### `pCertContext` [in]

A pointer to the
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure to be linked.

### `dwAddDisposition` [in]

Specifies the action if a matching certificate or a link to a matching certificate already exists in the store. Currently defined disposition values and their uses are as follows.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_ADD_ALWAYS** | The function makes no check for an existing matching certificate or link to a matching certificate. A new certificate is always added to the store. This can lead to duplicates in a store. |
| **CERT_STORE_ADD_NEW** | If a matching certificate or a link to a matching certificate exists, the operation fails. [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the CRYPT_E_EXISTS code. |
| **CERT_STORE_ADD_REPLACE_EXISTING** | If a link to a matching certificate exists, that existing link is deleted and a new link is created and added to the store. If no matching certificate or link to a matching certificate exists, one is added. |
| **CERT_STORE_ADD_USE_EXISTING** | If a matching certificate or a link to a matching certificate exists, the existing certificate is used. The function does not fail, but no new link is added. If no matching certificate or link to a matching certificate exists, a new link is added. |

### `ppStoreContext` [out, optional]

A pointer to a pointer to a copy of the link created. The *ppStoreContext* parameter can be **NULL** to indicate that a copy of the link is not needed. If a copy of the link is created, that copy must be freed using
the [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_EXISTS** | For a *dwAddDisposition* parameter of CERT_STORE_ADD_NEW, the certificate already exists in the store. |
| **E_INVALIDARG** | A disposition value that is not valid was specified in the *dwAddDisposition* parameter. |

## Remarks

Because the link provides access to the original certificate [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), setting an extended property in the linked [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) changes that extended property in the certificate's original location and in any other links to that certificate.

Links cannot be added to a store opened as a collection. Stores opened as collections include all stores opened with
[CertOpenSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopensystemstorea) or
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) using CERT_STORE_PROV_SYSTEM or CERT_STORE_PROV_COLLECTION. For more information, see
[CertAddStoreToCollection](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddstoretocollection).

If links are used and
[CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) is called with CERT_CLOSE_STORE_FORCE_FLAG, the store that uses links must be closed before the store that contains the original contexts is closed. If CERT_CLOSE_STORE_FORCE_FLAG is not used, the two stores can be closed in either order.

To remove the certificate context link from the certificate store, use the [CertDeleteCertificateFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletecertificatefromstore) function.

#### Examples

For an example that uses this function, see [Example C Program: Certificate Store Operations](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-certificate-store-operations). For additional code that uses this function, see [Example C Program: Collection and Sibling Certificate Store Operations](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-collection-and-sibling-certificate-store-operations).

## See also

[CertAddCRLLinkToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcrllinktostore)

[CertAddCTLLinkToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddctllinktostore)

[CertAddStoreToCollection](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddstoretocollection)

[CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore)

[CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext)

[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore)

[CertOpenSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopensystemstorea)

[Certificate Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)