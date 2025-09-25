# OleCreateFromData function

## Description

Creates an embedded object from a data transfer object retrieved either from the clipboard or as part of an OLE drag-and-drop operation. It is intended to be used to implement a paste from an OLE drag-and-drop operation.

## Parameters

### `pSrcDataObj` [in]

Pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data transfer object that holds the data from which the object is created.

### `riid` [in]

Reference to the identifier of the interface the caller later uses to communicate with the new object (usually IID_IOleObject, defined in the OLE headers as the interface identifier for [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)).

### `renderopt` [in]

Value from the enumeration [OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender) that indicates the locally cached drawing or data-retrieval capabilities the newly created object is to have. Additional considerations are described in the following Remarks section.

### `pFormatEtc` [in]

 Pointer to a value from the enumeration [OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender) that indicates the locally cached drawing or data-retrieval capabilities the newly created object is to have. The **OLERENDER** value chosen affects the possible values for the *pFormatEtc* parameter.

### `pClientSite` [in]

Pointer to an instance of [IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite), the primary interface through which the object will request services from its container. This parameter can be **NULL**.

### `pStg` [in]

Pointer to the [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the storage object. This parameter may not be **NULL**.

### `ppvObj` [out]

Address of pointer variable that receives the interface pointer requested in riid. Upon successful return, **ppvObj* contains the requested interface pointer on the newly created object.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_STATIC** | Indicates OLE can create only a static object. |
| **DV_E_FORMATETC** | No acceptable formats are available for object creation. |

## Remarks

The **OleCreateFromData** function creates an embedded object from a data transfer object supporting the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface. The data object in this case is either the type retrieved from the clipboard with a call to the [OleGetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegetclipboard) function or is part of an OLE drag-and-drop operation (the data object is passed to a call to [IDropTarget::Drop](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-drop)).

If either the FileName or FileNameW clipboard format (CF_FILENAME) is present in the data transfer object, and CF_EMBEDDEDOBJECT or CF_EMBEDSOURCE do not exist, **OleCreateFromData** first attempts to create a package containing the indicated file. Generally, it takes the first available format.

If **OleCreateFromData** cannot create a package, it tries to create an object using the CF_EMBEDDEDOBJECT format. If that format is not available, **OleCreateFromData** tries to create it with the CF_EMBEDSOURCE format. If neither of these formats is available and the data transfer object supports the [IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage) interface, **OleCreateFromData** calls the object's [IPersistStorage::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-save) to have the object save itself.

If an existing linked object is selected, then copied, it appears on the clipboard as just another embeddable object. Consequently, a paste operation that invokes **OleCreateFromData** may create a linked object. After the paste operation, the container should call the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) function, requesting IID_IOleLink (defined in the OLE headers as the interface identifier for [IOleLink](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolelink)), to determine if a linked object was created.

Use the *renderopt* and *pFormatetc* parameters to control the caching capability of the newly created object. For general information about using the interaction of these parameters to determine what is to be cached, refer to the [OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender) enumeration. There are, however, some additional specific effects of these parameters on the way **OleCreateFromData** initializes the cache.

When **OleCreateFromData** uses either the CF_EMBEDDEDOBJECT or the CF_EMBEDSOURCE clipboard format to create the embedded object, the main difference between the two is where the cache-initialization data is stored:

* CF_EMBEDDEDOBJECT indicates that the source is an existing embedded object. It already has in its cache the appropriate data, and OLE uses this data to initialize the cache of the new object.
* CF_EMBEDSOURCE indicates that the source data object contains the cache-initialization information in formats other than CF_EMBEDSOURCE. **OleCreateFromData** uses these to initialize the cache of the newly embedded object.

The *renderopt* values affect cache initialization as follows.

| Value | Description |
| --- | --- |
| OLERENDER_DRAW & OLERENDER_FORMAT | If the presentation information to be cached is currently present in the appropriate cache-initialization pool, it is used. (Appropriate locations are in the source data object cache for CF_EMBEDDEDOBJECT, and in the other formats in the source data object for CF_EMBEDSOURCE.) If the information is not present, the cache is initially empty, but will be filled the first time the object is run. No other formats are cached in the newly created object. |
| OLERENDER_NONE | Nothing is to be cached in the newly created object. If the source has the CF_EMBEDDEDOBJECT format, any existing cached data that has been copied is removed. |
| OLERENDER_ASIS | If the source has the CF_EMBEDDEDOBJECT format, the cache of the new object is to contain the same cache data as the source object. For CF_EMBEDSOURCE, nothing is to be cached in the newly created object. This option should be used by more sophisticated containers. After this call, such containers would call [IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache) and [IOleCache::Uncache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-uncache) to set up exactly what is to be cached. For CF_EMBEDSOURCE, they would then also call [IOleCache::InitCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-initcache). |

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[OleCreate](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreate)