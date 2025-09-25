# IUrlAccessor3::GetImpersonationSidBlobs

## Description

Retrieves an array of user security identifiers (SIDs) for a specified URL. This method enables protocol handlers to specify which users can access the file and the search protocol host to impersonate a user in order to index the file.

## Parameters

### `pcwszURL` [in]

Type: **LPCWSTR**

The URL to access on behalf of an impersonated user.

### `pcSidCount` [out]

Type: **DWORD***

Receives a pointer to the number of user SIDs returned in *ppSidBlobs*.

### `ppSidBlobs` [out]

Type: **BLOB****

Receives the address of a pointer to the array of candidate impersonation user SIDs.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the file is encrypted, this method identifies who can both decrypt and access it. If the method cannot identify this information, it fails with error code E_ACCESSDENIED.

This method assumes that the [IUrlAccessor2](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iurlaccessor2) object failed to initialize and returned the code [PRTH_S_TRY_IMPERSONATING](https://learn.microsoft.com/windows/desktop/search/-search-prth-error-constants). Then, the search protocol host calls this method to retrieve a list of SIDs to use for impersonation and reverts to using **IUrlAccessor2**, impersonating one of the allowed users when opening the item.

Impersonating a user does not elevate the caller's privileges. If the caller cannot directly retrieve the list of users authorized to access a resource, the caller won't be able to do that with this method, either. Only the search protocol host and the indexer have adequate privileges to impersonate users currently logged on.

## See also

[IUrlAccessor3](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iurlaccessor3)

[IUrlAccessor4](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iurlaccessor4)

[Search Protocol Handler Error Messages](https://learn.microsoft.com/windows/desktop/search/-search-prth-error-constants)