# IOfflineFilesTransparentCacheInfo::IsTransparentlyCached

## Description

Determines whether the item is transparently cached.

## Parameters

### `pbTransparentlyCached` [out]

A pointer to a variable that receives **TRUE** if the item is transparently cached, or **FALSE** otherwise.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

A transparently cached item is cached locally. However, it can be accessed only when the server is available and the user is online with respect to that server. If the cached version of the file matches the correct version of the file on the server, requests to read data will be satisfied from the cache rather than requesting the data from the server.

## See also

[IOfflineFilesEvents3::TransparentCacheItemNotify](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents3-transparentcacheitemnotify)

[IOfflineFilesTransparentCacheInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilestransparentcacheinfo)