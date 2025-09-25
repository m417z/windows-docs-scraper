# CMSG_SIGNER_ENCODE_INFO structure

## Description

The **CMSG_SIGNER_ENCODE_INFO** structure contains signer information. It is passed to
[CryptMsgCountersign](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcountersign),
[CryptMsgCountersignEncoded](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcountersignencoded), and optionally to
[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) as a member of
the [CMSG_SIGNED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signed_encode_info) structure, if the *dwMsgType* parameter is CMSG_SIGNED.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `pCertInfo`

A pointer to a
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure that contains the

**Issuer**, **SerialNumber**, and **SubjectPublicKeyInfo** members.

The **pbData** members of the **Issuer** and **SerialNumber** structures combined uniquely identify a certificate. The **Algorithm** member of the **SubjectPublicKeyInfo** structure specifies the [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) encryption algorithm used.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.hCryptProv`

A handle to the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP).
If **HashEncryptionAlgorithm** is set to szOID_PKIX_NO_SIGNATURE, this handle can be the handle of a CSP acquired by using the *dwFlags* parameter set to **CRYPT_VERIFYCONTEXT**. The CNG function [NCryptIsKeyHandle](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptiskeyhandle) is called to determine the union choice.

### `DUMMYUNIONNAME.hNCryptKey`

A handle to the CNG CSP. The CNG function [NCryptIsKeyHandle](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptiskeyhandle) is called to determine the union choice. New encrypt algorithms are only supported in CNG functions. The CNG function [NCryptTranslateHandle](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncrypttranslatehandle) will be called to convert the CryptoAPI *hCryptProv* choice where necessary. We recommend that applications pass, to the *hNCryptKey* member, the CNG CSP handle that is returned from the [NCryptOpenKey](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenkey) function.

### `DUMMYUNIONNAME.hBCryptKey`

### `dwKeySpec`

Specifies the private key to be used. This member is not used when the *hNCryptKey* member is used.

If **dwKeySpec** is zero, then the default AT_KEYEXCHANGE value is used.

The following **dwKeySpec** values are defined for the default provider.

| Value | Meaning |
| --- | --- |
| **AT_KEYEXCHANGE** | Keys used to encrypt/decrypt session keys. |
| **AT_SIGNATURE** | Keys used to create and verify digital signatures. |

### `HashAlgorithm`

A
[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that specifies the hash algorithm.

### `pvHashAuxInfo`

Not used. This member must be set to **NULL**.

### `cAuthAttr`

The number of elements in the **rgAuthAttr** array. If no authenticated attributes are present in **rgAuthAttr**, then **cAuthAttr** is zero.

### `rgAuthAttr`

An array of pointers to
[CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute) structures, each of which contains authenticated attribute information.

The PKCS #9 standard dictates that if there are any attributes, there must be at least two: the content type [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and the hash of the message. These attributes are automatically added by the system.

### `cUnauthAttr`

The number of elements in the **rgUnauthAttr** array. If there are no unauthenticated attributes, **cUnauthAttr** is zero.

### `rgUnauthAttr`

An array of pointers to [CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute) structures, each of which contains unauthenticated attribute information. Unauthenticated attributes can contain [countersignatures](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), among other uses.

### `SignerId`

A [CERT_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_id) structure that contains a unique identifier of the signer's certificate. This member can optionally be used with PKCS #7 with Cryptographic Message Syntax (CMS). If this member is not **NULL** and its **dwIdChoice** member is not zero, it is used to identify the certificate instead of the **Issuer** and **SerialNumber** members of the [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure pointed to by **pCertInfo**.
CMS supports the KEY_IDENTIFIER and ISSUER_SERIAL_NUMBER CERT_ID structures. PKCS version 1.5 supports only the ISSUER_SERIAL_NUMBER CERT_ID choice. This member is used with CMS for PKCS #7 processing and can be used only if CMSG_SIGNER_ENCODE_INFO_HAS_CMS_FIELDS is defined.

### `HashEncryptionAlgorithm`

A
[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure optionally used with PKCS #7 with CMS. If this member is not **NULL**, the algorithm identified is used instead of the SubjectPublicKeyInfo.Algorithm algorithm.
If this member is set to szOID_PKIX_NO_SIGNATURE, the signature value contains only the hash octets.

For RSA, the [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) encryption algorithm is normally the same as the public key algorithm. For DSA, the hash encryption algorithm is normally a DSS signature algorithm.

This member is used with CMS for PKCS #7 processing and can be used only if CMSG_SIGNER_ENCODE_INFO_HAS_CMS_FIELDS is defined.

### `pvHashEncryptionAuxInfo`

This member is not used. This member must be set to **NULL** if it is present in the data structure.
This member is present only if CMSG_SIGNER_ENCODE_INFO_HAS_CMS_FIELDS is defined.

## See also

[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info)

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute)

[CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol)

[CryptMsgCountersign](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcountersign)