# RxNameCacheFreeEntry function

## Description

**RxNameCacheFreeEntry** releases the storage for a NAME_CACHE entry and decrements the count of the NAME_CACHE cache entries associated with a NAME_CACHE_CONTROL structure.

## Parameters

### `NameCacheCtl` [in]

A pointer to the NAME_CACHE_CONTROL structure for the name cache.

### `NameCache` [in]

A pointer to the NAME_CACHE structure to free.

## Remarks

The **RxNameCacheFreeEntry** routine assumes that the name cache entry is not on either the free or active list.

The **RxNameCacheFreeEntry** routine frees memory allocated for the name buffer if the name buffer for this name cache entry is not **NULL**. This routine will then free memory used for the NAME_CACHE entry. Then, the count of name cache entries on *NameCacheCtl* is decremented.

## See also

[RxNameCacheActivateEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheactivateentry)

[RxNameCacheCheckEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachecheckentry)

[RxNameCacheCreateEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachecreateentry)

[RxNameCacheExpireEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheexpireentry)

[RxNameCacheExpireEntryWithShortName](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheexpireentrywithshortname)

[RxNameCacheFetchEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefetchentry)

[RxNameCacheFinalize](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefinalize)

[RxNameCacheInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheinitialize)