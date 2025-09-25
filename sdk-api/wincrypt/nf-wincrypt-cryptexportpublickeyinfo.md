# CryptExportPublicKeyInfo function

## Description

The **CryptExportPublicKeyInfo** function exports the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) information associated with the corresponding [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) of the provider. For an updated version of this function, see
[CryptExportPublicKeyInfoEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportpublickeyinfoex).

## Parameters

### `hCryptProvOrNCryptKey` [in]

Handle of the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) to use when exporting the public key information. This handle must be an [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) handle that has been created by using the
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function or an **NCRYPT_KEY_HANDLE** handle that has been created by using the [NCryptOpenKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenkey) function. New applications should always pass in the **NCRYPT_KEY_HANDLE** handle of a CNG CSP.

### `dwKeySpec` [in]

Identifies the private key to use from the container of the provider. It can be AT_KEYEXCHANGE or AT_SIGNATURE. This parameter is ignored if an **NCRYPT_KEY_HANDLE** is used in the *hCryptProvOrNCryptKey* parameter.

### `dwCertEncodingType` [in]

Specifies the [encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pInfo` [out]

A pointer to a
[CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure to receive the public key information to be exported.

To set the size of this information for memory allocation purposes, this parameter can be **NULL**. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbInfo` [in, out]

A pointer to a **DWORD** that contains the size, in bytes, of the buffer pointed to by the *pInfo* parameter. When the function returns, the **DWORD** contains the number of bytes needed for the return buffer.

**Note** When processing the data returned in the buffer, applications need to use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** Errors from the called functions
[CryptGetUserKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetuserkey) and
[CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey) might be propagated to this function.

This function has the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | If the buffer specified by the *pInfo* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code, and stores the required buffer size, in bytes, into the variable pointed to by *pcbInfo*. |
| **ERROR_FILE_NOT_FOUND** | Invalid certificate encoding type. Currently only X509_ASN_ENCODING is supported. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[CryptImportPublicKeyInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportpublickeyinfo)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)