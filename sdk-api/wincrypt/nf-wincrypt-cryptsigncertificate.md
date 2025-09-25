# CryptSignCertificate function

## Description

The **CryptSignCertificate** function signs the "to be signed" information in the encoded signed content.

## Parameters

### `hBCryptKey` [in]

Handle of the [CSP](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that does the signature. This handle must be an [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) handle that has been created by using the
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function or an **NCRYPT_KEY_HANDLE** handle that has been created by using the [NCryptOpenKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenkey) function. New applications should always pass in the **NCRYPT_KEY_HANDLE** handle of a CNG CSP.

### `dwKeySpec` [in]

Identifies the private key to use from the provider's container. It can be AT_KEYEXCHANGE or AT_SIGNATURE. This parameter is ignored if an **NCRYPT_KEY_HANDLE** is used in the *hCryptProvOrNCryptKey* parameter.

### `dwCertEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pbEncodedToBeSigned` [in]

A pointer to the encoded content to be signed.

### `cbEncodedToBeSigned` [in]

The size, in bytes, of the encoded content, *pbEncodedToBeSigned*.

### `pSignatureAlgorithm` [in]

A pointer to a
[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure with a **pszObjId** member set to one of the following:

* szOID_RSA_MD5RSA
* szOID_RSA_SHA1RSA
* szOID_X957_SHA1DSA
* szOID_RSA_SSA_PSS
* szOID_ECDSA_SPECIFIED

If the signature algorithm is a hash algorithm, the signature contains only the un-encrypted hash octets. A private key is not used to encrypt the hash. *dwKeySpec* is not used and *hCryptProvOrNCryptKey* can be **NULL** if an appropriate default CSP can be used for hashing.

### `pvHashAuxInfo` [in]

Not currently used. Must be **NULL**.

### `pbSignature` [out]

A pointer to a buffer to receive the signed [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the content.

This parameter can be **NULL** to set the size of this information for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbSignature` [in, out]

A pointer to a **DWORD** that contains the size, in bytes, of the buffer pointed to by the *pbSignature* parameter. When the function returns, the **DWORD** contains the number of bytes stored or to be stored in the buffer.

**Note** When processing the data returned in the buffer, applications must use the actual size of the data returned. The actual size can be slightly smaller than the size of the buffer specified on input. (On input, buffer sizes are usually specified large enough to ensure that the largest possible output data will fit in the buffer.) On output, the variable pointed to by this parameter is updated to reflect the actual size of the data copied to the buffer.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** Errors from the called functions
[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash),
[CryptSignHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignhasha) and
[CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata) might be propagated to this function.

This function has the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_MORE_DATA** | If the buffer specified by the *pbSignature* parameter is not large enough to hold the returned data, the function sets the ERROR_MORE_DATA code, and stores the required buffer size, in bytes, into the variable pointed to by *pcbSignature*. |
| **NTE_BAD_ALGID** | The signature algorithm's [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) does not map to a known or supported hash algorithm. |

## See also

[CryptSignAndEncodeCertificate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignandencodecertificate)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)