## Description

The **PFNCMFILTERPROC** function is a filter procedure that filters each certificate to determine whether it will appear in the certificate selection dialog box that is displayed by the [CertSelectCertificate](https://learn.microsoft.com/windows/win32/api/cryptdlg/nf-cryptdlg-certselectcertificatea) function. **PFNCMFILTERPROC** is an application-defined callback function that is specified in the [CERT_SELECT_STRUCT](https://learn.microsoft.com/windows/win32/api/cryptdlg/ns-cryptdlg-cert_select_struct_a) structure. The **CERT_SELECT_STRUCT** structure is a parameter in the [CertSelectCertificate](https://learn.microsoft.com/windows/win32/api/cryptdlg/nf-cryptdlg-certselectcertificatea) function. The **PFNCMFILTERPROC** function must be implemented by the developer to suit each application.

## Parameters

### `pCertContext`

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_context) structure that contains a certificate on which to make a filtering determination.

### `unnamedParam2`

*dwDisplayWell*. Reserved for future use.

### `unnamedParam3`

This `DWORD` parameter is *dwFlags*.

### `unnamedParam4`

This `DWORD` parameter is *lCustData*. It is the address of an array of byte values that holds custom data. *lCustData* is passed to the **PFNCMFILTERPROC** function by the [CertSelectCertificate](https://learn.microsoft.com/windows/win32/api/cryptdlg/nf-cryptdlg-certselectcertificatea) function.

## Return value

Return a nonzero value (**TRUE**) to display the certificate. Return zero (**FALSE**) to not display the certificate.

## Remarks

## See also

[CERT_SELECT_STRUCT](https://learn.microsoft.com/windows/win32/api/cryptdlg/ns-cryptdlg-cert_select_struct_a)

[CertSelectCertificate](https://learn.microsoft.com/windows/win32/api/cryptdlg/nf-cryptdlg-certselectcertificatea)