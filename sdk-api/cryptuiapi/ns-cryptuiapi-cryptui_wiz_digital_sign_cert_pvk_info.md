# CRYPTUI_WIZ_DIGITAL_SIGN_CERT_PVK_INFO structure

## Description

[The **CRYPTUI_WIZ_DIGITAL_SIGN_CERT_PVK_INFO** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPTUI_WIZ_DIGITAL_SIGN_CERT_PVK_INFO** structure contains information about the PVK file that contains the certificates used by the [CryptUIWizDigitalSign](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizdigitalsign) function.

## Members

### `dwSize`

The size, in bytes, of the structure.

### `pwszSigningCertFileName`

A pointer to a null-terminated Unicode string that contains the path and file named of the file that contains the signing certificates.

### `dwPvkChoice`

Specifies the type of entity that contains the certificates. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPTUI_WIZ_DIGITAL_SIGN_PVK_FILE** | The entity is a PVK file. |
| **CRYPTUI_WIZ_DIGITAL_SIGN_PVK_PROV** | The entity is a PVK provider. |

### `pPvkFileInfo`

A pointer to a [CRYPTUI_WIZ_DIGITAL_SIGN_PVK_FILE_INFO](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_pvk_file_info) structure that contains the PVK file that contains the certificates. This member is used if **CRYPTUI_WIZ_DIGITAL_SIGN_PVK_FILE** is specified for the **dwPvkChoice** member.

### `pPvkProvInfo`

A pointer to a [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure that contains information about the PVK provider that contains the certificates. This member is used if **CRYPTUI_WIZ_DIGITAL_SIGN_PVK_PROV** is specified for the **dwPvkChoice** member.

## See also

[CryptUIWizDigitalSign](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizdigitalsign)