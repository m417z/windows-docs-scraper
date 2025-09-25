# RxNameCacheCreateEntry function

## Description

**RxNameCacheCreateEntry** allocates and initializes a NAME_CACHE structure with the given name string.

## Parameters

### `NameCacheCtl` [in]

A pointer to the NAME_CACHE_CONTROL structure from which to allocate the entry.

### `Name` [in]

A pointer to the Unicode name string with which to initialize the name cache entry.

### `CaseInsensitive` [in]

A Boolean value that indicates if case insensitive comparisons should be used when comparing the *Name* parameter.

## Return value

**RxNameCacheCreateEntry** returns a pointer to the newly allocated NAME_CACHE structure on success or a **NULL** pointer if the allocation fails.

## Remarks

A network mini-redirector calls **RxNameCacheCreateEntry** to allocate and initialize a NAME_CACHE structure with the given name string. It is expected that the caller will then initialize any additional network mini-redirector elements of the name cache context, set the lifetime (in seconds) and the **Context** member of the NAME_CACHE structure and then put the entry on the name cache active list by calling **RxNameCacheActivateEntry**.

**RxNameCacheCreateEntry** will first attempt to reuse a NAME_CACHE entry on the free list, if one is available, before allocating a new NAME_CACHE entry.

## See also

[RxNameCacheActivateEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheactivateentry)

[RxNameCacheCheckEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachecheckentry)

[RxNameCacheExpireEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheexpireentry)

[RxNameCacheExpireEntryWithShortName](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheexpireentrywithshortname)

[RxNameCacheFetchEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefetchentry)

[RxNameCacheFinalize](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefinalize)

[RxNameCacheFreeEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefreeentry)

[RxNameCacheInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheinitialize)