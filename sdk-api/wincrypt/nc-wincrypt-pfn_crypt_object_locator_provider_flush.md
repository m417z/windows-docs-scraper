# PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH callback function

## Description

The **PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH** callback function specifies that an object has changed. The provider calls this function when the provider has determined that a particular name or identifier has been updated.

## Parameters

### `pContext` [in]

Pointer to a provider defined object that contains information about this provider.

### `rgIdentifierOrNameList` [in]

Pointer to an array of names or identifiers.

### `dwIdentifierOrNameListCount` [in]

The number of names or identifiers specified by the *rgIdentifierOrNameList* parameter.

## Return value

If the function succeeds, return nonzero (**TRUE**).

If the function fails, return zero (**FALSE**).

## Remarks

A provider calls an implementation of the **PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH** callback function to indicate that an object has changed.

A pointer to this function is set in the *pfnFlush* parameter of the [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_initialize) function.

An identifier is data chosen by the provider to represent the object being located for the caller. Identifiers need not be unique. If the provider determines that the object associated with the identifier is no longer valid, it should call this function to mark all objects with the associated identifier as invalid. This function is thread safe.

## See also

[PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_initialize)