# IOleCache2::DiscardCache

## Description

Discards the caches found in memory.

## Parameters

### `dwDiscardOptions` [in]

A value from the [DISCARDCACHE](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-discardcache) enumeration that indicates whether data is to be saved prior to being discarded. Containers that have drawn a large object and need to free up memory can specify DISCARDCACHE_SAVEIFDIRTY so that the newest presentation is saved for the next time the object must be drawn.

Containers that have activated an embedded object, made some changes, and then called [IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close) with OLECLOSE_NOSAVE to roll back the changes can specify DISCARDCACHE_NOSAVE to ensure that the native and presentation data are not out of synchronization.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_NOSTORAGE** | There is no storage available for saving the data in the cache. |
| **STG_E_MEDIUMFULL** | The storage medium is full. |

## Remarks

The **IOleCache2::DiscardCache** method is commonly used to handle low memory conditions by freeing memory currently being used by presentation caches.

After it is discarded, a cache will satisfy subsequent [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) calls by reverting to disk-based data.

## See also

[IOleCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache)

[IOleCache2](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache2)

[IOleCacheControl](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecachecontrol)