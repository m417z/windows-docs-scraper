# CryptSIPLoad function

## Description

The [SIP_DISPATCH_INFO](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_dispatch_info) structure. The exported functions must have been previously registered by calling the [CryptSIPAddProvider](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipaddprovider) function.

## Parameters

### `pgSubject` [in]

A pointer to a GUID returned by calling the [CryptSIPRetrieveSubjectGuid](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipretrievesubjectguid) function.

### `dwFlags` [in]

This parameter is reserved and must be set to zero.

### `pSipDispatch` [in, out]

A pointer to a [SIP_DISPATCH_INFO](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_dispatch_info) structure that contains pointers to SIP provider functions that are specific to the subject type. The caller must initialize this structure to binary zeros, and set the **cbSize** member to `sizeof(SIP_DISPATCH_INFO)` before calling the **CryptSIPLoad** function.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).