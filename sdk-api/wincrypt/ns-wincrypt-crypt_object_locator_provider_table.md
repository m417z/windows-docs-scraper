# CRYPT_OBJECT_LOCATOR_PROVIDER_TABLE structure

## Description

The **CRYPT_OBJECT_LOCATOR_PROVIDER_TABLE** structure contains pointers to functions implemented by an object location provider. This structure is used by the [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_initialize) callback function.

## Members

### `cbSize`

Size, in bytes, of this structure.

### `pfnGet`

Pointer to the [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_get) function implemented by the provider.

### `pfnRelease`

Pointer to the [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_RELEASE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_release) function implemented by the provider.

### `pfnFreePassword`

Pointer to the [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_PASSWORD](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_free_password) function implemented by the provider.

### `pfnFree`

Pointer to the [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_free) function implemented by the provider.

### `pfnFreeIdentifier`

Pointer to the [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_free_identifier) function implemented by the provider.

## Remarks

No pointers in this table can be **NULL**. The client application does not free this structure. It is expected that the provider will return a table that is not allocated on the heap.

## See also

[PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_initialize)