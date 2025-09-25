# CryptImportPKCS8 function

## Description

[The **CryptImportPKCS8** function is no longer available for use as of Windows Server 2008 and Windows Vista. Instead, use the [PFXImportCertStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfximportcertstore) function.]

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptImportPKCS8** function imports the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) in PKCS #8 format to a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP).**CryptImportPKCS8** will return a handle to the provider and the import KeySpec used.

## Parameters

### `sPrivateKeyAndParams` [in]

A [CRYPT_PKCS8_IMPORT_PARAMS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_pkcs8_import_params) structure that contains the [private key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) and corresponding parameters.

### `dwFlags` [in]

A **DWORD** value. This parameter can be one of the following values, a combination of them, or a null value.

| Value | Meaning |
| --- | --- |
| **CRYPT_EXPORTABLE** | The key being imported is eventually to be reexported. If this flag is not used, then calls to [CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey) with the key handle fail. |
| **CRYPT_USER_PROTECTED** | If this flag is set, the CSP notifies the user through a dialog box or some other method when certain actions are attempted using this key. The precise behavior is specified by the CSP or the CSP type used. If the provider context was acquired with CRYPT_SILENT set, using this flag causes a failure, and the last error is set to NTE_SILENT_CONTEXT. |

### `phCryptProv` [out, optional]

A pointer to the [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) to receive the handle of the provider into which the key is
imported by calling the **CryptImportPKCS8** function.

When you have finished using the handle, free the handle by calling [CryptReleaseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptreleasecontext).

This parameter can be **NULL**, in which case the handle of the provider is not returned.

### `pvAuxInfo` [in, optional]

This parameter must be **NULL**.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error code is specific to this function.

| Return code | Description |
| --- | --- |
| **ERROR_UNSUPPORTED_TYPE** | The algorithm [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of the private key is not supported. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

**CryptImportPKCS8** calls the [PCRYPT_RESOLVE_HCRYPTPROV_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pcrypt_resolve_hcryptprov_func) function by using the [CRYPT_PKCS8_IMPORT_PARAMS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_pkcs8_import_params) structure contained in the *sPrivateKeyAndParams* parameter to retrieve a handle of the provider to which to import the key. If **PCRYPT_RESOLVE_HCRYPTPROV_FUNC** is **NULL**, then the default provider is used.

This function is only supported for asymmetric keys.

## See also

[CRYPT_PKCS8_IMPORT_PARAMS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_pkcs8_import_params)

[CryptExportPKCS8Ex](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportpkcs8ex)

[CryptReleaseContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptreleasecontext)

[PCRYPT_DECRYPT_PRIVATE_KEY_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pcrypt_decrypt_private_key_func)

[PCRYPT_RESOLVE_HCRYPTPROV_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pcrypt_resolve_hcryptprov_func)