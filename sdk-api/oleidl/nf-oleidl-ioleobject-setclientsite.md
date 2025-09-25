# IOleObject::SetClientSite

## Description

Informs an embedded object of its display location, called a "client site," within its container.

## Parameters

### `pClientSite` [in]

Pointer to the [IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite) interface on the container application's client-site.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | An unexpected error occurred. |

## Remarks

Within a compound document, each embedded object has its own client site - the place where it is displayed and through which it receives information about its storage, user interface, and other resources. **IOleObject::SetClientSite** is the only method enabling an embedded object to obtain a pointer to its client site.

### Notes to Callers

A container can notify an object of its client site either at the time the object is created or, subsequently, when the object is initialized.

When creating or loading an object, a container may pass a client-site pointer (along with other arguments) to one of the following helper functions: [OleCreate](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreate), [OleCreateFromFile](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreatefromfile), [OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata) or [OleLoad](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleload). These helper functions load an object handler for the new object and call **IOleObject::SetClientSite** on the container's behalf before returning a pointer to the new object.

Passing a client-site pointer informs the object handler that the client site is ready to process requests. If the client site is unlikely to be ready immediately after the handler is loaded, you may want your container to pass a **NULL** client-site pointer to the helper function. The **NULL** pointer says that no client site is available and thereby defers notifying the object handler of the client site until the object is initialized. In response, the helper function returns a pointer to the object, but upon receiving that pointer the container must call **IOleObject::SetClientSite** as part of initializing the new object.

### Notes to Implementers

Implementation consists simply of incrementing the reference count on, and storing, the pointer to the client site.

## See also

[IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite)

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::GetClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getclientsite)

[OleCreate](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreate)

[OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata)

[OleCreateFromFile](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreatefromfile)

[OleLoad](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleload)