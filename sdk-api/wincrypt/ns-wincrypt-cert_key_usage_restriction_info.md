# CERT_KEY_USAGE_RESTRICTION_INFO structure

## Description

The **CERT_KEY_USAGE_RESTRICTION_INFO** structure contains restrictions imposed on the usage of a certificate's public key. This includes purposes for use of the key and policies under which the key can be used.

[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject) creates an instance of this structure when performed on a
[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structure's **Value** member with its structure's **pszObjId** member set to szOID_KEY_USAGE_RESTRICTION.

An instance of this structure can be used as input to the [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) function to create an appropriate [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension).

## Members

### `cCertPolicyId`

The number of elements in the **rgCertPolicyId** array.

### `rgCertPolicyId`

An array of pointers to
[CERT_POLICY_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_policy_id) structures.

### `RestrictedKeyUsage`

A
[CRYPT_BIT_BLOB](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_bit_blob) value that includes, as its **pbData**, a byte that indicates the purposes for which the key can be used.

If the **cbData** member is zero, the key has no usage restrictions.

The following are currently defined values for the **pbData** member of **RestrictedKeyUsage**. These can be combined using a bitwise-**OR** operation.

* CERT_DATA_ENCIPHERMENT_KEY_USAGE
* CERT_DIGITAL_SIGNATURE_KEY_USAGE
* CERT_KEY_AGREEMENT_KEY_USAGE
* CERT_KEY_CERT_SIGN_KEY_USAGE
* CERT_KEY_ENCIPHERMENT_KEY_USAGE
* CERT_NON_REPUDIATION_KEY_USAGE
* CERT_OFFLINE_CRL_SIGN_KEY_USAGE

## See also

[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension)

[CERT_POLICY_ID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_policy_id)

[CRYPT_BIT_BLOB](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_bit_blob)

[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject)

[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject)