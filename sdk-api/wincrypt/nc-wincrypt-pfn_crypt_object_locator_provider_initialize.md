# PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE callback function

## Description

The **PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE** function initializes the provider. You must implement this function as part of your custom provider.

## Parameters

### `pfnFlush` [in]

Pointer to the [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_flush) function implementation.

### `pContext` [in]

Pointer to a provider defined object that contains information about the provider and the objects.

### `pdwExpectedObjectCount` [out]

Specifies the number of unique objects that the provider expects to locate. This value tells the caller how much memory to allocate for storing objects. Set this value to zero (0) to specify the default value of 10,000 objects.

### `ppFuncTable` [out]

A [CRYPT_OBJECT_LOCATOR_PROVIDER_TABLE](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_object_locator_provider_table) structure that contains pointers to the functions implemented by the provider. No pointers in the table can be **NULL**. The caller does not free this structure. It is expected that the provider will return a table that is not allocated on the heap.

#### - **ppPluginContext [out]

Pointer to an optional buffer defined by this provider. The buffer is not modified by the caller. Your provider can use the data to help it determine what actions to perform or to maintain additional information. This value may be set to **NULL**.

### `ppPluginContext` [out]

Pointer to an optional buffer defined by this provider. The buffer is not modified by the caller. Your provider can use the data to help it determine what actions to perform or to maintain additional information. This value may be set to **NULL**.

## Return value

If the function succeeds, return nonzero (**TRUE**).

If the function fails, return zero (**FALSE**) and specify an appropriate error in the [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) function. Most errors are passed through Schannel unaltered but this behavior is not guaranteed. Some errors may be mapped to other errors.

## Remarks

 The **PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE** function is currently called by only the Secure Channel (Schannel) security service provider (SSP). The Cryptography API (CAPI) will internally call your custom provider if, beginning with Windows 8, you specify the name of the security principal in the *pszPrincipal* parameter of the [AcquireCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea) function.

When you implement this function, remember to fill the [CRYPT_OBJECT_LOCATOR_PROVIDER_TABLE](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_object_locator_provider_table) function table with pointers to the following functions implemented by your provider:

* [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_get)
* [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_RELEASE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_release)
* [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_PASSWORD](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_free_password)
* [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_free)
* [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_free_identifier)

You must call [CryptRegisterDefaultOIDFunction](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptregisterdefaultoidfunction) to register the provider in the Windows registry.

## See also

[CRYPT_OBJECT_LOCATOR_PROVIDER_TABLE](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_object_locator_provider_table)

[PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_flush)