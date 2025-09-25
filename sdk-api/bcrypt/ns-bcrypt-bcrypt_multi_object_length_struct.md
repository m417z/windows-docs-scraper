# BCRYPT_MULTI_OBJECT_LENGTH_STRUCT structure

## Description

The **BCRYPT_MULTI_OBJECT_LENGTH_STRUCT** structure contains information to determine the size of the *pbHashObject* buffer for the [BCryptCreateMultiHash](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptcreatemultihash) function.

## Members

### `cbPerObject`

The number of bytes needed for the object overhead.

### `cbPerElement`

The number of bytes needed for each element of the object.

## Remarks

The size of the *pbHashObject* buffer for the [BCryptCreateMultiHash](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptcreatemultihash) function is the following: `cbPerObject + (number of hash states) * cbPerElement`.

## See also

[BCryptCreateMultiHash](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptcreatemultihash)