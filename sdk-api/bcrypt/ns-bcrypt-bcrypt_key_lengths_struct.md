# BCRYPT_KEY_LENGTHS_STRUCT structure

## Description

The **BCRYPT_KEY_LENGTHS_STRUCT** structure defines the range of key sizes that are supported by the provider. This structure is used with the **BCRYPT_KEY_LENGTHS** property.

This structure is also used with the **BCRYPT_AUTH_TAG_LENGTH** property to contain the minimum, maximum, and increment size of an authentication tag.

## Members

### `dwMinLength`

The minimum length, in bits, of a key.

### `dwMaxLength`

The maximum length, in bits, of a key.

### `dwIncrement`

The number of bits that the key size can be incremented between **dwMinLength** and **dwMaxLength**.

## Remarks

The key sizes are given in a range that is inclusive of the minimum and maximum values and are separated by the increment. For example, if the minimum key size is 8 bits, the maximum key size is 16 bits, and the increment is 2 bits, the provider would support key sizes of 8, 10, 12, 14, and 16 bits.