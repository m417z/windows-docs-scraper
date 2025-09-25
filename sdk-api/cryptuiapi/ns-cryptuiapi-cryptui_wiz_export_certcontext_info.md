# CRYPTUI_WIZ_EXPORT_CERTCONTEXT_INFO structure

## Description

[The **CRYPTUI_WIZ_EXPORT_CERTCONTEXT_INFO** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPTUI_WIZ_EXPORT_CERTCONTEXT_INFO** structure contains information that controls the operation of the [CryptUIWizExport](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizexport) function when a certificate is the object being exported.

## Members

### `dwSize`

The size, in bytes, of this structure.

### `dwExportFormat`

A value that indicates the export format of the certificate. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPTUI_WIZ_EXPORT_FORMAT_DER** | Export in [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) format. |
| **CRYPTUI_WIZ_EXPORT_FORMAT_PFX** | Export in Private Information Exchange (PFX) format. |
| **CRYPTUI_WIZ_EXPORT_FORMAT_PKCS7** | Export in [Public Key Cryptography Standard](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) #7 ([PKCS #7](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly)) format. |
| **CRYPTUI_WIZ_EXPORT_FORMAT_BASE64** | Export in base 64 format. |
| **CRYPTUI_WIZ_EXPORT_FORMAT_CRL** | Export in [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) format. |
| **CRYPTUI_WIZ_EXPORT_FORMAT_CTL** | Export in [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) format. |

### `fExportChain`

Indicates whether the certificate chain should be exported in addition to the certificate. Contains nonzero to export the chain or zero to not export the chain.

### `fExportPrivateKeys`

Indicates whether the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) should be exported in addition to the certificate. Contains nonzero to export the private key or zero to not export the private key.

### `pwszPassword`

A pointer to a null-terminated Unicode string that contains the password used to access the private key. This is required if **fExportPrivateKeys** is nonzero and is otherwise ignored.

### `fStrongEncryption`

Indicates whether strong encryption should be used in the export process. Contains nonzero to use strong encryption or zero to use weak encryption. This must be nonzero if **dwExportFormat** is **CRYPTUI_WIZ_EXPORT_FORMAT_PFX**. If this is nonzero, the PFX [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) produced is not compatible with Internet Explorer 4.0 or earlier versions.

**Note** We recommend that you set this to nonzero; otherwise, a substantially weaker encryption algorithm is used in the export process.

## See also

[CRYPTUI_WIZ_EXPORT_INFO](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_export_info)

[CryptUIWizExport](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizexport)