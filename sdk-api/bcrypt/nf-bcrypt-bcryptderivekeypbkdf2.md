# BCryptDeriveKeyPBKDF2 function

## Description

The **BCryptDeriveKeyPBKDF2** function derives a key from a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) value by using the PBKDF2 key derivation algorithm as defined by [RFC 2898](https://www.ietf.org/rfc/rfc2898.txt).

## Parameters

### `hPrf` [in]

The handle of an algorithm provider that provides the pseudo-random function. This should be an algorithm provider that performs a [Message Authentication Code](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) computation. When you use the default Microsoft algorithm provider, any [hashing algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) opened by using the **BCRYPT_ALG_HANDLE_HMAC_FLAG** flag can be used.

**Note** Only algorithms that implement the BCRYPT_IS_KEYED_HASH property can be used to populate this parameter.

### `pbPassword` [in, optional]

A pointer to a buffer that contains the password parameter for the PBKDF2 key derivation algorithm.

**Note** Any secret information used in the key derivation should be passed in this buffer.

### `cbPassword` [in]

The length, in bytes, of the data in the buffer pointed to by the *pbPassword* parameter.

### `pbSalt` [in, optional]

A pointer to a buffer that contains the salt argument for the PBKDF2 key derivation algorithm.

**Note** Any information that is not secret and that is used in the key derivation should be passed in this buffer.

### `cbSalt` [in]

The length, in bytes, of the salt argument pointed to by the *pbSalt* parameter.

### `cIterations` [in]

The iteration count for the PBKDF2 key derivation algorithm.

### `pbDerivedKey` [out]

A pointer to a buffer that receives the derived key.

### `cbDerivedKey` [in]

The length, in bytes, of the derived key returned in the buffer pointed to by the *pbDerivedKey* parameter.

### `dwFlags` [in]

This parameter is reserved and must be set to zero.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_HANDLE** | The handle in the *hPrf* parameter is not valid. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |