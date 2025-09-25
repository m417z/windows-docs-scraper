# CERT_KEY_ATTRIBUTES_INFO structure

## Description

The **CERT_KEY_ATTRIBUTES_INFO** structure contains optional additional information about the public key being certified. It can include a key identifier, an indication of the intended use of that key, or an indication of the period of use of the corresponding private key.

[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject) creates an instance of this structure when performed on a
[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structure's **Value** member with its the structure's **pszObjId** member set to szOID_KEY_ATTRIBUTES.

An instance of this structure can be used as input to [CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) to create an appropriate [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension).

## Members

### `KeyId`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure with a unique identifier of a key.

### `IntendedKeyUsage`

**CRYPT_BIT_BLOB** with it **pbData** member indicating the intended purpose of the key. For a list of usage bit values, see the **RestrictedKeyUsage** member of
the [CERT_KEY_USAGE_RESTRICTION_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_usage_restriction_info) structure.

This member can be used to find the correct key or certificate of a user who has multiple keys or certificates. Its indication of usage is advisory field, only, and does not imply that usage of the key is restricted to the purpose indicated. The list of intended uses is not necessarily all-inclusive, and the field can be omitted. If a key is to be restricted to a particular use a [CERT_KEY_USAGE_RESTRICTION_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_usage_restriction_info) extension must be used.

### `pPrivateKeyUsagePeriod`

A pointer to a
[CERT_PRIVATE_KEY_VALIDITY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_private_key_validity) structure that indicates the period of use of the private key corresponding to the certified public key. This member is optional and can be set to **NULL**.

## See also

[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension)

[CERT_PRIVATE_KEY_VALIDITY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_private_key_validity)

[CRYPT_BIT_BLOB](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_bit_blob)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject)