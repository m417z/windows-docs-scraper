# CertCreateContext function

## Description

The **CertCreateContext** function creates the specified context from the encoded bytes. The context created does not include any extended properties.

## Parameters

### `dwContextType` [in]

Specifies the contexts that can be created. For example, to create a [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), set *dwContextType* to CERT_STORE_CERTIFICATE_CONTEXT.

Currently defined context type flags are shown in the following table.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_CERTIFICATE_CONTEXT** | Certificate context. |
| **CERT_STORE_CRL_CONTEXT** | CRL context. |
| **CERT_STORE_CTL_CONTEXT** | CTL context. |

### `dwEncodingType` [in]

Specifies the encoding type used. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are being used; however, additional encoding types may be added in the future. For either current encoding type, use:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING.

### `pbEncoded` [in]

A pointer to a buffer that contains the existing encoded context content to be copied.

### `cbEncoded` [in]

The size, in bytes, of the *pbEncoded* buffer.

### `dwFlags` [in]

The following flag values are defined and can be combined by using a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **CERT_CREATE_CONTEXT_NOCOPY_FLAG** | The created context points directly to the content pointed to by *pbEncoded* instead of an allocated copy. |
| **CERT_CREATE_CONTEXT_SORTED_FLAG** | The function creates a context with sorted entries. Currently, this flag only applies to a CTL context.<br><br>For CTLs, the **cCTLEntry** member of the returned [CTL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_info) structure is always zero. [CertFindSubjectInSortedCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindsubjectinsortedctl) and [CertEnumSubjectInSortedCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsubjectinsortedctl) must be called to find or enumerate the CTL entries. |
| **CERT_CREATE_CONTEXT_NO_HCRYPTMSG_FLAG** | By default, when a CTL context is created, a HCRYTPMSG handle to its [SignedData](https://learn.microsoft.com/windows/desktop/SecCrypto/signeddata) message is created. This flag can be set to improve performance by not creating this handle. This flag can only be used when *dwContextType* is CERT_STORE_CTL_CONTEXT. |
| **CERT_CREATE_CONTEXT_NO_ENTRY_FLAG** | By default, when a CTL context is created, its entries are decoded. When this flag is set, the entries are not decoded and performance is improved. This flag can only be used when *dwContextType* is CERT_STORE_CTL_CONTEXT. |

### `pCreatePara` [in, optional]

A pointer to a [CERT_CREATE_CONTEXT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_create_context_para) structure.

If *pCreatePara* and its **pfnFree** member are both non-**NULL**, the **pfnFree** member is used to free the memory specified by the **pvFree** member. If the **pvFree** member is **NULL**, the **pfnFree** member is used to free the *pbEncoded* pointer.

If *pCreatePara* or its **pfnFree** member is **NULL**, no attempt is made to free *pbEncoded*.

## Return value

If the function succeeds, the return value is a pointer to the newly created context. The **pvFree** member of *pCreatePara* must be called to free the created context.

If the function fails, the return value is **NULL**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_CANCELLED**, this means that the [PFN_CERT_CREATE_CONTEXT_SORT_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_create_context_sort_func) callback function returned **FALSE** to stop the sort.

## See also

[CTL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_info)

[CertEnumSubjectInSortedCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumsubjectinsortedctl)

[CertFindSubjectInSortedCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindsubjectinsortedctl)

[Certificate and Certificate Store Maintenance Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)