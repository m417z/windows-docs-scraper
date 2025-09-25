# CertAddCRLLinkToStore function

## Description

The **CertAddCRLLinkToStore** function adds a link in a store to a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) context in a different store. Instead of creating and adding a duplicate of the CRL, this function adds a link to the original CRL context.

## Parameters

### `hCertStore` [in]

Handle of a certificate store where the link is to be added.

### `pCrlContext` [in]

A pointer to the
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structure to be linked.

### `dwAddDisposition` [in]

Specifies the action to take if a matching CRL or a link to a matching CRL exists in the store. Currently defined disposition values and their uses are as follows.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_ADD_ALWAYS** | Makes no check for an existing matching CRL or link to a matching CRL. A new link is always added to the store. This can lead to duplicates in a store. |
| **CERT_STORE_ADD_NEW** | If a matching CRL or a link to a matching CRL exists, the operation fails. [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the CRYPT_E_EXISTS code. |
| **CERT_STORE_ADD_NEWER** | If a matching CRL or a link to a matching CRL exists, the **ThisUpdate** times on the CRLs are compared. If the existing CRL has a **ThisUpdate** time less than the **ThisUpdate** time on the new CRL, the old link is replaced just as with CERT_STORE_ADD_REPLACE_EXISTING. If the existing CRL has a **ThisUpdate** time greater than or equal to the **ThisUpdate** time on the CRL to be added, the function fails with [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returning the CRYPT_E_EXISTS code. <br><br>If a matching CRL or a link to a matching CRL is not found in the store, a new link is added to the store. |
| **CERT_STORE_ADD_REPLACE_EXISTING** | If a link to the matching CRL exists, that existing link is deleted and a new link is created and added to the store. If a matching CRL or a link to a matching CRL does not exist, a new link is added. |
| **CERT_STORE_ADD_USE_EXISTING** | If a matching CRL or a link to a matching CRL exists, that existing link is used. The function does not fail, but no new link is added. If a matching CRL or link to a CRL does not exist, a new link is added. |

### `ppStoreContext` [out, optional]

A pointer to a pointer of a copy of the link created. The *ppStoreContext* parameter can be **NULL** to indicate that a copy of the link is not needed. If a copy of the link is created, that copy must be freed using
[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext).

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_EXISTS** | For a *dwAddDisposition* of CERT_STORE_ADD_NEW, the CTL already exists in the store. |
| **E_INVALIDARG** | A disposition value that is not valid was specified in the *dwAddDisposition* parameter. |

## Remarks

Because the link provides access to an original CRL context, setting an extended property in the linked CRL context changes that extended property in the CRL's original location and in any other links to that CRL.

Links cannot be added to a store that is opened as a collection. Stores opened as collections include all stores opened with
[CertOpenSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopensystemstorea) or
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) using CERT_STORE_PROV_SYSTEM or CERT_STORE_PROV_COLLECTION. For more information, see
[CertAddStoreToCollection](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddstoretocollection).

If links are used and
[CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) is called with CERT_CLOSE_STORE_FORCE_FLAG, the store using links must be closed before the store containing the original contexts can be closed. If CERT_CLOSE_STORE_FORCE_FLAG is not used, the two stores can be closed in either order.

To remove the CRL context link from the certificate store, use the [CertDeleteCRLFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletecrlfromstore) function.

## See also

[CertAddCTLLinkToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddctllinktostore)

[CertAddCertificateLinkToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcertificatelinktostore)

[CertAddStoreToCollection](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddstoretocollection)

[CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore)

[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext)

[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore)

[CertOpenSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopensystemstorea)

[Certificate Revocation List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)