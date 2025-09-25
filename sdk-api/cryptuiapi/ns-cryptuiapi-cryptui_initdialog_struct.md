# CRYPTUI_INITDIALOG_STRUCT structure

## Description

The **CRYPTUI_INITDIALOG_STRUCT** structure supports the [CRYPTUI_VIEWCERTIFICATE_STRUCT](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_viewcertificate_structa) structure. It is passed as the *lParam* in the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) call to each
property sheet that is in the **rgPropSheetPages** array of the [CRYPTUI_VIEWCERTIFICATE_STRUCT](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_viewcertificate_structa) structure. The **CRYPTUI_VIEWCERTIFICATE_STRUCT** structure is used in the [CryptUIDlgViewCertificate](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuidlgviewcertificatea) function.

## Members

### `lParam`

The **lParam** in the [PROPSHEETPAGE](https://learn.microsoft.com/windows/desktop/api/prsht/ns-prsht-propsheetpagea_v2) structure.

### `pCertContext`

A pointer to the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure for the certificate that [CryptUIDlgViewCertificate](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuidlgviewcertificatea) is displaying.

## See also

[CRYPTUI_VIEWCERTIFICATE_STRUCT](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_viewcertificate_structa)

[CryptUIDlgViewCertificate](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuidlgviewcertificatea)