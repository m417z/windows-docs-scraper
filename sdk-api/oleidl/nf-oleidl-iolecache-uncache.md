# IOleCache::Uncache

## Description

Removes a cache connection created previously using [IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache).

## Parameters

### `dwConnection` [in]

The cache connection to be removed. This nonzero value was returned by [IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache) when the cache was originally established.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_NOCONNECTION** | No cache connection exists for *dwConnection*. |

## Remarks

The **IOleCache::Uncache** method removes a cache connection that was created in a prior call to [IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache). It uses the *dwConnection* parameter that was returned by the prior call to **IOleCache::Cache**.

## See also

[IOleCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache)

[IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache)