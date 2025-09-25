# OFFLINEFILES_CACHING_MODE enumeration

## Description

Describes the caching mode used in methods such as [IOfflineFilesCache::IsPathCacheable](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-ispathcacheable) and [IOfflineFilesShareInfo::GetShareCachingMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesshareinfo-getsharecachingmode).

## Constants

### `OFFLINEFILES_CACHING_MODE_NONE:0`

No caching mode value was found.

### `OFFLINEFILES_CACHING_MODE_NOCACHING`

The share or shared folder is configured to disallow caching.

### `OFFLINEFILES_CACHING_MODE_MANUAL`

The share or shared folder is configured to allow manual caching.

### `OFFLINEFILES_CACHING_MODE_AUTO_DOC`

The share or shared folder is configured to allow automatic caching of documents.

### `OFFLINEFILES_CACHING_MODE_AUTO_PROGANDDOC`

The share or shared folder is configured to allow automatic caching of programs and documents.

## See also

[IOfflineFilesCache::IsPathCacheable](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-ispathcacheable)

[IOfflineFilesShareInfo::GetShareCachingMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesshareinfo-getsharecachingmode)

[NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo)

[SHARE_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1005)