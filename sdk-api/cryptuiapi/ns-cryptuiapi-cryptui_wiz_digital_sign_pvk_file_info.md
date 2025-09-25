# CRYPTUI_WIZ_DIGITAL_SIGN_PVK_FILE_INFO structure

## Description

[The **CRYPTUI_WIZ_DIGITAL_SIGN_PVK_FILE_INFO** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPTUI_WIZ_DIGITAL_SIGN_PVK_FILE_INFO** structure is used with the [CRYPTUI_WIZ_DIGITAL_SIGN_INFO](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_info) structure to contain information about the PVK file used by the digital signature wizard.

## Members

### `dwSize`

The size, in bytes, of the structure.

### `pwszPvkFileName`

A pointer to a null-terminated Unicode string that contains the path and file name of the PVK file.

### `pwszProvName`

A pointer to a null-terminated Unicode string that contains the name of the provider.

### `dwProvType`

Contains the provider type identifier. For more information about the provider types, see [Cryptographic Provider Types](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptographic-provider-types).

## See also

[CRYPTUI_WIZ_DIGITAL_SIGN_INFO](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_info)

[Cryptographic Provider Types](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptographic-provider-types)