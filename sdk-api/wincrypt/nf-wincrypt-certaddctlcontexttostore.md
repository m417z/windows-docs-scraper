# CertAddCTLContextToStore function

## Description

The **CertAddCTLContextToStore** function adds a [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) context to a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Parameters

### `hCertStore` [in]

Handle of a certificate store.

### `pCtlContext` [in]

A pointer to the
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure to be added to the store.

### `dwAddDisposition` [in]

Specifies the action to take if a matching CTL or a link to a matching CTL already exists in the store. Currently defined disposition values and their uses are as follows.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_ADD_ALWAYS** | Makes no check for an existing matching CTL or link to a matching CTL. A new CTL is always added to the store. This can lead to duplicates in a store. |
| **CERT_STORE_ADD_NEW** | If a matching CTL or a link to a matching CTL exists, the operation fails. [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the CRYPT_E_EXISTS code. |
| **CERT_STORE_ADD_NEWER** | If a matching CTL or a link to a matching CTL exists, the **ThisUpdate** times on the CTLs are compared. If the existing CTL has a **ThisUpdate** time less than the **ThisUpdate** time on the new CTL, the old CTL or link is replaced just as with CERT_STORE_ADD_REPLACE_EXISTING. If the existing CTL has a **ThisUpdate** time greater than or equal to the **ThisUpdate** time on the CTL to be added, the function fails with [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returning the CRYPT_E_EXISTS code.<br><br>If a matching CTL or a link to a matching CTL is not found in the store, a new CTL is added to the store. |
| **CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES** | The action is the same as for CERT_STORE_ADD_NEWER, except that if an older CTL is replaced, the properties of the older CTL are incorporated into the replacement CTL. |
| **CERT_STORE_ADD_REPLACE_EXISTING** | If a matching CTL or a link to a matching CTL exists, the existing CTL or link is deleted and a new CTL is created and added to the store. If a matching CTL or a link to a matching CTL does not exist, one is added. |
| **CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES** | If a matching CTL exists in the store, that existing context is deleted before creating and adding the new context. The added context inherits properties from the existing CTL. |
| **CERT_STORE_ADD_USE_EXISTING** | If a matching CTL or a link to a matching CTL exists, that existing CTL is used and properties from the new CTL are added. The function does not fail, but no new CTL is added. If *ppCertContext* is not **NULL**, the existing context is duplicated.<br><br>If a matching CTL or a link to a matching CTL does not exist, a new CTL is added. |

### `ppStoreContext` [out, optional]

Pointer to a pointer to the decoded CTL [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This optional parameter can be **NULL** indicating that the calling application does not require a copy of the added or existing CTL. If a copy is made, that context must be freed using
[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext).

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. Errors from the called functions
[CertAddEncodedCRLToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedcrltostore) and
[CertSetCRLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetcrlcontextproperty) can be propagated to this function.

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_EXISTS** | This error is returned if CERT_STORE_ADD_NEW is set and the CTL exists in the store or if CERT_STORE_ADD_NEWER is set and a CTL exists in the store with a **ThisUpdate** date greater than or equal to the **ThisUpdate** date on the CTL to be added. |
| **E_INVALIDARG** | An add disposition that is not valid was specified by the *dwAddDisposition* parameter. |

## Remarks

The CTL context is not duplicated using
[CertDuplicateCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatectlcontext). Instead, a new copy is created and added to the store. In addition to the encoded CTL, the context's properties are copied.

To remove the CTL context from the certificate store, use the [CertDeleteCTLFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletectlfromstore) function.

## See also

[CertAddEncodedCTLToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedctltostore)

[CertSetCTLContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetctlcontextproperty)

[Certificate Trust List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)