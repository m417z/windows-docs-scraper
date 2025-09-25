# CryptUIDlgSelectCertificateFromStore function

## Description

The **CryptUIDlgSelectCertificateFromStore** function displays a dialog box that allows the selection of a certificate from a specified store.

## Parameters

### `hCertStore` [in]

Handle of the certificate store to be searched.

### `hwnd` [in]

Handle of the window for the display. If **NULL**, defaults to the desktop window.

### `pwszTitle` [in, optional]

String used as the title of the dialog box. If **NULL**, the default title, "Select Certificate," is used.

### `pwszDisplayString` [in, optional]

Text statement in the selection dialog box. If **NULL**, the default phrase, "Select a certificate you want to use," is used.

### `dwDontUseColumn` [in]

Flags that can be combined to exclude columns of the display.

| Value | Meaning |
| --- | --- |
| **CRYPTUI_SELECT_ISSUEDTO_COLUMN** | Do not display the ISSUEDTO information. |
| **CRYPTUI_SELECT_ISSUEDBY_COLUMN** | Do not display the ISSUEDBY information. |
| **CRYPTUI_SELECT_INTENDEDUSE_COLUMN** | Do not display IntendedUse information. |
| **CRYPTUI_SELECT_FRIENDLYNAME_COLUMN** | Do not display the display name information. |
| **CRYPTUI_SELECT_LOCATION_COLUMN** | Do not display location information. |
| **CRYPTUI_SELECT_EXPIRATION_COLUMN** | Do not display expiration information. |

### `dwFlags` [in]

Currently not used and should be set to 0.

### `pvReserved` [in]

Reserved for future use.

## Return value

Returns a pointer to the selected certificate context. If no certificate was selected, **NULL** is returned. When you have finished using the certificate, free the certificate context by calling the [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function.

## See also

[CryptUIDlgViewContext](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuidlgviewcontext)