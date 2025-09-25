# CryptExportPKCS8 function

## Description

[The **CryptExportPKCS8** function is no longer available for use as of Windows Server 2008 and Windows Vista. Instead, use the [PFXExportCertStoreEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfxexportcertstoreex) function.]

The **CryptExportPKCS8** function exports the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) in PKCS #8 format. The function is superseded by [CryptExportPKCS8Ex](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportpkcs8ex), which also may be altered or unavailable in subsequent versions.

## Parameters

### `hCryptProv` [in]

An [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) variable that contains the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). This is a handle to the CSP obtained by calling [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta).

### `dwKeySpec` [in]

A **DWORD** variable that contains the key specification. The following *dwKeySpec* values are defined for the default provider.

| Value | Meaning |
| --- | --- |
| **AT_KEYEXCHANGE** | Keys used to encrypt/decrypt session keys. |
| **AT_SIGNATURE** | Keys used to create and verify digital signatures. |

### `pszPrivateKeyObjId` [in]

An **LPSTR** variable that contains the private key  [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID).

### `dwFlags` [in]

This parameter should be zero if *pbPrivateKeyBlob* is **NULL** and 0x8000 otherwise.

### `pvAuxInfo` [in, optional]

This parameter must be set to **NULL**.

### `pbPrivateKeyBlob` [out, optional]

A pointer to an
array of **BYTE** structures to receive the private key to be exported.

The private key will contain the information in a PKCS #8 PrivateKeyInfo [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) type found in the PKCS #8 standard.

For memory allocation purposes, you can get the size of the private key to be exported by setting this parameter to **NULL**. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbPrivateKeyBlob` [in, out]

A pointer to a **DWORD** that may contain, on input, the size, in bytes, of the memory allocation needed to contain the *pbPrivateKeyBlob*. If *pbPrivateKeyBlob* is **NULL**, this parameter will return the size of the memory allocation needed for a second call to the function. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes are specific to this function.

| Return code | Description |
| --- | --- |
| **ERROR_UNSUPPORTED_TYPE** | An export function that can be installed or registered could not be found. |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbPrivateKeyBlob* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, in the variable pointed to by the *pcbPrivateKeyBlob* parameter. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an ASN.1 encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

This function is only supported for asymmetric keys.

## See also

[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta)

[CryptExportPKCS8Ex](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportpkcs8ex)

[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length)