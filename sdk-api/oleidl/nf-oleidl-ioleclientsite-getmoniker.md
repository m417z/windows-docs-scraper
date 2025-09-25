# IOleClientSite::GetMoniker

## Description

Retrieves a moniker for the object's client site. An object can force the assignment of its own or its container's moniker by specifying a value for *dwAssign*.

## Parameters

### `dwAssign` [in]

Specifies whether to get a moniker only if one already exists, force assignment of a moniker, create a temporary moniker, or remove a moniker that has been assigned. In practice, you will usually request that the container force assignment of the moniker. Possible values are taken from the [OLEGETMONIKER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olegetmoniker) enumeration.

### `dwWhichMoniker` [in]

Specifies whether to return the container's moniker, the object's moniker relative to the container, or the object's full moniker. In practice, you will usually request the object's full moniker. Possible values are taken from the [OLEWHICHMK](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olewhichmk) enumeration.

### `ppmk` [out]

A pointer to an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) pointer variable that receives the interface pointer to the moniker for the object's client site. If an error occurs, the implementation must set *ppmk* to **NULL**. Each time a container receives a call to **IOleClientSite::GetMoniker**, it must increase the reference count on the *ppmk* pointer it returns. It is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when it is finished with the pointer.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | This container cannot assign monikers to objects. This is the case with OLE 1 containers. |

## Remarks

Containers implement **GetMoniker** as a way of passing out monikers for their embedded objects to clients that need to link to those objects.

When a link is made to an embedded object or to a pseudo-object within it (a range of cells in a spreadsheet, for example), the object needs a moniker to construct the composite moniker indicating the source of the link. If the embedded object does not already have a moniker, it can call **GetMoniker** to request one.

Every container that expects to contain links to embeddings should support **GetMoniker** to give out OLEWHICHMK_CONTAINER, thus enabling link tracking when the link client and link source files move, but maintain the same relative position.

An object must not persistently store its full moniker or its container's moniker, because these can change while the object is not loaded. For example, either the container or the object could be renamed, in which event, storing the container's moniker or the object's full moniker would make it impossible for a client to track a link to the object.

In some very specialized cases, an object may no longer need a moniker previously assigned to it and may wish to have it removed as an optimization. In such cases, the object can call **GetMoniker** with OLEGETMONIKER_UNASSIGN to have the moniker removed.

## See also

[IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite)

[IOleClientSite::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getmoniker)

[IOleObject::SetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setmoniker)