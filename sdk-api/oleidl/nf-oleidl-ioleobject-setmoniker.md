# IOleObject::SetMoniker

## Description

Notifies an object of its container's moniker, the object's own moniker relative to the container, or the object's full moniker.

## Parameters

### `dwWhichMoniker` [in]

The moniker is passed in *pmk*. Possible values are from the enumeration [OLEWHICHMK](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olewhichmk).

### `pmk` [in]

Pointer to where to return the moniker.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |

## Remarks

A container that supports links to embedded objects must be able to inform an embedded object when its moniker has changed. Otherwise, subsequent attempts by link clients to bind to the object will fail. The **IOleObject::SetMoniker** method provides one way for a container to communicate this information.

The container can pass either its own moniker, an object's moniker relative to the container, or an object's full moniker. In practice, if a container passes anything other than an object's full moniker, each object calls the container back to request assignment of the full moniker, which the object requires to register itself in the running object table.

The moniker of an object relative to its container is stored by the object handler as part of the object's persistent state. The moniker of the object's container, however, must not be persistently stored inside the object because the container can be renamed at any time.

### Notes to Callers

A container calls **IOleObject::SetMoniker** when the container has been renamed, and the container's embedded objects currently or can potentially serve as link sources. Containers call SetMoniker mainly in the context of linking because an embedded object is already aware of its moniker. Even in the context of linking, calling this method is optional because objects can call [IOleClientSite::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getmoniker) to force assignment of a new moniker.

### Notes to Implementers

Upon receiving a call to **IOleObject::SetMoniker**, an object should register its full moniker in the running object table and send [IAdviseSink::OnRename](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onrename) notification to all advise sinks that exist for the object.

## See also

[CreateItemMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createitemmoniker)

[IAdviseSink::OnRename](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onrename)

[IOleClientSite::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getmoniker)

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmoniker)