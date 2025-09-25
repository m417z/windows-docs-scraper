# CERT_STRONG_SIGN_PARA structure

## Description

Contains parameters used to check for strong signatures on [certificates](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs), [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) responses, and [PKCS #7](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) messages.

## Members

### `cbSize`

Size, in bytes, of this structure.

### `dwInfoChoice`

Indicates which nested union member points to the strong signature information. This can be one of the following values:

| Value | Description |
| --- | --- |
| **CERT_STRONG_SIGN_SERIALIZED_INFO_CHOICE** | Specifies the **pSerializedInfo** member. |
| **CERT_STRONG_SIGN_OID_INFO_CHOICE** | Specifies the **pszOID** member. |

### `DUMMYUNIONNAME`

Union that contains the parameters that can be used for checking whether a signature is strong. The parameters consist of *signature algorithm* / *hash algorithm* pairs and *public key algorithm* / *bit length* pairs.

### `DUMMYUNIONNAME.pvInfo`

Reserved.

### `DUMMYUNIONNAME.pSerializedInfo`

Pointer to a [CERT_STRONG_SIGN_SERIALIZED_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_serialized_info) structure that specifies the parameters.

### `DUMMYUNIONNAME.pszOID`

Pointer to a string that contains an object identifier (OID) that represents predefined parameters that can be used for strong signature checking. This can be one of the following values:

| Value | Meaning |
| --- | --- |
| **szOID_CERT_STRONG_SIGN_OS_1**<br><br>"1.3.6.1.4.1.311.72.1.1" | The SHA2 hash algorithm is supported. MD2, MD4, MD5, and SSHA1 are not supported.<br><br>The signing and public key algorithms can be RSA or ECDSA. The DSA algorithm is not supported. The key size for the RSA algorithm must equal or be greater than 2047 bits. The key size for the ECDSA algorithm must equal or be greater than 256 bits. <br><br>Strong signing of CRLs and OCSP responses are enabled. |
| **szOID_CERT_STRONG_KEY_OS_1**<br><br>"1.3.6.1.4.1.311.72.2.1" | SHA1 and SHA2 hashes are supported. MD2, MD4, and MD5 are not.<br><br>The signing and public key algorithms can be RSA or ECDSA. The DSA algorithm is not supported. The key size for the RSA algorithm must equal or be greater than 2047 bits. The key size for the ECDSA algorithm must equal or be greater than 256 bits. <br><br>Strong signing of CRLs and OCSP responses are enabled. |

## Remarks

The parameters needed to check for a strong signature include the following:

* Name of the public (asymmetric) algorithm
* Size, in bits, of the public key
* Name of the signature algorithm
* Name of the hashing algorithm

The value you specify for the **dwInfoChoice** member of this structure chooses whether the parameters are transmitted as serialized strings or are predefined by using an object identifier.

The **CERT_STRONG_SIGN_PARA** structure is directly referenced by the following functions:

* [CertIsStrongHashToSign](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certisstronghashtosign)
* [CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol)
* [CryptMsgVerifyCountersignatureEncodedEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgverifycountersignatureencodedex)

The **CERT_STRONG_SIGN_PARA** structure is also directly referenced by the [CRYPT_VERIFY_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_verify_message_para) structure and is therefore available for use by the following functions:

* [CryptDecodeMessage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodemessage)
* [CryptDecryptAndVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecryptandverifymessagesignature)
* [CryptVerifyDetachedMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifydetachedmessagesignature)
* [CryptVerifyMessageSignature](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifymessagesignature)

Finally, the **CERT_STRONG_SIGN_PARA** structure is directly referenced by the [CERT_CHAIN_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_para) structure and is therefore available for use by the following functions:

* [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain)
* [CertSelectCertificateChains](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certselectcertificatechains)

## See also

[CERT_STRONG_SIGN_SERIALIZED_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_strong_sign_serialized_info)