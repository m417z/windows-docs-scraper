# OLEWHICHMK enumeration

## Description

Indicates which part of an object's moniker is being set or retrieved.

## Constants

### `OLEWHICHMK_CONTAINER:1`

The moniker of the object's container. Typically, this is a file moniker. This moniker is not persistently stored inside the object, since the container can be renamed even while the object is not loaded.

### `OLEWHICHMK_OBJREL:2`

The moniker of the object relative to its container. Typically, this is an item moniker, and it is part of the persistent state of the object. If this moniker is composed on to the end of the container's moniker, the resulting moniker is the full moniker of the object.

### `OLEWHICHMK_OBJFULL:3`

The full moniker of the object. Binding to this moniker results in a connection to the object. This moniker is not persistently stored inside the object, since the container can be renamed even while the object is not loaded.

## See also

[IOleClientSite::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getmoniker)

[IOleObject::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmoniker)

[IOleObject::SetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setmoniker)