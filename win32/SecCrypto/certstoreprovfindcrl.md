# CertStoreProvFindCRL callback function

The **CertStoreProvFindCRL** callback function enumerates or finds the first or next [*CRL*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) in an external [*store*](https://learn.microsoft.com/windows/win32/secgloss/e-gly) that matches specified criteria.

## Parameters

*hStoreProv* \[in\]

**HCERTSTOREPROV** handle to a [*certificate store*](https://learn.microsoft.com/windows/win32/secgloss/c-gly).

*pFindInfo* \[in\]

A pointer to a [**CERT\_STORE\_PROV\_FIND\_INFO**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-cert_store_prov_find_info) structure containing all the parameters passed to the [**CertFindCRLInStore**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/nf-wincrypt-certfindcrlinstore) function.

*pPrevCrlContext* \[in\]

A pointer to a [**CRL\_CONTEXT**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-crl_context) structure of the last CRL found. On first call to the function, this parameter should be set to **NULL**. On subsequent calls, it should be set to the pointer returned in the *ppProvCRLContext* parameter on the last call. A non-**NULL** pointer passed in this parameter is freed by the callback function.

*dwFlags* \[in\]

Any needed flag values.

*ppvStoreProvFindInfo* \[in, out\]

A pointer to a pointer to a buffer to return the store provider information. Optionally, the callback can return a pointer to internal find information in this parameter. After the first call, this parameter is set to the pointer returned by the previous call to the function.

*ppProvCrlContext* \[out\]

On a successful find, a pointer to the CRL found is returned in this parameter.

## Return value

Returns **TRUE** if the function succeeds or **FALSE** if it fails.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**CERT\_STORE\_PROV\_FIND\_INFO**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-cert_store_prov_find_info)

[**CertFindCRLInStore**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/nf-wincrypt-certfindcrlinstore)

[**CRL\_CONTEXT**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-crl_context)

