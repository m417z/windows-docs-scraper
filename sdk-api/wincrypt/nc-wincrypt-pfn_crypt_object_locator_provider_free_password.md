# PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_PASSWORD callback function

## Description

The **PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_PASSWORD** callback function releases the password used to encrypt a personal information exchange (PFX) byte array.

## Parameters

### `pPluginContext` [in, optional]

Pointer to an optional buffer defined by this provider and returned by the [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_initialize) function. The buffer is not modified by the caller. Your provider can use the data to help it determine what actions to perform or to maintain additional information.

### `pwszPassword` [in]

Null-terminated Unicode string that contains the password.

## Remarks

The **PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_PASSWORD** function is currently called by only the Secure Channel (Schannel) security package. Schannel calls [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_get) to retrieve a PFX byte array and then calls **PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_PASSWORD** after the byte array has been processed but before calling the [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_free_identifier) function.

## See also

[CRYPT_OBJECT_LOCATOR_PROVIDER_TABLE](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_object_locator_provider_table)

[PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_get)

[PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_initialize)