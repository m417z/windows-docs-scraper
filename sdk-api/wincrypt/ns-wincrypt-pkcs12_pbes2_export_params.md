## Description

Passed to the [PFXExportCertStoreEx](https://learn.microsoft.com/windows/win32/api/wincrypt/nf-wincrypt-pfxexportcertstoreex) function as _pvPara_ when the **PKCS12_EXPORT_PBES2_PARAMS** flag is set for _dwFlags_ to provide information about the encryption algorithm to use.

## Members

### `dwSize`

The size of the structure, in bytes.

### `hNcryptDescriptor`

If the **PKCS12_PROTECT_TO_DOMAIN_SIDS** flag is set for _dwFlags_ when calling the [PFXExportCertStoreEx](https://learn.microsoft.com/windows/win32/api/wincrypt/nf-wincrypt-pfxexportcertstoreex) function, you can set this field to an **NCRYPT_DESCRIPTOR_HANDLE** value. See the _pvPara_ description in the [PFXExportCertStoreEx](https://learn.microsoft.com/windows/win32/api/wincrypt/nf-wincrypt-pfxexportcertstoreex) for more information.

### `pwszPbes2Alg`

The designation of the password-based encryption algorithm to use.

| Value | Meaning |
|-------|---------|
| **PKCS12_PBES2_ALG_AES256_SHA256**AES256-SHA256 | AES256 will be used for key/certificate encryption, and SHA256 will be used for KDF2, and MacData hashing. |

## Remarks

## See also