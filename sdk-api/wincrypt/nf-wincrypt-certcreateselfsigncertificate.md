# CertCreateSelfSignCertificate function

## Description

The **CertCreateSelfSignCertificate** function builds a self-signed certificate and returns a pointer to a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that represents the certificate.

## Parameters

### `hCryptProvOrNCryptKey` [in, optional]

A handle of a [cryptographic provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) used to sign the certificate created. If **NULL**, information from the *pKeyProvInfo* parameter is used to acquire the needed handle. If *pKeyProvInfo* is also **NULL**, the default provider type, PROV_RSA_FULL provider type, the default key specification, AT_SIGNATURE, and a newly created [key container](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) with a unique container name are used.

This handle must be an [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) handle that has been created by using the
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function or an **NCRYPT_KEY_HANDLE** handle that has been created by using the [NCryptOpenKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenkey) function. New applications should always pass in the **NCRYPT_KEY_HANDLE** handle of a CNG [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP).

### `pSubjectIssuerBlob` [in]

A pointer to a [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) that contains the distinguished name (DN) for the certificate subject. This parameter cannot be **NULL**. Minimally, a pointer to an empty DN must be provided. This BLOB is normally created by using the
[CertStrToName](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certstrtonamea) function. It can also be created by using the
[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) function and specifying either the X509_NAME or X509_UNICODE_NAME *StructType*.

### `dwFlags` [in]

A set of flags that override the default behavior of this function. This can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_CREATE_SELFSIGN_NO_KEY_INFO**<br><br>2 | By default, the returned PCCERT_CONTEXT references the [private keys](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) by setting the CERT_KEY_PROV_INFO_PROP_ID. If you do not want the returned PCCERT_CONTEXT to reference private keys by setting the CERT_KEY_PROV_INFO_PROP_ID, specify CERT_CREATE_SELFSIGN_NO_KEY_INFO. |
| **CERT_CREATE_SELFSIGN_NO_SIGN**<br><br>1 | By default, the certificate being created is signed. If the certificate being created is only a dummy placeholder, the certificate might not need to be signed. Signing of the certificate is skipped if CERT_CREATE_SELFSIGN_NO_SIGN is specified. |

### `pKeyProvInfo` [in, optional]

A pointer to a [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure. Before a certificate is created, the CSP is queried for the key provider, key provider type, and the [key container](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) name. If the CSP queried does not support these queries, the function fails. If the default provider does not support these queries, a *pKeyProvInfo* value must be specified. The RSA BASE does support these queries.

If the *pKeyProvInfo* parameter is not **NULL**, the corresponding values are set in the **CERT_KEY_PROV_INFO_PROP_ID** value of the generated certificate. You must ensure that all parameters of the supplied structure are correctly specified.

### `pSignatureAlgorithm` [in, optional]

A pointer to a [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure. If **NULL**, the default algorithm, SHA1RSA, is used.

### `pStartTime` [in, optional]

A pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure. If **NULL**, the system current time is used by default.

### `pEndTime` [in, optional]

A pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure. If **NULL**, the *pStartTime* value plus one year will be used by default.

### `pExtensions` [optional]

A pointer to a [CERT_EXTENSIONS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extensions) array of [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structures. By default, the array is empty. An alternate subject name, if desired, can be specified as one of these extensions.

## Return value

If the function succeeds, a [PCCERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) variable that points to the created certificate is returned. If the function fails, it returns **NULL**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

As the pEndTime must be a valid date, and is automatically generated if it is not supplied by the user, unexpected failures may easily be caused when this API is called on a leap day without accompanying app logic to compensate. For more information, please see [leap year readiness](https://techcommunity.microsoft.com/t5/azure-developer-community-blog/it-s-2020-is-your-code-ready-for-leap-day/ba-p/1157279).

## See also

[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension)

[CERT_EXTENSIONS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extensions)

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CertStrToName](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certstrtonamea)

[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[PCCERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)