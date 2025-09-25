# SPC_INDIRECT_DATA_CONTENT structure

## Description

The **SPC_INDIRECT_DATA_CONTENT** structure is used in Authenticode signatures to store the digest and other attributes of the signed file.

## Members

### `Data`

A [CRYPT_ATTRIBUTE_TYPE_VALUE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute_type_value) that contains attributes of the digested file.

### `DigestAlgorithm`

Specifies the digest algorithm used to hash the file.

### `Digest`

The Authenticode digest value of the file using the algorithm specified in the *DigestAlgorithm* parameter.