# CertAddCTLLinkToStore function

## Description

The **CertAddCTLLinkToStore** function adds a link in a store to a [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) in a different store. Instead of creating and adding a duplicate of a CTL context, this function adds a link to the original CTL context.

## Parameters

### `hCertStore` [in]

Handle of the certificate store where the link is to be added.

### `pCtlContext` [in]

A pointer to the
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure to be linked.

### `dwAddDisposition` [in]

Specifies the action to take if a matching CTL or a link to a matching CTL already exists in the store. Currently defined disposition values and their uses are as follows.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_ADD_ALWAYS** | Makes no check for an existing matching CTL or link to a matching CTL. A new CTL is always added to the store. This can lead to duplicates in a store. |
| **CERT_STORE_ADD_NEW** | If a matching CTL or a link to a matching CTL exists, the operation fails. [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the CRYPT_E_EXISTS code. |
| **CERT_STORE_ADD_NEWER** | If a matching CTL or a link to a matching CTL exists, the **ThisUpdate** times on the CTLs are compared. If the existing CTL has a **ThisUpdate** time less than the **ThisUpdate** time on the new CTL, the old CTL or link is replaced just as with CERT_STORE_ADD_REPLACE_EXISTING. If the existing CTL has a **ThisUpdate** time greater than or equal to the **ThisUpdate** time on the CTL to be added, the function fails with [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returning the CRYPT_E_EXISTS code. <br><br>If a matching CTL or a link to a matching CTL is not found in the store, a new CTL is added to the store. |
| **CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES** | The action is the same as for CERT_STORE_ADD_NEWER, except that if an older CTL is replaced, the properties of the older CTL are incorporated into the replacement CTL. |
| **CERT_STORE_ADD_REPLACE_EXISTING** | If a matching CTL or a link to a matching CTL exists, the existing CTL or link is deleted and a new CTL is created and added to the store. If a matching CTL or a link to a matching CTL does not exist, one is added. |
| **CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES** | If a matching CTL exists in the store, that existing context is deleted before creating and adding the new context. The added context inherits properties from the existing CTL. |
| **CERT_STORE_ADD_USE_EXISTING** | If a matching CTL or a link to a matching CTL exists, that existing CTL is used and properties from the new CTL are added. The function does not fail, but no new CTL is added. If *ppCertContext* is not **NULL**, the existing context is duplicated.<br><br>If a matching CTL or a link to a matching CTL does not exist, a new CTL is added. |

### `ppStoreContext` [out, optional]

A pointer to a pointer to a copy of the link created. *ppStoreContext* can be **NULL** to indicate that a copy of the link is not needed. If a copy of the link is created, that copy must be freed using
[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext).

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_EXISTS** | For a *dwAddDisposition* of CERT_STORE_ADD_NEW, the CTL already exists in the store. |
| **E_INVALIDARG** | The add disposition specified by the *dwAddDisposition* parameter is not valid. |

## Remarks

Because the link provides access to the original [CTL](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) context, setting an extended property in the linked CTL context changes that extended property in the original CTL's location and in any other links to that CTL.

Links cannot be added to a store that is opened as a collection. Stores opened as collections include all stores opened with
[CertOpenSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopensystemstorea) or
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) using CERT_STORE_PROV_SYSTEM or CERT_STORE_PROV_COLLECTION. Also see
[CertAddStoreToCollection](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddstoretocollection).

When links are used and
[CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) is called with CERT_CLOSE_STORE_FORCE_FLAG, the store using links must be closed before the store containing the original contexts is closed. If CERT_CLOSE_STORE_FORCE_FLAG is not used, the two stores can be closed in either order.

To remove the CTL context link from the certificate store, use the [CertDeleteCTLFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletectlfromstore) function.

## See also

[CertAddCRLLinkToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcrllinktostore)

[CertAddCertificateLinkToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcertificatelinktostore)

[CertAddStoreToCollection](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddstoretocollection)

[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext)

[CertOpenSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopensystemstorea)

[Certificate Trust List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)