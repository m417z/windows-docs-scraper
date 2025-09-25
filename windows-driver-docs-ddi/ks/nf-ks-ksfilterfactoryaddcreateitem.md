# KsFilterFactoryAddCreateItem function

## Description

The **KsFilterFactoryAddCreateItem** function adds a new create item for the specified filter factory.

## Parameters

### `FilterFactory` [in]

A pointer to a [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) structure representing the filter factory to which to add a new create item.

### `RefString` [in]

A pointer to a Unicode text string that identifies the create item.

### `SecurityDescriptor` [in, optional]

This parameter optionally contains a pointer to a SECURITY_DESCRIPTOR structure for this type of object. See the Microsoft Windows SDK For information about this structure. For related information, see [KSOBJECT_CREATE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksobject_create_item). If **NULL**, no descriptor is assigned.

### `CreateItemFlags` [in]

See the table for the **Flags** member of [KSOBJECT_CREATE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksobject_create_item).

## Return value

**KsFilterFactoryAddCreateItem** returns success or failure of the attempt to add a new create item.

## Remarks

Normally, only a single create item using the reference GUID supplied in the filter descriptor is added for the filter factory. This function allows the caller to add create items associated with the given filter factory.

For more information, see [Initializing an AVStream Minidriver](https://learn.microsoft.com/windows-hardware/drivers/stream/initializing-an-avstream-minidriver).

## See also

[KSOBJECT_CREATE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksobject_create_item)

[KsAddObjectCreateItemToDeviceHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksaddobjectcreateitemtodeviceheader)

[KsAddObjectCreateItemToObjectHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksaddobjectcreateitemtoobjectheader)

[KsAllocateObjectCreateItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocateobjectcreateitem)

[KsFreeObjectCreateItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreeobjectcreateitem)

[KsQueryObjectCreateItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksqueryobjectcreateitem)