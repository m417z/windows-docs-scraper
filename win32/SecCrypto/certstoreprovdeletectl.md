# CertStoreProvDeleteCTL callback function

The **CertStoreProvDeleteCTL** callback function is called by [**CertDeleteCTLFromStore**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/nf-wincrypt-certdeletectlfromstore) before deleting a CTL from the store. This function determines whether a CTL can be deleted.

## Parameters

*hStoreProv* \[in\]

**HCERTSTOREPROV** handle to a [*certificate store*](https://learn.microsoft.com/windows/win32/secgloss/c-gly).

*pCtlContext* \[in\]

A pointer to a [**CTL\_CONTEXT**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-ctl_context) structure.

*dwFlags* \[in\]

Any needed flag values.

## Return value

Returns **TRUE** if a CTL can be deleted from the store.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

