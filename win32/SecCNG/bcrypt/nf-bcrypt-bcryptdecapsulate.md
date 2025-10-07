# BCryptDecapsulate function

> [!NOTE]
> Some information relates to a prerelease product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here. The feature described in this topic is available in pre-release versions of the [Windows Insider Preview](https://www.microsoft.com/software-download/windowsinsiderpreviewSDK).

The **BCryptDecapsulate** function performs the Decapsulation operation of a Key Encapsulation Mechanism (KEM).
It takes a KEM ciphertext and it decrypts with the provided private key, returning the shared secret key.

If the ciphertext is correctly formatted but does not match the decapsulation key, this API will succeed but a random shared secret key will be generated.

## Parameters

*hKey* `[in]`

The handle of the key to use to decapsulate the KEM ciphertext. This must be the private (decapsulation) key which corresponds to the public (encapsulation) key used to produce the KEM ciphertext. The key handle is obtained from one of the keypair creation functions, such as [BCryptGenerateKeyPair](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptgeneratekeypair) or [BCryptImportKeyPair](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptimportkeypair).

*pbCipherText* `[in]`

A pointer to a buffer that contains the KEM ciphertext. The [BCryptEncapsulate](https://learn.microsoft.com/windows/win32/seccng/bcrypt/nf-bcrypt-bcryptencapsulate) function may be used to create a KEM ciphertext.

*cbCipherText* `[in]`

The size, in bytes, of the *pbCipherText* buffer.

*pbSecretKey* `[out]`

A pointer to a buffer that receives the shared secret key. See [remarks](https://learn.microsoft.com/windows/win32/seccng/bcrypt/nf-bcrypt-bcryptdecapsulate#remarks) for more information.

*cbSecretKey* `[in]`

The size, in bytes, of the *pbSecretKey* buffer.

*pcbSecretKey* `[out]`

A pointer to a **ULONG** variable that the receives the number of bytes written to *pbSecretKey* buffer.

If *pbSecretKey* is `NULL`, this receives the size, in bytes, required for the shared secret key.
See [remarks](https://learn.microsoft.com/windows/win32/seccng/bcrypt/nf-bcrypt-bcryptdecapsulate#remarks) for more information.

*dwFlags* `[in]`

Reserved, must be zero.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return Code | Description |
|--|--|
| `STATUS_SUCCESS` | The function was successful. |
| `STATUS_INVALID_PARAMETER` | One or more required parameters (*hKey*, *pcbSecretKey*, *pbCipherText*) is `NULL`, or one of the parameters has an invalid value. |
| `STATUS_INVALID_BUFFER_SIZE` | A buffer size (*cbSecretKey*, *cbCipherText*) does not match the expected size for the KEM parameters associated with the decapsulation key. |
| `STATUS_BUFFER_TOO_SMALL` | An output buffer size (*cbSecretKey*) is too small for the result decapsulation operation for the KEM parameters associated with the decapsulation key. *pcbSecretKey* receives the number of bytes required for *pbSecretKey*. |

## Remarks

To query the required size of the *pbSecretKey* buffer needed for the KEM shared secret key, call **BCryptDecapsulate** with a `NULL` *pbSecretKey*. The required size will be returned in *pcbSecretKey*. This query is efficient and returns the size without performing the decapsulation.
Equivalently, use [BCryptGetProperty](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptgetproperty) to query the **BCRYPT_KEM_SHARED_SECRET_LENGTH** property of the algorithm or key handle.
For currently supported KEM algorithms (ML-KEM), the shared secret length is a constant size for a given algorithm.

### Additional remarks

Given an invalid, but correctly-sized, ciphertext, the ML-KEM decapsulation operation will *implicitly reject* the ciphertext by returning success in equal time to a valid decapsulation operation, with pseudo-random shared secret key output. This forces higher-level protocols to fail later when symmetric keys of peers don't match. So, decapsulate will only ever fail if there are programming errors (i.e. incorrect size, use of uninitialized *hKey*), or something fundamentally goes wrong with the environment (i.e. internal memory allocation fails, or and internal consistency test detects hardware error).

## Requirements

| Requirement | Value |
| ---- | ---- |
| **Minimum supported client** | **Windows Insiders (build 27843):** Support for ML-KEM begins. [desktop apps only] |
| **Minimum supported server** | **Windows Insiders (build 27843):** Support for ML-KEM begins. [desktop apps only] |
| **Library** | `Bcrypt.lib` |
| **DLL** | `Bcrypt.dll` |

## See also

[BCryptEncapsulate](https://learn.microsoft.com/windows/win32/seccng/bcrypt/nf-bcrypt-bcryptencapsulate)

[BCryptGetProperty](https://learn.microsoft.com/windows/win32/api/Bcrypt/nf-bcrypt-bcryptgetproperty)