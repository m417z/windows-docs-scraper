# BCryptKeyDerivation function

## Description

The **BCryptKeyDerivation** function derives a key by invoking a Key Derivation Function (KDF), with all parameters explicitly being provided.

It is similar in functionality to [BCryptDeriveKey](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptderivekey) but directly invokes a KDF algorithm, so does not require a **BCRYPT_SECRET_HANDLE** value as input.

## Parameters

### `hKey` [in]

Handle of the key derivation function (KDF) key. See Remarks.

### `pParameterList` [in, optional]

The address of a [BCryptBufferDesc](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcryptbufferdesc) structure that contains the KDF parameters. This parameter is optional and can be `NULL` if it is not needed.

The parameters can be specific to a key derivation function (KDF) or generic. The following table shows the required and optional parameters for specific KDFs implemented by the Microsoft Primitive provider. Some additional information can be found in the documentation for [BCryptBuffer](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcryptbuffer).

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

For some algorithms, the **KDF_GENERIC_PARAMETER** can be used instead of specifying several parameters. This maps to KDF specific parameters in the following manner:

SP800-108 HMAC in counter mode:
- KDF_GENERIC_PARAMETER = KDF_LABEL || 0x00 || KDF_CONTEXT

SP800-56A:
- KDF_GENERIC_PARAMETER = KDF_ALGORITHMID || KDF_PARTYUINFO || KDF_PARTYVINFO {|| KDF_SUPPPUBINFO } {|| KDF_SUPPPRIVINFO }

PBKDF2:
- KDF_GENERIC_PARAMETER = KDF_SALT

### `pbDerivedKey` [out]

Address of a buffer that receives the key. The *cbDerivedKey* parameter contains the size of this buffer.

### `cbDerivedKey` [in]

Size, in bytes, of the buffer pointed to by the *pbDerivedKey* parameter.

### `pcbResult` [out]

Pointer to a **ULONG** that receives the number of bytes that were copied to the buffer pointed to by the *pbDerivedKey* parameter.

### `dwFlags` [in]

Flags that modify the behavior of this function. The following value can be used with the Microsoft Primitive provider.

| Value | Meaning |
| ----- | ------- |
| **BCRYPT_CAPI_AES_FLAG** | Specifies that the target algorithm is AES and that the key therefore must be double expanded. This flag is only valid with the CAPI_KDF algorithm. |

## Return value

Returns a status code that indicates the success or failure of the function.

## Remarks

The flow for using *BCryptKeyDerivation* is to:
1) Determine the KDF algorithm you are going to use and get a algorithm handle for it. You can use the following algorithm identifiers in the [BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider):
- BCRYPT_CAPI_KDF_ALGORITHM
- BCRYPT_SP800108_CTR_HMAC_ALGORITHM
- BCRYPT_SP80056A_CONCAT_ALGORITHM
- BCRYPT_PBKDF2_ALGORITHM
- BCRYPT_TLS1_1_KDF_ALGORITHM
- BCRYPT_TLS1_2_KDF_ALGORITHM
- BCRYPT_HKDF_ALGORITHM

 2) Determine the secret data from which you are going to derive a key, and supply it to [BCryptGenerateSymmetricKey](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptgeneratesymmetrickey) with the algorithm handle, to produce a KDF key handle.

 3) Call *BCryptKeyDerivation* with the KDF key handle.

To call this function in kernel mode, use `Cng.lib`, which is part of the Driver Development Kit (DDK).
**Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use Ksecdd.lib.

### HKDF

In HKDF, a distinction is made between deriving a key from either:
1) The output of a secret agreement function, which is not uniformly random, and is considered to be input keying material (IKM).
2) A uniformly random secret value.

##### The first step is to "Extract" a pseudorandom key (PRK) from the provided secret data.

This step is performed by calling [BCryptSetProperty](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptsetproperty) on the KDF key handle with **BCRYPT_HKDF_HASH_ALGORITHM** to set the hash algorithm to use in HMAC computations in HKDF.
This is followed by a second call to [BCryptSetProperty](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptsetproperty) with one of either:
1) If the provided secret data represents IKM, use **BCRYPT_HKDF_SALT_AND_FINALIZE** to provide the optional salt value and extract the PRK from the IKM and finalize the KDF key handle.
2) Otherwise, use **BCRYPT_HKDF_PRK_AND_FINALIZE** to directly transform the provided secret into the HKDF PRK and finalize the KDF key handle.

##### The second step is to "Expand" the PRK into an output derived key.
This step is performed by calling *BCryptKeyDerivation* on a finalized KDF key handle.

## See also

[BCryptDeriveKey](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptderivekey)

[BCryptBufferDesc](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcryptbufferdesc)

[BCryptBuffer](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcryptbuffer)

[NCryptKeyDerivation](https://learn.microsoft.com/windows/win32/api/ncrypt/nf-ncrypt-ncryptkeyderivation)