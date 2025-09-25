# CRYPTUI_WIZ_EXPORT_INFO structure

## Description

[The **CRYPTUI_WIZ_EXPORT_INFO** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPTUI_WIZ_EXPORT_INFO** structure contains information that controls the operation of the [CryptUIWizExport](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizexport) function.

## Members

### `dwSize`

The size, in bytes, of this structure.

### `pwszExportFileName`

A pointer to a null-terminated Unicode string that contains the fully qualified file name to export to. If this member is
not **NULL** and the **CRYPTUI_WIZ_NO_UI** flag in the *dwFlags* parameter of the [CryptUIWizExport](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizexport) function is not set, this string is
displayed to the user as the default file name. This member is required if the **CRYPTUI_WIZ_NO_UI** flag is set. This member is otherwise optional.

### `dwSubjectChoice`

Indicates the type of the subject to export. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPTUI_WIZ_EXPORT_CERT_CONTEXT** | Export the certificate context that is specified in the **pCertContext** member. |
| **CRYPTUI_WIZ_EXPORT_CTL_CONTEXT** | Export the [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) context that is specified in the **pCTLContext** member. |
| **CRYPTUI_WIZ_EXPORT_CRL_CONTEXT** | Export the [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) context that is specified in the **pCRLContext** member. |
| **CRYPTUI_WIZ_EXPORT_CERT_STORE** | Export the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that is specified in the **hCertStore** member. |
| **CRYPTUI_WIZ_EXPORT_CERT_STORE_CERTIFICATES_ONLY** | Export only the [certificates](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) from the certificate store that is specified in the **hCertStore** member. |

### `pCertContext`

A pointer to the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the certificate to export. This member is used if the **dwSubjectChoice** member contains **CRYPTUI_WIZ_EXPORT_CERT_CONTEXT**.

### `pCTLContext`

A pointer to the [CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure that contains the CTL to export. This member is used if the **dwSubjectChoice** member contains **CRYPTUI_WIZ_EXPORT_CTL_CONTEXT**.

### `pCRLContext`

A pointer to the [CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structure that contains the CRL to export. This member is used if the **dwSubjectChoice** member contains **CRYPTUI_WIZ_EXPORT_CRL_CONTEXT**.

### `hCertStore`

A handle to the certificate store to export. This member is used if the **dwSubjectChoice** member contains **CRYPTUI_WIZ_EXPORT_CERT_STORE** or **CRYPTUI_WIZ_EXPORT_CERT_STORE_CERTIFICATES_ONLY**.

### `cStores`

The number of elements in the **rghStores** array.

### `rghStores`

An array of extra certificate stores to search for certificates in the trust chain if the chain is being exported with a certificate.
This member is ignored if **dwSubjectChoice** is anything other than the **CRYPTUI_WIZ_EXPORT_CERT_CONTEXT** value. The **cStores** member contains the number of elements in this array.

## See also

[CryptUIWizExport](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizexport)