# OleLoad function

## Description

Loads into memory an object nested within a specified storage object.

## Parameters

### `pStg` [in]

Pointer to the [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the storage object from which to load the specified object.

### `riid` [in]

Reference to the identifier of the interface that the caller wants to use to communicate with the object after it is loaded.

### `pClientSite` [in]

Pointer to the [IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite) interface on the client site object being loaded.

### `ppvObj` [out]

Address of pointer variable that receives the interface pointer requested in riid. Upon successful return, **ppvObj* contains the requested interface pointer on the newly loaded object.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_NOINTERFACE** | The object does not support the specified interface. |

Additionally, this function can return any of the error values returned by the [IPersistStorage::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-load) method.

## Remarks

OLE containers load objects into memory by calling this function. When calling the **OleLoad** function, the container application passes in a pointer to the open storage object in which the nested object is stored. Typically, the nested object to be loaded is a child storage object to the container's root storage object. Using the OLE information stored with the object, the object handler (usually, the default handler) attempts to load the object. On completion of the **OleLoad** function, the object is said to be in the loaded state with its object application not running.

Some applications load all of the object's native data. Containers often defer loading the contained objects until required to do so. For example, until an object is scrolled into view and needs to be drawn, it does not need to be loaded.

The **OleLoad** function performs the following steps:

* If necessary, performs an automatic conversion of the object (see the [OleDoAutoConvert](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oledoautoconvert) function).
* Gets the CLSID from the open storage object by calling the [IStorage::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-stat) method.
* Calls the [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) function to create an instance of the handler. If the handler code is not available, the default handler is used (see the [OleCreateDefaultHandler](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatedefaulthandler) function).
* Calls the [IOleObject::SetClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setclientsite) method with the *pClientSite* parameter to inform the object of its client site.
* Calls the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method for the [IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage) interface. If successful, the [IPersistStorage::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-load) method is invoked for the object.
* Queries and returns the interface identified by the *riid* parameter.