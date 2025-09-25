# PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_RELEASE callback function

## Description

The **PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_RELEASE** callback function releases the provider.

## Parameters

### `dwReason` [in]

Specifies the reason the provider is being released. This can be one of the following values:

| Value | Meaning |
| --- | --- |
| **CRYPT_OBJECT_LOCATOR_RELEASE_SYSTEM_SHUTDOWN**<br><br>1 | The computer is shutting down. |
| **CRYPT_OBJECT_LOCATOR_RELEASE_SERVICE_STOP**<br><br>2 | The service is stopping. |
| **CRYPT_OBJECT_LOCATOR_RELEASE_PROCESS_EXIT**<br><br>3 | The calling process is ending. |
| **CRYPT_OBJECT_LOCATOR_RELEASE_DLL_UNLOAD**<br><br>4 | The provider DLL is unloading. |

### `pPluginContext` [in, optional]

Pointer to an optional buffer defined by this provider and returned by the [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_initialize) function. The buffer is not modified by the caller. Your provider can use the data to help it determine what actions to perform or to maintain additional information.

## Remarks

The **PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_RELEASE** callback function is currently called by only the Secure Channel (Schannel) security package. This function is called once for every call made to [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_initialize).

The provider is not expected to release all memory for all objects but should clean itself if the *dwReason* parameter is set to **CRYPT_OBJECT_LOCATOR_RELEASE_SERVICE_STOP** or **CRYPT_OBJECT_LOCATOR_RELEASE_DLL_UNLOAD**.

This function must block so that calls to [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_flush) can complete.

## See also

[CRYPT_OBJECT_LOCATOR_PROVIDER_TABLE](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_object_locator_provider_table)

[PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_initialize)