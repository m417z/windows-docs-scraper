# NCryptOpenStorageProvider function

## Description

The **NCryptOpenStorageProvider** function loads and initializes a CNG key storage provider.

## Parameters

### `phProvider` [out]

A pointer to a **NCRYPT_PROV_HANDLE** variable that receives the provider handle. When you have finished using this handle, release it by passing it to the [NCryptFreeObject](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptfreeobject) function.

### `pszProviderName` [in, optional]

A pointer to a null-terminated Unicode string that identifies the key storage provider to load. This is the registered alias of the key storage provider. This parameter is optional and can be **NULL**. If this parameter is **NULL**, the default key storage provider is loaded. The following values identify the built-in key storage providers.

| Value | Meaning |
| --- | --- |
| **MS_KEY_STORAGE_PROVIDER**<br><br>L"Microsoft Software Key Storage Provider" | Identifies the software key storage provider that is provided by Microsoft. |
| **MS_SMART_CARD_KEY_STORAGE_PROVIDER**<br><br>L"Microsoft Smart Card Key Storage Provider" | Identifies the smart card key storage provider that is provided by Microsoft. |
| **MS_PLATFORM_CRYPTO_PROVIDER**<br><br>L"Microsoft Platform Crypto Provider" | Identifies the TPM key storage provider that is provided by Microsoft. |

### `dwFlags` [in]

Flags that modify the behavior of the function. No flags are defined for this function.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter contains one or more flags that are not supported. |
| **NTE_INVALID_PARAMETER** | One or more parameters are not valid. |
| **NTE_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

In the case that an error condition is returned, the provider will have been unloaded from memory. Functions within the provider must not be called after a failure error is returned.

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.