# OLECONTF enumeration

## Description

Indicates the type of objects
to be enumerated.

## Constants

### `OLECONTF_EMBEDDINGS:1`

Enumerates the embedded objects in the container.

### `OLECONTF_LINKS:2`

Enumerates the linked objects in the container.

### `OLECONTF_OTHERS:4`

Enumerates all objects in the container that are not OLE compound document objects (i.e., objects other than
linked or embedded objects). Use this flag to enumerate the container's pseudo-objects.

### `OLECONTF_ONLYUSER:8`

Enumerates only those objects the user is aware of. For example, hidden named-ranges in Microsoft Excel would
not be enumerated using this value.

### `OLECONTF_ONLYIFRUNNING:16`

Enumerates only those linked or embedded objects that are currently in the running state for this
container.

## See also

[IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown)

[IOleContainer::EnumObjects](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecontainer-enumobjects)

[IVBGetControl::EnumControls](https://learn.microsoft.com/windows/desktop/api/vbinterf/nf-vbinterf-ivbgetcontrol-enumcontrols)