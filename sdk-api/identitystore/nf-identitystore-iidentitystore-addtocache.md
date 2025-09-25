# IIdentityStore::AddToCache

## Description

The **AddtoCache** method caches the specified identity in the registry.

## Parameters

### `lpszUniqueID` [in]

The identity to cache.

### `ProviderGUID` [in]

The identity provider associated with the identity.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IIdentityStore](https://learn.microsoft.com/windows/desktop/api/identitystore/nn-identitystore-iidentitystore)