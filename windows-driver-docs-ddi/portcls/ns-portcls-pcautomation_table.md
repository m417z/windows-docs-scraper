# PCAUTOMATION_TABLE structure

## Description

The **PCAUTOMATION_TABLE** structure contains a miniport driver's master table of properties, methods, and events.

## Members

### `PropertyItemSize`

Specifies the size in bytes of the property structure used. Set this member to **sizeof**(PCPROPERTY_ITEM) or greater. See the following Remarks section.

### `PropertyCount`

Specifies the number of property items in the *Properties* array.

### `Properties`

Pointer to the filter's array of properties. This is an array of [PCPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcproperty_item) structures.

### `MethodItemSize`

Specifies the size in bytes of the methods structure used. Set this member to **sizeof**(PCMETHOD_ITEM) or greater. See the following Remarks section.

### `MethodCount`

Specifies the number of method items in the **Methods** array.

### `Methods`

Pointer to the filter's array of methods. This is an array of [PCMETHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcmethod_item) structures.

### `EventItemSize`

Specifies the size in bytes of the event structure used. Set this member to **sizeof**(PCEVENT_ITEM) or greater. See the following Remarks section.

### `EventCount`

Specifies the number of event items in the **Events** array.

### `Events`

Pointer to the filter's array of events. This is an array of [PCEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcevent_item) structures.

### `Reserved`

Reserved. Initialize to zero.

## Remarks

Any of the structure's item pointers can be **NULL**, in which case the corresponding counts should be zero. For item tables that are not zero length, the item size should not be smaller than the size of the corresponding item structure that is defined in the header file portcls.h. The minimum size for a property, event, or method item is **sizeof**(PCPROPERTY_ITEM), **sizeof**(PCEVENT_ITEM), or **sizeof**(PCMETHOD_ITEM), respectively. The item size can be larger than this, in which case the item structure is followed by whatever private data the miniport driver appends to it. Item sizes should be a multiple of eight.

The [IMiniport::GetDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-getdescription) method outputs a [PCFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcfilter_descriptor) structure that points to a PCAUTOMATION_TABLE structure that specifies the miniport driver's automation table.

## See also

[IMiniport::GetDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-getdescription)

[PCEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcevent_item)

[PCFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcfilter_descriptor)

[PCMETHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcmethod_item)

[PCPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcproperty_item)