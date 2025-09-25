# CryptImportPublicKeyInfo function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptImportPublicKeyInfo** function converts and imports the public key information into the provider and returns a handle of the public key.
[CryptImportPublicKeyInfoEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportpublickeyinfoex) provides a revised version of this function.

## Parameters

### `hCryptProv` [in]

The handle of the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) to use when importing the public key. This handle must have already been created using
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta).

### `dwCertEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pInfo` [in]

The address of a
[CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure that contains the public key to import into the provider.

### `phKey` [out]

The address of an **HCRYPTKEY** variable that receives the handle of the imported public key. When you have finished using the public key, release the handle by calling the [CryptDestroyKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdestroykey) function.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** Errors from the called functions
[CryptGetUserKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetuserkey) and
[CryptExportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportkey) might be propagated to this function. This function has the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | An import function that can be installed or registered could not be found for the specified *dwCertEncodingType* and *pInfo->Algorithm.pszObjId* parameters. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

This function is normally used to retrieve the public key from a certificate. This is done by passing the [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure from a filled-in certificate structure as shown in the following pseudocode.

``` syntax
PCCERT_CONTEXT pCertContext

// Get the certificate context structure from a certificate.
pCertContext = CertCreateCertificateContext(...)
if(pCertContext)
{
    HCRYPTKEY hCertPubKey

    // Get the public key information for the certificate.
    CryptImportPublicKeyInfo(
        hCryptProv,
        X509_ASN_ENCODING,
        &pCertContext->pCertInfo->SubjectPublicKeyInfo,
        &hCertPubKey)

    CertFreeCertificateContext(pCertContext)
}
```

## See also

[CryptExportPublicKeyInfo](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptexportpublickeyinfo)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)