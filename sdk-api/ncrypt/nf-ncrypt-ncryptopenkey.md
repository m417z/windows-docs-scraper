# NCryptOpenKey function

## Description

The **NCryptOpenKey** function opens a key that exists in the specified CNG key storage provider.

## Parameters

### `hProvider` [in]

The handle of the key storage provider to open the key from.

### `phKey` [out]

A pointer to a **NCRYPT_KEY_HANDLE** variable that receives the key handle. When you have finished using this handle, release it by passing it to the [NCryptFreeObject](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptfreeobject) function.

### `pszKeyName` [in]

A pointer to a null-terminated Unicode string that contains the name of the key to retrieve.

### `dwLegacyKeySpec` [in]

A legacy identifier that specifies the type of key. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **AT_KEYEXCHANGE** | The key is a key exchange key. |
| **AT_SIGNATURE** | The key is a signature key. |
| 0 | The key is none of the above types. |

### `dwFlags` [in]

Flags that modify function behavior. This can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **NCRYPT_MACHINE_KEY_FLAG** | Open the key for the local computer. If this flag is not present, the current user key is opened. |
| **NCRYPT_SILENT_FLAG** | Requests that the key storage provider (KSP) not display any user interface. If the provider must display the UI to operate, the call fails and the KSP should set the **NTE_SILENT_CONTEXT** error code as the last error. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter contains a value that is not valid. |
| **NTE_BAD_KEYSET** | The specified key was not found. |
| **NTE_INVALID_HANDLE** | The *hProvider* parameter is not valid. |
| **NTE_INVALID_PARAMETER** | One or more parameters are not valid. |
| **NTE_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.

For performance reasons, Microsoft software-based KSPs cache private key material in the Local Security Authority (LSA) for as long as a handle to the key is open. The LSA is a privileged system process. Therefore, other users cannot access this cached copy of the key unless the user possesses administrator privileges on the system. This behavior cannot be altered through configuration.