# IOleCache2::UpdateCache

## Description

Updates the specified caches. This method is used when the application needs precise control over caching.

## Parameters

### `pDataObject` [in]

A pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data object from which the cache is updated. Object handlers and in-process servers typically pass a non-**NULL** value. A container application usually passes **NULL**, and the source is obtained from the currently running object.

### `grfUpdf` [in]

The type of cache to be updated. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **UPDFCACHE_NODATACACHE** | Updates caches created by using ADVF_NODATA in the call to [IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache). |
| **UPDFCACHE_ONSAVECACHE** | Updates caches created by using ADVFCACHE_ONSAVE in the call to [IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache). |
| **UPDFCACHE_ONSTOPCACHE** | Updates caches created by using ADVFCACHE_ONSTOP in the call to [IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache). |
| **UPDFCACHE_NORMALCACHE** | Dynamically updates the caches (as is normally done when the object sends out [OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange) notices). |
| **UPDFCACHE_IFBLANK** | Updates the cache if blank, regardless of any other flag specified. |
| **UPDFCACHE_ONLYIFBLANK** | Updates only caches that are blank. |
| **UPDFCACHE_ IFBLANKORONSAVECACHE** | The equivalent of using an OR operation to combine UPDFCACHE_IFBLANK and UPDFCACHE_ONSAVECACHE. |
| **UPDFCACHE_ALL** | Updates all caches. |
| **UPDFCACHE_ ALLBUTNODATACACHE** | Updates all caches except those created with ADVF_NODATA in the call to [IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache). Thus, you can control updates to the caches created with the ADVF_NODATA flag and only update these caches explicitly. |

### `pReserved` [in]

This parameter is reserved and must be **NULL**.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the arguments is not valid. |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_OUTOFMEMORY** | Insufficient memory is available for this operation. |
| **OLE_E_NOTRUNNING** | The specified *pDataObject* is not running. |
| **CACHE_E_NOCACHE_UPDATED** | None of the caches were updated. |
| **CACHE_S_SOMECACHES_NOTUPDATED** | Some of the caches were updated. |

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IOleCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache)

[IOleCache2](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache2)

[IOleCacheControl](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecachecontrol)