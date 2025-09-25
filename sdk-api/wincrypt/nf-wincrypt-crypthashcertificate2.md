# CryptHashCertificate2 function

## Description

The **CryptHashCertificate2** function hashes a block of data by using a CNG hash provider.

## Parameters

### `pwszCNGHashAlgid` [in]

The address of a null-terminated Unicode string that contains the CNG hash algorithm identifier of the hash algorithm to use to hash the certificate. This can be one of the [CNG Algorithm Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-algorithm-identifiers) that represents a hash algorithm or any other registered hash algorithm identifier.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. No flags are defined for this function.

### `pvReserved`

Reserved for future use and must be **NULL**.

### `pbEncoded` [in]

The address of an array of bytes to be hashed. The *cbEncoded* parameter contains the size of this array.

### `cbEncoded` [in]

The number of elements in the *pbEncoded* array.

### `pbComputedHash` [out]

The address of a buffer that receives the computed hash. The variable pointed to by the *pcbComputedHash* parameter contains the size of this buffer.

### `pcbComputedHash` [in, out]

The address of a **DWORD** variable that, on entry, contains the size, in bytes, of the *pbComputedHash* buffer. After this function returns, this variable contains the number of bytes copied to the *pbComputedHash* buffer.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some of the possible error codes are identified in the following topics.

[BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider)

[BCryptCreateHash](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptcreatehash)

[BCryptGetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgetproperty)

[BCryptHashData](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcrypthashdata)

[BCryptFinishHash](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptfinishhash)

## See also

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)