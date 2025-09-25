# RxNameCacheExpireEntryWithShortName function

## Description

**RxNameCacheExpireEntryWithShortName** expires all of the name cache entries whose name prefix matches the given short file name.

## Parameters

### `NameCacheCtl` [in]

A pointer to the NAME_CACHE_CONTROL structure to scan.

### `Name` [in]

A pointer to the Unicode string that contains the name prefix to scan for name cache entry matches to expire.

## Remarks

The **RxNameCacheExpireEntryWithShortName** routine scans the active list and inserts any matching NAME_CACHE entries at the head of the free list. The **CaseInsensitive** member of the NAME_CACHE entry is used to determine whether the scan should ignore case sensitivity when matching the *Name* parameter.

Because the active list is scanned, the **RxNameCacheExpireEntryWithShortName** routine puts any non-matching entries that have expired on the free list. A *Name* value of zero length will match all entries and insert the entries on the free list.

## See also

[RxNameCacheActivateEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheactivateentry)

[RxNameCacheCheckEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachecheckentry)

[RxNameCacheCreateEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachecreateentry)

[RxNameCacheExpireEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheexpireentry)

[RxNameCacheFetchEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefetchentry)

[RxNameCacheFinalize](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefinalize)

[RxNameCacheFreeEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefreeentry)

[RxNameCacheInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheinitialize)