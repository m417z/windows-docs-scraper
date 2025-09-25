# IAzAuthorizationStore3::IsUpdateNeeded

## Description

The **IsUpdateNeeded** method checks whether the persisted version of this authorization store is newer than the cached version. If the cached version of the store is newer, the calling application can update the cached version by calling the [UpdateCache](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-updatecache) method of the [AzAuthorizationStore](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazauthorizationstore) object.

## Parameters

### `pbIsUpdateNeeded` [out]

**VARIANT_TRUE** if the persisted version of this authorization store is newer than the cached version; otherwise, **VARIANT_FALSE**.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).