# NCryptEncrypt function

## Description

The **NCryptEncrypt** function encrypts a block of data.

## Parameters

### `hKey` [in]

The handle of the key to use to encrypt the data.

### `pbInput` [in]

The address of a buffer that contains the data to be encrypted. The *cbInput* parameter contains the size of the data to encrypt. For more information, see Remarks.

### `cbInput` [in]

The number of bytes in the *pbInput* buffer to encrypt.

### `pPaddingInfo` [in, optional]

A pointer to a structure that contains padding information. The actual type of structure this parameter points to depends on the value of the *dwFlags* parameter. This parameter is only used with asymmetric keys and must be **NULL** otherwise.

### `pbOutput` [out]

The address of a buffer that will receive the encrypted data produced by this function. The *cbOutput* parameter contains the size of this buffer. For more information, see Remarks.

If this parameter is **NULL**, this function will calculate the size needed for the encrypted data and return the size in the location pointed to by the *pcbResult* parameter.

### `cbOutput` [in]

The size, in bytes, of the *pbOutput* buffer. This parameter is ignored if the *pbOutput* parameter is **NULL**.

### `pcbResult` [out]

A pointer to a **DWORD** variable that receives the number of bytes copied to the *pbOutput* buffer. If *pbOutput* is **NULL**, this receives the size, in bytes, required for the ciphertext.

### `dwFlags` [in]

Flags that modify function behavior. The allowed set of flags depends on the type of key specified by the *hKey* parameter.

If the key is an asymmetric key, this can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NCRYPT_NO_PADDING_FLAG** | Do not use any padding. The *pPaddingInfo* parameter is not used. <br><br>If you specify the **NCRYPT_NO_PADDING_FLAG**, then the **NCryptEncrypt** function only encrypts the first N bits, where N is the length of the key that was passed as the *hKey* parameter. Any bits after the first N bits are ignored. |
| **NCRYPT_PAD_OAEP_FLAG** | Use the Optimal Asymmetric Encryption Padding (OAEP) scheme. The *pPaddingInfo* parameter is a pointer to a [BCRYPT_OAEP_PADDING_INFO](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-bcrypt_oaep_padding_info) structure. |
| **NCRYPT_PAD_PKCS1_FLAG** | The data will be padded with a random number to round out the block size. The *pPaddingInfo* parameter is not used. |
| **NCRYPT_SILENT_FLAG** | Requests that the key storage provider (KSP) not display any user interface. If the provider must display the UI to operate, the call fails and the KSP should set the **NTE_SILENT_CONTEXT** error code as the last error. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter contains a value that is not valid. |
| **NTE_BAD_KEY_STATE** | The key identified by the *hKey* parameter has not been finalized or is incomplete. |
| **NTE_BUFFER_TOO_SMALL** | The size specified by the *cbOutput* parameter is not large enough to hold the encrypted data. |
| **NTE_INVALID_HANDLE** | The *hKey* parameter is not valid. |
| **NTE_INVALID_PARAMETER** | One or more parameters are not valid. |

## Remarks

The *pbInput* and *pbOutput* parameters can point to the same buffer. In this case, this function will perform the encryption in place. It is possible that the encrypted data size will be larger than the unencrypted data size, so the buffer must be large enough to hold the encrypted data.

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.