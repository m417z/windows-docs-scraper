# PFN_CRYPT_VERIFY_ENCODED_SIGNATURE_FUNC callback function

## Description

The **PFN_CRYPT_VERIFY_ENCODED_SIGNATURE_FUNC** callback function is called to decrypt an encoded signature and compare it to a computed hash.

## Parameters

### `dwCertEncodingType` [in]

Specifies the type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pPubKeyInfo` [in]

The address of a [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure that contains the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to use to verify the signature. You can use this with [CryptImportPublicKeyInfoEx2](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportpublickeyinfoex2) to get a **BCRYPT_KEY_HANDLE**.

### `pSignatureAlgorithm` [in]

A pointer to a [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains the signature [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and its optional encoded parameters.

### `pvDecodedSignPara` [in, optional]

An optional pointer to the decoded signature parameters data structure previously returned by the [PFN_CRYPT_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_extract_encoded_signature_parameters_func) function.

### `pwszCNGPubKeyAlgid` [in]

A Unicode string that contains the Cryptography API: Next Generation (CNG) [public key algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) identifier that corresponds to *pSignatureAlgorithm*->**pszObjId**.

### `pwszCNGHashAlgid` [in]

A Unicode string that contains the CNG [hashing algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) identifier that corresponds to *pSignatureAlgorithm*->**pszObjId** or to a hash algorithm identifier in *pvDecodedSignPara*.

### `pbComputedHash` [in]

A pointer to the computed hash bytes returned by the [BCryptFinishHash](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfinishhash) function that corresponds to *pwszCNGHashAlgid*.

### `cbComputedHash` [in]

A value that represents the length, in bytes, of the computed hash.

### `pbSignature` [in]

A pointer to the encoded signature bytes.

### `cbSignature` [in]

A value that represents the length, in bytes, of the encoded signature.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If this callback function does not support the signature algorithm, it must return **FALSE** and call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) with **ERROR_NOT_SUPPORTED**.

## Remarks

You can use [OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) to deploy this callback function. Wincrypt.h defines the following constant for this purpose.

| Constant | Definition |
| --- | --- |
| CRYPT_OID_VERIFY_ENCODED_SIGNATURE_FUNC | "CryptDllVerifyEncodedSignature" |