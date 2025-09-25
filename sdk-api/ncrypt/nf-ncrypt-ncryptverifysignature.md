# NCryptVerifySignature function

## Description

The **NCryptVerifySignature** function verifies that the specified signature matches the specified data.

## Parameters

### `hKey` [in]

The handle of the key to use to verify the signature. This must contain the public key portion of the key pair used to sign the data with the [NCryptSignHash](https://learn.microsoft.com/windows/win32/api/ncrypt/nf-ncrypt-ncryptsignhash) function.

### `pPaddingInfo` [in, optional]

A pointer to a structure that contains padding information. The actual type of structure this parameter points to depends on the value of the *dwFlags* parameter. When *dwFlags* is `0`, this parameter must be `NULL`.

### `pbHashValue` [in]

The address of a buffer that contains the input to be verified. The *cbHashValue* parameter contains the size of this buffer.

**Note:** The parameter name *pbHashValue* is a misnomer due to the history of this API.

For many signature algorithms (DSA, RSA, ECDSA, HashML-DSA, etc.), the verification routine is defined to take the result of a hash function as input. In these algorithms, the original message to be verified must first be hashed, and the resultant hash value (pre-hash) is passed in the *pbHashValue* buffer.

However, some signature algorithms (pure ML-DSA, pure SLH-DSA, etc.) allow direct signing of arbitrary sized data. For these algorithms the *pbHashValue* buffer represents the input to be verified. Signer and verifier must agree on how to construct this input, but there is no requirement for a pre-hash to be involved.

In either case, the *pbHashValue* buffer represents the data to be verified.

### `cbHashValue` [in]

The size, in bytes, of the *pbHashValue* buffer.

### `pbSignature` [in]

The address of a buffer that contains the signature of the data. The [NCryptSignHash](https://learn.microsoft.com/windows/win32/api/ncrypt/nf-ncrypt-ncryptsignhash) function is used to create the signature. The *cbSignature* parameter contains the size of this buffer.

### `cbSignature` [in]

The size, in bytes, of the *pbSignature* buffer. The [NCryptSignHash](https://learn.microsoft.com/windows/win32/api/ncrypt/nf-ncrypt-ncryptsignhash) function is used to create the signature.

### `dwFlags` [in]

Flags that modify function behavior. The allowed set of flags depends on the type of key specified by the *hKey* parameter.

This can be zero or a combination of one or more of the following values:

| Value | Meaning |
|-------|---------|
| **NCRYPT_PAD_PKCS1_FLAG** | The RSA PKCS1 padding scheme was used when the signature was created. The *pPaddingInfo* parameter is a pointer to a [BCRYPT_PKCS1_PADDING_INFO](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_pkcs1_padding_info) structure. |
| **NCRYPT_PAD_PSS_FLAG** | The RSA Probabilistic Signature Scheme (PSS) padding scheme was used when the signature was created. The *pPaddingInfo* parameter is a pointer to a [BCRYPT_PSS_PADDING_INFO](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_pss_padding_info) structure. |
| **NCRYPT_PAD_PQDSA_FLAG** | Extra information is required to specify how the Post-Quantum Digital Signature algorithm (PQDSA) signature was computed. The *pPaddingInfo* parameter is a pointer to a [BCRYPT_PQDSA_PADDING_INFO](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_pqdsa_padding_info) structure.<br><br>**Note:** This must be set if using a pre-hash PQDSA variant.<br><br>**Windows Insiders (build 27843):** Support for PQDSA begins. |
| **NCRYPT_SILENT_FLAG** | Requests that the key storage provider (KSP) not display any user interface. If the provider must display the UI to operate, the call fails and the KSP should set the **NTE_SILENT_CONTEXT** error code as the last error. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following:

| Return code | Description |
|-------------|-------------|
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_BAD_SIGNATURE** | The signature was not verified. |
| **NTE_INVALID_HANDLE** | The *hKey* parameter is not valid. |
| **NTE_NO_MEMORY** | A memory allocation failure occurred. |
| **NTE_NOT_SUPPORTED** | The algorithm provider used to create the key handle specified by the *hKey* parameter is not a signing algorithm. |

## Remarks

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its **StartService** function, a deadlock can occur, and the service may stop responding.

## See also

[NCryptSignHash](https://learn.microsoft.com/windows/win32/api/ncrypt/nf-ncrypt-ncryptsignhash)