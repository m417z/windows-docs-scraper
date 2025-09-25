# CRYPTUI_WIZ_DIGITAL_SIGN_CONTEXT structure

## Description

[The **CRYPTUI_WIZ_DIGITAL_SIGN_CONTEXT** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPTUI_WIZ_DIGITAL_SIGN_CONTEXT** structure is used with the [CryptUIWizDigitalSign](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizdigitalsign) function to contain information about a [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly).

## Members

### `dwSize`

The size, in bytes, of the structure.

### `cbBlob`

The size, in bytes, of the BLOB pointed to by the **pbBlob** member.

### `pbBlob`

A pointer to the signed BLOB.

## See also

[CryptUIWizDigitalSign](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizdigitalsign)