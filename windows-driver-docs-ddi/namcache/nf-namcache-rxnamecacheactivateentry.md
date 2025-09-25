# RxNameCacheActivateEntry function

## Description

**RxNameCacheActivateEntry** takes a name cache entry and updates the expiration time and the network mini-redirector context. It then puts the name cache entry on the active list.

## Parameters

### `NameCacheCtl` [in]

A pointer to the NAME_CACHE_CONTROL structure on which to activate the entry.

### `NameCache` [in]

A pointer to the NAME_CACHE structure to activate.

### `LifeTime` [in]

A value that indicates the valid lifetime in seconds of the cache entry. A value of 0 means to leave the current value unchanged. A value of 0 is used for reactivations after a match where you want the original lifetime preserved.

### `MRxContext` [in]

A value of context supplied by the network mini-redirector for equality checking when making a valid entry check. An *MRxContext* value of 0 means to leave the current value unchanged. A value of 0 is used for reactivations after a match where you want the original *MRxContext* preserved.

## Remarks

The **RxNameCacheActivateEntry** routine is normally called after a network mini-redirector calls **RxNameCacheCreateEntry** to allocate and initialize a NAME_CACHE structure with the given name string. It is expected that the caller will then initialize any additional network mini-redirector elements of the name cache context, such as *Lifetime* (in seconds) and *MRxContext*, and then put the entry on the name cache active list by calling **RxNameCacheActivateEntry**.

The **RxNameCacheActivateEntry** routine assumes that the name cache entry is not on either the free or active list.

## See also

[RxNameCacheCheckEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachecheckentry)

[RxNameCacheCreateEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachecreateentry)

[RxNameCacheExpireEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheexpireentry)

[RxNameCacheExpireEntryWithShortName](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheexpireentrywithshortname)

[RxNameCacheFetchEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefetchentry)

[RxNameCacheFinalize](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefinalize)

[RxNameCacheFreeEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefreeentry)

[RxNameCacheInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheinitialize)