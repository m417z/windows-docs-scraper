# RxNameCacheCheckEntry function

## Description

**RxNameCacheCheckEntry** checks a name cache entry for validity. A valid entry means that the lifetime has not expired and the *MRxContext* parameter passes the equality check.

## Parameters

### `NameCache` [in]

A pointer to the NAME_CACHE structure to check.

### `MRxContext` [in]

A value of context supplied by the network mini-redirector for equality checking when making a valid entry check.

## Return value

**RxNameCacheCheckEntry** returns one of the possible enumeration values defined for **RX_NC_CHECK_STATUS**:

| Return code | Description |
| --- | --- |
| **RX_NC_SUCCESS** | The check was successful and the entry is valid. |
| **RX_NC_TIME_EXPIRED** | The check failed because the lifetime has expired. |
| **RX_NC_MRXCTX_FAIL** | The check failed because *MRxContext* failed equality checking. |

## See also

[RxNameCacheActivateEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheactivateentry)

[RxNameCacheCreateEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachecreateentry)

[RxNameCacheExpireEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheexpireentry)

[RxNameCacheExpireEntryWithShortName](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheexpireentrywithshortname)

[RxNameCacheFetchEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefetchentry)

[RxNameCacheFinalize](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefinalize)

[RxNameCacheFreeEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecachefreeentry)

[RxNameCacheInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/namcache/nf-namcache-rxnamecacheinitialize)