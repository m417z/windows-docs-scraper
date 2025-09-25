# IOleCache::Cache

## Description

Specifies the format and other data to be cached inside an embedded object.

## Parameters

### `pformatetc` [in]

A pointer to a [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure that specifies the format and other data to be cached. View caching is specified by passing a zero clipboard format in *pformatetc*.

### `advf` [in]

A group of flags that control the caching. Possible values come from the [ADVF](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-advf) enumeration. When used in this context, for a cache, these values have specific meanings, which are outlined in Remarks. Refer to the **ADVF** enumeration for a more detailed description.

### `pdwConnection` [out]

A pointer to a variable that receives the identifier of this connection, which can later be used to turn caching off (by passing it to [IOleCache::Uncache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-uncache)). If this value is 0, the connection was not established. The OLE-provided implementation uses nonzero numbers for connection identifiers.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The supplied *pformatetc* or *advf* arguments are not valid. |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_OUTOFMEMORY** | Insufficient memory available for the operation. |
| **CACHE_S_FORMATETC_NOTSUPPORTED** | The cache was created, but the object application does not support the specified format. Cache creation succeeds even if the format is not supported, allowing the caller to fill the cache. If, however, the caller does not need to keep the cache, call [IOleCache::Uncache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-uncache). |
| **CACHE_S_SAMECACHE** | A cache already exists for the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) passed to [IOleCache::Uncache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-uncache). In this case, the new advise flags are assigned to the cache, and the previously assigned connection identifier is returned. |
| **DV_E_LINDEX** | Invalid value for *pformatetc*->**lindex**; currently only -1 is supported. |
| **DV_E_TYMED** | The value is not valid for *pformatetc*->**tymed**. |
| **DV_E_DVASPECT** | The value is not valid for *pformatetc*->**dwAspect**. |
| **DV_E_CLIPFORMAT** | The value is not valid for *pformatetc*->**cfFormat**. |
| **CO_E_NOTINITIALIZED** | The cache's storage is not initialized. |
| **DV_E_DVTARGETDEVICE** | The value is not valid for *pformatetc-*->**ptd**. |
| **OLE_E_STATIC** | The cache is for a static object and it already has a cache node. |

## Remarks

**IOleCache::Cache** can specify either data caching or view (presentation) caching. To specify data caching, a valid data format must be passed in *pformatetc*. For view caching, the cache object itself decides on the format to cache, so a caller would pass a zero data format in *pformatetc* as follows:

``` syntax
pFormatetc->cfFormat == 0
```

A custom object handler can choose not to store data in a given format. Instead, it can synthesize it on demand when requested.

The *advf* value specifies a member of the [ADVF](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-advf) enumeration. When one of these values (or an OR'd combination of more than one value) is used in this context, these values mean the following.

| ADVF Value | Description |
| --- | --- |
| ADVF_NODATA | The cache is not to be updated by changes made to the running object. Instead, the container will update the cache by explicitly calling [IOleCache::SetData](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-setdata), [IDataObject::SetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-setdata), or [IOleCache2::UpdateCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache2-updatecache). This flag is usually used when the iconic aspect of an object is being cached. |
| ADVF_ONLYONCE | Update the cache one time only. After the update is complete, the advisory connection between the object and the cache is disconnected. The source object for the advisory connection calls the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method. |
| ADVF_PRIMEFIRST | The object is not to wait for the data or view to change before updating the cache. OR'd with ADVF_ONLYONCE, this parameter provides an asynchronous [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) call. |
| ADVFCACHE_NOHANDLER | Synonym for ADVFCACHE_FORCEBUILTIN. |
| ADVFCACHE_FORCEBUILTIN | Used by DLL object applications and object handlers that draw their objects to cache presentation data to ensure that there is a presentation in the cache. This ensures that the data can be retrieved even when the object or handler code is not available. |
| ADVFCACHE_ONSAVE | Updates the cached representation only when the object containing the cache is saved. The cache is also updated when the OLE object changes from the running state back to the loaded state (because a subsequent save operation would require running the object again). |

## See also

[IOleCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache)

[IOleCache::Uncache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-uncache)