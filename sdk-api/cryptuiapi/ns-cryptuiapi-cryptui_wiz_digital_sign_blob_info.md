# CRYPTUI_WIZ_DIGITAL_SIGN_BLOB_INFO structure

## Description

[The **CRYPTUI_WIZ_DIGITAL_SIGN_BLOB_INFO** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPTUI_WIZ_DIGITAL_SIGN_BLOB_INFO** structure contains information about the [public key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) used by the [CryptUIWizDigitalSign](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizdigitalsign) function.

## Members

### `dwSize`

The size, in bytes, of the structure.

### `pGuidSubject`

A pointer to a **GUID** that contains the GUID that identifies the Session Initiation Protocol (SIP) functions to load.

### `cbBlob`

The size, in bytes, of the [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) pointed to by the **pbBlob** member.

### `pbBlob`

A pointer to the BLOB to sign.

### `pwszDisplayName`

A pointer to a null-terminated Unicode string that contains the display name of the BLOB to sign.

## See also

[CryptUIWizDigitalSign](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizdigitalsign)