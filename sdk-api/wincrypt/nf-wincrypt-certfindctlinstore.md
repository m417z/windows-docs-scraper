# CertFindCTLInStore function

## Description

The **CertFindCTLInStore** function finds the first or next [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that matches search criteria established by the *dwFindType* and its associated *pvFindPara*. This function can be used in a loop to find all of the CTL contexts in a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that match the specified find criteria.

## Parameters

### `hCertStore` [in]

Handle of the certificate store to be searched.

### `dwMsgAndCertEncodingType` [in]

Specifies the type of encoding used on the CTL. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

This parameter is used only when the *dwFindType* parameter is set to CTL_FIND_USAGE.

### `dwFindFlags` [in]

Can be set when *dwFindType* is set to CTL_FIND_USAGE. For details, see the comments under CTL_FIND_USAGE, following.

### `dwFindType` [in]

Specifies the type of search being made. The search type determines the data type, contents, and the use of *pvFindPara*. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CTL_FIND_ANY** | Data type of *pvFindPara*: **NULL**.<br><br>Any CTL is a match. |
| **CTL_FIND_SHA1_HASH** | Data type of *pvFindPara*: [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)).<br><br>A CTL with a hash matching the hash in the [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure is found. |
| **CTL_FIND_MD5_HASH** | Data type of *pvFindPara*: [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)).<br><br>A CTL with a hash matching the hash in the [CRYPT_HASH_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure is found. |
| **CTL_FIND_USAGE** | Data type of *pvFindPara*: [CTL_FIND_USAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_find_usage_para).<br><br>Any CTL is found that has a usage identifier, list identifier, or signer matching the usage identifier, list identifier, or signer in the [CTL_FIND_USAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_find_usage_para) structure.<br><br>If the **cUsageIdentifier** member is of **SubjectUsage** size, any CTL is a match.<br><br>If the **cbData** member of **ListIdentifier** member is zero, any list identifier is a match. If the **cbData** member of **ListIdentifier** is CTL_FIND_NO_LIST_ID_CBDATA, only a CTL without a list identifier is a match.<br><br>If the **pSigner** member in the [CTL_FIND_USAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_find_usage_para) structure is **NULL**, any CTL signer is a match, and only the **Issuer** and **SerialNumber** members in the **pSigner** [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure are used. If **pSigner** is CTL_FIND_NO_SIGNER_PTR, only a CTL without a signer is a match. |
| **CTL_FIND_SAME_USAGE_FLAG** | Data type of *pvFindPara*: [CTL_FIND_USAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_find_usage_para).<br><br>Only CTLs with exactly the same usage identifiers are matched. CTLs having additional usage identifiers are not matched. For example, if only "1.2.3" is specified in the [CTL_FIND_USAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_find_usage_para) structure, then for a match, the CTL must only contain "1.2.3" and no additional usage identifiers. |
| **CTL_FIND_EXISTING** | Data type of *pvFindPara*: [PCCTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context).<br><br>Searches for the next CRL that is an exact match of the [CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context). |
| **CTL_FIND_SUBJECT** | Data type of *pvFindPara*: [CTL_FIND_SUBJECT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_find_subject_para).<br><br>A CTL having the specified subject is found. [CertFindSubjectInCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindsubjectinctl) can be called to get a pointer to the subject's entry in the CTL. The **pUsagePara** member in [CTL_FIND_SUBJECT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_find_subject_para) can optionally be set to enable the matching described preceding under CTL_FIND_USAGE. |

### `pvFindPara` [in]

A pointer to the search value associated with the *dwFindType* parameter.

### `pPrevCtlContext` [in]

A pointer to the last
[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) returned by this function. It must be **NULL** to get the first CTL in the store. Successive CTLs are retrieved by setting *pPrevCtlContext* to the pointer to the **CTL_CONTEXT** returned by a previous function call. Any certificates that do not meet the search criteria or that have been previously deleted by
[CertDeleteCTLFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletectlfromstore) are skipped. This function frees the **CTL_CONTEXT** referenced by non-**NULL** values of this parameter.

## Return value

If the function succeeds, the return value is a pointer to a read-only [CTL](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly)[context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **CRYPT_E_NOT_FOUND** | Either no CTLs were found in the store, no CTL was found matching the search criteria, or the function reached the end of the store's list. |
| **E_INVALIDARG** | The handle in the *hCertStore* parameter is not the same as that in the CTL context pointed to by the *pPrevCtlContext* parameter, or a value that is not valid was specified in the *dwFindType* parameter. |

## Remarks

A returned pointer is freed when passed as the *pPrevCtlContext* on a subsequent call to the function. Otherwise, the pointer must be freed by calling
[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext). A non-**NULL***pPrevCtlContext* passed to the function is always freed with a call to **CertFreeCTLContext**, even if the function generates an error.

[CertDuplicateCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatectlcontext) can be called to make a duplicate of the returned context. The returned CTL context can be added to a different certificate store using
[CertAddCTLContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddctlcontexttostore), or a link to that CTL context can be added to a noncollection store using
[CertAddCTLLinkToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddctllinktostore). If a CTL matching the search criteria is not found, **NULL** is returned.

## See also

[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context)

[CTL_FIND_USAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_find_usage_para)

[CertAddCTLContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddctlcontexttostore)

[CertAddCTLLinkToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddctllinktostore)

[CertDeleteCTLFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletectlfromstore)

[CertDuplicateCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatectlcontext)

[CertEnumCTLsInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumctlsinstore)

[CertFindSubjectInCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindsubjectinctl)

[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext)

[Certificate Trust List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)