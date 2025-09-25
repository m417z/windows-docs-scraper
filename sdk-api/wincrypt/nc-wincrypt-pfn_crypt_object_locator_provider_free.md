# PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE callback function

## Description

The **PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE** callback function releases the object returned by the provider.

## Parameters

### `pPluginContext` [in, optional]

Pointer to an optional buffer defined by this provider and returned by the [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_initialize) function. The buffer is not modified by the caller. Your provider can use the data to help it determine what actions to perform or to maintain additional information.

### `pbData` [in]

Pointer to the buffer to release.

## Remarks

The **PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE** function is currently called by only the Secure Channel (Schannel) security package. Schannel calls [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_get) to retrieve an object and then calls **PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE** to remove the data returned by the **PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET** call from memory when it is no longer required.

## See also

[CRYPT_OBJECT_LOCATOR_PROVIDER_TABLE](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_object_locator_provider_table)

[PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_get)

[PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_initialize)