# RxNameCacheFetchEntry function

## Description

**RxNameCacheFetchEntry** looks for a match with a specified name string for a NAME_CACHE entry.

## Parameters

### `NameCacheCtl` [in]

A pointer to the NAME_CACHE_CONTROL structure to scan.

### `Name` [in]

A pointer to the Unicode string that contains the name to match.

## Return value

**RxNameCacheFetchEntry** returns a pointer to the matching NAME_CACHE structure if a match was found, or **NULL** if the match failed.

## Remarks

**RxNameCacheFetchEntry** looks for a match in the name cache active list for the specified *Name* parameter. If the name is found, the entry is removed from the name cache active list and a pointer to the NAME_CACHE structure is returned. Otherwise, **NULL** is returned.

The NAME_CACHE entry is removed from the active list to avoid possible problems with another thread that is trying to update the same entry, or observing that it expired and putting it on the free list. It is possible to get multiple entries with the same name by different threads, but eventually they will expire.

If a matching NAME_CACHE entry is found, no check is made for expiration. The caller must check for expiration because it might want to take some special action.

As a side effect as the name cache active list is scanned, any non-matching entries that have expired are put on the free list. The name cache lock is acquired to protect this operation.

## See also

[RxNameCacheActivateEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheactivateentry)

[RxNameCacheCheckEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachecheckentry)

[RxNameCacheCreateEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachecreateentry)

[RxNameCacheExpireEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheexpireentry)

[RxNameCacheExpireEntryWithShortName](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheexpireentrywithshortname)

[RxNameCacheFinalize](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefinalize)

[RxNameCacheFreeEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefreeentry)

[RxNameCacheInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheinitialize)