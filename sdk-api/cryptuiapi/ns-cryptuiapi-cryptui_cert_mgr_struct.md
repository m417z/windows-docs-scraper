# CRYPTUI_CERT_MGR_STRUCT structure

## Description

The **CRYPTUI_CERT_MGR_STRUCT** structure contains information about a certificate manager dialog box.

## Members

### `dwSize`

The size, in bytes, of the structure. This value must be set to `sizeof(CRYPTUI_CERT_MGR_STRUCT)`.

### `hwndParent`

Handle of the parent window of the dialog box.

### `dwFlags`

Reserved. This value must be set to zero.

### `pwszTitle`

Title of the dialog box.

### `pszInitUsageOID`

Enhanced key usage [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of the certificates that will initially appear in the dialog box. The default value is **NULL**, which displays all certificates.