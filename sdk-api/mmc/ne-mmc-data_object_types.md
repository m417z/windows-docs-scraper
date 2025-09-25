# DATA_OBJECT_TYPES enumeration

## Description

The
**DATA_OBJECT_TYPES** enumeration is used by the *type* parameter of
[IComponentData::QueryDataObject](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponentdata-querydataobject) and
[IComponent::QueryDataObject](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-querydataobject) to obtain context information about a specified cookie.

## Constants

### `CCT_SCOPE:0x8000`

Data object for scope pane context.

### `CCT_RESULT:0x8001`

Data object for result pane context.

### `CCT_SNAPIN_MANAGER:0x8002`

Data object for Snap-in Manager context.

### `CCT_UNINITIALIZED:0xffff`

Data object has an invalid type.