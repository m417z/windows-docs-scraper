# OLEGETMONIKER enumeration

## Description

Controls aspects of the behavior of the [IOleObject::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmoniker) and [IOleClientSite::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getmoniker) methods.

## Constants

### `OLEGETMONIKER_ONLYIFTHERE:1`

If a moniker for the object or container does not exist, [IOleClientSite::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getmoniker) should return E_FAIL and not assign a moniker.

### `OLEGETMONIKER_FORCEASSIGN:2`

If a moniker for the object or container does not exist, [IOleClientSite::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getmoniker) should create one.

### `OLEGETMONIKER_UNASSIGN:3`

[IOleClientSite::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getmoniker) can release the object's moniker (although it is not required to do so). This constant is not valid in [IOleObject::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmoniker).

### `OLEGETMONIKER_TEMPFORUSER:4`

If a moniker for the object does not exist, [IOleObject::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmoniker) can create a temporary moniker that can be used for display purposes ([IMoniker::GetDisplayName](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-getdisplayname)) but not for binding. This enables the object server to return a descriptive name for the object without incurring the overhead of creating and maintaining a moniker until a link is actually created.

## Remarks

If the OLEGETMONIKER_FORCEASSIGN flag causes a container to create a moniker for the object, the container should notify the object by calling the [IOleObject::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmoniker) method.

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)

[IOleClientSite::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getmoniker)

[IOleObject::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmoniker)