# CryptExportPKCS8Ex function

## Description

[The **CryptExportPKCS8Ex** function is no longer available for use as of Windows Server 2008 and Windows Vista. Instead, use the [PFXExportCertStoreEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfxexportcertstoreex) function.]

The **CryptExportPKCS8Ex** function exports the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) in PKCS #8 format.This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Crypt32.dll.

## Parameters

### `psExportParams` [in]

A pointer to a [CRYPT_PKCS8_EXPORT_PARAMS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_pkcs8_export_params) structure that contains information about the key to export.

### `dwFlags` [in]

This parameter should be zero if *pbPrivateKeyBlob* is **NULL** and 0x8000 otherwise.

### `pvAuxInfo` [in, optional]

This parameter must be **NULL**.

### `pbPrivateKeyBlob` [out, optional]

A pointer to an
array of **BYTE** structures to receive the private key to be exported.

The private key will contain the information in a PKCS #8
PrivateKeyInfo [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) type found in the PKCS #8 standard.

For memory allocation purposes, you can get the size of the private key to be exported by setting this parameter to **NULL**. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbPrivateKeyBlob` [in, out]

A pointer to a **DWORD** that may contain, on input, the size, in bytes, of the memory allocation needed to contain the *pbPrivateKeyBlob*. If *pbPrivateKeyBlob* is **NULL**, this parameter will return the size of the memory allocation needed for a second call to the function. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes are specific to this function.

| Return code | Description |
| --- | --- |
| **ERROR_UNSUPPORTED_TYPE** | An export function that can be installed or registered could not be found. |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbPrivateKeyBlob* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, in the variable pointed to by the *pcbPrivateKeyBlob* parameter. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns an ASN.1 encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

This function is only supported for asymmetric keys.

## See also

[CRYPT_PKCS8_EXPORT_PARAMS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_pkcs8_export_params)

[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta)

[CryptExportPKCS8](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportpkcs8)

[CryptImportPKCS8](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportpkcs8)