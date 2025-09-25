# IOfflineFilesShareInfo::GetShareCachingMode

## Description

Retrieves the caching mode configuration of the closest ancestor share to the item.

## Parameters

### `pCachingMode` [out]

Receives a value from the [OFFLINEFILES_CACHING_MODE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_caching_mode) enumeration that indicates the caching mode.

The following values can be returned:

#### OFFLINEFILES_CACHING_MODE_NONE (0)

No caching mode value was found. This value can be returned if the method fails.

#### OFFLINEFILES_CACHING_MODE_NOCACHING (1)

The share is configured to disallow caching. This value corresponds to a value of zero returned by the [NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo) function for the **CSC_MASK** portion of the [SHARE_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1005) structure.

#### OFFLINEFILES_CACHING_MODE_MANUAL (2)

The share is configured to allow manual caching. This value corresponds to a value of **CSC_CACHE_MANUAL_REINT** returned by the [NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo) function for the CSC_MASK portion of the [SHARE_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1005) structure.

#### OFFLINEFILES_CACHING_MODE_AUTO_DOC (3)

The share is configured to allow automatic caching of documents. This value corresponds to a value of **CSC_CACHE_AUTO_REINT** returned by the [NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo) function for the **CSC_MASK** portion of the [SHARE_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1005) structure.

#### OFFLINEFILES_CACHING_MODE_AUTO_PROGANDDOC (4)

The share is configured to allow automatic caching of programs and documents. This value corresponds to a value of **CSC_CACHE_VDO** (virtual disconnected operations) returned by the [NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo) function for the **CSC_MASK** portion of the [SHARE_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1005) structure.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

This method is equivalent to locating the nearest share item, obtaining its fully qualified UNC path and calling [NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo) for [SHARE_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1005) information.

## See also

[IOfflineFilesCache::IsPathCacheable](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-ispathcacheable)

[IOfflineFilesShareInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesshareinfo)