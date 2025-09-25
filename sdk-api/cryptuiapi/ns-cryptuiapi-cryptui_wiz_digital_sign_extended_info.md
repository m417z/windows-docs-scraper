# CRYPTUI_WIZ_DIGITAL_SIGN_EXTENDED_INFO structure

## Description

[The **CRYPTUI_WIZ_DIGITAL_SIGN_EXTENDED_INFO** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPTUI_WIZ_DIGITAL_SIGN_EXTENDED_INFO** structure is used with the [CRYPTUI_WIZ_DIGITAL_SIGN_INFO](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_info) structure to contain extended information about a signature.

## Members

### `dwSize`

The size, in bytes, of the structure.

### `dwAttrFlags`

A value that indicates the type of the signature. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPTUI_WIZ_DIGITAL_SIGN_COMMERCIAL** | The signature is a commercial signature. |
| **CRYPTUI_WIZ_DIGITAL_SIGN_INDIVIDUAL** | The signature is a personal signature. |

### `pwszDescription`

A pointer to a null-terminated Unicode string that contains the description of the subject of the signature.

### `pwszMoreInfoLocation`

A pointer to a null-terminated Unicode string that contains the location from which to get more information about the file. This information will be displayed when the file is downloaded.

### `pszHashAlg`

A pointer to a null-terminated ANSI string that contains the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of the hash algorithm used for the signature. The default value is **NULL**, which indicates that the SHA-1 hash algorithm is used.

### `pwszSigningCertDisplayString`

A pointer to a null-terminated Unicode string that contains the string displayed on the digital signature wizard page. The string should prompt the user to select a certificate for a specific purpose.

### `hAdditionalCertStore`

A handle to an additional certificate store that will be added to the signature.

### `psAuthenticated`

A pointer to a [CRYPT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attributes) structure that contains authenticated attributes supplied by the user.

### `psUnauthenticated`

A pointer to a [CRYPT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attributes) structure that contains unauthenticated attributes supplied by the user.

## See also

[CRYPTUI_WIZ_DIGITAL_SIGN_INFO](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_info)