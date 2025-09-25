# RxNameCacheInitialize function

## Description

**RxNameCacheInitialize** initializes a name cache (NAME_CACHE_CONTROL structure).

## Parameters

### `NameCacheCtl` [in]

A pointer to the NAME_CACHE_CONTROL structure to initialize.

### `MRxNameCacheSize` [in]

The size, in bytes, of the network mini-redirector portion of the NAME_CACHE entry.

### `MaximumEntries` [in]

The maximum number of entries that will ever be allocated. This value prevents an errant program that opens a large number of files with bad names from using all of the paged pool memory.

## See also

[RxNameCacheActivateEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheactivateentry)

[RxNameCacheCheckEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachecheckentry)

[RxNameCacheCreateEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachecreateentry)

[RxNameCacheExpireEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheexpireentry)

[RxNameCacheExpireEntryWithShortName](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheexpireentrywithshortname)

[RxNameCacheFetchEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefetchentry)

[RxNameCacheFinalize](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefinalize)

[RxNameCacheFreeEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefreeentry)