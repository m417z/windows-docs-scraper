# IOfflineFilesItem::IsMarkedForDeletion

## Description

Determines whether an item has been deleted from the Offline Files cache.

## Parameters

### `pbMarkedForDeletion` [out]

Receives **TRUE** if the item has been deleted, or **FALSE** otherwise.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

Due to internal (in-memory) caching of data structures in the remote file system and the CSC driver, deletion of an item might not remove the item from the cache immediately. An item is first marked for deletion then, after all handles have closed, the item is removed from the cache. This behavior is most apparent for share items.

Clients should normally treat such items as if they do not exist in the cache.

## See also

[IOfflineFilesItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitem)