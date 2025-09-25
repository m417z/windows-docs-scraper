# NCRYPT_SUPPORTED_LENGTHS structure

## Description

The **NCRYPT_SUPPORTED_LENGTHS** structure is used with the [NCRYPT_LENGTHS_PROPERTY](https://learn.microsoft.com/windows/desktop/SecCNG/key-storage-property-identifiers) property to contain length information for a key.

## Members

### `dwMinLength`

The minimum length, in bits, of a key.

### `dwMaxLength`

The maximum length, in bits, of a key.

### `dwIncrement`

The number of bits that the key size can be incremented between **dwMinLength** and **dwMaxLength**.

### `dwDefaultLength`

The default length, in bits, of a key.