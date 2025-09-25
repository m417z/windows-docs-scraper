# NCryptIsAlgSupported function

## Description

The **NCryptIsAlgSupported** function determines if a CNG key storage provider supports a specific cryptographic algorithm.

## Parameters

### `hProvider` [in]

The handle of the key storage provider. This handle is obtained with the [NCryptOpenStorageProvider](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptopenstorageprovider) function.

### `pszAlgId` [in]

A pointer to a null-terminated Unicode string that identifies the cryptographic algorithm in question. This can be one of the standard [CNG Algorithm Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-algorithm-identifiers) or the identifier for another registered algorithm.

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
| **ERROR_SUCCESS** | The provider supports the specified algorithm. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter contains one or more flags that are not supported. |
| **NTE_INVALID_HANDLE** | The handle specified by the *hProvider* parameter is not valid. |
| **NTE_INVALID_PARAMETER** | One or more parameters are not valid. |
| **NTE_NOT_SUPPORTED** | The provider does not support the specified algorithm. |

## Remarks

If the provider supports the algorithm, this function returns **ERROR_SUCCESS**. If the provider does not support the algorithm, and no other errors occurred, this function returns **NTE_NOT_SUPPORTED**.

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.