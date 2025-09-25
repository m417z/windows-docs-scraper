# CRYPTUI_WIZ_DIGITAL_SIGN_STORE_INFO structure

## Description

[The **CRYPTUI_WIZ_DIGITAL_SIGN_STORE_INFO** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPTUI_WIZ_DIGITAL_SIGN_STORE_INFO** structure contains information about the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) used by the digital signature wizard.

## Members

### `dwSize`

The size, in bytes, of the structure. This value must be set to `sizeof(CRYPTUI_WIZ_DIGITAL_SIGN_STORE_INFO)`.

### `cCertStore`

Number of certificates in the **rghCertStore** member.

### `rghCertStore`

A pointer to a handle to the certificate store that will be used by the digital signature wizard.

### `pFilterCallback`

Filter callback function used to display the certificate.

### `pvCallbackData`

A pointer to the callback data.