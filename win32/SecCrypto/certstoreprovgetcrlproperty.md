# CertStoreProvGetCRLProperty callback function

The **CertStoreProvGetCRLProperty** callback function retrieves a specified property of a [*CRL*](https://learn.microsoft.com/windows/win32/secgloss/c-gly).

## Parameters

*hStoreProv* \[in\]

**HCERTSTOREPROV** handle to a [*certificate store*](https://learn.microsoft.com/windows/win32/secgloss/c-gly).

*pCrlContext* \[in\]

A pointer to a [**CRL\_CONTEXT**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-crl_context) structure.

*dwPropId* \[in\]

Indicates a property identifier.

*dwFlags* \[in\]

Any needed flag values.

*pvData* \[out\]

A pointer to a buffer to contain the pointer to a [**CRL\_CONTEXT**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-crl_context) structure to be returned by the function. May be set to **NULL** on a first call to the function to get the value of *pcbData* before allocating memory for the buffer.

*pcbData* \[in, out\]

A pointer to a **DWORD** indicating the length of the *pvData* buffer.

## Return value

Returns **TRUE** if the function succeeds or **FALSE** if it fails.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**CRL\_CONTEXT**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-crl_context)

