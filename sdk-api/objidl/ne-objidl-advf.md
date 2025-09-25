# ADVF enumeration

## Description

Flags that control caching and notification of changes in data.

## Constants

### `ADVF_NODATA:1`

For data advisory connections ([IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise) or [IDataAdviseHolder::Advise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataadviseholder-advise)), this flag requests the data object not to send data when it calls [IAdviseSink::OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange). The recipient of the change notification can later request the data by calling [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata). The data object can honor the request by passing TYMED_NULL in the STGMEDIUM parameter, or it can provide the data anyway. For example, the data object might have multiple advisory connections, not all of which specified ADVF_NODATA, in which case the object might send the same notification to all connections. Regardless of the container's request, its [IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink) implementation must check the STGMEDIUM parameter because it is responsible for releasing the medium if it is not TYMED_NULL.

For cache connections ([IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache)), this flag requests that the cache not be updated by changes made to the running object. Instead, the container will update the cache by explicitly calling [IOleCache::SetData](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-setdata). This situation typically occurs when the iconic aspect of an object is being cached.

ADVF_NODATA is not a valid flag for view advisory connections ([IViewObject::SetAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-setadvise)) and it returns E_INVALIDARG.

### `ADVF_PRIMEFIRST:2`

Requests that the object not wait for the data or view to change before making an initial call to [IAdviseSink::OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange) (for data or view advisory connections) or updating the cache (for cache connections). Used with ADVF_ONLYONCE, this parameter provides an asynchronous [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) call.

### `ADVF_ONLYONCE:4`

Requests that the object make only one change notification or cache update before deleting the connection.

ADVF_ONLYONCE automatically deletes the advisory connection after sending one data or view notification. The advisory sink receives only one [IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink) call. A nonzero connection identifier is returned if the connection is established, so the caller can use it to delete the connection prior to the first change notification.

For data change notifications, the combination of ADVF_ONLYONCE and ADVF_PRIMEFIRST provides, in effect, an asynchronous [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) call.

When used with caching, ADVF_ONLYONCE updates the cache one time only, on receipt of the first [IAdviseSink::OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange) notification. After the update is complete, the advisory connection between the object and the cache is disconnected. The source object for the advisory connection calls the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

### `ADVF_DATAONSTOP:64`

For data advisory connections, assures accessibility to data. This flag indicates that when the data object is closing, it should call , providing data with the call. Typically, this value is used in combination with ADVF_NODATA. Without th[IAdviseSink::OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange) is value, by the time an **OnDataChange** call without data reaches the sink, the source might have completed its shutdown and the data might not be accessible. Sinks that specify this value should accept data provided in **OnDataChange** if it is being passed, because they may not get another chance to retrieve it.

For cache connections, this flag indicates that the object should update the cache as part of object closure.

ADVF_DATAONSTOP is not a valid flag for view advisory connections.

### `ADVFCACHE_NOHANDLER:8`

Synonym for ADVFCACHE_FORCEBUILTIN, which is used more often.

### `ADVFCACHE_FORCEBUILTIN:16`

This value is used by DLL object applications and object handlers that perform the drawing of their objects. ADVFCACHE_FORCEBUILTIN instructs OLE to cache presentation data to ensure that there is a presentation in the cache. This value is not a valid flag for data or view advisory connections. For cache connections, this flag caches data that requires only code shipped with OLE (or the underlying operating system) to be present in order to produce it with [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) or [IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw). By specifying this value, the container can ensure that the data can be retrieved even when the object or handler code is not available.

### `ADVFCACHE_ONSAVE:32`

For cache connections, this flag updates the cached representation only when the object containing the cache is saved. The cache is also updated when the OLE object transitions from the running state back to the loaded state (because a subsequent save operation would require rerunning the object). This value is not a valid flag for data or view advisory connections.

## Remarks

For a data or view advisory connection, the container uses the **ADVF** constants when setting up a connection between an [IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink) instance and either an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) or [IViewObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject) instance. These connections are set up using the [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise), [IDataAdviseHolder::Advise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataadviseholder-advise), or [IViewObject::SetAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-setadvise) methods.

For a caching connection, the constants are specified in the [IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache) method to indicate the container's requests on how the object should update its cache.

These constants are also used in the **advf** member of the [STATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statdata) structure. This structure is used by [IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata) to describe the enumerated connections, and the **advf** member indicates the flags that were specified when the advisory or cache connection was established. When **STATDATA** is used for an [IOleObject::EnumAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumadvise) enumerator, the **advf** member is indeterminate.

## See also

[IDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataadviseholder)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata)

[IOleCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache)

[IViewObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject)