# IOfflineFilesCache::IsPathCacheable

## Description

Determines whether a specified UNC path is in the Offline Files cache.

## Parameters

### `pszPath` [in]

The UNC path of the item.

### `pbCacheable` [out]

Receives **TRUE** if the item is in the Offline Files cache, **FALSE** if not.

### `pShareCachingMode` [out]

Receives one of the following [OFFLINEFILES_CACHING_MODE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_caching_mode) enumeration values indicating the caching configuration of the applicable network shared folder under which the specified item exists.

#### OFFLINEFILES_CACHING_MODE_NONE (0)

No caching mode value was found. This value is used when the item is not cacheable or an error has occurred.

#### OFFLINEFILES_CACHING_MODE_NOCACHING (1)

The shared folder is configured to disallow caching.

#### OFFLINEFILES_CACHING_MODE_MANUAL (2)

The shared folder is configured to allow manual caching.

#### OFFLINEFILES_CACHING_MODE_AUTO_DOC (3)

The shared folder is configured to allow automatic caching of documents.

#### OFFLINEFILES_CACHING_MODE_AUTO_PROGANDDOC (4)

The shared folder is configured to allow automatic caching of programs and documents.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

The caching mode value returned is equivalent to the **CSC_MASK** value associated with [SHARE_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1005) returned by [NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo). The value mapping is as follows:

| [OFFLINEFILES_CACHING_MODE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_caching_mode) Value | [SHARE_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1005) Value |
| --- | --- |
| **OFFLINEFILES_CACHING_MODE_NOCACHING** | 0 |
| **OFFLINEFILES_CACHING_MODE_MANUAL** | **CSC_CACHE_MANUAL_REINT** |
| **OFFLINEFILES_CACHING_MODE_AUTO_DOC** | **CSC_CACHE_AUTO_REINT** |
| **OFFLINEFILES_CACHING_MODE_AUTO_PROGANDDOC** | **CSC_CACHE_VDO** |

These settings are configured as attributes of the shared folder on the server by clicking the Caching button on the shared folder's Sharing property page or by using the `net share /cache` command.

## See also

[IOfflineFilesCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilescache)

[IOfflineFilesShareInfo::GetShareCachingMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesshareinfo-getsharecachingmode)

[OFFLINEFILES_CACHING_MODE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_caching_mode)