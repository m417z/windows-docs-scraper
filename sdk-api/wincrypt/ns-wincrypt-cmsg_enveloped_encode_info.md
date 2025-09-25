# CMSG_ENVELOPED_ENCODE_INFO structure

## Description

The **CMSG_ENVELOPED_ENCODE_INFO** structure contains information needed to encode an enveloped message. It is passed to
[CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) if the *dwMsgType* parameter is CMSG_ENVELOPED.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `hCryptProv`

This member is not used and should be set to **NULL**.

**Windows Server 2003 and Windows XP:** Specifies a handle to the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) used to do content encryption, recipient key encryption, and export. The private keys of the **hCryptProv** are not used.

This member's data type is **HCRYPTPROV**.

Unless there is a strong reason for passing in a specific cryptographic provider in **hCryptProv**, pass zero to use the default RSA or DSS provider.

### `ContentEncryptionAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains the signature algorithm type and any associated additional parameters in encoded form.

The **pszObjId** member of the structure specifies the algorithm used to encrypt the message contents.

The following encryption algorithms require an encoded eight byte [initialization vector](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) (IV) in the **Parameters** member of structure. For details, see
[CryptSetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyparam).

| Value | Meaning |
| --- | --- |
| **CALG_DES** | szOID_OIWSEC_desCBC |
| **CALG_3DES** | szOID_RSA_DES_EDE3_CBC |

If the **cbData** member of the **Parameters** member is zero, an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoded OCTET STRING containing the IV is generated using
[CryptGenRandom](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenrandom).

The szOID_RSA_RC2CBC (CALG_RC2) algorithm requires the **pbData** member of **Parameters** to be an encoded
[CRYPT_RC2_CBC_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_rc2_cbc_parameters) structure. If the **cbData** member of the **Parameters** member is zero, an ASN.1 encoded CRYPT_RC2_CBC_PARAMETERS is generated with a default value of 40 for the **dwVersion** member. This sets the default key length to 40 bits. This default key length can be overridden with **pvEncryptionAuxInfo** pointing to a
[CMSG_RC2_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_rc2_aux_info) structure containing the desired key length.

**Note** On decryption, if an IV exists,
[CryptSetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyparam) is called with the IV before decryption begins.

### `pvEncryptionAuxInfo`

A pointer to a structure depending on the encryption algorithm.

| Value | Meaning |
| --- | --- |
| **RC2** | [CMSG_RC2_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_rc2_aux_info) |
| **RC4** | [CMSG_RC4_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_rc4_aux_info) |
| **SP3 or compatible** | [CMSG_SP3_COMPATIBLE_AUX_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_sp3_compatible_aux_info) |
| **All other encryption algorithms** | **NULL** |

### `cRecipients`

Number of elements in the **rgpRecipients** or **rgCmsRecipients** array.

### `rgpRecipients`

An array of pointers to
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structures, each containing a recipient's certificate Issuer, SerialNumber, and SubjectPublicKeyInfo. This array can only be used for recipients identified by their Issuer and serial number. If **rgpRecipients** is not **NULL**, **rgCmsRecipients** must be **NULL**.

### `rgCmsRecipients`

Optional. An array of pointers to [CMSG_RECIPIENT_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_recipient_encode_info) structures containing recipient information. If **rgCmsRecipients** is not **NULL**, **rgpRecipients** must be **NULL**. CMSG_ENVELOPED_ENCODE_INFO_HAS_CMS_FIELDS must be defined to reference this field.

### `cCertEncoded`

Optional. A **DWORD** value that indicates the number of encoded certificates in the **rgCertEncoded** array. CMSG_ENVELOPED_ENCODE_INFO_HAS_CMS_FIELDS must be defined to reference this field.

### `rgCertEncoded`

Optional. Array of [CERT_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structures. CMSG_ENVELOPED_ENCODE_INFO_HAS_CMS_FIELDS must be defined to reference this field.

### `cCrlEncoded`

Optional. A **DWORD** value that indicates the number of encoded [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs) in the **rgCRLEncoded** array. CMSG_ENVELOPED_ENCODE_INFO_HAS_CMS_FIELDS must be defined to reference this field.

### `rgCrlEncoded`

Optional. An array of [CRL_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structures. CMSG_ENVELOPED_ENCODE_INFO_HAS_CMS_FIELDS must be defined to reference this field.

### `cAttrCertEncoded`

Optional. A **DWORD** value that indicates the number of encoded certificate attributes in the **rgAttrCertEncoded** array. CMSG_ENVELOPED_ENCODE_INFO_HAS_CMS_FIELDS must be defined to reference this field.

### `rgAttrCertEncoded`

Optional. An array of [CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute) structures. CMSG_ENVELOPED_ENCODE_INFO_HAS_CMS_FIELDS must be defined to reference this member.

### `cUnprotectedAttr`

Optional. A **DWORD** value that indicates the number of unprotected attributes in the **rgUnprotectedAttr** array. CMSG_ENVELOPED_ENCODE_INFO_HAS_CMS_FIELDS must be defined to reference this field.

### `rgUnprotectedAttr`

Optional. An array of [CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute) structures. CMSG_ENVELOPED_ENCODE_INFO_HAS_CMS_FIELDS must be defined to reference this field.

## See also

[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info)

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)