# CertAddCRLContextToStore function

## Description

The **CertAddCRLContextToStore** function adds a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) context to the specified [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Parameters

### `hCertStore` [in]

Handle of a certificate store.

### `pCrlContext` [in]

A pointer to the
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structure to be added.

### `dwAddDisposition` [in]

Specifies the action to take if a matching CRL or a link to a matching CRL already exists in the store. Currently defined disposition values and their uses are as follows.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_ADD_ALWAYS** | Makes no check for an existing matching CRL or link to a matching CRL. A new CRL is always added to the store. This can lead to duplicates in a store. |
| **CERT_STORE_ADD_NEW** | If a matching CRL or a link to a matching CRL exists, the operation fails. [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the CRYPT_E_EXISTS code. |
| **CERT_STORE_ADD_NEWER** | If a matching CRL or a link to a matching CRL exists, the function compares the **ThisUpdate** times on the CRLs. If the existing CRL has a **ThisUpdate** time less than the **ThisUpdate** time on the new CRL, the old CRL or link is replaced just as with CERT_STORE_ADD_REPLACE_EXISTING. If the existing CRL has a **ThisUpdate** time greater than or equal to the **ThisUpdate** time on the CRL to be added, the function fails with [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returning the CRYPT_E_EXISTS code.<br><br>If a matching CRL or a link to a matching CRL is not found in the store, a new CRL is added to the store. |
| **CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES** | The action is the same as for CERT_STORE_ADD_NEWER, except that if an older CRL is replaced, the properties of the older CRL are incorporated into the replacement CRL. |
| **CERT_STORE_ADD_REPLACE_EXISTING** | If a matching CRL or a link to a matching CRL exists, the existing CRL or link is deleted and a new CRL is created and added to the store. If a matching CRL or a link to a matching CRL does not exist, one is added. |
| **CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES** | If a matching CRL exists in the store, the existing context is deleted before creating and adding the new context. The added context inherits properties from the existing CRL. |
| **CERT_STORE_ADD_USE_EXISTING** | If a matching CRL or a link to a matching CRL exists, that existing CRL is used and properties from the new CRL are added. The function does not fail, but no new CRL is added. If *ppCertContext* is not **NULL**, the existing context is duplicated. <br><br>If a matching CRL or a link to a matching CRL does not exist, a new CRL is added. |

### `ppStoreContext` [out, optional]

A pointer to a pointer to the decoded CRL context. This is an optional parameter and can be **NULL**, indicating that the calling application does not require a copy of the added or existing CRL. If a copy is made, that context must be freed by using
[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext).

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. Errors from the called functions
[CertAddEncodedCRLToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedcrltostore) and
[CertSetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcrlcontextproperty) can be propagated to this function.

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_EXISTS** | This error is returned if CERT_STORE_ADD_NEW is set and the CRL already exists in the store or if CERT_STORE_ADD_NEWER is set and a CRL exists in the store with a **ThisUpdate** date greater than or equal to the **ThisUpdate** date on the CRL to be added. |
| **E_INVALIDARG** | The *dwAddDisposition* parameter specified a disposition value that is not valid. |

## Remarks

The CRL context is not duplicated using
[CertDuplicateCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecrlcontext). Instead, a new copy is created and added to the store. In addition to copying the encoded CRL, the function copies the context's properties.

To remove the CRL context from the certificate store, use the [CertDeleteCRLFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletecrlfromstore) function.

## See also

[CertAddEncodedCRLToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedcrltostore)

[CertDuplicateCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecrlcontext)

[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext)

[CertSetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcrlcontextproperty)

[Certificate Revocation List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)