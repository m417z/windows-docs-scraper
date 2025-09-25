# CRYPT_SMIME_CAPABILITY structure

## Description

The **CRYPT_SMIME_CAPABILITY** structure specifies a single capability and its associated parameters. Single capabilities are grouped together into a list of
[CRYPT_SMIME_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_smime_capabilities) which can specify a prioritized list of capability preferences.

**Note** The [CRYPT_SMIME_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_smime_capabilities) is part of an Internet draft proposal. For a complete definition, see "draft-dusse-s/mime-cert-01.txt" dated May 5, 1997.

## Members

### `pszObjId`

[Object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for a capability. Capabilities include signature algorithms, [symmetric algorithms](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), and key enciphering algorithms. Also included are non-algorithm capabilities, which are the preference for [signed data](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and the preference for unencrypted messages.

### `Parameters`

A [CRYPT_OBJID_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains any parameters associated with the specified capability in **pszObjId**.

**Note** For
[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) and
[CryptEncodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobjectex) with the *dwCertEncodingType* set to X509_ASN_ENCODING, if the **cbData** member of the **Parameters** member is zero, the encoded parameters are omitted. They are not encoded as a **NULL** (05 00) as is done when encoding a
[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier). This follows the [Secure/Multipurpose Internet Mail Extensions](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (S/MIME) specification for encoding capabilities that requires this omission.

## See also

[CRYPT_SMIME_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_smime_capabilities)