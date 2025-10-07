# CertStoreProvFreeFindCTL callback function

The **CertStoreProvFreeFindCTL** callback function is called when the certificate returned by the [**CertStoreProvFindCTL**](https://learn.microsoft.com/windows/win32/seccrypto/certstoreprovfindctl) callback was not used, and thus released, in a subsequent call to **CertStoreProvFindCTL**. Before the CLOSE callback is called, all certificates returned by the [**CertStoreProvFindCTL**](https://learn.microsoft.com/windows/win32/seccrypto/certstoreprovfindctl) callback must be released by the provider using **CertStoreProvFindCTL** or **CertStoreProvFreeFindCTL**.

## Parameters

*hStoreProv* \[in\]

**HCERTSTOREPROV** handle to a [*certificate store*](https://learn.microsoft.com/windows/win32/secgloss/c-gly).

*pCtlContext* \[in\]

A pointer to a [**CTL\_CONTEXT**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-cert_context) structure.

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

[**CertStoreProvFindCTL**](https://learn.microsoft.com/windows/win32/seccrypto/certstoreprovfindctl)

[**CTL\_CONTEXT**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-cert_context)

