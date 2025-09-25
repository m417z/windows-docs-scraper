# CryptMsgVerifyCountersignatureEncoded function

## Description

The **CryptMsgVerifyCountersignatureEncoded** function verifies a [countersignature](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) in terms of the SignerInfo structure (as defined by PKCS #7).

## Parameters

### `hCryptProv` [in]

This parameter is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:** **NULL** or the handle of the [cryptographic provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to use to [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) the encryptedDigest field of *pbSignerInfo*.This parameter's data type is **HCRYPTPROV**.

Unless there is a strong reason for passing in a specific cryptographic provider in *hCryptProv*, pass **NULL** to cause the default RSA or DSS provider to be used.

### `dwEncodingType` [in]

Specifies the encoding type used. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are being used; however, additional encoding types may be added in the future. For either current encoding type, use:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING.

### `pbSignerInfo` [in]

A pointer to the encoded [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) that contains the signer of the contents of a message to be countersigned.

### `cbSignerInfo` [in]

Count, in bytes, of the encoded BLOB for the signer of the contents.

### `pbSignerInfoCountersignature` [in]

A pointer to the encoded BLOB containing the countersigner information.

### `cbSignerInfoCountersignature` [in]

Count, in bytes, of the encoded BLOB for the countersigner of the message.

### `pciCountersigner` [in]

A pointer to a
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) that includes with the issuer and serial number of the countersigner. For more information, see Remarks.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table lists the error codes most commonly returned by the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Return code | Description |
| --- | --- |
| **CRYPT_E_AUTH_ATTR_MISSING** | The message does not contain an expected authenticated attribute. |
| **CRYPT_E_HASH_VALUE** | The hash value is not correct. |
| **CRYPT_E_UNEXPECTED_ENCODING** | The message is not encoded as expected. |
| **CRYPT_E_UNKNOWN_ALGO** | The cryptographic algorithm is unknown. |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **E_OUTOFMEMORY** | Ran out of memory. |

Propagated errors from the following functions might be returned.

* [CryptHashData](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-crypthashdata)
* [CryptGetHashParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgethashparam)
* [CryptImportKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptimportkey)
* [CryptVerifySignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifysignaturea)
* [CryptCreateHash](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptcreatehash)

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

Countersigner verification is done using the PKCS #7 **SIGNERINFO** structure. The signature must contain the encrypted hash of the encryptedDigest field of *pbSignerInfo*.

The issuer and serial number of the countersigner must match the countersigner information from *pbSignerInfoCountersignature*. The only fields referenced from *pciCountersigner* are SerialNumber, Issuer, and SubjectPublicKeyInfo. The SubjectPublicKeyInfo is used to access the public key that is then used to encrypt the [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) from the *pciCountersigner* so compare it with the hash from the *pbSignerInfo*.

#### Examples

For an example that uses this function, see
[Example C Program: Encoding and Decoding a CounterSigned Message](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-encoding-and-decoding-a-countersigned-message).

## See also

[CryptMsgCountersign](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcountersign)

[CryptMsgCountersignEncoded](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcountersignencoded)

[Low-level Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[Simplified Message Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)