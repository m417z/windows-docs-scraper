# CertSetCertificateContextPropertiesFromCTLEntry function

## Description

The **CertSetCertificateContextPropertiesFromCTLEntry** function sets the properties on the certificate context by using the attributes in the specified [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) entry.

## Parameters

### `pCertContext` [in]

A pointer to the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) whose attributes are to be set.

### `pCtlEntry` [in]

A pointer to the [CTL_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_entry) structure used to set the attributes on the certificate.

### `dwFlags` [in]

 A **DWORD**. This parameter can be set to CERT_SET_PROPERTY_IGNORE_PERSIST_ERROR_FLAG to ignore any persisted error flags.

## Return value

If the function succeeds, the function returns nonzero.

 If the function fails, it returns zero. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[CTL_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_entry)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)