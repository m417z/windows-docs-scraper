# NCryptSignHash function

## Description

The **NCryptSignHash** function creates a signature over data to be signed.

## Parameters

### `hKey` [in]

The handle of the private key to use to generate the signature.

### `pPaddingInfo` [in, optional]

A pointer to a structure that contains padding information. The actual type of structure this parameter points to depends on the value of the *dwFlags* parameter. When *dwFlags* is `0`, this parameter must be `NULL`.

### `pbHashValue` [in]

A pointer to a buffer that contains the input to be signed. The *cbHashValue* parameter contains the size of this buffer.

**Note:** The parameter name *pbHashValue* is a misnomer due to the history of this API.

For many signature algorithms (DSA, RSA, ECDSA, HashML-DSA, etc.), the signature routine is defined to take the result of a hash function as input. In these algorithms, the original message to be signed must first be hashed, and the resultant hash value (pre-hash) is passed in the *pbHashValue* buffer.

However, some signature algorithms (pure ML-DSA, pure SLH-DSA, etc.) allow direct signing of arbitrary sized data. For these algorithms the *pbHashValue* buffer contains the input to be signed. Signer and verifier must agree on how to construct this input, but there is no requirement for a pre-hash to be involved. Signing a very large buffer directly may harm interoperability.

In either case, the *pbHashValue* buffer represents the input to be signed.

### `cbHashValue` [in]

The size, in bytes, of the *pbHashValue* buffer.

### `pbSignature` [out]

The address of a buffer to receive the signature produced by this function. The *cbSignature* parameter contains the size of this buffer.

If this parameter is `NULL`, this function will calculate the size required for the signature and return the size in the location pointed to by the *pcbResult* parameter.

### `cbSignature` [in]

The size, in bytes, of the *pbSignature* buffer. This parameter is ignored if the *pbSignature* parameter is `NULL`.

### `pcbResult` [out]

A pointer to a **DWORD** variable that receives the number of bytes copied to the *pbSignature* buffer.

If *pbSignature* is `NULL`, this receives the size, in bytes, required for the signature.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. The allowed set of flags depends on the type of key specified by the *hKey* parameter.

This can be zero or a combination of one or more of the following values:

| Value | Meaning |
|-------|---------|
| **NCRYPT_PAD_PKCS1_FLAG** | Use the RSA PKCS1 padding scheme. The *pPaddingInfo* parameter is a pointer to a [BCRYPT_PKCS1_PADDING_INFO](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_pkcs1_padding_info) structure. |
| **NCRYPT_PAD_PSS_FLAG** | Use the RSA Probabilistic Signature Scheme (PSS) padding scheme. The *pPaddingInfo* parameter is a pointer to a [BCRYPT_PSS_PADDING_INFO](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_pss_padding_info) structure. |
| **NCRYPT_PAD_PQDSA_FLAG** | Use the PQ padding scheme for ML-DSA or SLH-DSA. The *pPaddingInfo* parameter is a pointer to a [BCRYPT_PQDSA_PADDING_INFO](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_pqdsa_padding_info) structure.<br><br>**Note:** This must be set if using a pre-hash ML-DSA variant. |
| **NCRYPT_SILENT_FLAG** | Requests that the key storage provider (KSP) not display any user interface. If the provider must display the UI to operate, the call fails and the KSP should set the **NTE_SILENT_CONTEXT** error code as the last error. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following:

| Return code | Description |
|-------------|-------------|
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_BAD_ALGID** | The key represented by the *hKey* parameter does not support signing. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter contains a value that is not valid. |
| **NTE_INVALID_HANDLE** | The *hKey* parameter is not valid. |
| **NTE_INVALID_PARAMETER** | One or more parameters are not valid. |
| **NTE_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its **StartService** function, a deadlock can occur, and the service may stop responding.