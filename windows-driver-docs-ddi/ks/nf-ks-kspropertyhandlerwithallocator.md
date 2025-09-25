## Description

The **KsPropertyHandlerWithAllocator** performs the same handling as [KsPropertyHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspropertyhandler), with the same restrictions, but allows an optional allocator callback to be used to provide a buffer for the parameters. If used, the filter may need to free the buffer in some nonconventional manner. IRP_BUFFERED_IO and IRP_DEALLOCATE_BUFFER flags are not set when using a custom allocator.

## Parameters

### `Irp` [in]

Specifies the IRP with the property request being handled.

### `PropertySetsCount` [in]

Specifies the number of property sets being passed.

### `PropertySet` [in]

Specifies the pointer to an array of property set information.

### `Allocator` [in, optional]

Optionally points to an allocation function used to allocate memory to store the property parameters.

### `PropertyItemSize` [in, optional]

Optionally contains the size of each KSPROPERTY_ITEM structure in the properties. The property item may be extended in order to store private information. If this parameter is zero, the structure size is assumed to be normal. If it is greater than or equal to a property item structure, the KSPROPERTY_ITEM_IRP_STORAGE macro can be used to return a pointer to the property item so the custom data can be retrieved. On 64-bit platforms, this parameter must be a multiple of 8.

## Return value

The **KsPropertyHandler** function returns STATUS_SUCCESS if successful, or an error specific to the property being handled if unsuccessful. The function sets the Irp->IoStatus.Information member, either through setting it to zero because of an internal error, or through a property handler setting it. The function does not set the lrp->IoStatus.Status member nor does it complete the IRP.

On 64-bit platforms, if the *PropertyItemSize* parameter is not a multiple of 8, STATUS_INVALID_PARAMETER is returned, and the call fails.

## Remarks

*KsPropertyHandlerWithAllocator* places a pointer to the relevant KSPROPERTY_ITEM structure in the **Irp->Tail.Overlay.DriverContext** parameter in the IRP. The minidriver can use the KSPROPERTY_ITEM_IRP_STORAGE macro, defined in *ks.h*, to access this pointer.

## See also

[KsFastPropertyHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfastpropertyhandler)

[KsPropertyHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspropertyhandler)