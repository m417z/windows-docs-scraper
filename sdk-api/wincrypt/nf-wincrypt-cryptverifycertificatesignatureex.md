# CryptVerifyCertificateSignatureEx function

## Description

The **CryptVerifyCertificateSignatureEx** function verifies the signature of a subject certificate, [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), or keygen request by using the issuer's [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). The function does not require access to a [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

## Parameters

### `hCryptProv` [in]

This parameter is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:** A handle to the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) used to verify the signature.This parameter's data type is **HCRYPTPROV**.

**NULL** is passed unless there is a strong reason for passing in a specific cryptographic provider. Passing in **NULL** causes the default RSA or DSS provider to be acquired.

### `dwCertEncodingType` [in]

The [certificate encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that was used to encrypt the subject.
The [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) identifier, contained in the high **WORD** of this value, is ignored by this function.

This parameter can be the following currently defined certificate encoding type.

| Value | Meaning |
| --- | --- |
| **X509_ASN_ENCODING**<br><br>1 (0x1) | Specifies X.509 certificate encoding. |

### `dwSubjectType` [in]

The subject type. This parameter can be one of the following subject types.

| Value | Meaning |
| --- | --- |
| **CRYPT_VERIFY_CERT_SIGN_SUBJECT_BLOB**<br><br>1 (0x1) | *pvSubject* is a pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure. |
| **CRYPT_VERIFY_CERT_SIGN_SUBJECT_CERT**<br><br>2 (0x2) | *pvSubject* is a pointer to a [CCERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure. |
| **CRYPT_VERIFY_CERT_SIGN_SUBJECT_CRL**<br><br>3 (0x3) | *pvSubject* is a pointer to a [CCRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structure. |
| **CRYPT_VERIFY_CERT_SIGN_SUBJECT_OCSP_BASIC_SIGNED_RESPONSE**<br><br>4 (0x4) | *pvSubject* is a pointer to an [OCSP_BASIC_SIGNED_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_signed_response_info) structure.<br><br>**Windows Server 2003 and Windows XP:** This subject type is not supported. |

### `pvSubject` [in]

A pointer to a structure of the type indicated by *dwSubjectType* that contains the signature to be verified.

### `dwIssuerType` [in]

The issuer type. This parameter can be one of the following issuer types.

| Value | Meaning |
| --- | --- |
| **CRYPT_VERIFY_CERT_SIGN_ISSUER_PUBKEY**<br><br>1 (0x1) | *pvIssuer* is a pointer to a [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure. |
| **CRYPT_VERIFY_CERT_SIGN_ISSUER_CERT**<br><br>2 (0x2) | *pvIssuer* is a pointer to a [CCERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure. |
| **CRYPT_VERIFY_CERT_SIGN_ISSUER_CHAIN**<br><br>3 (0x3) | *pvIssuer* is a pointer to a [CCERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context) structure. |
| **CRYPT_VERIFY_CERT_SIGN_ISSUER_NULL**<br><br>4 (0x4) | *pvIssuer* must be **NULL**. |

**Note** If *dwIssuerType* is **CRYPT_VERIFY_CERT_SIGN_ISSUER_NULL** and the signature algorithm is a hashing algorithm, the signature is expected to contain only unencrypted hash octets. Only **CRYPT_VERIFY_CERT_SIGN_ISSUER_NULL** can be specified in this nonencrypted signature case. If any other *dwIssuerType* is specified, verification fails and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns E_INVALIDARG.

### `pvIssuer` [in]

A pointer to a structure of the type indicated by the value of *dwIssuerType*. The structure contains access to the public key needed to verify the signature.

### `dwFlags` [in]

Flags that modify the function behavior. This can be zero or a bitwise **OR** of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_VERIFY_CERT_SIGN_DISABLE_MD2_MD4_FLAG**<br><br>0x00000001 | If you set this flag and **CryptVerifyCertificateSignatureEx** detects an MD2 or MD4 algorithm, the function returns **FALSE** and sets [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to **NTE_BAD_ALGID**. The signature is still verified, but this combination of errors enables the caller, now knowing that an MD2 or MD4 algorithm was used, to decide whether to trust or reject the signature.<br><br>**Windows 8 and Windows Server 2012:** Support for this flag begins. |
| **CRYPT_VERIFY_CERT_SIGN_SET_STRONG_PROPERTIES_FLAG**<br><br>0x00000002 | Sets strong signature properties, after successful verification, on the subject pointed to by the *pvSubject* parameter.<br><br>The following property is set on the certificate context:<br><br>* **CERT_SIGN_HASH_CNG_ALG_PROP_ID**<br><br>The following properties are set on the CRL context:<br><br>* **CERT_SIGN_HASH_CNG_ALG_PROP_ID**<br>* **CERT_ISSUER_PUB_KEY_BIT_LENGTH_PROP_ID**<br><br>**Note** This flag is only applicable if **CRYPT_VERIFY_CERT_SIGN_SUBJECT_CRL** is specified in the *dwSubjectType* parameter.<br><br>**Windows 8 and Windows Server 2012:** Support for this flag begins. |
| **CRYPT_VERIFY_CERT_SIGN_RETURN_STRONG_PROPERTIES_FLAG**<br><br>0x00000004 | Returns a pointer to a [CRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_verify_cert_sign_strong_properties_info) structure in the *pvExtra* parameter. The structure contains the length, in bits, of the public key and the names of the signing and hashing algorithms used.<br><br>You must call [CryptMemFree](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_verify_cert_sign_strong_properties_info) to free the structure. If memory cannot be allocated for the [CRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_verify_cert_sign_strong_properties_info) structure, this function returns successfully but sets the *pvExtra* parameter to **NULL**.<br><br>**Note** This flag is only applicable if **CRYPT_VERIFY_CERT_SIGN_SUBJECT_OCSP_BASIC_SIGNED_RESPONSE** is specified in the *dwSubjectType* parameter.<br><br>**Windows 8 and Windows Server 2012:** Support for this flag begins. |

### `pvExtra` [in, out, optional]

Pointer to a [CRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_verify_cert_sign_strong_properties_info) structure if the *dwFlags* parameter is set to **CRYPT_VERIFY_CERT_SIGN_RETURN_STRONG_PROPERTIES_FLAG**.

You must call [CryptMemFree](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmemfree) to free the structure.

## Return value

Returns nonzero if successful or zero otherwise.

For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** Errors from the called functions
[CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash),
[CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey),
[CryptVerifySignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifysignaturea), and
[CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata) may be propagated to this function.

On failure, this function will cause the following error codes to be returned from [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | Invalid certificate encoding type. Currently only **X509_ASN_ENCODING** is supported. |
| **NTE_BAD_ALGID** | The signature algorithm's [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) does not map to a known or supported [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) algorithm. |
| **NTE_BAD_SIGNATURE** | The signature was not valid. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

The subject buffer can contain an encoded [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) or a context for a certificate or CRL. In the case of a [certificate context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), if the certificate's public key parameters are missing and if these parameters can be inherited from the certificate's issuer for example from the DSS public key parameter, the context's CERT_PUBKEY_ALG_PARA_PROP_ID property is updated with the issuer's public key algorithm parameters for a valid signature.

## See also

[CryptVerifyCertificateSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifycertificatesignature)