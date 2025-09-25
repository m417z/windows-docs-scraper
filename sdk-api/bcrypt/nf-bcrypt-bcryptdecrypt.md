# BCryptDecrypt function

## Description

The **BCryptDecrypt** function decrypts a block of data.

## Parameters

### `hKey` [in, out]

The handle of the key to use to decrypt the data. This handle is obtained from one of the key creation functions, such as [BCryptGenerateSymmetricKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgeneratesymmetrickey), [BCryptGenerateKeyPair](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgeneratekeypair), or [BCryptImportKey](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptimportkey).

### `pbInput` [in]

The address of a buffer that contains the ciphertext to be decrypted. The *cbInput* parameter contains the size of the ciphertext to decrypt. For more information, see Remarks.

### `cbInput` [in]

The number of bytes in the *pbInput* buffer to decrypt.

### `pPaddingInfo` [in, optional]

A pointer to a structure that contains padding information. This parameter is only used with asymmetric keys and authenticated encryption modes. If an authenticated encryption mode is used, this parameter must point to a [BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcrypt_authenticated_cipher_mode_info) structure. If asymmetric keys are used, the type of structure this parameter points to is determined by the value of the *dwFlags* parameter. Otherwise, the parameter must be set to **NULL**.

### `pbIV` [in, out, optional]

The address of a buffer that contains the [initialization vector](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) (IV) to use during decryption. The *cbIV* parameter contains the size of this buffer. This function will modify the contents of this buffer. If you need to reuse the IV later, make sure you make a copy of this buffer before calling this function.

This parameter is optional and can be **NULL** if no IV is used.

 The required size of the IV can be obtained by calling the [BCryptGetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgetproperty) function to get the **BCRYPT_BLOCK_LENGTH** property. This will provide the size of a block for the algorithm, which is also the size of the IV.

### `cbIV` [in]

The size, in bytes, of the *pbIV* buffer.

### `pbOutput` [out, optional]

The address of a buffer to receive the plaintext produced by this function. The *cbOutput* parameter contains the size of this buffer. For more information, see Remarks.

If this parameter is **NULL**, the **BCryptDecrypt** function calculates the size required for the plaintext of the encrypted data passed in the *pbInput* parameter. In this case, the location pointed to by the *pcbResult* parameter contains this size, and the function returns **STATUS_SUCCESS**.

If the values of both the *pbOutput* and *pbInput* parameters are **NULL**, an error is returned unless an authenticated encryption algorithm is in use. In the latter case, the call is treated as an authenticated encryption call with zero length data, and the authentication tag, passed in the *pPaddingInfo* parameter, is verified.

### `cbOutput` [in]

The size, in bytes, of the *pbOutput* buffer. This parameter is ignored if the *pbOutput* parameter is **NULL**.

### `pcbResult` [out]

A pointer to a **ULONG** variable to receive the number of bytes copied to the *pbOutput* buffer. If *pbOutput* is **NULL**, this receives the size, in bytes, required for the plaintext.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. The allowed set of flags depends on the type of key specified by the *hKey* parameter.

If the key is a symmetric key, this can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **BCRYPT_BLOCK_PADDING** | The data was padded to the next block size when it was encrypted. If this flag was used with the [BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt) function, it must also be specified in this function. This flag must not be used with the authenticated encryption modes (AES-CCM and AES-GCM). |

If the key is an asymmetric key, this can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BCRYPT_PAD_NONE** | Do not use any padding. The *pPaddingInfo* parameter is not used. The *cbInput* parameter must be a multiple of the algorithm's block size.<br><br> The block size can be obtained by calling the [BCryptGetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgetproperty) function to get the **BCRYPT_BLOCK_LENGTH** property for the key. This will provide the size of a block for the algorithm. |
| **BCRYPT_PAD_OAEP** | The Optimal Asymmetric Encryption Padding (OAEP) scheme was used when the data was encrypted. The *pPaddingInfo* parameter is a pointer to a [BCRYPT_OAEP_PADDING_INFO](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-bcrypt_oaep_padding_info) structure. |
| **BCRYPT_PAD_PKCS1** | The data was padded with a random number when the data was encrypted. The *pPaddingInfo* parameter is not used. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_AUTH_TAG_MISMATCH** | The computed authentication tag did not match the value supplied in the *pPaddingInfo* parameter. |
| **STATUS_BUFFER_TOO_SMALL** | The size specified by the *cbOutput* parameter is not large enough to hold the ciphertext. |
| **STATUS_INVALID_BUFFER_SIZE** | The *cbInput* parameter is not a multiple of the algorithm's block size, and the **BCRYPT_BLOCK_PADDING** flag was not specified in the *dwFlags* parameter. |
| **STATUS_INVALID_HANDLE** | The key handle in the *hKey* parameter is not valid. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NOT_SUPPORTED** | The algorithm does not support decryption. |

## Remarks

The *pbInput* and *pbOutput* parameters can be equal. In this case, this function will perform the decryption in place. If *pbInput* and *pbOutput* are not equal, the two buffers may not overlap.

When using a supported algorithm provider, **BCryptDecrypt** can be called either from user mode or kernel mode. Kernel mode callers can execute either at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) or **DISPATCH_LEVEL** IRQL. If the current IRQL level is **DISPATCH_LEVEL**, the handle provided in the *hKey* parameter must be derived from an algorithm handle returned by a provider that was opened with the **BCRYPT_PROV_DISPATCH** flag, and any pointers passed to the **BCryptDecrypt** function must refer to nonpaged (or locked) memory.

To call this function in kernel mode, use Cng.lib, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use Ksecdd.lib.

## See also

[BCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptencrypt)