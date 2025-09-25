# CryptExportPublicKeyInfoEx function

## Description

The **CryptExportPublicKeyInfoEx** function exports the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) information associated with the provider's corresponding [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). This function allows the application to specify the [public key algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly), overriding the default provided by the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP).

## Parameters

### `hCryptProvOrNCryptKey` [in]

A handle of the CSP to use when exporting the public key information. This handle must be an [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) handle that has been created by using the
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function or an **NCRYPT_KEY_HANDLE** handle that has been created by using the [NCryptOpenKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenkey) function. New applications should always pass in the **NCRYPT_KEY_HANDLE** handle of a CNG CSP.

### `dwKeySpec` [in]

Identifies the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to use from the provider's container. It can be AT_KEYEXCHANGE or AT_SIGNATURE. This parameter is ignored if an **NCRYPT_KEY_HANDLE** is used in the *hCryptProvOrNCryptKey* parameter.

### `dwCertEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pszPublicKeyObjId` [in]

Specifies the public key algorithm.

**Note** *pszPublicKeyObjId* and *dwCertEncodingType* are used together to determine the installable **CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FUNC** to call. If an installable function was not found for the *pszPublicKeyObjId* parameter, an attempt is made to export the key as an RSA Public Key (szOID_RSA_RSA).

### `dwFlags` [in]

A **DWORD** flag value that indicates how the public key information is exported. The flag value is passed directly to the [CryptFindOIDInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptfindoidinfo) function when mapping the public key [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) to the corresponding CNG public key algorithm Unicode string. The following flag values can be set.

| Value | Meaning |
| --- | --- |
| CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG | Skips public keys in the **CRYPT_PUBKEY_ALG_OID_GROUP_ID** group explicitly flagged with the **CRYPT_OID_PUBKEY_ENCRYPT_ONLY_FLAG** flag. |
| CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG | Skips public keys in the **CRYPT_PUBKEY_ALG_OID_GROUP_ID** group explicitly flagged with the **CRYPT_OID_PUBKEY_SIGN_ONLY_FLAG** flag. |

### `pvAuxInfo` [in]

This parameter is reserved for future use and must be set to **NULL**.

### `pInfo` [out]

A pointer to a
[CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure to receive the public key information to be exported.

This parameter can be **NULL** to set the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbInfo` [in, out]

A pointer to a **DWORD** that contains the size, in bytes, of the buffer pointed to by the *pInfo* parameter. When the function returns, the **DWORD** contains the number of bytes stored in the buffer.

**Note** When processing the data returned in the buffer, applications need to use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** Errors from the called functions
[CryptGetUserKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetuserkey) and
[CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey) can be propagated to this function.

This function has the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | An export function that can be installed or registered could not be found for the specified *dwCertEncodingType* and *pszPublicKeyObjId* parameters. |
| **ERROR_MORE_DATA** | If the buffer specified by the *pInfo* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code and stores the required buffer size, in bytes, in the variable pointed to by the *pcbInfo* parameter. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## See also

[CryptImportPublicKeyInfoEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportpublickeyinfoex)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)