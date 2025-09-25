# RxNameCacheFinalize function

## Description

**RxNameCacheFinalize** releases the storage for all of the NAME_CACHE entries associated with a NAME_CACHE_CONTROL structure.

## Parameters

### `NameCacheCtl` [in]

A pointer to the NAME_CACHE_CONTROL structure for the name cache.

## Remarks

The **RxNameCacheFinalize** routine acquires the lock on the name cache to scan the free list and remove entries from the active list.

On checked builds, this routine causes the system to ASSERT if after releasing all of the active and free entries a reference count still remains on the name cache. This indicates a memory leak where some caller did not call [RxNameCacheFreeEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefreeentry) when done with an entry.

## See also

[RxNameCacheActivateEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheactivateentry)

[RxNameCacheCheckEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachecheckentry)

[RxNameCacheCreateEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachecreateentry)

[RxNameCacheExpireEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheexpireentry)

[RxNameCacheExpireEntryWithShortName](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheexpireentrywithshortname)

[RxNameCacheFetchEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefetchentry)

[RxNameCacheFreeEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefreeentry)

[RxNameCacheInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheinitialize)