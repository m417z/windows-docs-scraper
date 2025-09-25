# IOleCache::InitCache

## Description

Fills the cache as needed using the data provided by the specified data object.

## Parameters

### `pDataObject` [in]

A pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data object from which the cache is to be initialized.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface is invalid. |
| **E_OUTOFMEMORY** | Insufficient memory is available for the operation. |
| **OLE_E_NOTRUNNING** | The cache is not running. |
| **CACHE_E_NOCACHE_UPDATED** | None of the caches were updated. |
| **CACHE_S_SOMECACHES_NOTUPDATED** | Only some of the existing caches were updated. |

## Remarks

**InitCache** is usually used when creating an object from a drag-and-drop operation or from a clipboard paste operation. It fills the cache as needed with presentation data from all the data formats provided by the data object provided on the clipboard or in the drag-and-drop operation. Helper functions like [OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata) or [OleCreateLinkFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelinkfromdata) call this method when needed. If a container does not use these helper functions to create compound document objects, it can use [IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache) to set up the cache entries which are then filled by **InitCache**.

## See also

[IOleCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache)

[IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache)