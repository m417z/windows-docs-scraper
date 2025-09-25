# OleCreateFromDataEx function

## Description

Extends [OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata) functionality by supporting more efficient instantiation of objects in containers requiring caching of multiple formats of presentation or data, instead of the single format supported by **OleCreateFromData**.

## Parameters

### `pSrcDataObj` [in]

Pointer to the data transfer object holding the new data used to create the new object. (see [OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata)).

### `riid` [in]

Reference to the identifier of the interface of the object to return.

### `dwFlags` [in]

This parameter can be 0 or OLECREATE_LEAVERUNNING (0x00000001).

### `renderopt` [in]

Value taken from the [OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender) enumeration.

### `cFormats` [in]

When *renderopt* is OLERENDER_FORMAT, indicates the number of [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structures in the *rgFormatEtc* array, which must be at least one. In all other cases, this parameter must be zero.

### `rgAdvf` [in]

When *renderopt* is OLERENDER_FORMAT, points to an array of **DWORD** elements, each of which is a combination of values from the [ADVF](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-advf) enumeration. Each element of this array is passed in as the advf parameter to a call to either [IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache) or [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise), depending on whether *pAdviseSink* is **NULL** or non-**NULL** (see below). In all other cases, this parameter must be **NULL**.

### `rgFormatEtc` [in]

When *renderopt* is OLERENDER_FORMAT, points to an array of [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structures. When *pAdviseSink* is **NULL**, each element of this array is passed as the *pFormatEtc* parameter to a call to the object's [IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache). This populates the data and presentation cache managed by the object's in-process handler (typically the default handler) with presentation or other cacheable data. When *pAdviseSink* is non-**NULL**, each element of this array is passed as the *pFormatEtc* parameter to a call to [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise). This allows the caller (typically an OLE Container) to do its own caching or processing of data received from the object.

### `lpAdviseSink` [in]

When renderopt is OLERENDER_FORMAT, may be either a valid [IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink) pointer, indicating custom caching or processing of data advises, or **NULL**, indicating default caching of data formats.

### `rgdwConnection` [out]

Location to return the array of dwConnection values returned when the [IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink) interface is registered for each advisory connection using [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise), or **NULL** if the returned advisory connections are not needed. This parameter must be **NULL** if *pAdviseSink* is **NULL**.

### `pClientSite` [in]

Pointer to the primary interface through which the object will request services from its container. This parameter may be **NULL**, in which case it is the caller's responsibility to establish the client site as soon as possible using [IOleObject::SetClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setclientsite).

### `pStg` [in]

Pointer to the storage to use for the object and any default data or presentation caching established for it.

### `ppvObj` [out]

Address of output pointer variable that receives the interface pointer requested in riid. Upon successful return, **ppvObj* contains the requested interface pointer on the newly created object.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_NOINTERFACE** | The provided interface identifier is invalid. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## Remarks

The following call to [OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata):

``` syntax
OleCreateFromData(lpszFileName, riid, renderopt, pFormatEtc, pClientSite, pStg, ppvObj);
```

is equivalent to the following call to **OleCreateFromDataEx**:

``` syntax
DWORD    advf = ADVF_PRIMEFIRST;
    OleCreateFromFileEx(rclsid, lpszFileName, riid, renderopt, 1, &advf, pFormatEtc, NULL, pClientSite, pStg, ppvObj);
```

Existing instantiation functions ([OleCreate](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreate), [OleCreateFromFile](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreatefromfile), [OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata), [OleCreateLink](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelink), [OleCreateLinkToFile](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelinktofile), and [OleCreateLinkFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelinkfromdata)) create only a single presentation or data format cache in the default cache location (within the '\001OlePresXXX' streams of the passed-in [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage)) during instantiation. Plus, these caches must be created when the object next enters the running state. Because most applications require caching at least two presentations (screen and printer) and may require caching data in a different format or location from the handler, applications must typically launch and shut down the object server multiple times in order to prime their data caches during object creation, i.e., Insert Object, Insert Object from File, and Paste Object.

Extended versions of these creation functions solve this problem. [OleCreateEx](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreateex), [OleCreateFromFileEx](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromfileex), **OleCreateFromDataEx**, [OleCreateLinkEx](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelinkex), [OleCreateLinkToFileEx](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelinktofileex), and [OleCreateLinkFromDataEx](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelinkfromdataex), contain the following new parameters: *dwFlags* to indicate additional options, *cFormats* to indicate how many formats to cache, *rgAdvf*, from the [ADVF](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-advf) enumeration, to specify the advise flags for each format to be cached, *pAdviseSink* to indicate whether presentation (default-handler) or data (non-default-handler) caching is required, *rgdwConnection* to return [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise) cookies, and *rgFormatEtc*, an array of formats rather than a single format.

Containers requiring that multiple presentations be cached on their behalf by the object's handler can simply call these functions and specify the number of formats in *cFormats*, the [ADVF](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-advf) flags for each format in *rgAdvf*, and the set of formats in *rgFormatEtc*. These containers pass **NULL** for *pAdviseSink*.

Containers performing all their own data- or presentation-caching perform these same steps, but pass a non-**NULL***pAdviseSink*. They perform their own caching or manipulation of the object or data during [IAdviseSink::OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange). Typically, such containers never establish the advisory connections with ADVF_NODATA, although they are not prevented from doing so.

These new functions are for OLE Compound Documents. Using these functions, applications can avoid the repeated launching and initialization steps required by the current functions. They are targeted at OLE Compound Document container applications that use default data- and presentation-caching, and also at applications that provide their own caching and data transfer from the underlying [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise) support.

## See also

[ADVF](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-advf)

[FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc)

[IAdviseSink::OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange)

[IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise)

[IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache)

[IOleObject::SetClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setclientsite)

[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage)

[OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender)

[OleCreate](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreate)

[OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata)