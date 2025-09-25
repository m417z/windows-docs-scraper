# PFNCFILTERPROC callback function

## Description

The **PFNCFILTERPROC** function is an application-defined callback function that filters the certificates that appear in the digital signature wizard that are displayed by the [CryptUIWizDigitalSign](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizdigitalsign) function.

## Parameters

### `pCertContext` [in]

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the certificate to filter.

### `pfInitialSelectedCert` [in]

A Boolean value that specifies whether the certificate contained in the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure pointed to by the *pCertContext* parameter should be initially selected in the dialog box. This parameter is used only if the filter process returns **TRUE**.

### `pvCallbackData` [in]

A pointer to user-defined data.

## Return value

A Boolean value that specifies whether the certificate contained in the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure pointed to by the *pCertContext* parameter should be displayed in the digital signature wizard.