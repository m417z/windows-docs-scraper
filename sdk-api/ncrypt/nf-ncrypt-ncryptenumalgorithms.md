# NCryptEnumAlgorithms function

## Description

The **NCryptEnumAlgorithms** function obtains the names of the algorithms that are supported by the specified key storage provider.

## Parameters

### `hProvider` [in]

The handle of the key storage provider to enumerate the algorithms for. This handle is obtained with the [NCryptOpenStorageProvider](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenstorageprovider) function.

### `dwAlgOperations` [in]

A set of values that determine which algorithm classes to enumerate. This can be zero or a combination of one or more of the following values. If *dwAlgOperations* is zero, all algorithms are enumerated.

| Value | Meaning |
| --- | --- |
| **NCRYPT_CIPHER_OPERATION**<br><br>0x00000001 | Enumerate the cipher (symmetric encryption) algorithms. |
| **NCRYPT_HASH_OPERATION**<br><br>0x00000002 | Enumerate the hashing algorithms. |
| **NCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION**<br><br>0x00000004 | Enumerate the asymmetric encryption algorithms. |
| **NCRYPT_SECRET_AGREEMENT_OPERATION**<br><br>0x00000008 | Enumerate the secret agreement algorithms. |
| **NCRYPT_SIGNATURE_OPERATION**<br><br>0x00000010 | Enumerate the digital signature algorithms. |

### `pdwAlgCount` [out]

The address of a **DWORD** that receives the number of elements in the *ppAlgList* array.

### `ppAlgList` [out]

The address of an [NCryptAlgorithmName](https://learn.microsoft.com/windows/desktop/api/ncrypt/ns-ncrypt-ncryptalgorithmname) structure pointer that receives an array of the registered algorithm names. The variable pointed to by the *pdwAlgCount* parameter receives the number of elements in this array.

When this memory is no longer needed, it must be freed by passing this pointer to the [NCryptFreeBuffer](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptfreebuffer) function.

### `dwFlags` [in]

Flags that modify function behavior. This can be zero (0) or the following value.

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
| **NTE_INVALID_HANDLE** | The *hProvider* parameter is not valid. |
| **NTE_INVALID_PARAMETER** | One or more parameters are not valid. |
| **NTE_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.