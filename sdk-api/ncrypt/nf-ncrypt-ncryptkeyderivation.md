# NCryptKeyDerivation function

## Description

The **NCryptKeyDerivation** function derives a key by invoking a Key Derivation Function (KDF), with all parameters explicitly being provided.

It is similar in functionality to [NCryptDeriveKey](https://learn.microsoft.com/windows/win32/api/ncrypt/nf-ncrypt-ncryptderivekey) but directly invokes a KDF algorithm, so does not require a **NCRYPT_SECRET_HANDLE** value as input.

## Parameters

### `hKey` [in]

Handle of the key derivation function (KDF) key.

### `pParameterList` [in]

The address of an [NCryptBufferDesc](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcryptbufferdesc) structure that contains the KDF parameters.

The parameters can be specific to a key derivation function (KDF) or generic. The following table shows the required and optional parameters for specific KDFs implemented by the Microsoft software key storage provider.

| KDF | Parameter | Required | Default |
| --- | --------- | -------- | ------- |
| SP800-108 HMAC in counter mode | KDF_LABEL | yes | |
| | KDF_CONTEXT | yes | |
| | KDF_HASH_ALGORITHM | yes | |
| SP800-56A | KDF_ALGORITHMID | yes | |
| | KDF_PARTYUINFO | yes | |
| | KDF_PARTYVINFO | yes | |
| | KDF_HASH_ALGORITHM | yes | |
| | KDF_SUPPPUBINFO | no | "" |
| | KDF_SUPPPRIVINFO | no | "" |
| PBKDF2 | KDF_HASH_ALGORITHM | yes | |
| | KDF_SALT | yes | |
| | KDF_ITERATION_COUNT | no | 10000 |
| CAPI_KDF | KDF_HASH_ALGORITHM | yes | |
| TLS1_1_PRF | KDF_TLS_PRF_LABEL | yes | |
| | KDF_TLS_PRF_SEED | yes | |
| TLS1_2_PRF | KDF_TLS_PRF_LABEL | yes | |
| | KDF_TLS_PRF_SEED | yes | |
| | KDF_HASH_ALGORITHM | yes | |
| HKDF | KDF_HKDF_INFO | no | "" |

For some algorithms, the **KDF_GENERIC_PARAMETER** instead of specifying several parameters. This maps to KDF specific parameters in the following manner:

SP800-108 HMAC in counter mode:
- KDF_GENERIC_PARAMETER = KDF_LABEL || 0x00 || KDF_CONTEXT

SP800-56A:
- KDF_GENERIC_PARAMETER = KDF_ALGORITHMID || KDF_PARTYUINFO || KDF_PARTYVINFO {|| KDF_SUPPPUBINFO } {|| KDF_SUPPPRIVINFO }

PBKDF2:
- KDF_GENERIC_PARAMETER = KDF_SALT

### `pbDerivedKey` [out]

Address of a buffer that receives the key. The *cbDerivedKey* parameter contains the size, in bytes, of the key buffer.

### `cbDerivedKey` [in]

Size, in bytes, of the buffer pointed to by the *pbDerivedKey* parameter.

### `pcbResult` [out]

Pointer to a **DWORD** that receives the number of bytes copied to the buffer pointed to by the *pbDerivedKey* parameter.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. This can be zero or a combination of one or more of the following values. The set of valid flags is specific to each key storage provider.

| Value | Meaning |
| ----- | ------- |
| **BCRYPT_CAPI_AES_FLAG** | Specifies that the target algorithm is AES and that the key therefore must be double expanded. This flag is only valid with the CAPI_KDF algorithm. |
| **NCRYPT_SILENT_FLAG** | Requests that the key storage provider (KSP) not display any user interface. If the provider must display the UI to operate, the call fails and the KSP should set the **NTE_SILENT_CONTEXT** error code as the last error. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| ----------- | ----------- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_INVALID_HANDLE** | The *hProvider* or *hKey* handles are not valid. |
| **NTE_INVALID_PARAMETER** | The *pParameterList* parameter cannot be `NULL`, or some other parameter is invalid. |
| **NTE_NO_MEMORY** | A memory allocation failure occurred. |
| **NTE_NOT_SUPPORTED** | This function is not supported by the key storage provider. |

## Remarks

You can use the following algorithm identifiers in the [NCryptCreatePersistedKey](https://learn.microsoft.com/windows/win32/api/ncrypt/nf-ncrypt-ncryptcreatepersistedkey) function before calling *NCryptKeyDerivation*:
- BCRYPT_CAPI_KDF_ALGORITHM
- BCRYPT_SP800108_CTR_HMAC_ALGORITHM
- BCRYPT_SP80056A_CONCAT_ALGORITHM
- BCRYPT_PBKDF2_ALGORITHM
- BCRYPT_TLS1_1_KDF_ALGORITHM
- BCRYPT_TLS1_2_KDF_ALGORITHM

## See also

[BCryptKeyDerivation](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptkeyderivation)

[NCryptDeriveKey](https://learn.microsoft.com/windows/win32/api/ncrypt/nf-ncrypt-ncryptderivekey)