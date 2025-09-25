# BCryptVerifySignature function

## Description

The **BCryptVerifySignature** function verifies that the specified signature matches the specified data.

## Parameters

### `hKey` [in]

The handle of the key to use to verify the signature. This must contain the public key portion of the key pair used to sign the data with the [BCryptSignHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptsignhash) function.

### `pPaddingInfo` [in, optional]

A pointer to a structure that contains padding information. The actual type of structure this parameter points to depends on the value of the *dwFlags* parameter. When *dwFlags* is `0`, this parameter must be `NULL`.

### `pbHash` [in, optional]

The address of a buffer that contains the input to be verified. The *cbHash* parameter contains the size of this buffer.

**Note:** The parameter name *pbHash* is a misnomer due to the history of this API.

For many signature algorithms (DSA, RSA, ECDSA, HashML-DSA, etc.), the verification routine is defined to take the result of a hash function as input. In these algorithms, the original message to be verified must first be hashed, and the resultant hash value (pre-hash) is passed in the *pbHash* buffer.

However, some signature algorithms (pure ML-DSA, pure SLH-DSA, etc.) allow direct signing of arbitrary sized data. For these algorithms the *pbHash* buffer represents the input to be verified. Signer and verifier must agree on how to construct this input, but there is no requirement for a pre-hash to be involved.

In either case, the *pbHash* buffer represents the input to be verified.

### `cbHash` [in]

The size, in bytes, of the *pbHash* buffer.

### `pbSignature` [in]

The address of a buffer that contains the signature of the data. The [BCryptSignHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptsignhash) function is used to create the signature. The *cbSignature* parameter contains the size of this buffer.

### `cbSignature` [in]

The size, in bytes, of the *pbSignature* buffer. The [BCryptSignHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptsignhash) function is used to create the signature.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. The allowed set of flags depends on the type of key specified by the *hKey* parameter.

This can be zero or one of the following values:

| Value | Meaning |
|-------|---------|
| **BCRYPT_PAD_PKCS1** | The RSA PKCS1 signature padding scheme was used when the signature was created. The *pPaddingInfo* parameter is a pointer to a [BCRYPT_PKCS1_PADDING_INFO](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_pkcs1_padding_info) structure. |
| **BCRYPT_PAD_PSS** | The RSA Probabilistic Signature Scheme (PSS) padding scheme was used when the signature was created. The *pPaddingInfo* parameter is a pointer to a [BCRYPT_PSS_PADDING_INFO](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_pss_padding_info) structure. |
| **BCRYPT_PAD_PQDSA** | Extra information is required to specify how the Post-Quantum Digital Signature algorithm (PQDSA) signature was computed. The *pPaddingInfo* parameter is a pointer to a [BCRYPT_PQDSA_PADDING_INFO](https://learn.microsoft.com/windows/win32/seccng/bcrypt/ns-bcrypt-bcrypt_pqdsa_padding_info) structure.<br><br>**Note:** This must be set if using a pre-hash PQDSA variant.<br><br>**Windows Insiders (build 27843):** Support for PQDSA begins. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following:

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_SIGNATURE** | The signature was not verified. |
| **STATUS_INVALID_PARAMETER** | One of the supplied parameters is invalid. |
| **STATUS_INVALID_HANDLE** | The key handle specified by the *hKey* parameter is not valid. |
| **STATUS_NO_MEMORY** | A memory allocation failure occurred. |
| **STATUS_NOT_SUPPORTED** | The algorithm provider used to create the key handle specified by the *hKey* parameter is not a signing algorithm. |

## Remarks

This function uses the public part of the provided key to calculate whether the provided data, and additional parameters specified by *dwFlags* and *pPaddingInfo*, matches the provided signature according to the signature algorithm specification.

If the signature algorithm takes a pre-hashed value as input, you must hash the original data by using the same hashing algorithm that was used to create the hash value that was signed.
If applicable, you must also specify the same padding scheme that was specified when the signature was created.

When using a supported algorithm provider, **BCryptVerifySignature** can be called either from user mode or kernel mode. Kernel mode callers can execute either at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/win32/SecGloss/i-gly) or **DISPATCH_LEVEL** IRQL. If the current IRQL level is **DISPATCH_LEVEL**, the handle provided in the *hKey* parameter must be derived from an algorithm handle returned by a provider that was opened by using the **BCRYPT_PROV_DISPATCH** flag, and any pointers passed to the **BCryptVerifySignature** function must refer to nonpaged (or locked) memory.

To call this function in kernel mode, use `Cng.lib`, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use `Ksecdd.lib`.

## See also

[BCryptSignHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptsignhash)