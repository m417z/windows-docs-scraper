# RxNameCacheExpireEntry function

## Description

**RxNameCacheExpireEntry** puts a NAME_CACHE entry on the free list for recycling.

## Parameters

### `NameCacheCtl` [in]

A pointer to the NAME_CACHE_CONTROL structure on which to expire the entry.

### `NameCache` [in]

A pointer to the NAME_CACHE structure to expire.

## Remarks

The **RxNameCacheExpireEntry** routine assumes that the name cache entry is not on the active or free list. This routine inserts the *NameCache* entry at the head of the free list and subtracts one from the **NumberActivates** member of the NAME_CACHE_CONTROL structure pointed to by *NameCacheCtl* to update statistics.

## See also

[RxNameCacheActivateEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheactivateentry)

[RxNameCacheCheckEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachecheckentry)

[RxNameCacheCreateEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachecreateentry)

[RxNameCacheExpireEntryWithShortName](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheexpireentrywithshortname)

[RxNameCacheFetchEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefetchentry)

[RxNameCacheFinalize](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefinalize)

[RxNameCacheFreeEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefreeentry)

[RxNameCacheInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheinitialize)