# CertStoreProvGetCTLProperty callback function

The **CertStoreProvGetCTLProperty** callback function retrieves a specified property of a [*certificate trust list*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CTL).

## Parameters

*hStoreProv* \[in\]

A **HCERTSTOREPROV** handle to a [*certificate store*](https://learn.microsoft.com/windows/win32/secgloss/c-gly).

*pCtlContext* \[in\]

A pointer to a [**CTL\_CONTEXT**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-ctl_context) structure.

*dwPropId* \[in\]

Indicates a property identifier.

*dwFlags* \[in\]

Any needed flag values.

*pvData* \[out\]

A pointer to a buffer to contain the pointer to a [**CTL\_CONTEXT**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-ctl_context) structure to be returned by the function. To get the value of *pcbData* before allocating memory for the buffer, this parameter can be set to **NULL** on a first call to the function.

*pcbData* \[in, out\]

A pointer to a **DWORD** that indicates the length of the *pvData* buffer.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**CTL\_CONTEXT**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-ctl_context)

