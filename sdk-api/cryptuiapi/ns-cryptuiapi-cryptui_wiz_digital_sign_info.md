# CRYPTUI_WIZ_DIGITAL_SIGN_INFO structure

## Description

[The **CRYPTUI_WIZ_DIGITAL_SIGN_INFO** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPTUI_WIZ_DIGITAL_SIGN_INFO** structure contains information about digital signing. This structure is used by the [CryptUIWizDigitalSign](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizdigitalsign) function.

## Members

### `dwSize`

The size, in bytes, of the structure.

### `dwSubjectChoice`

A value that indicates the entity that is to be signed. This member is required if **CRYPTUI_WIZ_NO_UI** is specified in the *dwFlags* parameter of the [CryptUIWizDigitalSign](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizdigitalsign) function. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPTUI_WIZ_DIGITAL_SIGN_SUBJECT_BLOB** | The memory [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) specified by the **pSignBlobInfo** member is to be signed. |
| **CRYPTUI_WIZ_DIGITAL_SIGN_SUBJECT_FILE** | The file specified by the **pwszFileName** member is to be signed. |
| **0** | The user will be prompted for a file to sign. |

### `pwszFileName`

A pointer to a null-terminated Unicode string that contains the path and file name of the file to sign. This member is used if **CRYPTUI_WIZ_DIGITAL_SIGN_SUBJECT_FILE** is specified for the **dwSubjectChoice** member.

### `pSignBlobInfo`

A pointer to a [CRYPTUI_WIZ_DIGITAL_SIGN_BLOB_INFO](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_blob_info) structure that contains the BLOB to sign. This member is used if **CRYPTUI_WIZ_DIGITAL_SIGN_SUBJECT_BLOB** is specified for the **dwSubjectChoice** member.

### `dwSigningCertChoice`

A value that specifies the location of the certificate that is used to sign the entity. The default value is zero. This can be one of the following values.

**Note** If **CRYPTUI_WIZ_NO_UI** is specified in the *dwFlags* parameter of the [CryptUIWizDigitalSign](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizdigitalsign) function, this value must be either **CRYPTUI_WIZ_DIGITAL_SIGN_CERT** or **CRYPTUI_WIZ_DIGITAL_SIGN_PVK**.

| Value | Meaning |
| --- | --- |
| **CRYPTUI_WIZ_DIGITAL_SIGN_CERT** | The certificate is contained in the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure pointed to by the **pSigningCertContext** member. |
| **CRYPTUI_WIZ_DIGITAL_SIGN_STORE** | The certificate is contained in the certificate store contained in the [CRYPTUI_WIZ_DIGITAL_SIGN_STORE_INFO](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_store_info) structure pointed to by the **pSigningCertStore** member. |
| **CRYPTUI_WIZ_DIGITAL_SIGN_PVK** | The certificate is contained in the PVK file contained in the [CRYPTUI_WIZ_DIGITAL_SIGN_CERT_PVK_INFO](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_cert_pvk_info) structure pointed to by the **pSigningCertPvkInfo** member. |
| **0** | The certificates in the My store are used. |

### `pSigningCertContext`

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to use to sign the entity. This member is used if **CRYPTUI_WIZ_DIGITAL_SIGN_CERT** is specified for the **dwSigningCertChoice** member.

### `pSigningCertStore`

A pointer to a [CRYPTUI_WIZ_DIGITAL_SIGN_STORE_INFO](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_store_info) structure that contains the certificate to use to sign the entity. This member is used if **CRYPTUI_WIZ_DIGITAL_SIGN_STORE** is specified for the **dwSigningCertChoice** member.

### `pSigningCertPvkInfo`

A pointer to a [CRYPTUI_WIZ_DIGITAL_SIGN_CERT_PVK_INFO](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_cert_pvk_info) structure that contains the certificate to use to sign the entity. This member is used if **CRYPTUI_WIZ_DIGITAL_SIGN_PVK** is specified for the **dwSigningCertChoice** member.

### `pwszTimestampURL`

A pointer to a null-terminated Unicode string that contains the URL for the time stamp.

### `dwAdditionalCertChoice`

A value that indicates whether additional certificates will be included in the signature. The default value is zero. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPTUI_WIZ_DIGITAL_SIGN_ADD_CHAIN** | The entire certificate chain will be included in the signature. |
| **CRYPTUI_WIZ_DIGITAL_SIGN_ADD_CHAIN_NO_ROOT** | All certificates in the certificate chain except the root will be included in the signature. |
| **0** | No additional certificates will be included in the signature. |

### `pSignExtInfo`

A pointer to a [CRYPTUI_WIZ_DIGITAL_SIGN_EXTENDED_INFO](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_extended_info) structure that contains extended information about the signature.

## See also

[CryptUIWizDigitalSign](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizdigitalsign)