# NCryptDecrypt function

## Description

The **NCryptDecrypt** function decrypts a block of encrypted data.

## Parameters

### `hKey` [in]

The handle of the key to use to decrypt the data.

### `pbInput` [in]

The address of a buffer that contains the data to be decrypted. The *cbInput* parameter contains the size of the data to decrypt. For more information, see Remarks.

### `cbInput` [in]

The number of bytes in the *pbInput* buffer to decrypt.

### `pPaddingInfo` [in, optional]

A pointer to a structure that contains padding information. The actual type of structure this parameter points to depends on the value of the *dwFlags* parameter. This parameter is only used with asymmetric keys and must be **NULL** otherwise.

### `pbOutput` [out]

The address of a buffer that will receive the decrypted data produced by this function. The *cbOutput* parameter contains the size of this buffer. For more information, see Remarks.

If this parameter is **NULL**, this function will calculate the size needed for the decrypted data and return the size in the location pointed to by the *pcbResult* parameter.

### `cbOutput` [in]

The size, in bytes, of the *pbOutput* buffer. This parameter is ignored if the *pbOutput* parameter is **NULL**.

### `pcbResult` [out]

A pointer to a **DWORD** variable that receives the number of bytes copied to the *pbOutput* buffer. If *pbOutput* is **NULL**, this receives the size, in bytes, required for the decrypted data.

### `dwFlags` [in]

Flags that modify function behavior. The allowed set of flags depends on the type of key specified by the *hKey* parameter.

If the key is an asymmetric key, this can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NCRYPT_NO_PADDING_FLAG** | No padding was used when the data was encrypted. The *pPaddingInfo* parameter is not used. |
| **NCRYPT_PAD_OAEP_FLAG** | The Optimal Asymmetric Encryption Padding (OAEP) scheme was used when the data was encrypted. The *pPaddingInfo* parameter is a pointer to a [BCRYPT_OAEP_PADDING_INFO](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-bcrypt_oaep_padding_info) structure. |
| **NCRYPT_PAD_PKCS1_FLAG** | The data was padded with a random number to round out the block size when the data was encrypted. The *pPaddingInfo* parameter is not used. |

The following value can be used for any key.

| Value | Meaning |
| --- | --- |
| **NCRYPT_SILENT_FLAG** | Requests that the key storage provider (KSP) not display any user interface. If the provider must display the UI to operate, the call fails and the KSP should set the **NTE_SILENT_CONTEXT** error code as the last error. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter contains a value that is not valid. |
| **NTE_BUFFER_TOO_SMALL** | The size specified by the *cbOutput* parameter is not large enough to hold the decrypted data. |
| **NTE_INVALID_HANDLE** | The *hKey* parameter is not valid. |
| **NTE_INVALID_PARAMETER** | One or more parameters are not valid. |
| **NTE_PERM** | The key identified by the *hKey* parameter cannot be used for decryption. |

## Remarks

The *pbInput* and *pbOutput* parameters can point to the same buffer. In this case, this function will perform the decryption in place.

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.

## See also

[NCryptEncrypt](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptencrypt)