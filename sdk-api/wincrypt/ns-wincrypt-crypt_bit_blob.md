# CRYPT_BIT_BLOB structure

## Description

The **CRYPT_BIT_BLOB** structure contains a set of bits represented by an array of bytes.

## Members

### `cbData`

The number of bytes in the **pbData** array.

### `pbData`

A pointer to an array of bytes that represents the bits.

### `cUnusedBits`

The number of unused bits in the last byte of the array. The unused bits are always the least significant bits in the last byte of the array.

## Remarks

Because the smallest chunk of memory that can normally be allocated is a byte, the **CRYPT_BIT_BLOB** structure allows the last byte in the array to contain zero to seven unused bits. The number of unused bits in the array is contained in the **cUnusedBits** member of this structure. The number of meaningful bits in the **pbData** member is calculated with the formula ((**cbData** × 8) –**cUnusedBits**). For example, if you need to represent 10 bits, you would allocate an array of 2 bytes and set **cUnusedBits** to 6. If you view the array as contiguous bits from left to right, the left 10 bits would be meaningful, and the right 6 bits would be unused.

## See also

[CERT_BASIC_CONSTRAINTS_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_basic_constraints_info)

[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info)

[CERT_KEY_ATTRIBUTES_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_attributes_info)

[CERT_KEY_USAGE_RESTRICTION_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_key_usage_restriction_info)

[CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info)

[CERT_SIGNED_CONTENT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_signed_content_info)