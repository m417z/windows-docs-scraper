# IOleCache::SetData

## Description

Initializes the cache with data in a specified format and on a specified medium.

## Parameters

### `pformatetc` [in]

A pointer to a [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure that specifies the format of the presentation data being placed in the cache.

### `pmedium` [in]

A pointer to a [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) structure that specifies the storage medium that contains the presentation data.

### `fRelease` [in]

Indicates the ownership of the storage medium after completion of the method. If *fRelease* is **TRUE**, the cache takes ownership, freeing the medium when it is finished using it. When *fRelease* is **FALSE**, the caller retains ownership and is responsible for freeing the medium. The cache can only use the storage medium for the duration of the call.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **DV_E_LINDEX** | The value is not valid for *pformatetc*->**lindex**. Currently, only -1 is supported. |
| **DV_E_FORMATETC** | The [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure is invalid. |
| **DV_E_TYMED** | The value is not valid for *pformatetc*->**tymed**. |
| **DV_E_DVASPECT** | The value is not valid for *pformatetc*->**dwAspect**. |
| **OLE_E_BLANK** | There is an uninitialized object. |
| **DV_E_TARGETDEVICE** | The object is static and *pformatetc*->**ptd** is non-**NULL**. |
| **STG_E_MEDIUMFULL** | The storage medium is full. |

## Remarks

**IOleCache::SetData** is usually called when an object is created from the clipboard or through a drag-and-drop operation, and Embed Source data is used to create the object.

**IOleCache::SetData** and [IOleCache::InitCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-initcache) are very similar. There are two main differences. The first difference is that while **IOleCache::InitCache** initializes the cache with the presentation format provided by the data object, **IOleCache::SetData** initializes it with a single format. Second, the **IOleCache::SetData** method ignores the ADVF_NODATA flag while **IOleCache::InitCache** obeys this flag.

A container can use this method to maintain a single aspect of an object, such as the icon aspect of the object.

## See also

[IOleCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache)

[IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache)

[IOleCache::SetData](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-setdata)