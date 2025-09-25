# OleCreate function

## Description

Creates an embedded object identified by a CLSID. You use it typically to implement the menu item that allows the end user to insert a new object.

## Parameters

### `unnamedParam1`

TBD

### `unnamedParam2`

TBD

### `unnamedParam3`

TBD

### `unnamedParam4`

TBD

### `unnamedParam5`

TBD

### `unnamedParam6`

TBD

### `unnamedParam7`

TBD

### `unnamedParam8`

TBD

#### - pClientSite [in]

If you want **OleCreate** to call [IOleObject::SetClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setclientsite), pointer to the [IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite) interface on the container. The value may be **NULL**, in which case you must specifically call **IOleObject::SetClientSite** before attempting operations.

#### - pFormatEtc [in]

Depending on which of the [OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender) flags is used as the value of renderopt, pointer to one of the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) enumeration values. Refer to the **OLERENDER** enumeration for restrictions. This parameter, along with the *renderopt* parameter, specifies what the new object can cache initially.

#### - pStg [in]

Pointer to an instance of the [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the storage object. This parameter may not be **NULL**.

#### - ppvObj [out]

Address of pointer variable that receives the interface pointer requested in riid. Upon successful return, **ppvObject* contains the requested interface pointer.

#### - rclsid [in]

CLSID of the embedded object that is to be created.

#### - renderopt [in]

A value from the enumeration [OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender), indicating the locally cached drawing capabilities the newly created object is to have. The **OLERENDER** value chosen affects the possible values for the *pFormatEtc* parameter.

#### - riid [in]

Reference to the identifier of the interface, usually IID_IOleObject (defined in the OLE headers as the interface identifier for [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)), through which the caller will communicate with the new object.

## Return value

This function returns S_OK on success and supports the standard return value E_OUTOFMEMORY.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory for the operation. |

## Remarks

The **OleCreate** function creates a new embedded object, and is typically called to implement the menu item Insert New Object. When **OleCreate** returns, the object it has created is blank (contains no data), unless *renderopt* is OLERENDER_DRAW or OLERENDER_FORMAT, and is loaded. Containers typically then call the [OleRun](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olerun) function or [IOleObject::DoVerb](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb) to show the object for initial editing.

The *rclsid* parameter specifies the CLSID of the requested object. CLSIDs of registered objects are stored in the system registry. When an application user selects Insert Object, a selection box allows the user to select the type of object desired from those in the registry. When **OleCreate** is used to implement the Insert Object menu item, the CLSID associated with the selected item is assigned to the rclsid parameter of **OleCreate**.

The *riid* parameter specifies the interface the client will use to communicate with the new object. Upon successful return, the *ppvObject* parameter holds a pointer to the requested interface.

The created object's cache contains information that allows a presentation of a contained object when the container is opened. Information about what should be cached is passed in the *renderopt* and *pFormatetc* values. When **OleCreate** returns, the created object's cache is not necessarily filled. Instead, the cache is filled the first time the object enters the running state. The caller can add additional cache control with a call to [IOleCache::Cache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache-cache) after the return of **OleCreate** and before the object is run. If renderopt is OLERENDER_DRAW or OLERENDER_FORMAT, **OleCreate** requires that the object support the [IOleCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecache) interface. There is no such requirement for any other value of renderopt.

If *pClientSite* is non-**NULL**, **OleCreate** calls [IOleObject::SetClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setclientsite) through the *pClientSite* pointer. [IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite) is the primary interface by which an object requests services from its container. If *pClientSite* is **NULL**, you must make a specific call to **IOleObject::SetClientSite** before attempting any operations.

## See also

[FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc)

[IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite)

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[OLERENDER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olerender)