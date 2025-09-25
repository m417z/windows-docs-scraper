# PFXExportCertStore function

## Description

The **PFXExportCertStore** function exports the certificates and, if available, the associated private keys from the referenced certificate store. This is an old function kept for compatibility with Internet Explorer 4.0 clients. New applications should use the
[PfxExportCertStoreEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfxexportcertstoreex) function that provides enhanced private key security.

## Parameters

### `hStore` [in]

Handle of the certificate store containing the certificates to be exported.

### `pPFX` [in, out]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure to contain the PFX packet with the exported certificates and keys. If *pPFX*->*pbData* is **NULL**, the function calculates the number of bytes needed for the encoded BLOB and returns this in *pPFX*->*cbData*. When the function is called with *pPFX*->*pbData* pointing to an allocated buffer of the needed size, the function copies the encoded bytes into the buffer and updates *pPFX*->*cbData* with the encode byte length.

### `szPassword` [in]

String password used to encrypt and verify the PFX packet. When you have finished using the password, clear the password from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `dwFlags` [in]

Flag values can be set to any combination of the following.

| Value | Meaning |
| --- | --- |
| **EXPORT_PRIVATE_KEYS** | Private keys are exported as well as the certificates. |
| **REPORT_NO_PRIVATE_KEY** | If a certificate is encountered that has no associated private key, the function returns **FALSE** with the last error set to either CRYPT_E_NOT_FOUND or NTE_NO_KEY. |
| **REPORT_NOT_ABLE_TO_EXPORT_PRIVATE_KEY** | If a certificate is encountered that has a non-exportable private key, the function returns **FALSE** and the last error set to NTE_BAD_KEY, NTE_BAD_KEY_STATE, or NTE_PERM. |

## Return value

Returns **TRUE** (nonzero) if the function succeeds, and **FALSE** (zero) if the function fails. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[PFXExportCertStoreEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfxexportcertstoreex)

[PFXImportCertStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfximportcertstore)