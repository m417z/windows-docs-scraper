# PFN_CRYPT_SIGN_AND_ENCODE_HASH_FUNC callback function

## Description

The **PFN_CRYPT_SIGN_AND_ENCODE_HASH_FUNC** callback function is called to sign and encode a computed hash.

## Parameters

### `hKey` [in]

A handle to the Cryptography API: Next Generation (CNG) [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to use to sign the hash.

### `dwCertEncodingType` [in]

Specifies the type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pSignatureAlgorithm` [in]

A pointer to a [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains the signature [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and its optional encoded parameters.

### `pvDecodedSignPara` [in]

An optional pointer to the decoded signature parameters data structure previously returned by the [PFN_CRYPT_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_extract_encoded_signature_parameters_func) function.

### `pwszCNGPubKeyAlgid` [in]

A Unicode string that contains the CNG [public key algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) identifier that corresponds to *pSignatureAlgorithm*->**pszObjId**.

### `pwszCNGHashAlgid` [in]

A Unicode string that contains the CNG hash algorithm identifier that corresponds to *pSignatureAlgorithm*->**pszObjId** or to a hash algorithm identifier in *pvDecodedSignPara*.

### `pbComputedHash` [in]

A pointer to the computed hash bytes returned by the [BCryptFinishHash](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfinishhash) function that corresponds to *pwszCNGHashAlgid*.

### `cbComputedHash` [in]

A value that represents the length, in bytes, of the computed hash.

### `pbSignature` [out]

A pointer to the encoded signature bytes.

### `pcbSignature` [in, out]

A value that represents the length, in bytes, of the encoded signature.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If this callback function does not support the signature algorithm, it must return **FALSE** and call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) with **ERROR_NOT_SUPPORTED**.

## Remarks

You can use [OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) to deploy this callback function. Wincrypt.h defines the following constant for this purpose.

| Constant | Definition |
| --- | --- |
| CRYPT_OID_SIGN_AND_ENCODE_HASH_FUNC | "CryptDllSignAndEncodeHash" |