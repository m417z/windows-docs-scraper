# IAzAuthorizationStore::UpdateCache

## Description

The **UpdateCache** method updates the cache of objects and object attributes to match the underlying policy store.

## Parameters

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

When the **UpdateCache** method is called, all changes to the persistent store after the last call to the [Initialize](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazauthorizationstore-initialize) method or to the **UpdateCache** method are incorporated into the cache. Any changes to the cache that have not been submitted using the [Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazauthorizationstore-submit) method override the changes to the store.

Most stores should be stable and have few changes. Providers are expected to implement this method to efficiently determine whether changes have been written to the physical store since the last update.

## See also

[Initialize](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazauthorizationstore-initialize)

[Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazauthorizationstore-submit)