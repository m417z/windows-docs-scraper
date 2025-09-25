# KsPropertyHandler function

## Description

Drivers call **KsPropertyHandler** function for IRP handling.

## Parameters

### `Irp` [in]

Specifies the IRP with the property request being handled.

### `PropertySetsCount` [in]

Specifies the number of property sets being passed.

### `PropertySet` [in]

Points to an array of [KSPROPERTY_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_set) structures. The driver should provide one structure for each property set it wants KsPropertyHandler to handle.

## Return value

The **KsPropertyHandler** function returns STATUS_SUCCESS if successful, or an error specific to the property being handled if unsuccessful. The function sets the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)->[IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block).Information member, either through setting it to zero because of an internal error, or through a property handler setting it. The function does not set the lrp->IoStatus.Status member nor does it complete the IRP.

## Remarks

**KsPropertyHandler** responds to all property identifiers defined by the sets, and can only be called at PASSIVE_LEVEL.

Each [KSPROPERTY_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_set) entry contains a pointer to an array of [KSPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_item) structures in its PropertyItem member. For driver-specific processing, KsPropertyHandler hands off each request to one of the driver-supplied callbacks within PropertyItem. KsPropertyHandler takes care of any IRP processing required.

KsPropertyHandler does not use the FastIoTable member of its [KSPROPERTY_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_set) structure. If the driver needs to support Fast I/O handling of requests, the same KSPROPERTY_SET structure should be passed to the KsFastPropertyHandler routine.

The owner of the property sets can perform prefiltering or postfiltering of property handling. Basic property structure access exceptions are handled by the **KsPropertyHandler** function, though cleanup for specific exceptions must be covered by the property handler.

**KsPropertyHandler** places a pointer to the relevant KSPROPERTY_SET structure in the **Irp->Tail.Overlay.DriverContext** parameter in the IRP. The minidriver can use the KSPROPERTY_SET_IRP_STORAGE macro, defined in *ks.h*, to access this pointer.

## See also

[KsFastPropertyHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfastpropertyhandler)

[KsPropertyHandlerWithAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspropertyhandlerwithallocator)