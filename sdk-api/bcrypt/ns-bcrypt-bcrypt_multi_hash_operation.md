# BCRYPT_MULTI_HASH_OPERATION structure

## Description

A **BCRYPT_MULTI_HASH_OPERATION** structure defines a single operation in a multi-hash operation.

## Members

### `iHash`

An index into the multi-object state array of the hash state on which this computation operates. The first element of the array corresponds to an *iHash* value of zero (0). Valid values are less than the value of the *nHashes* parameter of the [BCryptCreateMultiHash](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptcreatemultihash) function.

### `hashOperation`

A hash operation type, either **BCRYPT_HASH_OPERATION_HASH_DATA** or **BCRYPT_HASH_OPERATION_FINISH_HASH**.

If the value is **BCRYPT_HASH_OPERATION_HASH_DATA**, the operation performed is equivalent to calling the [BCryptHashData](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcrypthashdata) function on the hash object array element with *pbBuffer*/*cbBuffer* pointing to the buffer to be hashed.

If the value is **BCRYPT_HASH_OPERATION_FINISH_HASH**, the operation performed is equivalent to calling the [BCryptFinishHash](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfinishhash) function on the hash object array element with *pbBuffer*/*cbBuffer* pointing to the output buffer that receives the result.

### `pbBuffer`

The buffer on which the operation works.

### `cbBuffer`

The buffer on which the operation works.

## See also

[BCryptCreateMultiHash](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptcreatemultihash)

[BCryptFinishHash](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfinishhash)

[BCryptHashData](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcrypthashdata)