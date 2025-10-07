# CertStoreProvFreeFindCRL callback function

The **CertStoreProvFreeFindCRL** callback function is called when the certificate returned by the [**CertStoreProvFindCRL**](https://learn.microsoft.com/windows/win32/seccrypto/certstoreprovfindcrl) callback was not used, and thus released, in a subsequent call to **CertStoreProvFindCRL**. Before the CLOSE callback is called, all certificates returned by the [**CertStoreProvFindCRL**](https://learn.microsoft.com/windows/win32/seccrypto/certstoreprovfindcrl) callback must be released by the provider using **CertStoreProvFindCRL** or **CertStoreProvFreeFindCRL**.

## Parameters

*hStoreProv* \[in\]

**HCERTSTOREPROV** handle to a [*certificate store*](https://learn.microsoft.com/windows/win32/secgloss/c-gly).

*pCrlContext* \[in\]

A pointer to a [**CRL\_CONTEXT**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-cert_context).

*pvStoreProvFindInfo* \[in\]

A pointer to a buffer containing find information.

*dwFlags* \[in\]

Any needed flag values.

## Return value

Returns **TRUE** if the function succeeds or **FALSE** if it fails.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**CertStoreProvFindCRL**](https://learn.microsoft.com/windows/win32/seccrypto/certstoreprovfindcrl)

[**CRL\_CONTEXT**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-cert_context)

